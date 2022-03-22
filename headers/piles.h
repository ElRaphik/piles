#ifndef PILES_H
#define PILES_H

/*On implemente une structure classique de pile*/
typedef struct node {
	int numero;
	struct node* next;
}Jeton;

typedef struct Pile {
    int taille;
	Jeton* premier;
}Pile;



/*  @requires none
    @assigns none
    @ensures la fonction renvoie une Pile de taille 0 et de premier Jeton* NULL*/
Pile init_pile();

/*  @requires carreau est une adresse valide
    @assigns alloue de la memoire pour un Jeton que l'on va mettre en premier dans la pile
    @ensures empile un jeton avec comme valeur joueur proprement*/
void empiler(Pile *carreau,int joueur);

/*  @requires carreau est une adresse valide
    @assigns modifie l'adresse pointee par la Pile, et libere la case memoire pointee precedemment
    @ensures enleve le premier Jeton de la Pile proprement et libere sa memoire allouee
    renvoie le numero du Jeton depile*/
int depiler(Pile *carreau);

/*  @requires carreau est une adresse valide
    @assigns none
    @ensures envoie sur la stdout une representation textuelle de *carreau */
void pile_print(const Pile *carreau);

/*  @requires carreau est une adresse valide
    @assigns libere la memoire allouee pour chaque Jeton de la pile, puis celle allouee pour cette derniere
    @ensures detruit la pile de la memoire*/
void free_pile(Pile *carreau);

#endif