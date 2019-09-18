/*
  FICHERO: ejecutarColaEnteros.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include<stdio.h>

#include "colaEnteros.h"

int main(){
	tipoElementoCola elem;
	tipoCola cola;
	int opcion;
	
	nuevaCola(&cola);
	do
    {
		printf("--------MENU-------- \n");
		printf("1 - Encolar un elemento\n");
		printf("2 - Desencolar un elemento\n");
		printf("3 - Mostrar elemento del frente.\n");
		printf("4 - Salir.\n");
		printf("Escoja una opcion: ");
		scanf("%d",&opcion);
		switch(opcion){           
			case 1: 
				printf("Introduce el entero: ");
				scanf("%d",&elem);
				encolar(&cola,elem);
				break;    
			case 2: 
				desencolar(&cola);
				printf("Se ha eliminado un elemento\n");
				break;
			case 3:
				elem=frente(cola);
				printf("El frente es %d\n",elem);
				break;
		}
	}while(opcion<4);
}
