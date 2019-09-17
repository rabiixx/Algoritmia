#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "colaEnteros.h"

//typedef int tipoElementoCola;

void nuevaCola(cola *c) {
	c->head = NULL;
	c->fin = NULL;
}

void encolar(cola *c, int auxElem){

	celdaC *aux = (celdaC*)calloc(1, sizeof(celdaC));
	aux->elem = auxElem;
	aux->sig = NULL;

	if (esNulaCola(c)) { 
		c->head = aux;
		c->fin = aux;
	} else {
		(c->fin)->sig = aux;
		c->fin = aux;
	}
}

void desencolar(cola *c) {
	if (esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		celdaC *aux;
		aux = c->head;
		c->head = aux->sig;		//c->head = (c->head)->sig
		printf("[+] %d desencolado.\n", aux->elem);
		free(aux);
	}
}

int frente(cola *c) {		
	if (esNulaCola(c))
		printf("[+] La cola esta vacia.\n");
	else 
		return c->head->elem;	
}

bool esNulaCola(cola *c) {	return (c->head)? true:false; 	}

void mostrarCola(cola *c) {

	if (esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		celdaC *aux = c->head;
		printf("Cola: ");
		while (aux) {
			printf("%d, \t", aux->elem);
			aux = aux->sig;
		}
	}
}

void buscar(cola *c) {
	
	if(esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		
		int auxElem;
		celdaC *aux = c->head;

		printf("[+] Introduzca el elemento que desea buscar : \n");
		scanf("%d", &auxElem);

		while (aux) {
			if (aux->elem == auxElem)
				printf("[+] El elemento se encuentra en la cola. \n", );
			else 
				aux = aux->sig;
		}
	}
}


