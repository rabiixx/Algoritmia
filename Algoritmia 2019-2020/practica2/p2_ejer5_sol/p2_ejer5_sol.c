
/** 
  * Se ha modificado ligeramente la funcion elimnarElemento de la libraria minMonticulo
  * debido a que siempre quremos eliminar el elemento que se encuentra en la raiz, por tanto, 
  * el segundo argumento queda en desuso
  **/

#include<stdio.h>
#include <stdlib.h>
#include "minMonticulo.h"

#define MAGIC_NUM 777

int main(void){
	
	int numEl;
	tipoElementoMinMonticulo elem;
	tipoMinMonticulo mon;
	
	printf("[+] Introduce el numero maximo de elementos: ");
	scanf("%d",&numEl);
	nuevoMinMonticulo(&mon,numEl);
	
	printf("[+] Introduce elementos para ordenar. 0 para terminar: ");
	scanf("%d", &elem);
	while(elem != 0) {
		insertarMinMonticulo(&mon, elem);
		scanf("%d", &elem);
	}

	size_t arr_length = mon.numEl;

	tipoElementoMinMonticulo *sol = (tipoElementoMinMonticulo*)calloc(mon.numEl, sizeof(tipoElementoMinMonticulo));
	for (int i = 0; i < arr_length; ++i){
		sol[i] = devolverRaiz(mon);
		eliminarElemento(&mon, MAGIC_NUM);
	}

	printf("[+] Los elemenetos ordenados son: ");
	for (int i = 0; i < arr_length; ++i){
		printf("%d, ", sol[i]);
	}
	printf("\n");

	return 0;

}