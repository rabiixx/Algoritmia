lib: pilaEnterosDinamica.c
	gcc -c pilaEnterosDinamica.c

main: p1_ejer3_sol.c pilaEnterosDinamica.o
	gcc -g -o  p1_ejer3_sol p1_ejer3_sol.c pilaEnterosDinamica.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v p1_ejer3_sol
	@- rm -f -v pilaEnterosDinamica.o
