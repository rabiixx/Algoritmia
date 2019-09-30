lib: arbolBin.c
	gcc -c arbolBin.c

main: ejecutarArbolBin.c arbolBin.o
	gcc -g -o  ejecutarArbolBin ejecutarArbolBin.c arbolBin.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarColaDobleCaracteres
	@- rm -f -v colaDobleCaracteres.o
