#include <stdio.h>
#include "../headers/piles.h"
#include "../headers/plateau.h"

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
coord init_coord() {
    coord init=(coord) {0,0};
    return(init);
}

/*  @requires none
    @assigns none
    @ensures demande a l'utilisateur d'entrer des coordonnees via le stdin et les renvoie
    sous la forme d'un coord*/
coord get_coordonnees(){
    char buf[256];
    coord new_coord=init_coord();
    printf("Entrez vos coordonnees :");
    fgets(buf,256,stdin);
    sscanf(buf,"%d %d",&(new_coord.lgn),&(new_coord.cln));
    return(new_coord);
}

/*  @requires plato et donnees ont ete initialises
    @assigns none
    @ensures demande a l'utilisateur de confirmer via le stdin si il veut bien empiler aux coordonnees choisies
    renvoie 1 si la reponse commence par un 'o' ou un '\n', 0 cela commence par 'n'*/
int confirm_coord(const coord donnees,const Plateau plato){
    char buf[256],rep;
    pile_print(&plato.contenu[donnees.lgn-1][donnees.cln-1]);
    do {
        printf("Voulez-vous poser votre jeton ici ? [O/n]\n");
        fgets(buf,256,stdin);
        sscanf(buf,"%c",&rep);
    }while(rep!=YES&&rep!=NO&&rep!=RTR);//on sort de la boucle quand l'utilisateur entre une reponse attendue
    return(rep!=NO);
}

/*  @requires max est un entier strictement superieur a deux
    @assigns none
    @ensures renvoie 1 si les coordonnees sont valides par rapport au max entre, 0 sinon*/
int coord_check(coord entree,const int max){
    return((entree.cln-1<max&&entree.lgn-1<max)&&(entree.cln-1>=0&&entree.lgn-1>=0));
}
