#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "listaOrdenadaEnteros.h"

void nuevaLista(tipoLista *l) {
	l->ini = NULL;
	l->fin = NULL;
}

void insertar(tipoLista *l, tipoElementoLista auxElem) {
	
	if ( estaElemento(*l, auxElem) ) {
		printf("- El elemento %d ya se encuentra en la lista", auxElem);
	} else {
		celdaLista *aux = (celdaLista*)malloc(sizeof(celdaLista));
		aux->elem = auxElem;
		aux->sig = NULL;
		aux->ant = NULL;

		if (esNulaLista(*l)) {
			l->ini = aux;
			l->fin = aux;
		} else if( (aux->elem) < (l->ini->elem) ) {
			aux->sig = l->ini;
			l->ini->ant = aux;
			l->ini = aux;
		} else {
			
			celdaLista *rec = l->ini;
			while( (rec->sig != NULL) && (rec->sig->elem < aux->elem) )
				rec = rec->sig;
			
			if (rec->sig == NULL) {		/* Insertar al final */
				aux->ant = l->fin;
				l->fin->sig = aux;
				l->fin = aux;
			} else {
				aux->ant = rec;
				aux->sig = rec->sig;
				rec->sig = aux;
				rec->sig->ant = aux;
			}
		}
	}
}

void eliminarMenor(tipoLista *l) {
	
	if(esNulaLista(*l)) {
		printf("La lista esta vacia\n");
	} else {
		celdaLista *aux = l->ini;
		if(aux->sig != NULL)
			aux->sig->ant = NULL;
		l->ini = aux->sig;
		free(aux);
	}
}

void eliminarMayor(tipoLista *l) {
	if(esNulaLista(*l)) {
		printf("La lista esta vacia\n");
	} else {
		celdaLista *aux = l->fin;
		if (aux->ant != NULL)
			aux->ant->sig = NULL;
		l->fin = aux->ant;
		free(aux);
	}
}

tipoElementoLista consultarMenor(tipoLista l) {
	if (esNulaLista(l)) {
		printf("La lista esta vacia\n");
	} else {
		return (l.ini)->elem;
	}
}

tipoElementoLista consultarMayor(tipoLista l) {
	if (esNulaLista(l)) {
		printf("La lista esta vacia\n");
	} else {
		return (l.fin)->elem;
	}
}

bool estaElemento(tipoLista l, tipoElementoLista auxElem) {

	if( esNulaLista(l) )
		return false;
	
	if( (auxElem < l.ini->elem) || (auxElem > l.fin->elem) ) 
		return false;

	celdaLista *aux = l.ini;
	while (aux != NULL) {	/* while(1) */
		if (aux->elem == auxElem) {
			return true;
		} else if (aux->elem < auxElem) { /* && aux->sig->elem < auxElem */ 
			aux = aux->sig;
		} else if (aux->elem > auxElem)
			return false;
	}
}

bool esNulaLista(tipoLista l) {
	return (l.ini) ? false:true;
}

void concatenar (tipoLista *l1, tipoLista *l2) {
	tipoElementoLista auxElem;

	while(!esNulaLista(*l2)) {
		auxElem = consultarMenor(*l2);
		eliminarMenor(l2);
		insertar(l1, auxElem);
	}

}

void imprimirLista (tipoLista l){

	if (esNulaLista(l) ) {
		printf("La lista esta vacia.\n");
	} else {
		celdaLista *aux = l.ini;
		while (aux != NULL) {
			printf("%d, ", aux->elem);
			aux = aux->sig;
		}
		printf("\n\n");
	} 	
}
