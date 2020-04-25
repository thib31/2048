#include "game.h"

using namespace std;

game::game(QObject *parent) : QObject(parent)
{
    nouvPartie();
}

void game::nouvPartie()
{
    T.clear();
    taille=4;
    Damier = new int* [taille];
    for (int i=0; i<taille; i++) {
        Damier[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            Damier[i][j] = 1;
        }
    }
    T.push_back(Damier);

    for (int i=0; i<16; i++){
        Damier_valeurs.push_back(QString());
        Damier_couleurs.push_back(QString());
    }
    gameChanged();
}


QStringList game::readVal(){
    for (int i=0; i<taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (Damier[i][j]==0)
            {Damier_valeurs[i*taille+j]=QString();}
            else
            {Damier_valeurs[i*taille+j]=QString::number(Damier[i][j]);}
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
