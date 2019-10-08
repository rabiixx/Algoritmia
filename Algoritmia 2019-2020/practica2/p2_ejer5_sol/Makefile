lib: minMonticulo.c
	gcc -c minMonticulo.c

main: p2_ejer5_sol.c minMonticulo.o
	gcc -g -o  p2_ejer5_sol p2_ejer5_sol.c minMonticulo.o -Wall -pedantic

all: lib main

clean:
	@- rm -f -v p2_ejer5_sol
	@- rm -f -v minMonticulo.o
