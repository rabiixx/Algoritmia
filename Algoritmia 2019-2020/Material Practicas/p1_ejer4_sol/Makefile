libs: pilaEnterosDinamica.c secuenciaEnteros.c
	gcc -c pilaEnterosDinamica.c secuenciaEnteros.c

seq: ejecutarSecuenciaEnteros.c pilaEnterosDinamica.o secuenciaEnteros.o
	gcc -o ejecutarSecuenciaEnteros ejecutarSecuenciaEnteros.c pilaEnterosDinamica.o secuenciaEnteros.o -Wall -pedantic

all: libs seq
	

clean:
	@- rm -f -v ejecutarSecuenciaEnteros
