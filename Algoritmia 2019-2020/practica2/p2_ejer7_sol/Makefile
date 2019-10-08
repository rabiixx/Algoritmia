lib: arbolBin.c
	gcc -c arbolBin.c

main1: p2_ejer7_sol.c.c arbolBin.o
	gcc -g -o  p2_ejer7_sol p2_ejer7_sol.c arbolBin.o -Wall -pedantic

main2: p2_ejer7_sol2.c arbolBin.o
	gcc -g -o  p2_ejer7_sol2 p2_ejer7_sol2.c arbolBin.o -Wall -pedantic

all: lib main1

clean:
	@- rm -f -v p2_ejer7_sol
	@- rm -f -v p2_ejer7_sol2
	@- rm -f -v arbolBin.o
