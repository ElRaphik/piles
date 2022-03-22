#ifndef PLATEAU_H
#define PLATEAU_H
#include "piles.h"

/*Cette structure de plateau contient a la fois la taille et un tableau 2D de Pile*/
typedef struct Plateau {
    int taille;
    Pile** contenu;
}Plateau;

/*  @requires none
    @assigns none
    @ensures demande a l'utilisateur d'entrer la taille du plateau dans le stdin
    si cette taille est inferieure strictement a 2, on redemande une taille valable
    renvoie la premiere taille valide entree*/
int plateau_get_length();

/*  @requires taille est un entier strictement positif
    @assigns alloue de la memoire pour le plateau
    @ensures renvoie un plateau avec la taille entree et avec un tableau de Piles initialisees*/
Plateau init_plateau(int taille);

/*  @requires plateau est une adresse valide
    @assigns libere la memoire allouee pour les piles ainsi que pour le tableau de Piles de *plateau
    @ensures */
void destroy_plateau(Plateau *plateau);

/*  @requires none
    @assigns none
    @ensures envoie sur le stdout une representation du plateau comprehensible par les joueurs*/
void print_plateau(Plateau plateau);

#endif
