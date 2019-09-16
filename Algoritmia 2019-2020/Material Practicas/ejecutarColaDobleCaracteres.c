/*
  FICHERO: ejecutarColaCaracteres.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include<stdio.h>

#include "colaDobleCaracteres.h"

int main(){
	tipoElementoColaDoble elem;
	tipoColaDoble cola;
	int opcion;
	
	nuevaColaDoble(&cola);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Encolar un elemento al inicio\n");
		printf("2 - Encolar un elemento al final\n");
		printf("3 - Desencolar un elemento del inicio\n");
		printf("4 - Desencolar un elemento del final\n");
		printf("5 - Mostrar el elemento del inicio.\n");
		printf("6 - Mostrar el elemento del final.\n");
		printf("7 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
			case 1: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				encolarPrimero(&cola,elem);
				break;   
			case 2: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				encolarUltimo(&cola,elem);
				break; 
			case 3: 
				desencolarPrimero(&cola);
				printf("Se ha eliminado un elemento\n");
				break;
			case 4: 
				desencolarUltimo(&cola);
				printf("Se ha eliminado un elemento\n");
				break;
			case 5:
				elem=elemPrimero(cola);
				printf("El primer elemento es %d\n",elem);
				break;
			case 6:
				elem=elemUltimo(cola);
				printf("El ultimo elemento es %d\n",elem);
				break;
		}
	}while(opcion<7);
}