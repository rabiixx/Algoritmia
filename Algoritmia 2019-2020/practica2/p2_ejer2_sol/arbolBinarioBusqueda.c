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
	/*celdaArbolBusqueda *aux = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
	aux->izda = NULL;
	aux->dcha = NULL;
	aux->elem = 10;
	(*a) = aux;*/
	*a = NULL;
}

void errorArbolBB(char s[]){}

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem) {
	

	if ( esVacio(*a) ) {
		celdaArbolBusqueda *aux = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
		aux->izda = NULL;
		aux->dcha = NULL;
		aux->elem = auxElem;
		*a = aux;
	} else if ((*a)->elem == aux->elem) {
		printf("El valor ya se encuentra en el arbol");
	} else if ((*a)->elem > aux->elem) {
		insertar(&(*a)->izda, auxElem);
	} else if ((*a)->elem < aux->elem) {
		insertar(&(*a)->dcha, auxElem);
	}

}

void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem){
	printf("borrar\n");
	if ( (*a)->elem > auxElem ) {
		printf("1\n");
		borrar(&(*a)->izda, auxElem);
	} else if ( (*a)->elem < auxElem ) {
		printf("2\n");
		borrar(&(*a)->dcha, auxElem);
	} else if ( (*a)->elem == auxElem ) {
		printf("3\n");
		if ( esHoja(*a) ) {
			free(*a);
			*a = NULL;

		} else if ( (*a)->dcha && (*a)->izda ){
			
			tipoArbolBB *suc;
			
			suc = &(*a)->dcha;

			while ( (*suc)->izda ) {
				suc = &(*suc)->izda;
			}

			(*a)->elem = (*suc)->elem;

			borrar(&(*a)->dcha, (*suc)->elem);

		} else if ( (*a)->dcha ) {
			printf("1.2\n");
			tipoArbolBB aux;			
			aux = (*a);
			*a = (*a)->dcha;
			free(aux);
		} else if ( (*a)->izda ) {
			printf("1.3\n");
			tipoArbolBB aux;		
			aux = *a;	
			*a = (*a)->izda;
			free(aux);
		}
	}
}

void mostrarPreorden(tipoArbolBB a) {
	if(a != NULL){
        printf("%d, ", a->elem);
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