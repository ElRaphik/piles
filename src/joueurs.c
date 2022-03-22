#include <stdio.h>

/*  @requires none
    @assigns none
    @ensures demande a l'utilisateur d'entrer un nombre de joueurs via le stdin
    la procedure demandera d'entrer un nombre valide tant que l'entree sera inferieure
    strictement a 2*/
int get_nb_joueurs(){
    int nb_jrs;
    char buf[256];
    do {
        printf("Entrez le nombre de joueurs :");
        fgets(buf, 256, stdin);
        sscanf_s(buf, "%d", &nb_jrs);
        if(nb_jrs<2) printf("%d est un nombre insuffisant.\n",nb_jrs);
    }while(nb_jrs<2); //On sort de la boucle quand le nombre entre par l'utilisateur depasse 2
    printf("Il y aura donc %d joueurs.\n\n",nb_jrs);
    return(nb_jrs);
}

/*  @requires joueur est une adresse valide
    @assigns modifie la valeur pointee par joueur
    @ensures incremente de 1 la valeur pointee par joueur
    si cette valeur depasse strictement nb_joueurs, alors on la remet a 1*/
void next_joueur(int* joueur,const int nb_joueurs){
    (*joueur)++;
    if(*joueur>nb_joueurs) (*joueur)=(*joueur)-nb_joueurs;
}