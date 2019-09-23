#include <stdbool.h>

 typedef int tipoElementoLista;
 typedef struct celdaL{
	 tipoElementoLista elem;
	 struct celdaL *sig;
	 struct celdaL *ant;
 }celdaLista; 
typedef struct tipoL{
	celdaLista *ini;
	celdaLista *fin;
}tipoLista;

void nuevaLista(tipoLista *l) {
	l->ini = NULL;
	l->fin = NULL;
}

void insertar(tipoLista *, tipoElementoLista auxElem) {
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

void eliminarMenor(tipoLista *);

void eliminarMayor(tipoLista *);

tipoElementoLista consultarMenor(tipoLista);

tipoElementoLista consultarMayor(tipoLista);

bool estaElemento(tipoLista, tipoElementoLista);

bool esNulaLista(tipoLista);

void concatenar (tipoLista *, tipoLista *);

void imprimirLista (tipoLista);
