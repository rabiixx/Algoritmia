/*
 * Para mostrar los elementos de un arbol de busqueda binario en orden, 
 *	vale con mostrar los elemtos del arbol en inroden debido a la estrutura
 * que siguen este tipo de arboles 
 */


#include <stdio.h>
#include "arbolBinarioBusqueda.h"


int main(int argc, char const *argv[])
{
	
	tipoElementoArbolBusqueda elem;
	tipoArbolBB arbol;

	nuevoArbolBB(&arbol);

	printf("Introduce elementos para ordenar. 0 para terminar: ");
	scanf("%d", &elem);
	while(elem != 0) {
		insertar(&arbol, elem);
		scanf("%d", &elem);
	}

	printf("Los elementos ordenados son: ");
	mostrarInorden(arbol);

	return 0;
}