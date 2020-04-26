#include "game.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <fstream>


using namespace std;

game::game(QObject *parent) : QObject(parent)
{
    // On déclare les premiers paramètres/variables
    taille=4;
    // Création des damiers de valeurs et couleurs.
    for (int i=0; i<16; i++){
        Damier_valeurs.push_back(QString());
        Damier_couleurs.push_back(QString::fromStdString(couleur[0]));
    }

    nouvPartie();
}

void game::nouvPartie()
{
    // On initialise les tableaux de données
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

    // Insertion dans la "pile" du jeu
    T.push_back(Damier);
    etape=0;

    // MaJ initiale du jeu
    gameChanged();
}


QStringList game::readVal(){
    for (int i=0; i<taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (Damier[i][j]==0)
            {Damier_valeurs[i*taille+j]=QString();}                         // Quand la case est vide, on n'affiche pas le nombre "0"
            else
            {Damier_valeurs[i*taille+j]=QString::number(pow(2,Damier[i][j]));}     // Sinon on affiche la valeur concernée
        }
    }
    return Damier_valeurs;
}

QStringList game::readCol(){

    for (int i=0; i<taille; i++) {
        for (int j = 0; j < taille; j++) {
            Damier_couleurs[i*taille+j]=QString::fromStdString(couleur[Damier[i][j]]);
        }
    }

    return Damier_couleurs;
}

QStringList game::readTemplate(){
    templateQML.push_back(QString::fromStdString(couleur[0]));
    return templateQML;
}

void game::deplacement(int dir_i, int dir_j){
    while (T.size()-etape>1){
        T.pop_back();
    }
    recupDamier();
    int debut; int fin;
    if (dir_i+dir_j==1){
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
                indices[cpt]=i;
                cpt++;
            }
            traiteListe(atraiter);
            for (int k=0; k<taille; k++)
                Damier[indices[k]][j]=atraiter[k];
            if (atraiter[taille-1]==0){
                tabCaseVide[cptCaseVide]=j;
                cptCaseVide++;
            }
        }
        if (cptCaseVide==0){
            // Partie perdue
        }
        else{
            Damier[fin-dir_i][tabCaseVide[rand()%cptCaseVide]]=1;
        }
    }
    else{          // 2nd cas : déplacement horizontal. On traite les lignes l'une après l'autre.
        for (int i=0; i<taille; i++){
            cpt=0;
            for (int j=debut; j!=fin; j+=dir_j){
                atraiter[cpt]=Damier[i][j];             // On stocke la ligne ou colonne sous forme de liste, pour utiliser une seule fonction de traitement
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
            // Partie perdue
        }
        else{
            Damier[tabCaseVide[rand()%cptCaseVide]][fin-dir_j]=1;
        }
    }
    T.push_back(Damier);
    etape++;
    gameChanged();
}

void game::traiteListe(int *atraiter){
    condense(atraiter);
    fusionne(atraiter);
    condense(atraiter);
}

void game::condense(int *atraiter){
    int indice_premier_zero(taille);        // Sert à la fois de paramètre de detection et de "marque page"
    int k(0);
    while(k<taille){
        if (atraiter[k]==0){
            if (indice_premier_zero>k){     // Premier zéro que l'on rencontre
                indice_premier_zero=k;
            }
            k++;
        }
        else{
            if (indice_premier_zero<k){     // On est déjà passés sur une case vide
                atraiter[indice_premier_zero]=atraiter[k];
                atraiter[k]=0;
                k=indice_premier_zero+1;
                indice_premier_zero=taille; // On réinitialise le paramètre de détection
            }
            else k++;                       // Pas de case vide disponible
        }
    }
}

void game::fusionne(int *atraiter){
    int k(0);
    while (k<taille-1){
        if (atraiter[k]==0){
            k=taille;
        }
        else if (atraiter[k]==atraiter[k+1]){
            atraiter[k]++;
            atraiter[k+1]=0;
            k+=2;
        }
        else k++;
    }
}

void game::precedent(){
    if (etape>0){
        etape--;
        Damier=T[etape];
        gameChanged();
    }
}

void game::suivant(){
    if (1<T.size()-etape){
        etape++;
        Damier=T[etape];
        gameChanged();
    }
}

void game::recupDamier(){
        Damier = new int* [taille];
    for (int i=0; i<taille; i++) {
        Damier[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            Damier[i][j] = T[etape][i][j];
        }
    }
}

int game::enregistrePartie(QString nom, bool force){
    ofstream parties(nomFichier.c_str(), ios::app);
    string nomStr=nom.toStdString();
    if (force|| !rechPartie(nomStr)){
        parties<<nomStr<<" "<<etape<<" "<<T.size();
        for (int k=0; T.size()-k>0; k++){
            for (int i=0; i<taille; i++) {
                for (int j = 0; j < taille; j++) {
                    parties<<" "<<T[k][i][j];
                }
            }
        }
        parties<<endl;
        return 0;
    }
    else return 1;
}

void game::getNomPartie(){
    ifstream parties(nomFichier.c_str());
    string nom;
    do{
        parties>>nom;
        nomsParties.push_back(QString::fromStdString(nom));
    }while(getline(parties, nom));
}

bool game::rechPartie(string nom){
    ifstream parties(nomFichier.c_str());
    string test;
    string trash;
    do{
        parties>>test;
    }while(test!=nom && getline(parties, trash));
    if (test==nom) return true;
    else return false;
}

void game::chargePartie(QString nom){
    ifstream parties(nomFichier.c_str());
    string nomStr=nom.toStdString();
    string test;
    string trash;
    int longueurT;

    parties>>test;
    while(test!=nomStr){
        getline(parties, trash);
        parties>>test;
    }

    parties>>etape;
    parties>>longueurT;
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
    gameChanged();
}

void game::deletePartie(QString nom){
    ifstream parties(nomFichier.c_str());
    ofstream temp("Temp.txt");
    string nomStr=nom.toStdString();
    string name;
    string queue;

    parties>>name;
    while(getline(parties, queue)){
        if (nomStr!=name){
            temp<<name<<" "<<queue<<endl;
        }
    }
}
