#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <vector>

using namespace std;

class game : public QObject
{
    Q_OBJECT
public:
    explicit game(QObject *parent = nullptr);
    Q_INVOKABLE void nouvPartie();                  // Fonction qui initialise le jeu / remet à zero

    Q_PROPERTY(QStringList valQML READ readVal NOTIFY gameChanged)
    Q_PROPERTY(QStringList colQML READ readCol NOTIFY gameChanged)
    Q_PROPERTY(QStringList templateQML READ readTemplate NOTIFY gameChanged)
    Q_PROPERTY(QStringList partiesQML READ readParties NOTIFY listePartieChanged)
    Q_PROPERTY(bool valPerdu READ readPerdu NOTIFY gameChanged)

    QStringList readVal();                          // Valeurs des cases
    QStringList readCol();                          // Couleurs des cases
    QStringList readTemplate();                     // Informations sur le template : détaillées dans game.cpp
    QStringList readParties();                      // Liste des parties sauvegardées
    bool readPerdu();

    Q_INVOKABLE void precedent();                   // Fonction permettant de revenir à l'étape précédente
    Q_INVOKABLE void suivant();                     // Pour passer à l'étape suivante
    Q_INVOKABLE void deplacement(int dir_i, int dir_j);     // Instruction de mouvement
    void traiteListe(int atraiter[]);               // Chaque ligne ou colonne est transformée en ligne, selon la direction à traiter
    void condense(int atraiter[]);                  // "Plaque" les éléments sur le bord
    void fusionne(int atraiter[]);                  // Effectue les combinaisons possibles
    void recupDamier();                             // Crée une copie du damier, pour garder l'ancien en mémoire
    Q_INVOKABLE void closePerdu();                  // Referme la fenêtre qui s'affiche lors que la partie est perdue

    // Fonctions de gestion des enregistrements
    Q_INVOKABLE int enregistrePartie(QString nom, bool force);
    Q_INVOKABLE void chargePartie(QString nom);
    Q_INVOKABLE void deletePartie(QString nom);
    void getNomPartie();                            // Crée la liste des parties enregistrées
    bool rechPartie(string nom);                    // Recherche l'existence d'un doublon

    // Choix de la police
    Q_INVOKABLE void changePolice(QString police);



private:
    vector<int**> T;                            // Contient la liste des positions dans le jeu (on stocke uniquement les exposants)
    int** Damier;                               // Element de travail
    int etape;                                  // Indice de Damier dans T
    int taille;                                 // Taille du jeu, pour amélioration ultérieure du code
    string* couleur;
    QStringList Damier_valeurs;                 // Damier envoyé à l'interface QML, contenant les valeurs à afficher
    QStringList Damier_couleurs;                // Damier envoyé à l'interface QML, contenant les couleurs des cases
    QStringList templateQML;                    // Damier envoyé à l'interface QML, contenant les informations du template
    QStringList nomsParties;                    // Damier envoyé à l'interface QML, contenant les noms des parties enregistrées
    bool valPerdu;

    // Répertoire des fichiers txt
    string const nomFichier=("C:/Users/thilv/Desktop/2048/2048/Fichiers/partiesEnregistrees.txt");      // Fichier de stockage des parties
    string const tempFichier=("C:/Users/thilv/Desktop/2048/2048/Fichiers/Temp.txt");                    // Fichier provisoire, utilisé pour modifier le fichier précédent
    string storagePath=("C:/Users/thilv/Desktop/2048/2048");




signals:
    void gameChanged();                         // Modification du damier
    void listePartieChanged();                  // Modification de la liste des parties enregistrées
};

#endif // GAME_H
