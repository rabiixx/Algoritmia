#include <stdbool.h>

typedef int tipoElementoCola;

typedef struct _celdaC{
  	int elem;
  	struct celdaC *sig;
}celdaC; 

typedef struct _cola{
	struct celdaC *head;
  	struct celdaC *fin;
}cola;

void nuevaCola(cola *c);

void encolar(cola *c, int auxElem);

void desencolar(cola *c);

int frente(cola *c);

bool esNulaCola(cola *c);

void mostrarCola(cola *c);

void buscar(cola *c);