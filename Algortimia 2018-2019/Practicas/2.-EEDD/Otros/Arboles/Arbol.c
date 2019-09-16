//Nombre del programa: arbol.c
//Autor: Ruben Cherif Narvaez
//NIA: 121871
//Entorno de desarrollo: Linux Ubuntu 18.04 LTS
//Compilador: Gcc/g++
//Estilo programacion: GNOME
//Descripcion...
//*********************************************

//Librerias
#include <stdio.h>
#include <stdlib.h>

//Estructuras 
typedef struct arbol{
        int valor;
        struct arbol *izq;
        struct arbol *der;
} arbol;

//Declaracion de funciones 
void pideinsertar(arbol **c);

void insertar(arbol **c, arbol *aux);

void pidebuscar(arbol *c);

void buscar(arbol *c, int valor);

void profundidad(arbol *c);

void preOrden(arbol *c);

void inOrden(arbol *c);

void postOrden(arbol *c);

void mostrar(arbol *c);

int vacio(arbol* c);

int EsHoja(arbol *c);

void infoprogram();

int menu();

//Programa Principal
void main(){
        infoprogram();
        arbol *c;
        int men;
        c = NULL;
        do{
                men = menu();
                switch(men){
                        case 1: pideinsertar(&c);
                                break;
                        case 2: pidebuscar(c);
                                break;
                        case 3: exit(0);
                                break;
                        case 4: mostrar(c);
                                break;
                        case 5: printf("%d\n", vacio(c));
                                break;
                        case 6: printf("%d\n", EsHoja(c)); 
                                break;
                        }
                }while(1);
}


void mostrar(arbol *c){
    printf("preOrden\n");
    preOrden(c);
    printf("inOrden\n");
    inOrden(c);
    printf("postOrden\n");
    postOrden(c);
    printf("profundidad\n");
    profundidad(c);
}

//Definicion de fucniones 
int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1- Insertar elemento\n");
        printf("2- Buscar elemento\n");
        printf("3- Salir\n");
        do{
                 scanf("%d",&op);
        }while(op<1 || op>6);
        return(op);
}

void infoprogram(){
        printf("Nombre del programa: arbol.c\n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Descripcion: pereza...\n");
        printf("\n\n");
}

void pideinsertar(arbol **c){
        int val;
        arbol *aux;
        printf("Dame el valor a insertar: ");
        scanf("%d", &val);
        aux = (arbol*)malloc(sizeof(arbol));//reserva memoria
        aux->valor = val;
        aux->izq = NULL;
        aux->der = NULL;
        insertar(c, aux);
}

/*
funcion recursiva insertar: buscamos el elemento hasta encontrarlo de forma recursiva,
si no esta lo insertamos correctamente
*/
void insertar(arbol **c, arbol *aux){
        if (*c == NULL) {//arbol vacio
                (*c) = aux;
        } else if ((*c)->valor == aux->valor){
                printf("El valor ya esta en el arbol");
        } else if ( ((*c)->valor) > (aux->valor) ){// buscamos en la rama derecha
                insertar(&(*c)->izq, aux );
        } else if ( ((*c)->valor) < (aux->valor)){// buscamos en la rama izquierda
                insertar(&(*c)->der, aux);
        }
        printf("\n");
}


void pidebuscar(arbol *c) {
        int valor;
        printf("Dame el valor a buscar: ");
        scanf("%d", &valor);
        buscar(c, valor);
}


void buscar(arbol *c, int valor) {
        if (c == NULL) {//arbol vacio
                printf("El valor buscado no esta en el arbol\n\n");
        } else if (c->valor == valor){
                printf("El valor esta en el arbol\n\n");
        } else if (c->valor > valor){
                buscar(c->izq, valor);
        } else if (c->valor < valor){
                buscar(c->der, valor);
        }
}

/*Notas:
        -Si vamos a insertar un elemento, siempre necesitaremos una variable aux para poder almacenar el...
        ...valor a introducir en ella
        -En los arboles siempre utilizaremos funciones recursivas 
*/
void profundidad(arbol *head){
    if (head == NULL){
        printf("El arbol se encuentra vacio\n");
    }else{
        printf("%d\n", head->valor);
        if(head->izq != NULL)
            profundidad(head->izq);
        if(head->der != NULL)
            profundidad(head->der);
    }
}


void inOrden(arbol *head){
    if(head != NULL){
        inOrden(head->izq);
        printf("%d", head->valor);
        inOrden(head->der);
    }else{
        return;
    }
}


void postOrden(arbol *head){
    if(head != NULL){
        postOrden(head->izq);
        postOrden(head->der);
        printf("%d\n", head->valor);
    }else{
        return;
    }
}



void preOrden(arbol *head){
    if(head != NULL){
        printf("%d\n", head->valor);
        preOrden(head->izq);
        preOrden(head->der);
    }else{
        return;
    }
}

int vacio(arbol* head){
    return head == NULL;
}

int EsHoja(arbol *head)
{
   return !head->der && !head->izq;
}