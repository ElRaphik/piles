#ifndef PILACTIVE_H
#define PILACTIVE_H
#include "coordonnees.h"
#include "plateau.h"
#include "piles.h"

typedef int** grid_act;

/*  @requires taille est un entier strictement positif
    @assigns alloue de la memoire libre
    @ensures renvoie un grid_act de longueur taille, et ayant de la memoire allouee*/
grid_act init_active(int taille);

/*  @requires entree est une adresse valide, taille est la taille de *entree
    @assigns libere la memoire allouee a *entree
    @ensures libere la memoire allouee a *entree */
void destroy_actives(grid_act *entree,int taille);

/*  @requires entree est une coordonnee valide
    @assigns none
    @ensures renvoie 1 si la case de coordonnees entree est active, 0 sinon*/
int est_active(coord entree,grid_act actives);

/*  @requires entree est une coordonnee valide, actives - plato - sont_vides sont des adresses valides
    @assigns alloue et libere de la memoire a plusieurs reprises en modifiant les Jetons contenus par les piles
    dans *plato
    modifie des valeurs dans *actives, et modifie a plusieurs reprises la valeuir de *sont_vides
    @ensures sert de processus d'activation des cases du plateau, est recursive et opere de proche en proche
    l'effet recursif s'arrete car une pile deja activee ne peut se reactiver, et on est limite par les bords du plato*/
void devient_active(coord entree,grid_act* actives,Plateau* plato,int joueur,int* sont_vides);

#endif // PILACTIVE_H