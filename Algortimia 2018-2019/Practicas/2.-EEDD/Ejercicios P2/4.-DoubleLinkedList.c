//Lista doblemente enlazada 
//Librerias 
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	struct celda *head;
	struct celda *last;
}lista;

typedef struct celda{
	struct celda *sig;
	struct celda *ant;
	int valor;
}celda;

void pideInsertar(lista *list);
void insertar(lista *list, celda *aux);
void eliminar(lista *list);
void mostrarAsc(lista *list);
void mostrarDes(lista *list);
int menu();
void infoprogram();

int menu(){
        int op;
        printf("[+] Elija la opcion deseada: \n");
        printf("\t1.- Insertar elemento\n");
        printf("\t2.- Eliminar un elemento coincidente con un valor\n");
        printf("\t3.- Mostrar lista en orden ascendente\n");
        printf("\t4.- Mostrar lista en orden descendente\n");
        printf("\t5.- Salir\n");
        printf("[+] Opcion: ");
        scanf("%d",&op);
        return(op);
}

void infoprogram(){

        printf("Nombre del programa: ListaDoblementeEnlazada\n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Entorno de desarrollo: Linux Ubuntu 18.04 LTS\n");
        printf("Compilador: gcc\n");
        printf("Descripcion: leete las putas practicas y lo sabras...\n");
        printf("\n\n");
}

void main(){

		system("clear");
		infoprogram();

	  	int men;

        lista *list;
        list = (lista*)malloc(sizeof(lista));

        list->head = NULL;
        list->last = NULL;

        do{
                men = menu();
                switch(men){
                        case 1: pideInsertar(list);
                                break;
                        case 2: eliminar(list);
                                break;
                        case 3: mostrarAsc(list);
                                break;
                        case 4: mostrarDes(list);
                                break;
                        case 5: exit(0);
                                break;
                        default: printf("Opcion erronea\n");
                }
        }while(1);
}

void pideInsertar(lista *list){
	int valor;

	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	printf("[+] Inserta un numero positivo: ");
	scanf("%d", &valor);

	aux->valor = valor;
	aux->sig = NULL;
	aux->ant = NULL;

	insertar(list, aux);
}

/*
Puntero last(apunta al ultimo elemento), dos casos posibles:
	1.- El primer elemento que itrodcimos finalmete sera el maximo 
	2.- El maximo sera el que cumple "rec->sig == NULL"
*/
//vamos a insertar los elemento ordenados de menor a mayor
void insertar(lista *list, celda *aux){

	celda *rec;
	rec = (celda*)malloc(sizeof(celda));
	//insertar elemento al principio 
	if ( list->head == NULL ){		//La lista esta vacia
		/*
		aux->sig = list->head;
		aux->ant = NULL;
		*/
		list->head = aux;
		list->last = aux;			//Por si el maximo resulta ser el primero introducido 
	}else if (( (aux->valor) < ((list->head)->valor) )){		//Insercion en primera pos de la lista
		aux->sig = list->head;
		list->head->ant = aux;
		/*
		aux->ant = NULL;
		*/
		list->head = aux;
	}else{
		rec = list->head;
		while ( (rec->sig != NULL) && ((aux->valor) > ((rec->sig)->valor) ) ){
			rec = rec->sig;
		}
		if (rec->sig == NULL){	//Insercion al final
			aux->ant = list->last;
			list->last->sig = aux;
			list->last = aux;
		}else{	
			aux->sig = rec->sig;
			aux->ant = rec;
			(rec->sig)->ant = aux;	
			rec->sig = aux;

		}
	}
}

void eliminar(lista *list){
	int x;
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));


	printf("[+] Introduce el valor del elemento que desea eliminar: ");
	scanf("%d", &x);
	/*busqueda del elemento x para su eliminacion(lista ordenada):
		1.-Cota inf: si x es menor que list->head, x no esta en la lista	
		2.-Cota sup: si x es mayor que list->last, x no esta en la lista	
		3.- Si x se encuentra entre la cota inf-sup procedemos a buscar 
	*/
	if (x < (list->head)->valor){
		printf("[+] El valor que desea eliminar no se encuentra en la lista\n");
	}else if (x > (list->last)->valor){
		printf("[+] EL valor que desea eliminar no se encuentra en la lista\n");
	}else {			//Comprobemos si el valor se encuentra en la lista
		aux = list->head;
		while(1){
			if (x > aux->valor){
				aux = aux->sig;
			}else if(x < aux->valor){
				printf("[+] El valor que busca no se encuentra en la lista\n");
				break;
			}else if(x = aux->valor){
				if (aux->ant == NULL){
					(aux->sig)->ant = NULL;
					list->head = aux->sig;
					printf("[+] Eliminando elemento,%d \n", aux->valor);
					free(aux);
					break;
				}else if (aux->sig == NULL){
					(aux->ant)->sig = NULL;
					list->last = aux->ant;
					printf("[+] Eliminando elemento, %d \n", aux->valor);
					free(aux);
					break;
				}else{
					(aux->ant)->sig = aux->sig;
					(aux->sig)->ant = aux->ant;
					printf("[+] Eliminando elemento, espere: \n");
					free(aux);
					printf("[+] Eliminacion completada con exito\n");
					break;
				}
			}
		}
	}	
}
//Esta forma de hacer la busqueda es igual de eficaz, pero mucho mas eficiente 

void mostrarDes(lista *list){
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	aux = list->head;
	printf("Lista en orden descendente:\t");
	while( aux != NULL){
		printf("%d\t", aux->valor);
		aux = aux->sig;
	}
	printf("\n");
}

void mostrarAsc(lista *list){
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	aux = list->last;
	printf("Lista en orden descendente:\t");
	while(aux != NULL){
		printf("%d\t", aux->valor);
		aux = aux->ant;
	}
	printf("\n");
}
