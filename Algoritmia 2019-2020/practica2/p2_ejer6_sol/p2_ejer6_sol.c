// The MIT License (MIT)

// Copyright (c) YEAR NAME

//  Permission is hereby granted, free of charge, to any person obtaining a 
//  copy of this software and associated documentation files (the "Software"), 
//  to deal in the Software without restriction, including without limitation 
//  the rights to use, copy, modify, merge, publish, distribute, sublicense, 
//  and/or sell copies of the Software, and to permit persons to whom the 
//  Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in 
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
//  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
//  DEALINGS IN THE SOFTWARE.


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "arbolBin.h"
//#include "pilaEnterosDinamica.h"

#define MAX_STR 100 /* Maximum string elements */

/* Util functions */
bool esOperador(char c);

typedef struct celdaP{
	char val;
	struct celdaP *sig;
	struct celdaABin *head;
}celdaPila;

typedef celdaPila *tipoPila;

void nuevaPila(tipoPila *p) {
	(*p) = NULL;
}


tipoArbolBin devArbol(tipoPila p) {
	return p->head;
}


void apilar(tipoPila *p, tipoElementoArbolBin auxElem) {
	
	celdaPila *auxP = (celdaPila*)malloc(sizeof(celdaPila));
	celdaArbolBin *auxA = (celdaArbolBin*)malloc(sizeof(celdaArbolBin));
	
	auxA->elem = auxElem;
	auxA->izda = NULL;
	auxA->dcha = NULL;

	auxP->val = auxElem;
	auxP->head = auxA;
	auxP->sig = *p;
	
	*p = auxP;
}

int main(int argc, char const *argv[])
{

	tipoPila pila;
	nuevaPila(&pila);

	tipoArbolBin arbol;
	nuevoArbolBin(&arbol);


	char *str = (char*)calloc(100, sizeof(char));
	printf("Introduce la operacion en notacion postija, sin espacios: ");
	scanf("%s", str);

	for (int i = 0; i < ; ++i)
	{
		/* code */
	}

	int i = 0;		
	while ( !esOperador(str[i]) )
		apilar(&pila, str[i]);
		

	tipoArbolBin der = devArbol(pila);
	tipoArbolBin izq = devArbol(pila);
	arbol = construir(str[i], izq, der);

	printf("Inorden: ");
	inorden(arbol);

	return 0;
}

bool esOperador(char c) {
	return (c == '+' || c == '-' || c == '*' || c == '/' ) ? true:false;
}

