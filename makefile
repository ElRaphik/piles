#BUT

but: projet

#DECLARATION DES VARIABLES

NAME = projet

OFILES = activite.o \
	coordonnees.o \
	joueurs.o \
	piles.o \
	plateau.o \
	points.o \
	main.o

TESTFILE = partie.txt

CC = gcc

CFLAGS = -Wall -Wextra -pedantic

#DECLARATION DES REGLES

activite.o: activite.h piles.h plateau.h coordonnees.h
coordonnees.o: coordonnees.h piles.h plateau.h
joueurs.o: joueurs.h
piles.o: piles.h
plateau.o: piles.h plateau.h
points.o: points.h plateau.h piles.h
main.o: *.h

projet: $(OFILES)
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

#BUTS FACTICES

clean:
	-rm -f $(OFILES) $(NAME)

run:
	./$(NAME)

run_test:
	./$(NAME) < $(TESTFILE)

archive:
	tar -czvf raphael.soranzo.tgz *.pdf *.c *.h $(TESTFILE) makefile

.PHONY: but clean \
	but run \
	but run_test\
	but archive
