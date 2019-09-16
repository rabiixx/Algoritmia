//Lista de listas 

#include <stdio.h>
#include <stdlib.h>

typedef struct supraLista
{
	struct supraLista *sig;
	struct subLista *head;
}supraLista;

typedef struct subLista{
	struct subLista *sig;
	int valor;
}subLista;

typedef struct lista{
	struct supraLista *header;
}lista;


void insertarSub(supraLista *supLista, subLista *celda);
void insertarSupra(lista *list, supraLista *supLista);


void main(){

	int nListas;
	int num;

	printf("Introduce el numero de listas\n");
	scanf("%d", &nListas);

	lista *list;
	list = (lista*)malloc(sizeof(lista));
	list->header = NULL;

	for (int i = 0; i < nListas; ++i){

		printf("Para la lista %d introduce los elementos y termina con 0: \n", (i + 1) );
		scanf("%d", &num);

		supraLista *supLista;
		supLista = (supraLista*)malloc(sizeof(supraLista));
		supLista->sig = NULL;
		supLista->head = NULL;

		while(num != 0){

				subLista *celda;
				celda = (subLista*)malloc(sizeof(subLista));
				celda->valor = num;
				celda->sig = NULL;

				insertarSub(supLista, celda );

				scanf("%d", &num);
		}
		insertarSupra(list, supLista);
	}
printf("El minimo de los maximos es: %d\n", list->header->head->valor);
}

//Ordenacion en base al primer elemento (maximo de la subLista) de la supraLista
void insertarSupra(lista *list, supraLista *supLista){
	//Insertar al inicio

	supraLista *aux;			//Puntero para realizar busqueda y ordenar los elementos de la lista
	aux = (supraLista*)malloc(sizeof(supraLista)); 


	if( (list->header == NULL) || ( (list->header->head->valor) > (supLista->head->valor) ) ) {//Insercion al inicio 
		supLista->sig = list->header;
		list->header = supLista;
	}else{
		aux = list->header;
		while ((aux->sig != NULL) && ( (aux->head->valor) < (supLista->head->valor) )  ){
			aux = aux->sig;
		}
		if (aux->sig == NULL){//Insercion al final de la lista
			aux->sig = supLista;
		}else{//Insercion entre medias 
			supLista->sig = aux->sig;
			aux->sig = supLista;
		}
	}
}



void insertarSub(supraLista *supLista, subLista *celda){

	subLista *aux;
	aux = (subLista*)malloc(sizeof(subLista));

	if ( (supLista->head == NULL) || (supLista->head->valor < celda->valor )){
		celda->sig = supLista->head;
		supLista->head = celda;
	}else{
		aux = supLista->head;
		while(aux->sig != NULL && aux->sig->valor  >= celda->valor){
			aux = aux->sig;
		}
		if (aux->sig == NULL){
			aux->sig = celda;
		}else{
			celda->sig = aux->sig;
			aux->sig = celda;
		}
	}
}





