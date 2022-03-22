#include <stdlib.h>
#include <stdio.h>
#include "../headers/coordonnees.h"
#include "../headers/plateau.h"
#include "../headers/piles.h"

typedef int** grid_act;

/*  @requires taille est un entier strictement positif
    @assigns alloue de la memoire libre
    @ensures renvoie un grid_act de longueur taille, et ayant de la memoire allouee*/
grid_act init_active(const int taille){
    grid_act res=(int**) malloc(taille*sizeof(int*));
    for(int i=0;i<taille;i++) {
        res[i]=(int*) calloc(taille,sizeof(int));
    }
    return(res);
}

/*  @requires entree est une adresse valide, taille est la taille de *entree
    @assigns libere la memoire allouee a *entree
    @ensures libere la memoire allouee a *entree */
void destroy_actives(grid_act *entree,const int taille){
    for(int i=0;i<taille;i++) {
        free((*entree)[i]);
    }
    free(*entree);
}

/*  @requires entree est une coordonnee valide
    @assigns none
    @ensures renvoie 1 si la case de coordonnees entree est active, 0 sinon*/
int est_active(const coord entree,grid_act actives){
    return(actives[entree.lgn-1][entree.cln-1]);
}

/*  @requires entree est une coordonnee valide, actives - plato - sont_vides sont des adresses valides
    @assigns alloue et libere de la memoire a plusieurs reprises en modifiant les Jetons contenus par les piles
    dans *plato
    modifie des valeurs dans *actives, et modifie a plusieurs reprises la valeuir de *sont_vides
    @ensures sert de processus d'activation des cases du plateau, est recursive et opere de proche en proche
    l'effet recursif s'arrete car une pile deja activee ne peut se reactiver, et on est limite par les bords du plato*/
void devient_active(const coord entree,grid_act* actives,Plateau* plato,const int joueur,int* sont_vides){
    coord dessus,adroite,dessous,agauche;
    Jeton* top_jeton;
    int lgn=entree.lgn-1,cln=entree.cln-1,taille;

    dessus=(coord) {lgn,cln+1};
    adroite=(coord) {lgn+1,cln+2};
    dessous=(coord) {lgn+2,cln+1};
    agauche=(coord) {lgn+1,cln};

    (*actives)[lgn][cln]=1;

    /*  On arrive ici dans un des quatre modules qui composent cette procedure
        Ils sont tous identiques alors je n'en commenterai qu'un (ils sont dans l'ordre haut-droite-bas-gauche*/

    if(dessus.lgn-1>=0) { //test si on va finir en out of bounds
        if(!est_active(dessus,*actives)) { //test si la case est deja active
            lgn = dessus.lgn - 1,cln = dessus.cln - 1; //lgn et cln=vue machine alors que coord=vue joueur
            if (plato->contenu[lgn][cln].taille == 0) (*sont_vides) -= 1;
            empiler(&(plato->contenu[lgn][cln]), joueur);
            taille=plato->contenu[lgn][cln].taille;
            top_jeton = plato->contenu[lgn][cln].premier;
            if(taille>1) {
                if (top_jeton->numero == top_jeton->next->numero) {
                    /*  Comme explique dans le @ensures, on fait des appels recursifs, mais avec les tests precedents,
                        on est oblige de finir car cette fonction recevra au plus un nombre d'appels egal au nombre de
                        cases du plateau*/
                    devient_active(dessus, actives, plato, joueur, sont_vides);
                }
            }
        }
    }

    if(adroite.cln-1<plato->taille){
        if(!est_active(adroite,*actives)) {
            lgn = adroite.lgn - 1, cln = adroite.cln - 1;
            if (plato->contenu[lgn][cln].taille == 0) (*sont_vides) -= 1;
            empiler(&plato->contenu[lgn][cln], joueur);
            taille=plato->contenu[lgn][cln].taille;
            top_jeton = plato->contenu[lgn][cln].premier;
            if(taille>1) {
                if (top_jeton->numero == top_jeton->next->numero) {
                    devient_active(adroite, actives, plato, joueur, sont_vides);
                }
            }
        }
    }

    if(agauche.cln-1>=0){
        if(!est_active(agauche,*actives)) {
            lgn = agauche.lgn - 1, cln = agauche.cln - 1;
            if (plato->contenu[lgn][cln].taille == 0) (*sont_vides) -= 1;
            empiler(&plato->contenu[lgn][cln], joueur);
            taille=plato->contenu[lgn][cln].taille;
            top_jeton = plato->contenu[lgn][cln].premier;
            if(taille>1) {
                if (top_jeton->numero == top_jeton->next->numero) {
                    devient_active(agauche, actives, plato, joueur, sont_vides);
                }
            }
        }
    }

    if(dessous.lgn-1<plato->taille) {
        if (!est_active(dessous, *actives)) {
            lgn = dessous.lgn - 1, cln = dessous.cln - 1;
            if (plato->contenu[lgn][cln].taille == 0) (*sont_vides) -= 1;
            empiler(&plato->contenu[lgn][cln], joueur);
            taille=plato->contenu[lgn][cln].taille;
            top_jeton = plato->contenu[lgn][cln].premier;
            if(taille>1) {
                if (top_jeton->numero == top_jeton->next->numero) {
                    devient_active(dessous, actives, plato, joueur, sont_vides);
                }
            }
        }
    }

    lgn=entree.lgn-1;
    cln=entree.cln-1;
    depiler(&plato->contenu[entree.lgn-1][entree.cln-1]);
    depiler(&plato->contenu[entree.lgn-1][entree.cln-1]);
    if(plato->contenu[lgn][cln].taille==0) (*sont_vides)+=1;
}