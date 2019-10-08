
#include <stdlib.h>
#include <stdio.h>
#include "arbolBin.h"

tipoArbolBin abeto_recursivo(int arrPre[], int arrIn[], int low_index, int high_index, int *preIndex);
int searchIndex(tipoElementoArbolBin in[], int low, int high, int elem );

int main(int argc, char const *argv[]) {
	
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

	printf("El arbol en postorden es: ");
	postorden(a);
	printf("\n");

	return 0;
}



tipoArbolBin abeto_recursivo(int arrPre[], int arrIn[], int low_index, int high_index, int *preIndex) {

	/* Caso1: No tiene hijo derecho o hijo izquierdo */
	if (low_index > high_index) 
		return NULL;

	tipoArbolBin arbol;
	nuevoArbolBin(&arbol);

	/* El nodo padre no tiene ningun hijo */
	if (low_index == high_index )
		return construir(arrPre[(*preIndex)++], NULL, NULL);

	int index = searchIndex(arrIn, low_index, high_index, arrPre[(*preIndex)]);

	tipoArbolBin aux1 =	abeto_recursivo(arrPre, arrIn, low_index, index -1, preIndex);
	tipoArbolBin aux2 = abeto_recursivo(arrPre, arrIn, index + 1, high_index, preIndex);

	return construir(arrPre[(*preIndex)++], aux1, aux2);

}




/* Busca el indice de elem en el array de inroden */
int searchIndex(tipoElementoArbolBin in[], int low, int high, int elem ) {
	for (int i = low; i < high; ++i){
		if (in[i] == elem)
			return i;
	}

	printf("[+] El elemento %d no se encuentra en el inorden.\n", elem);
	exit(1);
}