
#include <stdio.h>
#include <stdlib.h>

typedef struct monticulo{
	int n;
	int *t;
}monticulo;

void insertar(monticulo *m, int x){
	int aux,i;
	m->n = m-> n+1;
	m->t[m->n] = x;
	i = m->n;
	// mientras no fin de tabla y elemento sea menor que su padre.
	while ((i>0) && (m->t[i] < m->t[(i-1)/2])){
		//intercambio con su padre.
		aux = m->t[i];
		m->t[i] = m->t[(i-1)/2];
		m->t[(i-1)/2] = aux;
		i = (i-1)/2;
	}
}
void eliminar_raiz(monticulo *m){
	int aux, i;
	m->t[0] = m->t[m->n];
	m->n = m->n-1;
	i=0;
	//mientras el nodo tenga hijo izquierdo y sea mayor que su hijo izquierdo o el nodo tenga hijo derecho y sea mas mayor que su hijo derecho
	while (((i*2+1 <= m->n) && (m->t[i] > m->t[i*2+1])) || ((i*2+2 <= m->n) && (m->t[i] > m->t[i*2+2]))){
		if ((i*2+2 > m->n) || (m->t[i*2+1] <= m->t[i*2+2])){ //no haya hijo derecho o el hijo izquierdo es menor que el derecho
			aux = m->t[i*2+1];
			m->t[i*2+1] = m->t[i];
			m->t[i] = aux;
			i = i*2+1;
		}
		else{
			aux = m->t[i*2+2];
			m->t[i*2+2] = m->t[i];
			m->t[i] = aux;
			i = i*2+2;
		}
	}
}


void heapshort(monticulo *m){
	while (m->n >= 0){
		printf ("%d",m->t[0]);
		eliminar_raiz(m);
	}
	printf("\n");
}

int main(){
	system("pause");
	return 0;
}
		
			
			
		

