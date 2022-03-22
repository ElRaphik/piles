#ifndef JOUEURS_H
#define JOUEURS_H

/*  @requires none
    @assigns none
    @ensures demande a l'utilisateur d'entrer un nombre de joueurs via le stdin
    la procedure demandera d'entrer un nombre valide tant que l'entree sera inferieure
    strictement a 2*/
int get_nb_joueurs();

/*  @requires joueur est une adresse valide
    @assigns modifie la valeur pointee par joueur
    @ensures incremente de 1 la valeur pointee par joueur
    si cette valeur depasse strictement nb_joueurs, alors on la remet a 1*/
void next_joueur(int* joueur,int nb_joueurs);

#endif //JOUEURS_H
