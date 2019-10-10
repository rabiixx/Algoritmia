#include<stdio.h>
#include<stdlib.h>

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

	insertar(&arbol, 10);
	insertar(&arbol, 7);
	insertar(&arbol, 4);
	insertar(&arbol, 5);
	insertar(&arbol, 5);		
	insertar(&arbol, 11);
	insertar(&arbol, 8);
	insertar(&arbol, 4);
	insertar(&arbol, 4);
	insertar(&arbol, 8);
	insertar(&arbol, 8);
	insertar(&arbol, 8);
	insertar(&arbol, 6);


	printf("[+] Inorden: ");
	mostrarInorden(arbol);
	printf("\n");

	printf("[+] Preorden: ");
	mostrarPreorden(arbol);
	printf("\n");

	int cont = 0;
	printf("[+] Mostrar: \n");
	mostrar(arbol, &cont);

	imprimir_suc_pre(arbol, 7);


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

void imprimir_suc_pre(tipoArbol arbol, tipoElementoArbol auxElem	) {

	tipoArbol a = buscar(arbol, auxElem);

	mostrarPreorden(a);

	printf("1\n");
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
	printf("hola1\n");
	if (a) 
		sucesor(a->izq);
	else
		return a;
}

tipoArbol antecesor(tipoArbol a) {
	printf("hola2\n");
	if (a) 
		sucesor(a->der);
	else
		return a;
}

tipoArbol buscar(tipoArbol a, tipoElementoArbol auxElem) {


	printf("fldsfm\n");
	if(a->elem == auxElem)
		return a;
	else if (auxElem < a->elem)
		buscar(a->izq, auxElem);
	else if (auxElem > a->elem)
		buscar(a->der, auxElem);
}


        /*         
  celda* buscar(celda *a, int valor){
       if(valor < a->num)
                buscar(a->izda);
       if(valor > a->num)
                buscar(a->dcha);
       if(valor == a->num)
                return a;
                }
  void esHoja(celda *a){
       return !a->izda && !a->dcha;
    }
     
     
*/