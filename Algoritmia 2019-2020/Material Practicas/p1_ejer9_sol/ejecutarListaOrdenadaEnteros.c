/*
  FICHERO: ejecutarListaOrdenadaEnteros.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include<stdio.h>
#include <stdlib.h>
#include "listaOrdenadaEnteros.h"

int main(void){

	system("clear");

	tipoElementoLista elem;
	tipoLista lista,lista2;
	int opcion;
	
	nuevaLista(&lista);
	nuevaLista(&lista2);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Insertar un elemento en la primera lista\n");
		printf("2 - Insertar un elemento en la segunda lista\n");
		printf("3 - Eliminar el menor elemento de la lista 1\n");
		printf("4 - Eliminar el mayor elemento de la lista 1\n");
		printf("5 - Mostrar todos los elementos de la lista 1.\n");
		printf("6 - Mostrar todos los elementos de la lista 2.\n");
		printf("7 - Comprobar si un elemento esta en la lista 1.\n");
		printf("8 - Concatenar ambas listas.\n");
		printf("9 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
			case 1: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				insertar(&lista,elem);
				break;
			case 2: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				insertar(&lista2,elem);
				break;    
			case 3: 
				eliminarMenor(&lista);
				printf("Se ha eliminado un elemento\n");
				break;
			case 4: 
				eliminarMayor(&lista);
				printf("Se ha eliminado un elemento\n");
				break;
			case 5:
				printf("Lista 1: ");
				imprimirLista(lista);
				break;
			case 6:
				printf("Lista 2: ");
				imprimirLista(lista2);
				break;
			case 7: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				if(estaElemento(lista,elem))
					printf("El elemento %d esta en la lista\n",elem);
				else
					printf("El elemento %d NO esta en la lista\n",elem);
				break;
			case 8: 
				concatenar(&lista,&lista2);
				break;
		}
		//system("clear");
	}while(opcion<9);

	return 0;
}
