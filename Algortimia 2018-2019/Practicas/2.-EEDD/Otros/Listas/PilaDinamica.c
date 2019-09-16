#include <stdio.h>
#include <stdlib.h>
typedef struct celda{
  int valor;
  struct celda *s;
} celda;
typedef struct pila{
  struct celda *f;
} pila;
void insertar(pila *c);
void eliminar(pila *c);
void mostrar(pila *c);
void buscar(pila *c);
int menu();

void main(){
  pila *c;
  int men;
  c=(pila*)malloc(sizeof(pila));
  c->f=NULL;
  do{
    men=menu();
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
    }
  }while(1);
}

int menu(){
  int op;
  printf("Elija la opcion deseada: \n");
  printf("1_ Insertar elemento\n");
  printf("2_ Eliminar elemento\n");
  printf("3_ Mostrar pila\n");
  printf("4_ Buscar elemento\n");
  printf("5_ Salir\n");
  do{
    scanf("%d",&op);
  }while(op<1||op>5);
  return(op);
}

void insertar(pila *c){
  int valor;
  celda *aux;
  printf("Dame el valor a insertar: ");
  scanf("%d",&valor);
  aux=(celda*)malloc(sizeof(celda));
  aux->valor=valor;
  aux->s=c->f;
  c->f=aux;
  printf("\n");
}

void eliminar(pila *c){
  celda *aux;
  if(c->f==NULL){
    printf("La pila esta vacia. Nada que eliminar\n");
  }else{
    aux=c->f;
    c->f=(c->f)->s;
    printf("Eliminamos %d\n\n",aux->valor);
    free(aux);
  }
}

void mostrar(pila *c){
  celda *aux;
  aux=c->f;
  printf("La pila contiene (cima-fondo): ");
  while(aux!=NULL){
    printf("%d ",aux->valor);
    aux=aux->s;
  }
  printf("\n\n");
}

void buscar(pila *c){
  celda *aux;
  int valor;
  aux=c->f;
  printf("Dame el valor a buscar: ");
  scanf("%d",&valor);
  while(aux!=NULL){
    if(aux->valor==valor){
      break;
    }
    aux=aux->s;
  }
  if(aux!=NULL){
    printf("El valor buscado esta en la pila\n");
  }else{
    printf("El valor buscado no esta en la pila\n\n");
  }
}

