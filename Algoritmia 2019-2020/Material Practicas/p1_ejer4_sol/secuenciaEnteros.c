

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "pilaEnterosDinamica.h"
#include "secuenciaEnteros.h"


void nuevaSecuencia(tipoSecuencia *s){
	s->pilaIzq = NULL;
	s->pilaDcha = NULL;
}

void insertarDelantePunto(tipoSecuencia *s, tipoElementoPila elem){
	apilar( &(s->pilaIzq), elem);
}

void insertarEnPunto(tipoSecuencia *s, tipoElementoPila elem){
	apilar( &(s->pilaDcha), elem);
}

void eliminarEnPunto(tipoSecuencia *s) {
	desapilar( &(s->pilaDcha));
}

tipoElementoPila consultarEnPunto(tipoSecuencia s) {
	return cima(s.pilaDcha);
}

void avanzarPunto (tipoSecuencia *s) {
	tipoElementoPila elemP = cima(s->pilaDcha);	//cima(*(s->pilaDcha))
	desapilar(&(s->pilaDcha));
	apilar( &(s->pilaIzq), elemP);
}

void moverPuntoAlPrincipio (tipoSecuencia *s) {
	while(s->pilaIzq != NULL) {
		tipoElementoPila elemP = cima(s->pilaDcha);	//cima(*(s->pilaDcha))
		desapilar(&(s->pilaDcha));
		apilar( &(s->pilaDcha), elemP);
	}
}

bool esPuntoUltimo(tipoSecuencia s) {
	return esNulaPila(s.pilaDcha);
}

bool esVaciaSecuencia(tipoSecuencia s) {
	return (!(esNulaPila(s.pilaIzq)) && !(esNulaPila(s.pilaDcha))) ? true:false;
}