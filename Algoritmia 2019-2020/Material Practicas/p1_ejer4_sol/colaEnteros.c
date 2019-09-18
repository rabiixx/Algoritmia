#include <stdbool.h>

 typedef int tipoElementoCola;
 
 typedef struct celdaC{
	 tipoElementoCola elem;
	 struct celdaC *sig;
 } celdaCola; 

typedef struct tipoC{
	celdaCola* ini;
	celdaCola* fin;
}tipoCola;

void nuevaCola(tipoCola *c) {
	c->ini = NULL;
	c->fin = NULL;
}

void encolar(tipoCola *c, tipoElementoCola auxElem) {

	celdaCola *aux = (celdaCola*)malloc(sizeof(celdaCola));
	aux->elem = auxElem;
	aux->sig = NULL;

	if (esNulaCola(c)) {
		(*c)->ini = aux;
		(*c)->fin = aux;
	} else {
		(c->fin)->sig = aux;
		c->fin = aux;
	}

}

void desencolar(tipoCola *c) {
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

tipoElementoCola frente(tipoCola c) {
	if (esNulaPila(c))
		errorPila("No se puede obtener el frente en una cola vacia.");
	else
		return c->head->elem;
}

bool esNulaCola(tipoCola c) {
	return ( (c->head == NULL) && (c->fin == NULL) )
}