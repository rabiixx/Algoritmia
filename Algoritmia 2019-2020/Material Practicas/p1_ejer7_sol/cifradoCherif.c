#include<stdio.h>

#include "colaEnteros.h"

int main(){
	tipoElementoCola elem;
	tipoCola cola;
	int opcion;
	
	nuevaCola(&cola);

	printf("Introduce: ");
	while( (ch = fgetc(stdin)) != '\n') {
		printf("%c\n", ch);
		apilar(cola, ch);
	}






}