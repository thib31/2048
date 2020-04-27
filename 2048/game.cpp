#include "game.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

game::game(QObject *parent) : QObject(parent)
{
    // On déclare les premiers paramètres/variables
    taille=4;
    couleur = new string[16]{"#d6cdc4","#eee4da","#ece0c8","#f2b179","#f59563","#f57c5f","#f65e39","#edce71","#edcb61","#ecc850","#ecc850","#ecc850","#ecc850","#ecc850","#ecc850","#ecc850"};
    templateQML.push_back(QString::fromStdString("#fbf8ef"));           // Couleur de l'arrière plan
    templateQML.push_back(QString::fromStdString("#80cfceca"));         // Couleur de masquage (pour les fenêtres Enregistrer et Charger
    templateQML.push_back(QString::fromStdString("#bbada0"));           // Couleurs de la grille
    templateQML.push_back(QString::fromStdString(couleur[0]));          // Couleur des boutons
    templateQML.push_back(QString::fromStdString(couleur[5]));          // Couleur boutons (variante rouge)
    templateQML.push_back(QString::fromStdString("true"));              // Permet de réinitialiser l'état du focus lorsque celui-ci se désactive (enregistrement ou chargement de partie)
    templateQML.push_back(QString::fromStdString("Tahoma"));            // Police par défaut
    templateQML.push_back(QString::fromStdString("file:///"+storagePath+"/Images/Cat.jpg")); // Image affichée à la défaite
    templateQML.push_back(QString::fromStdString("file:///"+storagePath+"/Images/Win.jpg")); // Image affichée à la victoire
    valFin.append(false); valFin.append(false); valFin.append(false);   // Définit l'état des fenetres de fin de partie : affiche perdu; affiche gagné; partie déjà gagnée

    // Création des damiers de valeurs et couleurs.
    for (int i=0; i<16; i++){
        Damier_valeurs.push_back(QString());
        Damier_couleurs.push_back(QString::fromStdString(couleur[0]));
    }
    nouvPartie();
}

void game::nouvPartie()
{
    // On réinitialise les tableaux de données
    T.clear();

    // Création du premier damier, vide
    Damier = new int* [taille];
    for (int i=0; i<taille; i++) {
        Damier[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            Damier[i][j] = 0;
        }
    }

    // Première case remplie
    Damier[rand()%taille][rand()%taille]=1;

    // Insertion du damier dans la "pile" du jeu
    T.push_back(Damier);
    etape=0;

    // MaJ initiale du jeu
    gameChanged();
    listePartieChanged();
}

///////////////// Section 1 : Mise à jours d'informations pour l'interface QML /////////////////

QStringList game::readVal(){                                // Valeurs du damier : on récupère les exposants, on fait le calcul, et on transforme en Qstring
    for (int i=0; i<taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (Damier[i][j]==0)
            {Damier_valeurs[i*taille+j]=QString();}         // Quand la case est vide, on n'affiche pas le nombre "0"
            else
            {Damier_valeurs[i*taille+j]=QString::number(pow(2,Damier[i][j]));}     // Sinon on affiche la valeur concernée
        }
    }
    return Damier_valeurs;
}

QStringList game::readCol(){                                // Couleurs du damier
    for (int i=0; i<taille; i++) {
        for (int j = 0; j < taille; j++) {
            Damier_couleurs[i*taille+j]=QString::fromStdString(couleur[Damier[i][j]]); // On récupère dans "couleur" celle qui correspond
        }
    }
    return Damier_couleurs;
}

QStringList game::readTemplate(){
    return templateQML;
}

QStringList game::readParties(){
    nomsParties.clear();    // Nécessaire si on effectue une mise à jour
    getNomPartie();         // On remplit la liste
    nomsParties.sort();     // Et on la trie par ordre alphabétique, pour plus de lisibilité
    return nomsParties;
}

QList<bool> game::readFin(){
    return valFin;
}

///////////////// Section 2 : Algorithme du jeu /////////////////

