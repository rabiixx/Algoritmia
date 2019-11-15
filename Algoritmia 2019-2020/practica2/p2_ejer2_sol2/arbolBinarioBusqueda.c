#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "arbolBinarioBusqueda.h"
#include <assert.h>

void nuevoArbolBB(tipoArbolBB *a) {
	*a = NULL;
}

void errorArbolBB(char s[]){}

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem) {
	
	if ( esVacio(*a) ) {

		*a = (celdaArbolBusqueda*)malloc(sizeof(celdaArbolBusqueda));
		(*a)->izda = NULL;
		(*a)->dcha = NULL;
		(*a)->elem = auxElem;

	} else if ((*a)->elem == auxElem) {
		printf("El valor ya se encuentra en el arbol\n");
	} else if ((*a)->elem > auxElem) {
		insertar(&(*a)->izda, auxElem);
	} else if ((*a)->elem < auxElem) {
		insertar(&(*a)->dcha, auxElem);
	}

}

void borrar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem){
	if ( (*a)->elem > auxElem ) {
		printf("1\n");
		borrar(&(*a)->izda, auxElem);
	} else if ( (*a)->elem < auxElem ) {
		borrar(&(*a)->dcha, auxElem);
	} else if ( (*a)->elem == auxElem ) {
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
			tipoArbolBB aux = (*a);
			*a = (*a)->dcha;
			free(aux);
		} else if ( (*a)->izda ) {
			tipoArbolBB aux = *a;	
			*a = (*a)->izda;
			free(aux);
		}
	}
}

void mostrarPreorden(tipoArbolBB a) {
	if (a) {
        printf("%d, ", a->elem);
        mostrarPreorden(a->izda);
        mostrarPreorden(a->dcha);
    } else {
        return;
    }
}

void mostrarInorden(tipoArbolBB a){
	if (a) {
        mostrarInorden(a->izda);
        printf("%d, ", a->elem);
        mostrarInorden(a->dcha);
    } else {
        return;
    }
}

void mostrarPostorden(tipoArbolBB a){
	if (a) {
        mostrarPostorden(a->izda);
        mostrarPostorden(a->dcha);
        printf("%d, ", a->elem);
    } else {
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
	if (a)
		return a->elem;
}

int calcAlturaArbol(tipoArbolBB a) {
	
	if ( !a ) return 0;

	int altIzq = calcAlturaArbol(a->izda);
	int altDer = calcAlturaArbol(a->dcha);

	return (altIzq > altDer) ? (altIzq + 1) : (altDer + 1);

}

int contarNodos(tipoArbolBB a) {

	if ( !a ) return 0;

	int contIzq = contarNodos(a->izda);
	int contDer = contarNodos(a->dcha);

	return (contIzq + contDer + 1);

	/*return (contarNodos(a->izda) + contarNodos(a->dcha))*/

}

/* Contar numero de nodos completos */
unsigned int getfullCount(tipoArbolBB a) 
{ 
    if (a == NULL) 
       return 0; 
   
    int res = 0; 
    if  (a->izda && a->dcha)  
       res++; 
   
    res += (getfullCount(a->izda) +  
            getfullCount(a->dcha)); 
    return res; 
} 


/* Comprueba si dos arboles son iguales */
bool comprArbolesIguales(tipoArbolBB a, tipoArbolBB b) {

	if ( !a && !b ) {
		return true;
	}

	return ( (a->elem == b->elem) && comprArbolesIguales(a->izda, b->izda) && comprArbolesIguales(a->dcha, b->dcha) );
}


/* Borra el arbol por completo */
void borrarArbol(tipoArbolBB *a) {

	if ( !(*a) ) 
		return;

	borrarArbol(&(*a)->izda);
	borrarArbol(&(*a)->dcha);

	free(*a);
	*a = NULL;
}

bool buscarNodo(tipoArbolBB a, int auxElem) {

	if ( !a ) return false;

	if (auxElem == a->elem)
		return true;
	else if (auxElem > a->elem)
		return buscarNodo(a->izda, auxElem);
	else if (auxElem < a->elem)
		return buscarNodo(a->dcha, auxElem);

}