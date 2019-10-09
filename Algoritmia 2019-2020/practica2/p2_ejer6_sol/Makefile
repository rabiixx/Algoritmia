lib: arbolBin.c
	gcc -c arbolBin.c

main: ejecutarArbolBin.c arbolBin.o
	gcc -g -o  p2_ejer6_sol p2_ejer6_sol.c arbolBin.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v arbolBin.o
	@- rm -f -v ejecutarArbolBin
