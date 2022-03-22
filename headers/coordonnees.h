#ifndef COORDONNEES_H
#define COORDONNEES_H
#include "piles.h"
#include "plateau.h"

#define YES 'o'
#define NO 'n'
#define RTR '\n'

/*  Les elements qui composent un coord sont les coordonnees vues par les joueurs et non par la machine*/
typedef struct coordonnees {
    int lgn;
    int cln;
}coord;

/*  @requires none
    @assigns none
    @ensures renvoie un coord de valeurs lgn=0, cln=0*/
coord init_coord();

/*  @requires none
    @assigns none
    @ensures demande a l'utilisateur d'entrer des coordonnees via le stdin et les renvoie
    sous la forme d'un coord*/
coord get_coordonnees();

/*  @requires plato et donnees ont ete initialises
    @assigns none
    @ensures demande a l'utilisateur de confirmer via le stdin si il veut bien empiler aux coordonnees choisies
    renvoie 1 si la reponse commence par un 'o' ou un '\n', 0 cela commence par 'n'*/
int confirm_coord(coord donnees,Plateau plato);

/*  @requires max est un entier strictement superieur a deux
    @assigns none
    @ensures renvoie 1 si les coordonnees sont valides par rapport au max entre, 0 sinon*/
int coord_check(coord entree,int max);

#endif