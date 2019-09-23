lib: colaEnteros.c
	gcc -c colaEnteros.c

cola: p1_ejer8_sol.c colaEnteros.o
	gcc -g -o  p1_ejer8_sol p1_ejer8_sol.c colaEnteros.o -Wall -pedantic

all: lib cola

clean:
	@- rm -f -v ejecutarColaEnteros
