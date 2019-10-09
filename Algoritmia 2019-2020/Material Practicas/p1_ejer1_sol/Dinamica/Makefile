lib: pilaEnterosDinamica.c
	gcc -c pilaEnterosDinamica.c

cola: ejecutarPilaEnteros.c pilaEnterosDinamica.o
	gcc -o ejecutarPilaEnteros ejecutarPilaEnteros.c pilaEnterosDinamica.o -Wall -pedantic

all: lib cola
	

clean:
	@- rm -f -v colaEnterosMain
