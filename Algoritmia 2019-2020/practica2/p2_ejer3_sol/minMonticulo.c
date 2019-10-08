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

	/*swap(arr[0], arr[m->numEl - 1]);

	if( ( (2*i + 1) < m->numEl) && (m->arr[(2*i+1)] < arr->pos) )
		arr->pos = 2 * i + 1;

	if( ( (2*i + 2) < m->numEl) && (m->arr[(2*i+2)] < arr->pos) )
		arr->pos = 2 * i + 2;

	if()*/
	/*for (int i = 0; i < m->numEl; ++i){
		if (auxElem == m->arr[i]) {
			m->pos = i;
			if ( (m->arr[(2*i+1)] == INT_MIN) && (m->arr[(2*i+2)] == INT_MIN) ) {
				m->arr[i] = INT_MIN;
			} else if ( (m->arr[(2*i+1)] != INT_MIN) ) {
				m->arr[i] = m->arr[(2*i+1)];
				m->arr[(2*i+1)] = INT_MIN;
			} else if (m->arr[(2*i+2)] != INT_MIN) {
				m->arr[i] = m->arr[(2*i+2)];
				m->arr[(2*i+2)] = INT_MIN;
			} else {
				if ( m->arr[(2*i+1)] > m->arr[(2*i+1)] )  {
					m->arr[i] = m->arr[(2*i+1)];
					m->arr[(2*i+1)] = INT_MIN;
				} else {
					m->arr[i] = m->arr[(2*i+2)];
					m->arr[(2*i+2)] = INT_MIN;
				}
			}
		}
	}*/

	unsigned int i = 0;
	while( (i < m->numEl) && (m->arr[i] != auxElem) ) {
		++i;
	}

	if (i == m->numEl) {
		printf("El elemento no se encuentra en el monticulo\n");
		return;
	} else {
		printf("Numero elem1: %d\n", m->numEl);
		m->numEl--;
		printf("Numero elem2: %d\n", m->numEl);
		m->arr[i] = m->arr[m->numEl];
		m->arr[m->numEl] = INT_MAX;
		mostrarAnchura(*m);
		m->pos = i;
		printf("1\n");

		while ( (m->arr[m->pos] > m->arr[2*(m->pos) + 1]) || (m->arr[m->pos] > m->arr[2*(m->pos) + 2]) ) {
			printf("\n2\n");
			if ( m->arr[2*m->pos + 1] <= m->arr[2*(m->pos) + 2]) {
				printf("3\n");
				swap(m, m->pos, 2*(m->pos) + 1);
				m->pos = 2*(m->pos) + 1;
			} else {
				printf("4\n");
				swap(m, m->pos, 2*(m->pos) + 2);
				m->pos = 2*(m->pos) + 2;
			}
			printf("POSICION: %d\n", m->pos);
			printf("POSc: %d\n", m->arr[m->pos]);
			printf("POSi: %d\n", m->arr[2*(m->pos) + 1]);
			printf("POSd: %d\n", m->arr[2*(m->pos) + 2]);
			mostrarAnchura(*m);

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