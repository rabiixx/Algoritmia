
#include <stdio.h>
#include <stdlib.h>
#include "colaEnteros.h"


int menu(){
	
	int op;
	
	printf("[+] Elija la opcion deseada: \n");
	printf("\t1- Encolar elemento\n");
	printf("\t2- Desapilar elemento\n");
	printf("\t3- Mostrar cola completa\n");
	printf("\t4- Buscar elemento\n");
	printf("\t5- Mostrar elemento del frente\n");
	printf("\t6- Comprobar si esta vacia\n");
	printf("\t7- Salir\n");
	printf("[+] Opcion: ");
	scanf("%d", &op);
		
	return(op);
}


void auxFrente(cola *c) {
	
}

void auxEsNulaCola(cola *c) {

}


//Programa Principal
int main(){
	
	system("clear");
	int men;
	int auxElem;
	
	cola *c = (cola*)malloc(sizeof(cola));
	nuevaCola(c);

	do{
		men = menu();
		switch(men){
			case 1: 
				printf("[+] Introduzca el numero que desea encolar: ");
				scanf("%d", &auxElem);
				encolar(c, auxElem);;
				break;
			case 2: desencolar(c);
				break;
			case 3: mostrarCola(c);
				break;
			case 4: 
				printf("[+] Introduzca el elemento que desea buscar: ");
				scanf("%d", &auxElem);
				if ( buscar(c, auxElem) )
					printf("[+] El elemento %d se encuentra en la cola.\n", auxElem);
				else
					printf("[+] El elemento %d no se encuentra en la cola.\n", auxElem);
				break;
			case 5: 
				printf("[+] Frente: %d\n", frente(c));
				break;
			case 6: 
				if (esNulaCola(c))
					printf("[+] La cola esta vacia.\n");
				else
					printf("[+] La cola no esta vacia.\n");
				break;
			case 7: 
				system("clean");
				exit(EXIT_SUCCESS);
			default: printf("[+] Opcion erronea!\n");
				break;
		}
	} while(1);

	return EXIT_SUCCESS;
}


