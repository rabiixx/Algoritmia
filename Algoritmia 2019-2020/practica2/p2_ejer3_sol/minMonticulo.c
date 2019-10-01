#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
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


}

tipoElementoMinMonticulo devolverRaiz(tipoMinMonticulo m) {
	return m.arr[0];
}

void mostrarAnchura(tipoMinMonticulo m) {
	for (int i = 0; i < m.numEl; ++i){
		printf("%d, ", m.arr[i]);
	}
}

bool esVacio(tipoMinMonticulo m) {

}

bool estaLleno(tipoMinMonticulo m) {
	//return (m.numEl == )?
}


void swap(tipoMinMonticulo *m, tipoElementoMinMonticulo index1, tipoElementoMinMonticulo index2) {
	tipoElementoMinMonticulo aux = m->arr[index1];
	m->arr[index1] = m->arr[index2];
	m->arr[index2] = aux;
}