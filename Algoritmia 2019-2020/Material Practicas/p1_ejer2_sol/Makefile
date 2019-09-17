lib: colaEnteros.c
	gcc -c colaEnteros.c

cola: colaEnterosMain.c colaEnteros.o
	gcc -o colaEnterosMain colaEnterosMain.c colaEnteros.o -Wall -pedantic

all: lib cola
	

clean:
	@- rm -f -v colaEnterosMain
