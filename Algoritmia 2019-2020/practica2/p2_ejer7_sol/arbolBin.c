
#include <stdio.h>
#include <stdlib.h>
#include "arbolBin.h"

void nuevoArbolBin(tipoArbolBin *a) {
	a = NULL;
}	

void errorArbolBin(char s[]) {	
	return;
}

tipoArbolBin construir(tipoElementoArbolBin auxElem, tipoArbolBin izq, tipoArbolBin der) {

	celdaArbolBin *aux = (celdaArbolBin*)malloc(sizeof(celdaArbolBin));
	aux->elem = auxElem;
	aux->dcha = der;
	aux->izda = izq;

	return aux;
}

tipoElementoArbolBin devolverRaiz(tipoArbolBin a) {
	return a->elem;
}

void preorden(tipoArbolBin a) {

	if(a){
        printf("%d, ", a->elem);
        preorden(a->izda);
        preorden(a->dcha);
    }else{
        return;
    }
}

void inorden(tipoArbolBin a) {
	if(a){
        inorden(a->izda);
        printf("%d, ", a->elem);
        inorden(a->dcha);
    }else{
        return;
    }
}

void postorden(tipoArbolBin a) {
	    if(a){
        postorden(a->izda);
        postorden(a->dcha);
        printf("%d, ", a->elem);
    }else{
        return;
    }
}
