lib: minMonticulo.c
	gcc -c minMonticulo.c

main: ejecutarMinMonticulo.c minMonticulo.o
	gcc -g -o  ejecutarMinMonticulo ejecutarMinMonticulo.c minMonticulo.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v ejecutarColaDobleCaracteres
	@- rm -f -v colaDobleCaracteres.o
