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

//Estructuras
typedef struct celda
    {
        int valor;
        struct celda *sig;
    } celda;

//Variables de recorrido de la cola
typedef struct cola
    {
        struct celda *head;//Cabecera: siempre apunta al primer elemento de la cola
        struct celda *last;   //"last" siempre apunta al ultimo elemento de la cola
    } cola;

//Declaracion funciones 
void insertar(cola *c);
void eliminar(cola *c);
void mostrar(cola *c);
void buscar(cola *c);
int menu();
void vaciar(cola *c);
int estaVacia();
void infoprogram();

//Programa Principal
void main(){
        system("clear");
        infoprogram();
        cola *c;
        int men;
        c = (cola*)malloc(sizeof(cola));
        c->head = NULL;
        c->last = NULL;
        do{
        men = menu();
        switch(men){
                case 1: insertar(c);
                        break;
                case 2: eliminar(c);
                        break;
                case 3: mostrar(c);
                        break;
                case 4: buscar(c);
                        break;
                case 5: exit(0);
                         break;
                case 6: vaciar(c);
                        break;
                case 7: estaVacia(c);
                        break;
                default: printf("Opcion erronea\n");
                        break;
                }
        }while(1);
}


//Definicion de funciones 
void infoprogram(){
        printf("Nombre del programa: cola.c\n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Entorno de desarrollo: Linux Ubuntu 18.04 LTS\n");
        printf("Compilador: gcc\n");
        printf("Descripcion: pereza...\n");
        printf("\n\n");
}

int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1- Insertar elemento\n");
        printf("2- Eliminar elemento\n");
        printf("3- Mostrar cola\n");
        printf("4- Buscar elemento\n");
        printf("5- Salir\n");
        printf("6- Vaciar cola\n");
        printf("7- ¿Vacia?\n");
        scanf("%d", &op);
        //Agregar mensaje de error si op no se encuentra entre 1..5
        return(op);
}

//insertar: inserta un valor dado en la cola
void insertar(cola *c)
    {
        int valor;
        celda *aux;
        printf("Dame el valor a insertar: ");
        scanf("%d", &valor);
        aux = (celda*)malloc(sizeof(celda));
        aux->valor = valor;
        aux->sig = NULL;
        if (c->last /*c->head*/== NULL)//La cola esta vacia
            {
                c->head = aux;//Este sera el primer elemento de la cola
                c->last = aux;
            }
        else 
            {
                (c->last)->sig = aux;
                c->last = aux;
            }
        printf("\n");
    }

//eliminar: eliminamos el primer valor introducido(cola)
void eliminar(cola *c)
    {
        celda *aux;
        if(c->head == NULL)//la cola se encuentra vacia
            {
                printf("La cola esta vacia. Nada que eliminar\n");
            }
        else
            {
                aux = c->head;
                c->head = (c->head)->sig;
                printf("Eliminamos %d\n\n", aux->valor);
                free(aux);
            }
    }

//mostrar: nos muestras los elementos de la cola 
void mostrar(cola *c){
        celda *aux;
        aux = c->head;
        if (aux == 0)
                printf("La cola se encuentra vacia\n");
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
//buscar: buscamos si el valor introducido por el usuario se encuentra en la cola
void buscar(cola *c)
    {
        celda *aux;
        int valor;
        aux = c->head;
        printf("Dame el valor a buscar: ");
        scanf("%d",&valor);
        while(aux != 0){//no esta vacia
                if(aux->valor == valor){//Hemos encontrado el valor en la cola(1. posicion)
                        break;//salimos del while
                }
                aux = aux->sig;//c->last = (c->last)->sig 
            }
        /*Podemos salir del "while" por dos motivos:
                -1.- Hemos encontrado el valor que buscabamos
                -2.- Hemos llegado al final de la cola
        Por ello, hacemos una ultima comprobacion
        */
        if(aux != 0)//Caso en el que el elemento no se encuentras en la cola, necesitamos hacer una ultima comprobacion al salir del "while"
            {
                printf("El valor buscado esta en la cola\n");
            }
        else
            {
                printf("El valor buscado no esta en la cola\n\n");
            }
    }
void vaciar(cola *c){
        while(c->head != 0){
                eliminar(c);
        }
        return;
}


int estaVacia(cola *c){
        if (c->head == NULL){
                printf("La cola SI esta vacia\n");
                return (1);//vacia
        }else{
                printf("La cola NO esta vacia\n");
                return (0);
        }
}
