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
    void nouvPartie();

    Q_PROPERTY(QStringList valQML READ readVal NOTIFY gameChanged)
    Q_PROPERTY(QStringList colQML READ readCol NOTIFY gameChanged)

    QStringList readVal();
    QStringList readCol();

private:
    vector<int**> T;                            // Contient la liste des positions dans le jeu
    int** Damier;                               // Element de travail = dernier élément de T
    int taille;                                 // Taille du jeu, pour amélioration ultérieure du code
    string couleur[2]={"#eeeeee","#333333"};
    QStringList Damier_valeurs;                 // Damier envoyé à l'interface QML, contenant les valeurs à afficher
    QStringList Damier_couleurs;                // Damier envoyé à l'interface QML, contenant les couleurs des cases



signals:
    void gameChanged();
};

#endif // GAME_H
