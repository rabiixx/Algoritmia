//Cola de Prioridad

//Librerias 
#include <stdio.h>
#include <stdlib.h>

//Estructura del programa

typedef struct celda{
	int prioridad;
	int valor;
	struct celda *sig;
}celda;

typedef struct cola{
	struct celda *head;	
}cola;

void pideEncolar(cola *c);
void encolar(cola *c, celda *aux);
void desencolar(cola *c);
void estaVacia(cola *c);
int menu();
void infoprogram();

//Programa Principal
void main(){

		system("clear");
        int men;

        cola *c;
        c = (cola*)malloc(sizeof(cola));
        c->head = NULL;

        do{
        men = menu();
        switch(men){
                case 1: pideEncolar(c);
                        break;
                case 2: desencolar(c);
                        break;
                case 3: estaVacia(c);
                		break;
                case 4: exit(0);
                         break;
                default: printf("Opcion erronea\n");
                        break;
                }
        }while(1);
}


void infoprogram(){
        printf("Nombre del programa: PriorityQueue.c\n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Entorno de desarrollo: Linux Ubuntu 18.04 LTS\n");
        printf("Compilador: gcc\n");
        printf("Descripcion: leete las putas practicas y lo sabras...\n");
        printf("\n\n");
}

int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1- Insertar elemento\n");
        printf("2- Eliminar elemento\n");
        printf("Esta vacia\n");
        printf("3- Salir de una puta vez\n");
        scanf("%d", &op);
        //Agregar mensaje de error si op no se encuentra entre 1..5
        return(op);
}


void pideEncolar(cola *c){

	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	int prioridad;
	int valor;

	printf("Introdice un numero y su prioridad: ");
	scanf("%d %d", &valor, &prioridad);

	aux->valor = valor;
	aux->prioridad = prioridad;
	aux->sig = NULL;

	encolar(c, aux);

}


void encolar(cola *c, celda *aux){
	celda *rec;
	rec = (celda*)malloc(sizeof(celda));

	if( ( c->head == NULL )	||	( ( (c->head)->prioridad) < (aux->prioridad) ) ){		//La cola se encuentra vacia o el primer elmento tiene menor prioridad que aux
		aux->sig = c->head;
		c->head = aux;
	}else{	//Busqueda de un elemento con menor prioridad que aux o hasta llegar al final de ls lista
		rec = c->head;
		while(rec->sig != NULL  &&  ( ( (rec->sig)->prioridad) > (aux->prioridad) ) ){
			rec = rec->sig;
		}
		if (rec->sig = NULL){
			rec->sig = aux;
		}else{
			aux->sig = rec->sig;
			rec->sig = aux;
		}
	}
}


void desencolar(cola *c){
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	aux = c->head;
	c->head = (c->head)->sig;

	printf("Desencolando elemento %d con prioridad %d\n", aux->valor, aux->prioridad );
	free(aux);
}


void estaVacia(cola *c){
	if (c->head == NULL){
		printf("La cola de prioridad se encuentra vacia\n");
	}else {
		printf("La cola de prioridad no se encuentra vacia\n"); 
	}

}


void vaciarCola(cola *c){
	celda *aux;
	aux = (celda*)malloc(sizeof(celda));

	while(c->head != NULL){
		aux = c->head;
		c->head = (c->head)->sig;
		free(aux);
	}

}
