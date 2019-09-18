#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "colaEnteros.h"


void nuevaCola(tipoCola *c) {
	c->ini = NULL;
	c->fin = NULL;
}

void encolar(tipoCola *c, tipoElementoCola auxElem) {

	celdaCola *aux = (celdaCola*)malloc(sizeof(celdaCola));
	aux->elem = auxElem;
	aux->sig = NULL;

	if (esNulaCola(*c)) {
		c->ini = aux;
		c->fin = aux;
	} else {
		(c->fin)->sig = aux;
		c->fin = aux;
	}

}

void desencolar(tipoCola *c) {
	if (esNulaCola(*c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		celdaCola *aux;
		aux = c->ini;
		c->ini = aux->sig;		//c->head = (c->head)->sig
		printf("[+] %d desencolado.\n", aux->elem);
		free(aux);
	}
}

tipoElementoCola frente(tipoCola c) {
	if (esNulaCola(c))
		printf("No se puede obtener el frente en una cola vacia.\n");
	else
		return (c.ini)->elem;
}

bool esNulaCola(tipoCola c) {
	return ( (c.ini == NULL) && (c.fin == NULL) );
}


void encriptar(tipoCola *c) {

	celdaCola *aux1;
	celdaCola *aux2;

	aux1 = c->head;
	aux2 = (c->head)->sig;

	if( esCons(aux1->elem) && esCons(aux2->elem) ) {
		aux1 = 



		twist()
	} 
}


bool esCons(char ch) {
	return ( (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u') )
}