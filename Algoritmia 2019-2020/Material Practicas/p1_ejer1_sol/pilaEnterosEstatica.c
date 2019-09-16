/*
  FICHERO: pilaEnterosEstatica.c
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include "pilaEnterosEstatica.h"
#include <stdio.h>
#include <stdlib.h>


void nuevaPila(tipoPila *p){
	p->cima=-1;
}

void errorPila(char s[]){
	printf("\n\n\nERROR en el modulo pilas: %s \n", s);
}

bool llenaPila(tipoPila p){
	return (p.cima == TAMANIO_PILA_DE_ENTEROS -1);
}

void apilar(tipoPila *p, tipoElementoPila x){
	if (llenaPila(*p))
		errorPila("Apilando en una pila de enteros llena.");
	p->cima++;
	p->valores[p->cima]=x;
}

void desapilar(tipoPila *p){
	if (esNulaPila(*p))
		errorPila("Desapilando en una pila de enteros vacia.");
	p->cima--;
}

tipoElementoPila cima (tipoPila p){
	if (esNulaPila(p))
		errorPila("Cima en una pila de enteros vacia.");
	else
		return(p.valores[p.cima]);
}

bool esNulaPila (tipoPila p){
	return (p.cima == -1);
}

