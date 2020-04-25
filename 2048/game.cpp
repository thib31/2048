#include "game.h"
#include <iostream>
#include <math.h>

using namespace std;

game::game(QObject *parent) : QObject(parent)
{
    nouvPartie();
}

void game::nouvPartie()
{
    // On (ré-)initialise les tableaux de données
    T.clear();
    taille=4;
    Damier_valeurs.clear();
    Damier_couleurs.clear();

    // Création du premier damier, vide
    Damier = new int* [taille];
    for (int i=0; i<taille; i++) {
        Damier[i] = new int[taille];
        for (int j = 0; j < taille; j++) {
            Damier[i][j] = 0;
        }
    }
    // Insertion dans la "pile" du jeu
    T.push_back(Damier);

    // Initialisation des damiers de valeurs et couleurs, vides pour l'instant.
    for (int i=0; i<16; i++){
        Damier_valeurs.push_back(QString());
        Damier_couleurs.push_back(QString());
    }


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

void game::deplacement(int dir_i, int dir_j){
    int debut; int fin;
    if (dir_i+dir_j==1){
        debut=0;
        fin=taille-1;
    }
    else{
        debut=taille;
        fin=1;
    }
    int atraiter[4];
    int indices[4];
    int cpt(0);
    if (dir_j==0){          // 1er cas : déplacement vertical. On traite les colonnes l'une après l'autre.
        for (int j=0; j<taille; j++){
            for (int i=debut; i!=fin; i+=dir_i){
                atraiter[cpt]=Damier[i][j];
                indices[cpt]=i;
            }

        }
    }
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
    while (k<taille){

    }

}