void game::deplacement(int dir_i, int dir_j){       // Actionnée lors d'un mouvement, avec l'un des deux entiers qui vaut +/-1, l'autre 0
    while (T.size()-etape>1){       // On supprime les configurations "suivantes" si elles existent
        T.pop_back();               // (si la touche Précédent a été utilisée)
    }
    recupDamier();
    int debut; int fin;             // Dans la suite, je vais parcourir soit en ligne, soit en colonne, dans le sens opposé au déplacement.
    if (dir_i+dir_j==1){            // Ces entiers correspondent au 1er et dernier élément à traiter.
        debut=0;
        fin=taille;
    }
    else{
        debut=taille-1;
        fin=-1;
    }
    int atraiter[4];
    int indices[4];
    int cpt(0);
    int cptCaseVide(0);
    int tabCaseVide[4];

    if (dir_j==0){          // 1er cas : déplacement vertical. On traite les colonnes l'une après l'autre.
        for (int j=0; j<taille; j++){
            cpt=0;
            for (int i=debut; i!=fin; i+=dir_i){
                atraiter[cpt]=Damier[i][j];             // On stocke la ligne ou colonne sous forme de liste, pour utiliser une seule fonction de traitement
                indices[cpt]=i;                         // Et dans l'ordre opposé au déplacement
                cpt++;
            }
            traiteListe(atraiter);                      // On applique la transformation
            for (int k=0; k<taille; k++)                // Et on met les valeurs finales dans Damier
                Damier[indices[k]][j]=atraiter[k];
            if (atraiter[taille-1]==0){                 // On indique que la dernière case de la colonne est libre
                tabCaseVide[cptCaseVide]=j;
                cptCaseVide++;
            }
        }
        if (cptCaseVide==0){                            // Cas où toutes les colonnes sont prises : plus d'espace libre, la partie est perdue
            valFin[0]=true;
        }
        else{
            Damier[fin-dir_i][tabCaseVide[rand()%cptCaseVide]]=1;   // On insère un 2 de manière aléatoire
        }
    }
    else{          // 2nd cas : déplacement horizontal. On traite les lignes l'une après l'autre. Même chose, mais transposée.
        for (int i=0; i<taille; i++){
            cpt=0;
            for (int j=debut; j!=fin; j+=dir_j){
                atraiter[cpt]=Damier[i][j];             // On stocke la ligne de la même manière
                indices[cpt]=j;
                cpt++;
            }
            traiteListe(atraiter);
            for (int k=0; k<taille; k++)
                Damier[i][indices[k]]=atraiter[k];
            if (atraiter[taille-1]==0){
                tabCaseVide[cptCaseVide]=i;
                cptCaseVide++;
            }
        }
        if (cptCaseVide==0){
            valFin[0]=true;
        }
        else{
            Damier[tabCaseVide[rand()%cptCaseVide]][fin-dir_j]=1;
        }
    }
    T.push_back(Damier);                    // On rajoute la dernière configuration,
    etape++;                                // incrémente le numéro de l'étape en cours,
    gameChanged();                          // et met à jour l'interface QML
}

void game::traiteListe(int *atraiter){
    condense(atraiter);                     // On plaque les cases (non nulles) contre un bord,
    fusionne(atraiter);                     // On effectue les fusions possibles,
    condense(atraiter);                     // Et on replaque, pour compenser les eventuels trous laissés
}

void game::condense(int *atraiter){
    int indice_premier_zero(taille);        // Sert à la fois de paramètre de detection et de "marque page"
    int k(0);
    while(k<taille){
        if (atraiter[k]==0){                // On note l'indice du premier 0 rencontré
            if (indice_premier_zero>k){
                indice_premier_zero=k;
            }
            k++;
        }
        else{                               // Dès que l'on rencontre une case pleine,
            if (indice_premier_zero<k){     // Si on est déjà passés sur un 0, on la rapproche
                atraiter[indice_premier_zero]=atraiter[k];
                atraiter[k]=0;
                k=indice_premier_zero+1;
                indice_premier_zero=taille; // On réinitialise le paramètre de détection, et on reprend à la case suivante
            }
            else k++;                       // Pas de case vide disponible
        }
    }
}

