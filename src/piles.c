#include <stdio.h>
#include <stdlib.h>

/*On implemente une structure classique de pile*/
typedef struct node {
    int numero;
    struct node* next;
}Jeton;

typedef struct Pile {
    int taille;
    struct node* premier;
}Pile;

/*  @requires none
    @assigns none
    @ensures la fonction renvoie une Pile de taille 0 et de premier Jeton* NULL*/
Pile init_pile(){
    Pile res={0,NULL};
    return(res);
}

/*  @requires carreau est une adresse valide
    @assigns alloue de la memoire pour un Jeton que l'on va mettre en premier dans la pile
    @ensures empile un jeton avec comme valeur joueur proprement*/
void empiler(Pile* carreau,const int joueur){
    Jeton *n_jeton=(Jeton*) malloc(sizeof(*n_jeton));

    if (carreau==NULL||n_jeton==NULL) return;

    n_jeton->numero=joueur;
    n_jeton->next=carreau->premier;
    carreau->premier=n_jeton;
    carreau->taille+=1;
}

/*  @requires carreau est une adresse valide
    @assigns modifie l'adresse pointee par la Pile, et libere la case memoire pointee precedemment
    @ensures enleve le premier Jeton de la Pile proprement et libere sa memoire allouee
    renvoie le numero du Jeton depile*/
int depiler(Pile *carreau){
    int top=-1;

    if (carreau==NULL) return(top);

    Jeton *jeton_depile=carreau->premier;
    if (carreau->premier != NULL){
        top=jeton_depile->numero;
        carreau->premier=jeton_depile->next;
        carreau->taille-=1;
        free(jeton_depile);
    }
    return(top);
}

/*  @requires carreau est une adresse valide
    @assigns none
    @ensures envoie sur la stdout une representation textuelle de *carreau */
void pile_print(const Pile *carreau){
    if (carreau==NULL) return;
    Jeton *current=carreau->premier;

    printf("\nVoici la pile :\n\n");
    if (carreau->premier==NULL){
        printf("---\n\n");
        return;
    }
    do {
        printf("%d\n",current->numero);
        current=current->next;
    }while(current!=NULL);//La boucle se termine quand on atteind le denier jeton.next qui vaut forcement NULL

    printf("---\n\n");
}

/*  @requires carreau est une adresse valide
    @assigns libere la memoire allouee pour chaque Jeton de la pile, puis celle allouee pour cette derniere
    @ensures detruit la pile de la memoire*/
void free_pile(Pile *carreau){
    Jeton *tmp,*tmpbis;
    if (carreau==NULL) return;

    tmp=carreau->premier;
    if(tmp==NULL) return;

    while(tmp!=NULL){ //on sort car le dernier jeton.next de la pile pointe vers NULL, et on l'atteint forcement
        tmpbis=tmp;
        tmp=tmp->next;
        free(tmpbis);
    }
    carreau->premier=NULL;
}