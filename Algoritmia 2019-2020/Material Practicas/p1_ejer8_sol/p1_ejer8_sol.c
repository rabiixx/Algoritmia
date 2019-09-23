#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "colaEnteros.h"


void Josephus(tipoCola *c, int paso, tipoElementoCola numRes) {
	


	unsigned int cont = 1;
	celdaCola *aux;
	aux = c->ini;

	for (int i = 0; i < (numRes - 1); ++i) {

		while(cont != 2) {
			if(aux->sig == NULL)
				aux = c->ini;
			else
				aux = aux->sig;
			cont++;
		}

		c->fin->sig = c->ini;
		c->fin = aux;
		c->ini = aux->sig;
		aux = aux->sig;
		c->fin->sig = NULL;
		//c->ini = aux;
		//frente(*c);
		
		aux = aux->sig;
		//aux = c->ini->sig;
		desencolar(c);
		mostrar(*c);
		frente(*c);
		atras(*c);
		cont = 1;
	}

	frente(*c);
}

int main(int argc, char const *argv[])
{

	system("clear");

	tipoElementoCola numRes;
	int paso;
	printf("Introduce el numero de resistentes: ");
	scanf("%d", &numRes);
	printf("Introduce el paso: ");
	scanf("%d", &paso);


	tipoCola cola;
	nuevaCola(&cola);


	for (int i = 1; i < (numRes + 1); ++i)
		encolar(&cola, i);
	mostrar(cola);
	Josephus(&cola, paso, numRes);

	return 0;
}


