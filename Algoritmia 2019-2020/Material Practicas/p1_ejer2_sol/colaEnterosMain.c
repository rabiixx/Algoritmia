
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
	scanf("%d", &op);
		
	return(op);
}

void auxEncolar(cola *c) {
	int auxElem;
	printf("[+] Introduzca el numero que desea encolar: \n");
	scanf("%d", &auxElem);
	encolar(c, auxElem);
}

void auxFrente(cola *c) {
	printf("[+] Frente: %d\n", frente(c));
}

void auxEsNulaCola(cola *c) {
	if (esNulaCola(c))
		printf("[+] La cola esta vacia.\n");
	else
		printf("[+] La cola no esta vacia.\n");
}


//Programa Principal
int main(){
	
	system("clear");
	int men;
	
	cola *c = (cola)malloc(sizeof(cola));
	nuevaCola(c);

	do{
		men = menu();
		switch(men){
			case 1: auxEncolar(c);
				break;
			case 2: desencolar(c);
				break;
			case 3: mostrarCola(c);
				break;
			case 4: buscar(c);
				break;
			case 5: auxFrente(c);
				break;
			case 6: auxEsNulaCola(c);
				break;
			case 7: exit(0);
				break;
			default: printf("[+] Opcion erronea!\n");
				break;
		}
	} while(1);

	return EXIT_SUCCESS;
}