void game::fusionne(int *atraiter){
    int k(0);
    while (k<taille-1){
        if (atraiter[k]==0){                // Si l'on rencontre un 0, alors la suite de la liste est vide (fonction condense)
            k=taille;                       // Donc on s'arrête
        }
        else if (atraiter[k]==atraiter[k+1]){  // Si on peut réaliser la fusion,
            atraiter[k]++;                  // On incrémente l'exposant du 1er,
            atraiter[k+1]=0;                // On passe le second a 0,
            k+=2;                           // Et on enjambe le 0 ainsi créé.
            if (atraiter[k]==11 && valFin[2]==false){
                valFin[1]=true;             // On affiche la fenetre de victoire
                valFin[2]=true;             // On enregistre que la partie est déjà gagnée, pour ne pas déranger dans les mouvements ultérieurs
            }
        }                                   // Dans le jeu du 2048, un chiffre peut se combiner au plus 1 fois par coup joué

        else k++;                           // Sinon, on passe à la case suivante.
    }
}

void game::precedent(){                     // Retour à l'étape précédente : si possible,
    if (etape>0){
        etape--;                            // On décrémente le compteur,
        Damier=T[etape];                    // Change le damier,
        gameChanged();                      // Et met à jour l'interface QML
    }
}

void game::suivant(){                       // Idem dans l'autre sens
    if (1<T.size()-etape){
        etape++;
        Damier=T[etape];
        gameChanged();
    }
}

void game::recupDamier(){                   // La structure utilisée pose un problème : on ne peut pas modifier
        Damier = new int* [taille];         // le même damier tout au long de la partie.
    for (int i=0; i<taille; i++) {          // Il faut donc créer une copie, à chaque nouveau déplacement
        Damier[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            Damier[i][j] = T[etape][i][j];
        }
    }
}

void game::closeFin(int i){
    valFin[i]=false;
    gameChanged();
}

///////////////// Section 3 : Gestion de l'enregistrement des parties /////////////////

int game::enregistrePartie(QString nom, bool force){
    // J'ai créé une seule fonction d'enregistrement pour 2 cas :
    //      - Création d'un nouvel enregistrement       (force = false)
    //      - Ecrasement d'un ancien.                   (force = true)
    // Cela est géré par l'interface graphique, fichier "Enregistrer.qml"
    // La structure du fichier est faite avec 1 ligne par enregistrement, et décomposée ainsi :
    //      - Le nb de mots qui composent le nom
    //      - Le nom (qui peut contenir des espaces)
    //      - L'étape à laquelle en est le jeu
    //      - La taille de T
    //      - T, "linéarisé" : parcouru par des boucles for, tous les éléments stockés les uns après les
    //          autres, et séparés par des espaces.
    // On utilise l'espace comme séparateur pour se servir du module ifstream.

    if (force) deletePartie(nom);           // Si l'on force l'enregistrement, on supprime l'ancien fichier

    ofstream parties(nomFichier.c_str(), ios::app); // On ouvre le fichier en écriture, à la fin
    string nomStr=nom.toStdString();

    if (force|| !rechPartie(nomStr)){       // Distinction : soit on écrase, soit il n'y a pas d'enregistrement du même nom
        parties<<count(nomStr.begin(), nomStr.end(), ' ')+1<<" ";   // Pour les explications, tout est au début de la fonction.
        parties<<nomStr<<" "<<etape<<" "<<T.size();
        for (int k=0; T.size()-k>0; k++){
            for (int i=0; i<taille; i++) {
                for (int j = 0; j < taille; j++) {
                    parties<<" "<<T[k][i][j];
                }
            }
        }
        parties<<endl;
        listePartieChanged();
        return 0;       // On retourne 0 : si l'enregistrement était possible, il s'est bien passé. S'il était forcé, on se fiche du résultat.
    }
    else return 1;      // Et s'il n'était pas possible, on renvoie 1. L'interface QML va evoyer une demande de confirmation
}

