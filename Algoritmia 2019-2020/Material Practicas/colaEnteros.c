#include <stdbool.h>

 typedef int tipoElementoCola;

 
typedef struct _celdaC{
	int elem;
	celdaC *sig;
}celdaC; 


typedef struct _cola{
	celdaCola* ini;
	celdaCola* fin;
}cola;

void nuevaCola(tipoC *c) {
	cola *c = (cola*)calloc(1, sizeof(cola));
	c = NULL;
}

void encolar(tipoCola *, int auxElem){

	celdaC *aux = (celdaC*)calloc(1, sizeof(celdaC));
	aux->elem = auxElem;

	if (c == NULL) { 
		c = aux;
	}




}

void desencolar(tipoCola *);

tipoElementoCola frente(tipoCola);

bool esNulaCola(tipoCola);


int main(int argc, char const *argv[])
{
	



	return 0;
}


/* calloc inicilaiza todo a 0/NULL por tanto no es necesario inicializar */