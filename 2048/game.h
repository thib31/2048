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

    QStringList readVal();

private:
    vector<int**> T;
    int** Damier;
    int taille;
    string couleur[2]={"#dddddd","#333333"};
    QStringList Damier_valeurs;



signals:
    void gameChanged();
};

#endif // GAME_H
