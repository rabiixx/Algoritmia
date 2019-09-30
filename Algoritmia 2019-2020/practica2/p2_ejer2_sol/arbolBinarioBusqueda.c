#include <stdbool.h>
#include <stdio.h>


 typedef int tipoElementoArbolBusqueda;

 typedef struct celdaABB{
	 tipoElementoArbolBusqueda elem;
	 struct celdaABB *izda;
	 struct celdaABB *dcha;
 }celdaArbolBusqueda; 

typedef celdaArbolBusqueda *tipoArbolBB;

void nuevoArbolBB(tipoArbolBB *a) {
	a = NULL;
}

void errorArbolBB(char s[]);

void insertar(tipoArbolBB *a, tipoElementoArbolBusqueda auxElem) {
	
	celdaArbolBusqueda *aux = (celdaArbolBusqueda)malloc(sizeof(celdaArbolBusqueda));
	aux->izda = NULL;
	aux->dcha = NULL;ç
	aux->elem = auxElem;

	if ( esVacio(a) ) {
		a = aux;
	} else if ((*a)->elem == aux->elem) {
		printf("El valor ya se encuentra en el arbol");
	} else if ((*a)->elem > aux->elem) {
		insertar((*a)->izda, auxElem);
	} else if ((*a)->elem < aux->elem) {
		insertar((*a)->dcha, auxElem);
	}

}

void borrar(tipoArbolBB *, tipoElementoArbolBusqueda);

void mostrarPreorden(tipoArbolBB);

void mostrarInorden(tipoArbolBB);

void mostrarPostorden(tipoArbolBB);

bool esVacio(tipoArbolBB a) {
	return a
}
