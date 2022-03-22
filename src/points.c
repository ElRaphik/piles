#include <stdlib.h>
#include <stdio.h>
#include "../headers/plateau.h"

/*  @requires plato est une adresse valide
    @assigns alloue de la memoire pour la variable renvoyee
    modifie chaque pile contenue dans le plato, libere de la memoire allouee a des Jetons
    @ensures renvoie une liste contenant les points des joueurs*/
int* compte_points(Plateau* plato,const int nb_joueurs){
    int* compte=(int*) calloc(nb_joueurs,sizeof(int));
    int top;
    for(int i=0;i<plato->taille;i++){
        for(int j=0;j<plato->taille;j++){
            top=depiler(&(plato->contenu[i][j]));
            compte[top-1]++;
        }
    }
    return(compte);
}

/*  @requires total_pts est une adresse valide
    @assigns none
    @ensures Renvoie le numero du ou des vainqueurs sur le stdout*/
void vainqueur(const int* total_pts,const int nb_joueurs){
    int score_max=0;
    for(int i=0;i<nb_joueurs;i++){
        if(total_pts[i]>score_max) score_max=total_pts[i];
    }
    for(int i=0;i<nb_joueurs;i++) if(score_max==total_pts[i]){
        printf("Bravo au joueur %d ! Il est vainqueur !\n",i+1);
    }
}