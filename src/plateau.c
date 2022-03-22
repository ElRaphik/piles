#include <stdio.h>
#include <stdlib.h>
#include "../headers/piles.h"

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
int plateau_get_length(){
    int taille=0;
    do {
        printf("Donnez la taille du plateau :");
        scanf("%d", &taille);
        getchar();
        if(taille<2) printf("%d est une taille de plateau insuffisante!\n",taille);
    }while(taille<2);//on sort si la taille entree vaut 2 ou +
    printf("Le plateau est donc de taille %dx%d.\n\n",taille,taille);
    return(taille);
}

/*  @requires taille est un entier strictement positif
    @assigns alloue de la memoire pour le plateau
    @ensures renvoie un plateau avec la taille entree et avec un tableau de Piles initialisees*/
Plateau init_plateau(const int taille){
    Plateau plateau_initialized;

    Pile** contenu=(Pile**) malloc(taille*sizeof(Pile*));
    for(int i=0;i<taille;i++){
        contenu[i]=(Pile*) malloc(taille*sizeof(Pile));
        for(int j=0;j<taille;j++) {
            contenu[i][j] = init_pile();
        }
    }
    plateau_initialized.contenu = contenu;
    plateau_initialized.taille = taille;
    return plateau_initialized;
}

/*  @requires plateau est une adresse valide
    @assigns libere la memoire allouee pour les piles ainsi que pour le tableau de Piles de *plateau
    @ensures */
void destroy_plateau(Plateau *plateau){
    for(int i=0;i<(*plateau).taille;i++) {
        for (int j = 0; j < (*plateau).taille; j++) free_pile(&(*plateau).contenu[i][j]);
    }
    for(int i=0;i<(*plateau).taille;i++) free((*plateau).contenu[i]);
    free((*plateau).contenu);
}

/*  @requires none
    @assigns none
    @ensures envoie sur le stdout une representation du plateau comprehensible par les joueurs*/
void print_plateau(Plateau plateau){
    printf("\n |");
    for(int i=1;i<=plateau.taille;i++){
        printf("%d ",i);
    }
    printf("\n-+");
    for(int i=0;i<(2*plateau.taille + plateau.taille / 2);i++) printf("-");
    printf("\n");
    for(int i=1;i<=plateau.taille;i++){
        printf("%s%d|", plateau.taille > 9 && i < 10 ? "0" : "", i);
        for(int j=0;j<plateau.taille;j++) {
            if (plateau.contenu[i-1][j].taille==0) printf("  ");
            else printf("%d ",plateau.contenu[i-1][j].premier->numero);
        }
        printf("\n");
    }
    printf("\n\n");
}