#include<stdio.h>
#include<stdlib.h>

typedef struct celda{
	int num;
	struct celda *izda;
	struct celda *dcha;
	struct celda *centro;
}celda;

void insertar(celda **arbol, int valor);
void mostrar(celda *arbol);
void imprimir_suc_pre(celda *arbol, int valor);
void buscar(celda *arbol);
celda *antecesor(celda *arbol);
celda *sucesor(celda *arbol);
void esHoja(celda *arbol);


main(){
	celda *arbol=NULL;
	printf("Introduce numeros naturales. 0 para terminar\n");
	int n;
	scanf("%d",&n);
	while(n!=0){
		insertar(&arbol,n);
		scanf("%d",&n);
	}
	printf("Wl contenido del arbol es:\n");
	mostrar(arbol);
	printf("Introduce un numero: ");
	scanf("%d",&n);
	imprimir_suc_pre(arbol,n);
	system("pause");
}

void insertar(celda **a, int valor){
     celda *aux;
     aux = (celda*)malloc(sizeof(celda));
     
     aux->num = valor;
     aux->izda = NULL;
     aux->dcha = NULL;
     aux->centro = NULL;
     
     
     if((*a) == NULL)
             *a = aux;
     else{
          if((valor < (*a)->num) && ((*a)->izda))
                   insertarRec(&((*a)->izda), valor);
                   (*a)->izda = aux;
          if(valor > (*a)->num) && ((*a)->dcha))
                   insertarRec(&((*a)->dcha), valor);
                   (*a)->dcha = aux;
          if(valor == (*a)->num)
                   (*a)->centro == aux;
          
          
/*Nota: cualquier nodo del centro(menos el primero) no tiene hijo izq ni der*/
        void  mostrar(celda *a){
              int cont = 0; /*Cuenta el numero de nodos repetidos*/
              
              if (a->izq)
                 mostrar(a->izq);
              if (a->centro )
                 cont++;    /*Si tiene centro le sumamos uno */
                 mostrar(a->centro)
              print(" %d %d ", a->num, cont); 
              cont = 0;
              if (a->der)
                 mostrar(a->der);
              }
          
          void imprimir_suc_pre(celda *a, int valor)
               buscar(a, valor);
               if(esHoja(a))
                             print("El nodo no tiene hijo izquierdo y derecho
               else{
                    celda *aux1  = sucesor((*a)->der);
                    celda *aux2 = antecesor((*a)->izq);
                    printf("Su antecesor es %d y su sucesor %d", aux1->num, aux2->num);
                    
                    
          void sucesor(celda *a){
               if(!(a->izda))
                             return a;
               else if(a->izda){
                    sucesor(a->izda);
          }
                         
          void antecesor(celda *a){
               if(!(a->dcha))
                            return a;
               else if (a->dcha)
                    antecesor(a->dcha);
                         
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
     
     
