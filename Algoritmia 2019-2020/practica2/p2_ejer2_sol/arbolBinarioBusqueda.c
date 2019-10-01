#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbolBinarioBusqueda.h"


 /*typedef int tipoElementoArbolBusqueda;

 typedef struct celdaABB{
	 tipoElementoArbolBusqueda elem;
	 struct celdaABB *izda;
	 struct celdaABB *dcha;
 }celdaArbolBusqueda; 

typedef celdaArbolBusqueda *tipoArbolBB;
*/

void nuevoArbolBB(tipoArbolBB *a) {
	a = NULL;
}

void errorArbolBB(char s[]){}

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem) {
	
	celdaArbolBusqueda *aux = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
	aux->izda = NULL;
	aux->dcha = NULL;
	aux->elem = auxElem;

	if ( esVacio(*a) ) {
		printf("1\n");
		a = &aux;
		/* (*a) = aux; */
		printf("sankdjsa: %d\n", (*a)->elem);
	} else if ((*a)->elem == aux->elem) {
		printf("El valor ya se encuentra en el arbol");
	} else if ((*a)->elem > aux->elem) {
		insertar(&(*a)->izda, auxElem);
	} else if ((*a)->elem < aux->elem) {
		insertar(&(*a)->dcha, auxElem);
	}

}

void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem){
	if ( (*a)->elem > auxElem ) {
		borrar(&(*a)->dcha, auxElem);
	} else if ( (*a)->elem < auxElem ) {
		borrar(&(*a)->izda, auxElem);
	} else if ( (*a)->elem == auxElem ) {
		if ( esHoja(*a) )
			free(a);
		else if( (*a)->dcha && (*a)->izda ){
			
			tipoArbolBB *suc;
			
			suc = &(*a)->dcha;

			while ( (*suc)->izda ) {
				suc = &(*suc)->izda;
			}

			(*a)->elem = (*suc)->elem;

			borrar(&(*a)->dcha, (*suc)->elem);

		} else if ( (*a)->dcha ) {
			tipoArbolBB aux;			
			a = &(*a)->dcha;
			aux = (*a);
			free(aux);
		} else if ( (*a)->izda ) {
			tipoArbolBB aux;			
			a = &(*a)->izda;
			aux = *a;
			free(aux);
		}
	}
}

void mostrarPreorden(tipoArbolBB a) {
	printf("joder1\n");
	if(a != NULL){
		printf("joder3\n");
        printf("hola%d, ", a->elem);
        mostrarPreorden(a->izda);
        mostrarPreorden(a->dcha);
    } else {
        return;
    }
}

void mostrarInorden(tipoArbolBB a){
	if(a){
        mostrarInorden(a->izda);
        printf("%d, ", a->elem);
        mostrarInorden(a->dcha);
    }else{
        return;
    }
}

void mostrarPostorden(tipoArbolBB a){
	if(a){
        mostrarPostorden(a->izda);
        mostrarPostorden(a->dcha);
        printf("%d, ", a->elem);
    }else{
        return;
    }
}

bool esVacio(tipoArbolBB a) {
	return !a;
}

bool esHoja(tipoArbolBB a) {
	return ( !(a->izda) && !(a->dcha) );

}

tipoElementoArbolBusqueda devolverRaiz(tipoArbolBB a) {
	return a->elem;
}