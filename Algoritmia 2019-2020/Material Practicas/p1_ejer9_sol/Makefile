lib: listaOrdenadaEnteros.c
	gcc -c listaOrdenadaEnteros.c

lista: ejecutarListaOrdenadaEnteros.c listaOrdenadaEnteros.o
	gcc -g -o  ejecutarListaOrdenadaEnteros ejecutarListaOrdenadaEnteros.c listaOrdenadaEnteros.o -Wall -pedantic

all: lib lista

clean:
	@- rm -f -v ejecutarListaOrdenadaEnteros
	@- rm -f -v listaOrdenadaEnteros.o