void game::getNomPartie(){
    // Ici, in crée la liste avec les noms de toutes les parties.

    ifstream parties(nomFichier.c_str());
    string nom;
    string mot;
    int longNom;
    string trash;
    parties>>longNom;                   // On récupère la longueur du 1er nom
    for (int k=0; k<longNom; k++){      // On le reconstitue
        parties>>mot;
        nom+=mot+" ";
    } nom.pop_back();
    while(getline(parties, trash)){     // Et on parcourt la boucle
        nomsParties.push_back(QString::fromStdString(nom));
        parties>>longNom;
        nom="";
        for (int k=0; k<longNom; k++){
            parties>>mot;
            nom+=mot+" ";
        }
        nom.pop_back();
    };
    // L'utilisation d'une do{}while() ne permet pas d'enlever la première itération de la boucle,
    // Au contraire elle crée un doublon, lorsqu'on arrive sur la dernière ligne (vide)
}

bool game::rechPartie(string nom){
    // Ici, on vérifie si un nom de partie a déjà été emprunté.
    // Même principe, avec cette fois un test dans la boucle,
    // et une vérification de la condition d'arrêt à la fin.

    ifstream parties(nomFichier.c_str());
    string test;
    int longTest;
    string mot;
    string trash;

    parties>>longTest;
    for (int k=0; k<longTest; k++){
        parties>>mot;
        test+=mot+" ";
    } test.pop_back();
    while(test!=nom && getline(parties, trash)){
        parties>>longTest;
        test="";
        for (int k=0; k<longTest; k++){
            parties>>mot;
            test+=mot+" ";
        }
        test.pop_back();
    }
    if (test==nom) return true;
    else return false;
}

void game::chargePartie(QString nom){
    // Dans cette partie, on va procéder en 2 étapes :
    //      - aller chercher la ligne à charger
    //      - charger la ligne

    ifstream parties(nomFichier.c_str());
    string nomStr=nom.toStdString();
    string test;
    int longTest;
    string mot;
    string trash;
    int longueurT;

    // On parcourt le fichier txt jusqu'à la bonne ligne
    parties>>longTest;
    for (int k=0; k<longTest; k++){
        parties>>mot;
        test+=mot+" ";
    } test.pop_back();
    while(test!=nomStr){
        getline(parties, trash);
        parties>>longTest;
        test="";
        for (int k=0; k<longTest; k++){
            parties>>mot;
            test+=mot+" ";
        } test.pop_back();
    }

    // La ligne en cours est la bonne : on récupère les données
    parties>>etape;
    parties>>longueurT;

    // Et on reconstitue T
    for (int k=0; k<longueurT; k++){
        Damier = new int* [taille];
        for (int i=0; i<taille; i++){
            Damier[i]=new int[taille];
            for (int j=0; j<taille; j++){
                parties>>Damier[i][j];
            }
        }
        T.push_back(Damier);
    }
    gameChanged();      // On met à jour le damier.
}

void game::deletePartie(QString nom){
    // On ne peut pas éditer directement un txt (ou en tout cas je n'ai pas trouvé les fonctions).
    // Pour contourner le problème, on crée un nouveau fichier dans lequel on recopie l'ancien, à
    // l'exception de la ligne à supprimer.
    // Puis on supprime l'ancien fichier, et on renomme le nouveau.

    ifstream parties(nomFichier.c_str());
    ofstream temp(tempFichier.c_str());
    string nomStr=nom.toStdString();
    string test;
    int longTest;
    string mot;
    string queue;

    parties>>longTest;
    test="";
    for (int k=0; k<longTest; k++){
        parties>>mot;
        test+=mot+" ";
    } test.pop_back();
    while(getline(parties, queue)){
        if (nomStr!=test){
            temp<<longTest<<" "<<test<<queue<<endl;
        }
        parties>>longTest;
        test="";
        for (int k=0; k<longTest; k++){
            parties>>mot;
            test+=mot+" ";
        } test.pop_back();
    }
    parties.close();
    temp.close();
    remove(nomFichier.c_str());
    rename(tempFichier.c_str(),nomFichier.c_str());
    listePartieChanged();    // Permet la mise à jour de la liste quand on supprime un enregistrement
}


///////////////// Partie 4 : Modification de l'apparence /////////////////
void game::changePolice(QString police){
    templateQML[6]=police;
    gameChanged();
}
