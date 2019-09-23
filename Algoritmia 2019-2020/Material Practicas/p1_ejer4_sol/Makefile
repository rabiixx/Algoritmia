lib1: pilaEnterosDinamica.c 
	gcc -c pilaEnterosDinamica.c 
lib2: secuenciaEnteros.c
	gcc -c secuenciaEnteros.c


seq: ejecutarSecuenciaEnteros.c pilaEnterosDinamica.o secuenciaEnteros.o
	gcc -o ejecutarSecuenciaEnteros ejecutarSecuenciaEnteros.c pilaEnterosDinamica.o secuenciaEnteros.o -Wall -pedantic

all: lseq
	
clean:
	@- rm -f -v ejecutarSecuenciaEnteros
	@- rm -f -v pilaEnterosDinamica.o
	@- rm -f -v secuenciaEnteros.o