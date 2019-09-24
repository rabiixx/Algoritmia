lib: colaDobleCaracteres.c
	gcc -c colaDobleCaracteres.c

main: ejecutarColaDobleCaracteres.c colaDobleCaracteres.o
	gcc -g -o  ejecutarColaDobleCaracteres ejecutarColaDobleCaracteres.c colaDobleCaracteres.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarColaDobleCaracteres
	@- rm -f -v colaDobleCaracteres.o
