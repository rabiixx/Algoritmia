pila: pilaEnterosDinamica.c
	gcc -c pilaEnterosDinamica.c

cola: colaEnteros.c
	gcc -c colaEnteros.c


main: test.c pilaEnterosDinamica.o colaEnteros.o
	gcc -o test test.c pilaEnterosDinamica.o colaEnteros.o -Wall -pedantic

all: main pila cola
	

clean:
	@- rm -f -v pilaEnterosDinamica.o
	@- rm -f -v test
	@- rm -f -v colaEnteros.o
