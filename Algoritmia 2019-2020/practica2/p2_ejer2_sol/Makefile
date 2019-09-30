lib: arbolBinarioBusqueda.c
	gcc -c arbolBinarioBusqueda.c

main: ejecutarArbolBB.c arbolBinarioBusqueda.o
	gcc -g -o  ejecutarArbolBB ejecutarArbolBB.c arbolBinarioBusqueda.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarColaDobleCaracteres
	@- rm -f -v colaDobleCaracteres.o
