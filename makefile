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

activite.o: headers/activite.h headers/piles.h headers/plateau.h headers/coordonnees.h
coordonnees.o: headers/coordonnees.h headers/piles.h headers/plateau.h
joueurs.o: headers/joueurs.h
piles.o: headers/piles.h
plateau.o: headers/piles.h headers/plateau.h
points.o: headers/points.h headers/plateau.h headers/piles.h
main.o: headers/*.h

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
	tar -czvf my_archive.tgz *.pdf *.c *.h $(TESTFILE) makefile

.PHONY: but clean \
	but run \
	but run_test\
	but archive
