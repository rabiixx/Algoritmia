lib: arbolBin.c
	gcc -c arbolBin.c

main: ejecutarArbolBin.c arbolBin.o
	gcc -g -o  p2_ejer7_sol p2_ejer7_sol.c arbolBin.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarColaDobleCaracteres
	@- rm -f -v colaDobleCaracteres.o
