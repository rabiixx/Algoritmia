#include <stdio.h>
#include <stdlib.h>
#include "arbolBinarioBusqueda.h"

int main() {
	tipoElementoArbolBusqueda elem;
	tipoArbolBB arbol;
	int opcion;
	
	nuevoArbolBB(&arbol);
	do {
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento en el arbol\n");
		printf("2 - Eliminar un elemento del arbol\n");
		printf("3 - Mostrar el arbol en preorden\n");
		printf("4 - Mostrar el arbol en inorden\n");
		printf("5 - Calcular altura del arbol\n");
		printf("6 - Contar numero de nodos\n");
		printf("7 - Salir\n");
		printf("Escoja una opcion: ");
		scanf("%d", &opcion);
		switch(opcion){           
			case 1: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				insertar(&arbol,elem);
				break;
			case 2: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				borrar(&arbol,elem);
				break;    
			case 3: 
				printf("Raiz: %d\n", devolverRaiz(arbol));
				printf("Los elementos del arbol son: ");
				mostrarPreorden(arbol);
				printf("\n");
				break;
			case 4:
				printf("Inorden: ");
				mostrarInorden(arbol);
				printf("\n");
				break;
			case 5:
				printf("Altura del arbol: %d\n", calcAlturaArbol(arbol));
				break;
			case 6:
				printf("Numero de nodos: %d\n", /*contarNodos(arbol)*/getfullCount(arbol));
				break;
			case 7: 	
				return EXIT_SUCCESS;
		}	
	} while (opcion < 7);

	return EXIT_SUCCESS;

}
