lib: arbolBinarioBusqueda.c
	gcc -g -c arbolBinarioBusqueda.c

main: ejecutarArbolBB.c arbolBinarioBusqueda.o
	gcc -g -o  ejecutarArbolBB ejecutarArbolBB.c arbolBinarioBusqueda.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarArbolBB
	@- rm -f -v arbolBinarioBusqueda.o
