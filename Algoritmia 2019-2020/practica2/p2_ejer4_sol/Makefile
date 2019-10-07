lib: arbolBinarioBusqueda.c
	gcc -c arbolBinarioBusqueda.c

main: p2_ejer4_sol.c arbolBinarioBusqueda.o
	gcc -g -o p2_ejer4_sol p2_ejer4_sol.c arbolBinarioBusqueda.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v p2_ejer4_sol
	@- rm -f -v arbolBinarioBusqueda.o
