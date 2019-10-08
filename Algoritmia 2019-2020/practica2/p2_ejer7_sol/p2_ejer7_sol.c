#include <stdlib.h>
#include <stdio.h>
#include "arbolBin.h"


/* Funciones utilitarias */

/* Buscar un valor dado en el array de inorden y devuelve el indice  */
int searchIndex(tipoElementoArbolBin in[], int low, int high, int elem );

/* Imprime el arbol en postorden, inorden, preorden respectivamente */
void printTraversals(tipoArbolBin a);

/* Funcion recursiva para construir un arbol binario a partir de sus recorridos en 
   preorden y inorden. */
tipoArbolBin abeto_recursivo(int arrPre[], int arrIn[], int low_index, int high_index, int *preIndex) {

	/* No tiene hijo derecho o hijo izquierdo */
	if (low_index > high_index) 
		return NULL;

	int auxELem = arrPre[(*preIndex)];

	(*preIndex)++;

	/* El nodo padre no tiene ningun hijo */
	if (low_index == high_index )
		return construir(auxELem, NULL, NULL);

	int index = searchIndex(arrIn, low_index, high_index, auxELem);

	tipoArbolBin aux1 =	abeto_recursivo(arrPre, arrIn, low_index, index -1, preIndex);
	tipoArbolBin aux2 = abeto_recursivo(arrPre, arrIn, index + 1, high_index, preIndex);

	return construir(auxELem, aux1, aux2);

}

int main(int argc, char const *argv[]) {
	
	system("clear");

	unsigned int N;
	printf("Introduce el numero de elementos: ");
	scanf("%u", &N);

	int arrPre[N];
	int arrIn[N];

	printf("Introduce Preorden: ");
	for (int i = 0; i < N; ++i){
		scanf("%d", &arrPre[i]);
	}
	
	printf("Introduce Inorden: ");
	for (int i = 0; i < N; ++i){
		scanf("%d", &arrIn[i]);
	}

	tipoArbolBin a;
	nuevoArbolBin(&a);

	int preIndex = 0;	/* Guarda el indice del array en Preorden */
	a = abeto_recursivo(arrPre, arrIn, 0, N - 1, &preIndex);

	printTraversals(a);

	return 0;
}


/* Busca el indice de elem en el array de inorden */
int searchIndex(tipoElementoArbolBin in[], int low, int high, int elem ) {

	for (int i = low; i <= high; ++i)
		if (in[i] == elem) 
			return i;

	printf("[+] El elemento %d no se encuentra en el inorden.\n", elem);
	exit(1);
}

void printTraversals(tipoArbolBin a) {

	printf("[+] EL arbol en postorden es: ");
	postorden(a);
	printf("\n");
	printf("[+] EL arbol en preorden es: ");
	preorden(a);
	printf("\n");
	printf("[+] EL arbol en inorden es: ");
	inorden(a);
	printf("\n");
}