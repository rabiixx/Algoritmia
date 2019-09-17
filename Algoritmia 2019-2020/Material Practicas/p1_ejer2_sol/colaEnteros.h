#include <stdbool.h>

typedef int tipoElementoCola;

typedef struct celdaC{
  	int elem;
  	struct celdaC *sig;
}celdaC; 

typedef struct cola{
	struct celdaC *head;
  	struct celdaC *fin;
}cola;

void nuevaCola(cola *c);

void encolar(cola *c, int auxElem);

void desencolar(cola *c);

int frente(cola *c);

bool esNulaCola(cola *c);

void mostrarCola(cola *c);

bool buscar(cola *c, int auxElem);