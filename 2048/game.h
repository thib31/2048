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
    Q_INVOKABLE void nouvPartie();

    Q_PROPERTY(QStringList valQML READ readVal NOTIFY gameChanged)
    Q_PROPERTY(QStringList colQML READ readCol NOTIFY gameChanged)
    Q_PROPERTY(QStringList templateQML READ readTemplate NOTIFY gameChanged)

    QStringList readVal();
    QStringList readCol();
    QStringList readTemplate();

    Q_INVOKABLE void precedent();
    Q_INVOKABLE void suivant();
    Q_INVOKABLE void deplacement(int dir_i, int dir_j);
    void traiteListe(int atraiter[]);
    void condense(int atraiter[]);
    void fusionne(int atraiter[]);
    void recupDamier();

    Q_INVOKABLE int enregistrePartie(QString nom, bool force);
    Q_INVOKABLE void chargePartie(QString nom);
    Q_INVOKABLE void deletePartie(QString nom);
    void getNomPartie();
    bool rechPartie(string nom);




private:
    vector<int**> T;                            // Contient la liste des positions dans le jeu (on stocke uniquement les exposants)
    int** Damier;                               // Element de travail = dernier élément de T
    int etape;
    int taille;                                 // Taille du jeu, pour amélioration ultérieure du code
    string couleur[10]={"#d6cdc4","#eee4da","#ece0c8","#f2b179","#f59563","#f57c5f","#f65e39","#edce71","#edcb61","#ecc850"};
    QStringList Damier_valeurs;                 // Damier envoyé à l'interface QML, contenant les valeurs à afficher
    QStringList Damier_couleurs;                // Damier envoyé à l'interface QML, contenant les couleurs des cases
    QStringList templateQML;

    //string const nomFichier=("partiesEnregistrees.txt");
    string const nomFichier=("C:/Users/thilv/Desktop/2048/2048/Fichiers/partiesEnregistrees.txt");
    QStringList nomsParties;


signals:
    void gameChanged();
};

#endif // GAME_H
