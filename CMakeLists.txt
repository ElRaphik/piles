cmake_minimum_required(VERSION 3.17)
project(piles C)

set(CMAKE_C_STANDARD 99)

add_executable(piles src/piles.c src/plateau.c src/coordonnees.c src/main.c headers/piles.h headers/coordonnees.h headers/plateau.h src/activite.c headers/activite.h src/joueurs.c headers/joueurs.h src/points.c headers/points.h)