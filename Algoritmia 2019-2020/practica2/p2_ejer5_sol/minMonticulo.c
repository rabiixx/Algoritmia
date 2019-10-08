#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "minMonticulo.h"


/*typedef int tipoElementoMinMonticulo;

typedef struct tMM{
	tipoElementoMinMonticulo *arr;
	int pos;
	int numEl;
}tipoMinMonticulo;
*/

void swap(tipoMinMonticulo *m, tipoElementoMinMonticulo index1, tipoElementoMinMonticulo index2);


void nuevoMinMonticulo(tipoMinMonticulo *m, int numElem) {
	m->arr = (tipoElementoMinMonticulo*)calloc(numElem, sizeof(tipoElementoMinMonticulo));
	m->pos = 0;
	m->numEl = 0;
	for (int i = 0; i < numElem; ++i){
		m->arr[i] = INT_MAX;
	}
}

void errorMinMonticulo(char s[]){}

void insertarMinMonticulo(tipoMinMonticulo *m, tipoElementoMinMonticulo auxElem) {
	
	m->arr[m->numEl] = auxElem;
	m->numEl++;
	if (m->numEl > 1){
		m->pos = m->numEl - 1;
		int auxIndex = (m->pos - 1)/2;
		while (m->arr[auxIndex] > m->arr[m->pos]) {
			swap(m, auxIndex, m->pos);
			m->pos = auxIndex;
			auxIndex = (m->pos - 1)/2;
		}
	}
		
}

void eliminarElemento(tipoMinMonticulo *m, tipoElementoMinMonticulo auxElem) {

	m->numEl--;
	m->arr[0] = m->arr[m->numEl];
	m->arr[m->numEl] = INT_MAX;
	m->pos = 0;

	while ( (m->arr[m->pos] > m->arr[2*(m->pos) + 1]) || (m->arr[m->pos] > m->arr[2*(m->pos) + 2]) ) {
		if ( m->arr[2*m->pos + 1] <= m->arr[2*(m->pos) + 2]) {
			swap(m, m->pos, 2*(m->pos) + 1);
			m->pos = 2*(m->pos) + 1;
		} else {
			swap(m, m->pos, 2*(m->pos) + 2);
			m->pos = 2*(m->pos) + 2;
		}
	}
}

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo m) {
	return m.arr[0];
}

void mostrarAnchura(tipoMinMonticulo m) {
	printf("anchura:");
	for (int i = 0; i < m.numEl; ++i){
		printf("%d, ", m.arr[i]);
	}
	printf("\n");
}

bool esVacio(tipoMinMonticulo m) {
	return (m.numEl == 0) ? true:false; 
}

bool estaLleno(tipoMinMonticulo m) {
	
}


void swap(tipoMinMonticulo *m, tipoElementoMinMonticulo index1, tipoElementoMinMonticulo index2) {
	tipoElementoMinMonticulo aux = m->arr[index1];
	m->arr[index1] = m->arr[index2];
	m->arr[index2] = aux;
}