#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "pilaEnterosDinamica.h"

typedef struct _data {
	int victimas;
	int fecha;
	int hack;
} infoDesastres;

int main(int argc, char const *argv[]) {

	system("clear");

	int numDesastres;

	printf("Introduce el numero de desastres: ");
	scanf("%d", &numDesastres);

	infoDesastres *arrD = (infoDesastres*)malloc(numDesastres*sizeof(infoDesastres));

	for (int i = 0; i < numDesastres; ++i) {
		printf("Introduce la fecha y el numero de desastres: ");
		scanf("%d %d", &arrD[i].fecha, &arrD[i].victimas);
	}

	tipoPila p;
	nuevaPila(&p);

	for (int i = 0; i < numDesastres; ++i) {
		while(1) {
			if( esNulaPila(p) ) {
				arrD[i].hack = 0;
				break;
			} else {
				if(arrD[i].victimas < arrD[cima(p)].victimas) {
					arrD[i].hack = arrD[cima(p)].fecha;
					break;
				} else {
					desapilar(&p);
				}
			}
		}
		apilar(&p, i);
	}

	for (int i = 0; i < numDesastres; ++i) {
		printf("Desastre %d: %d - %d - %d\n", i, arrD[i].fecha, arrD[i].victimas, arrD[i].hack);
	}


	return 0;
}