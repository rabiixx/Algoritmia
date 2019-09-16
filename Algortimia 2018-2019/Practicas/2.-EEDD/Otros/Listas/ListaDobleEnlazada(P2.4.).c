//Nombre del programa: cola.c
//Autor: Ruben Cherif Narvaez
//NIA: 121871
//Entorno de desarrollo: Linux Ubuntu 18.04 LTS
//Compilador: Gcc/g++
//Estilo programacion: GNOME
//Descripcion...

//Librerias
#include <stdio.h>
#include <stdlib.h>
//Esta estructura representa una lista doblemente enlazada
typedef struct celda{
        int valor;
        struct celda *sig;
        struct celda *ant;
} celda;
//Para tener mayor control de la lista es utilizaremos otra estructura que nos de informacion sobre nuentra lista 
typedef struct lista{
        struct celda *head;
        struct celda *last;
} lista;

void insertar(lista *list);
void eliminar(lista *list);
void buscar(lista *list);
void mostrarAsc(lista *list);
void mostrarDes(lista *list);
int menu();
void infoprogram();

void main(){
        lista *list;
        int men;
        list = (lista*)malloc(sizeof(lista));
        list->head = NULL;
        list->last = NULL;
        do{
                men = menu();
                switch(men){
                        case 1: insertar(list);
                                break;
                        case 2: eliminar(list);
                                break;
                        case 3: buscar(list);
                                break;
                        case 4: mostrarAsc(list);
                                break;
                        case 5: mostrarDes(list);
                                break;
                        case 6: exit(0);
                                break;
                        default: printf("Opcion erronea\n");
                }
        }while(1);
}


int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1.- Insertar elemento\n");
        printf("2.- Eliminar un elemento coincidente con un valor\n");
        printf("3.- Comprobar si un elemento esta en la lista\n");
        printf("4.- Mostrar lista en orden ascendente\n");
        printf("5.- Mostrar lista en orden descendente\n");
        printf("6.- Salir\n");
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
/*El insertar lo podemos hacer de dos formas:
1.Insertar elementos al principio de la lista:
        aux->sig = list->head;
        (list->head)->ant = aux;
        list->head = aux;
2.Insertar elementos al final de la lista
        (list->last)->sig = aux;
        aux->ant = list->last;
        list->last = aux;
*/
void insertar(lista *list){
        int valor;
        celda *aux;
        printf("Dame el valor a insertar: ");
        scanf("%d",&valor);
        aux = (celda*)malloc(sizeof(celda));//reserva memoria para el elemento a introducir
        aux->valor = valor;
        aux->ant = NULL;
        aux->sig = NULL;
        if (list->head == NULL) {//lista vacia
                list->head = aux;
                list->last = aux;
        }else {//insertamos un elemento al inicio de la lista
                aux->sig = list->head;
                (list->head)->ant = aux;
                list->head = aux;
        }
        printf("\n");
}

//buscamos el elemento y procedemos a eliminar 
void eliminar(lista *list){
        celda *aux;
        int valor;
        aux = list->head;
        if(list->head == NULL){
                printf("La lista esta vacia. Nada que eliminar\n");
        }else{
                printf("Introduzca el valor que desea eliminar\n");
                scanf("%d", &valor); 
                while(aux->valor != valor){//busqueda del elemento introducido
                        if(aux->valor == valor){
                                break;
                        }else {
                                aux = aux->sig;
                        }
                }
                if (aux != NULL){
                        /*Tres opciones:
                                -El valor se encuentra al principio 
                                -El valor se encuentra al final
                                -el valor se encuentra entremedias 
                                Para poder eliminar un elemento necesitamos eliminar sus punteros?
                        */
                        printf("El valor buscado se encuentra en la lista\n");
                        if ((aux->ant) == NULL) {
                                /*(aux->sig)->ant = NULL;*/
                                list->head = aux->sig;
                                /*aux->sig = NULL;*/
                        }else if((aux->sig) = NULL) {
                                list->last = aux->ant;
                                /*(aux->ant)->sig = NULL;*/
                                /*aux->ant = NULL;*/
                        }
                        else {
                                (aux->ant)->sig = aux->sig;
                                (aux->sig)->ant = aux->ant;
                                /**/
                        }
                        printf("Eliminamos %d\n\n", aux->valor);
                        free(aux);
                }else {
                        printf("El valor a eliminar no se encuentra en la lista\n");
                }
        }
}

//necesitamos dos variables auxiliares para poder realizar la comparacion
void ordenar(lista *list){
        celda *aux;
        celda *aux2;
        int temp;//variable temporal para no para no perder el valor de los punteros al intercambiar 
        aux = list->head;
        while(aux->sig != NULL){      
                aux2 = (list->head)->sig;
                while(aux2 != NULL){
                        if((aux2->valor) < (aux->valor)){
                                temp = aux->valor;
                                aux->valor = aux2->valor;
                                aux2->valor = temp;    
                        } 
                        aux2 = aux2->sig;       
                }
                aux = aux->sig;
        }
}


//necesitamos ordenar los elementos para poder mostrarlos en orden(7 5 3)
void mostrarDes(lista *list){
        celda *aux;
        if(aux == NULL){
                printf("La lista esta vacia");
        }else {
                ordenar(list);
                aux = list->last;
                while(aux != NULL){
                        printf("Lista en orden descendente es: %d", aux->valor);
                        aux = aux->ant;
                }
        printf("\n\n");
        }
     
}


void mostrarAsc(lista *list){
        celda *aux;
        if(aux == NULL){
                printf("La lista esta vacia");
        }else {
                ordenar(list);
                aux = list->head;
                while(aux != NULL){
                        printf("Lista en orden descendente es: %d", aux->valor);
                        aux = aux->sig;
                }
        printf("\n\n");
        }
     
}


void buscar(lista *list){
        celda *aux;
        int valor;
        aux = list->head;
        printf("Dame el valor a buscar: ");
        scanf("%d", &valor);
        while(aux != NULL){
                if(aux->valor == valor){
                        break;
                }
                aux = aux->sig;
        }
        if(aux != NULL){//comprobacion salida del bucle
                printf("El valor buscado se encuentra en la lista");//el valor esta en la lista
        }else{
                printf("El valor buscado no se encuentra en la lista");//el valor buscado no se encuentra en la lista 
        }
}

/*Para poder mostrar la lista en orden ascendente como descendiente 
anteriormente ordenamos anteriormente la lista
-Como tenemos dos puneteros, una apuntando al primer elementoy otro al ultimo
simplemente mostramos la lista cade vez empezando desde esos punteros
*/
/*Notas:
        -Si elimino un elemento y posteriormente muestro el orden desdendente 
        entoces me aparece un cero en lugar del elemento eliminado
*/