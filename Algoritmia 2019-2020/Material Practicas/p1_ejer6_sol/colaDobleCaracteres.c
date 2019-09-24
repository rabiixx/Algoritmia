
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "colaDobleCaracteres.h"

void nuevaColaDoble(tipoColaDoble *c) {
	c->ini = NULL;
	c->fin = NULL;
}

void encolarPrimero(tipoColaDoble *c, tipoElementoColaDoble auxElem){
	
	celdaColaDoble *aux = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
	
	aux->elem = auxElem;
	aux->sig = NULL;
	aux->ant = NULL;
	
	if(esNulaColaDoble(*c)) {
		c->ini = aux;
		c->fin = aux;
	} else {
		aux->sig = c->ini;
		c->ini->ant = aux;
		c->ini = aux;
	}
}

void encolarUltimo(tipoColaDoble *c, tipoElementoColaDoble auxElem) {

	celdaColaDoble *aux = (celdaColaDoble*)malloc(sizeof(celdaColaDoble));
	
	aux->elem = auxElem;
	aux->sig = NULL;
	aux->ant = NULL;

	if(esNulaColaDoble(*c)) {
		c->ini = aux;
		c->fin = aux;
	} else {
		aux->ant = c->fin;
		c->fin->sig = aux;
		c->fin = aux;
	}

}

void desencolarPrimero(tipoColaDoble *c) {
	if(esNulaColaDoble(*c)) {
		printf("La cola doble esta vacia\n");
	} else {
		celdaColaDoble *aux = c->ini;
		if ( aux->sig != NULL)
			aux->sig->ant = NULL;
		c->ini = aux->sig;
		free(aux);
	}
}

void desencolarUltimo(tipoColaDoble *c) {
	
	if(esNulaColaDoble(*c)) {
		printf("La cola doble esta vacia\n");
	} else {
		celdaColaDoble *aux = c->fin;
		if (aux->ant != NULL)
			aux->ant->sig = NULL;
		c->fin = aux->ant;
		free(aux);
	}
}

tipoElementoColaDoble elemPrimero(tipoColaDoble c) {
	if(esNulaColaDoble(c))
		printf("La cola doble esta vacia\n");
	else 
		return (c.ini)->elem; 
}

tipoElementoColaDoble elemUltimo(tipoColaDoble c) {
	if(esNulaColaDoble(c))
		printf("La cola doble esta vacia\n");
	else 
		return (c.fin)->elem; 
}

bool esNulaColaDoble(tipoColaDoble c) {
	return (c.ini) ? false:true;
}

void mostrar(tipoColaDoble c) {

	if(esNulaColaDoble(c)) {
		printf("La cola doble esta vacia\n");
	} else {
		celdaColaDoble *aux = c.ini;
		while(aux != NULL) {
		    printf("%c, ", aux->elem);
		    aux =  aux->sig;
		}
		printf("\n\n");
	}
}


void vaciarColaDoble(tipoColaDoble *c) {
	while( !esNulaColaDoble(*c)) {
	    desencolarPrimero(c);
	}
}