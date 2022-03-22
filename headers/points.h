#ifndef POINTS_H
#define POINTS_H
#include "plateau.h"

/*  @requires plato est une adresse valide
    @assigns alloue de la memoire pour la variable renvoyee
    modifie chaque pile contenue dans le plato, libere de la memoire allouee a des Jetons
    @ensures renvoie une liste contenant les points des joueurs*/
int* compte_points(Plateau* plato,int nb_joueurs);

/*  @requires total_pts est une adresse valide
    @assigns none
    @ensures Renvoie le numero du ou des vainqueurs sur le stdout*/
void vainqueur(const int* total_pts, int nb_joueurs);

#endif //POINTS_H