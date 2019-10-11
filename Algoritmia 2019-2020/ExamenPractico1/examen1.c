#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int tipoElementoArbol;

typedef struct celdaA{
	tipoElementoArbol elem;
	struct celdaA *izq;
	struct celdaA *cen;
	struct celdaA *der;
}celdaArbol;

typedef celdaArbol *tipoArbol;

void mostrarInorden(tipoArbol a);
void mostrarPreorden(tipoArbol a);
void mostrar(tipoArbol a, int *cont);
void nuevoArbol(tipoArbol *a);
void insertar(tipoArbol *a, tipoElementoArbol auxElem);
void imprimir_suc_pre(tipoArbol a, int valor);
tipoArbol sucesor(tipoArbol a);
tipoArbol antecesor(tipoArbol a);
tipoArbol buscar(tipoArbol a, tipoElementoArbol auxElem);


int main(int argc, char const *argv[]) {

	system("clear");


	tipoArbol arbol;
	nuevoArbol(&arbol);

	clock_t start, end;

	start = clock();

	insertar(&arbol, 50); 
	insertar(&arbol, 30); 
	insertar(&arbol, 20); 
	insertar(&arbol, 40); 
	insertar(&arbol, 70); 
	insertar(&arbol, 60); 
	insertar(&arbol, 80);
	
	end = clock();

	printf("Done. Took %f seconds\n\n", (double) (end - start) / CLOCKS_PER_SEC);


	printf("[+] Inorden: ");
	mostrarInorden(arbol);
	printf("\n");

	printf("[+] Preorden: ");
	mostrarPreorden(arbol);
	printf("\n");

	int cont = 0;
	printf("[+] Mostrar: \n");
	mostrar(arbol, &cont);

	imprimir_suc_pre(arbol, 20);


	exit(EXIT_SUCCESS);
}

void mostrar(tipoArbol a, int *cont ) {
	if (a) {
		mostrar(a->izq, cont);
		if (a->cen) {
			++(*cont);
			mostrar(a->cen, cont);
		}
		if (*cont > 0){
			printf("\t[+] El elemento %d aparece repetido %d veces\n", a->elem, (*cont));
			*cont = 0;
		}
		mostrar(a->der, cont);
	} else { 
		return;
	}

}

void nuevoArbol(tipoArbol *a) {
	(*a) = NULL;
}

void insertar(tipoArbol *a, tipoElementoArbol auxElem) {

	tipoArbol aux = (tipoArbol)calloc(1, sizeof(celdaArbol));

	aux->elem = auxElem;
	aux->izq = aux->cen = aux->der = NULL;

	if( !(*a) ) {
		(*a) = aux;
	} else {
		if (auxElem < (*a)->elem )
			insertar(&(*a)->izq, auxElem);
		else if (auxElem == (*a)->elem )
			insertar(&(*a)->cen, auxElem);
		else if (auxElem > (*a)->elem )
			insertar(&(*a)->der, auxElem);
	}
}

void mostrarInorden(tipoArbol a){

	if(a){
        mostrarInorden(a->izq);
        printf("%d, ", a->elem);
        mostrarInorden(a->cen);
        mostrarInorden(a->der);
    }else{
        return;
    }
}


void mostrarPreorden(tipoArbol a) {
	if(a){
        printf("%d, ", a->elem);
        mostrarPreorden(a->izq);
        mostrarPreorden(a->cen);
        mostrarPreorden(a->der);
    } else {
        return;
    }
}

void imprimir_suc_pre(tipoArbol arbol, tipoElementoArbol auxElem) {

	tipoArbol a = buscar(arbol, auxElem);

	if ( (a->der) && (a->izq) ) {
		tipoArbol aux1 = sucesor(a->der);
		tipoArbol aux2 = antecesor(a->izq);
		printf("[+] EL sucesor es: %d.\n", aux1->elem);
		printf("[+] EL antecesor es: %d.\n", aux2->elem);
	} else if (a->der) {
		tipoArbol aux = sucesor(a->der);
		printf("[+] EL sucesor es: %d.\n", aux->elem);
		printf("[+] Este nodo no tiene antecesor.\n");
	} else if (a->izq) {
		tipoArbol aux = antecesor(a->izq);
		printf("[+] Este nodo no tiene sucesor.\n");
		printf("[+] EL antecesor es: %d.\n", aux->elem);
	} else {
		printf("[+] El nodo no tiene antecesor ni sucesor.\n");
	}	
}


tipoArbol sucesor(tipoArbol a) {
	if (a->izq){ 
		sucesor(a->izq);
	} else {
		return a;
	}
}

tipoArbol antecesor(tipoArbol a) {
	if (a->der) 
		antecesor(a->der);
	else
		return a;
}


tipoArbol buscar(tipoArbol a, tipoElementoArbol auxElem) {

	if(a->elem == auxElem)
		return a;
	else if (auxElem < a->elem)
		buscar(a->izq, auxElem);
	else if (auxElem > a->elem)
		buscar(a->der, auxElem);
}
