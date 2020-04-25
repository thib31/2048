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
    vector<int**> T;
    int** Damier;
    int taille;
    string couleur[2]={"#dddddd","#333333"};
    QStringList Damier_valeurs;
    QStringList Damier_couleurs;



signals:
    void gameChanged();
};

#endif // GAME_H
