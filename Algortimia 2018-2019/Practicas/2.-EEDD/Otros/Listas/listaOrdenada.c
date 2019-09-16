#include <stdio.h>
#include <stdlib.h>

//Estructura de las celda que componen las listas
typedef struct celda
{
	int valor;
	struct celda *sig;
}celda;

//Cabecera de nuestra lista
typedef struct lista
{
	struct celda *head;
}lista;

void pideInsertar();
void insertarElemento(lista *list, celda *aux);
void mostrar(lista *list);

void main()
{
	lista *list;
	list = (lista*)malloc(sizeof(lista));
	list->head = NULL;
	pideInsertar(list);
	pideInsertar(list);
	pideInsertar(list);
	pideInsertar(list);
	mostrar(list);
}


void pideInsertar(lista *list){
	int valor;
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	printf("Introduzca el elemento que desea introducir en la lista\n");
	scanf("%d", &valor);

	aux->valor = valor;
	aux->sig = NULL;
	 
	insertarElemento(list, aux);
}

void insertarElemento(lista *list, celda *aux){
	//lista vacia o insercion al inicio
	celda *rec;
	rec = (celda*)malloc(sizeof(celda));
	

	if ( (list->head == NULL) || ( ((list->head)->valor) > aux->valor) ) {
		aux->sig = list->head;
		list->head = aux;
	}else {
		rec = list->head;
		while ( (rec->sig != NULL) && ( (rec->sig->valor) <= aux->valor ) ){
			rec = rec->sig;
		}
		if (rec->sig == NULL){
			rec->sig = aux;
		}else{
			aux->sig = rec->sig;
			rec->sig = aux;
		}
	}

}

void mostrar(lista *list){
        celda *aux;
        aux = list->head;
        if (aux == 0)
                printf("La lista se encuentra vacia\n");
        else{
                printf("La cola contiene (salida-entrada): ");
                while(aux != NULL)
                    {
                        printf("%d ", aux->valor);
                        aux = aux->sig;
                    }
                printf("\n\n");
    }
}

