#include <stdlib.h>
#include "../headers/plateau.h"
#include "../headers/joueurs.h"
#include "../headers/coordonnees.h"
#include "../headers/piles.h"
#include "../headers/activite.h"
#include "../headers/points.h"

int main(){
    int j=get_nb_joueurs(),n=plateau_get_length(),j_actuel=1,x,y,reset_actives=0;
    system("cls");
    int cases_vides=n*n;
    int* compte;
    Plateau plato=init_plateau(n);
    coord donnees;
    Pile* case_actuelle;
    grid_act plato_act;
    plato_act=init_active(n);

    while(cases_vides>0) {
        print_plateau(plato);
        do {
            do {
                donnees=get_coordonnees();
            }while(!coord_check(donnees,n));//La boucle se termine quand donnees est jugee valide
        }while(!confirm_coord(donnees,plato));//La boucle se termine quand le joueur a confirme ses coordonnees

        x=donnees.lgn-1;//x est une coordonnee vue par la machine
        y=donnees.cln-1;//y est une coordonnee vue par la machine
        case_actuelle=&plato.contenu[x][y];

        if(plato.contenu[x][y].taille==0) cases_vides--;
        empiler(case_actuelle,j_actuel);

        /*Si la pile actuelle a une taille inferieure a 1, pas la peine d'essayer de verifier si ses 2 premiers jetons
         sont egaux*/
        if(case_actuelle->taille>1&&case_actuelle->premier->numero==case_actuelle->premier->next->numero){
            devient_active(donnees,&plato_act,&plato,j_actuel,&cases_vides);
            reset_actives+=1;
        }
        next_joueur(&j_actuel,j);

        /*On entre ici seulement si on a besoin de reset le tableau de suivi des cases actives*/
        if(reset_actives){
            for(int i=0; i<n;i++) free(plato_act[i]);
            for(int i=0;i<n;i++) plato_act[i]=(int *) calloc(n,sizeof(int));
            reset_actives--;
        }
        system("cls");
    }
    print_plateau(plato);
    compte=compte_points(&plato,j);
    vainqueur(compte,j);

    destroy_actives(&plato_act,n);
    free(compte);
    destroy_plateau(&plato);
}