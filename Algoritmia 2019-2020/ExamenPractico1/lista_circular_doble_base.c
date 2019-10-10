#include<stdio.h>
#include<stdlib.h>

typedef struct celda{
	int num;
	struct celda *sig;
	struct celda *ant;
}celda;

void insertar( celda **lista, int valor);
void mostrar_ascendentemente(celda *lista, int valor);
void mostrar_descendentemente(celda *lista, int valor);

main(){
	celda *lista = NULL;
	printf("Introduce numeros naturales. 0 para terminar\n");
	int n;
	scanf("%d",&n);
	while(n!=0){
		insertar(&lista,n);
		scanf("%d",&n);
	}
	printf("Introduce un número a partir del que mostrar ascendente: ");
	scanf("%d",&n);
	mostrar_ascendente(lista,n);
	printf("\nIntroduce un numero a partir del que mostrar descendente: ");
	scanf("%d",&n);
	mostrar_descendente(lista,n);
	system("pause");
}

void insertar( celda **list, int valor){
     
     celda *aux;
     aux = (celda*)malloc(sizeof(celda));
     
     aux->num = valor;
     aux->sig = aux;
     aux->ant = aux;
     
     if (*list == NULL )       /* La lista esta vacia*/
        *list = aux;
     else if((*list)->num > valor){         /*Elemento a insertar menos que el primero en la lista */
          aux->sig = *list;
          aux->ant = *list;
          (*list)->ant = aux;
          (*list)->sig = aux;
          *list = aux; 
     }else{
           int fin = (*list)->ant->num;   /*Para saber el final de la lista*/
            
          celda *rec;  /*Puntero para recorrer la lista*/
          rec = (celda*)malloc(sizeof(celda));
          
          rec = *list;
          while( rec->sig->num != fin && aux->num >= rec->sig->num){
                 rec = rec->sig;
          }
          if (rec->sig->num == fin){  /*Insercion al final de la lista */
             aux->sig = *list;
             aux->ant = rec;
             rec->sig = aux;
             (*list)->ant = aux;
          }else{  /* Insrecion entre medias de la lista */
             aux->sig = rec->sig;
             aux->ant = rec;
             rec->sig->ant = aux;
             rec->sig = aux;   
          }
}
           
           void mostrar_ascendente(celda *list, int valor){
                if( list == NULL)
                    printf("La lista esta vacia");
                if( valor < list->num)
                    printf("El valor no esta en la lista");
                if(valor > (list->ant->num))
                       printf("El valor no esta en la lista");
                else{
                     int aux = list->ant->num;
                     celda *rec;
                     rec = list;
                     while(rec->num != valor && rec->num != aux){
                         rec = rec->sig;
                     }
                     if (rec->num == aux)
                             printf("El valor no se encuentra en la lista");
                     else if(rec->num = valor){
                          rec = rec->sig;
                          while( rec->num != aux){
                                 printf("%d", rec->num);
                                 rec = rec->sig;
                          }
                }
           }
                  
            void mostrar_descendente(celda *list, int valor){
                if( list == NULL)
                    printf("La lista esta vacia");
                if( valor < list->num)
                    printf("El valor no esta en la lista");
                if(valor > (list->ant->num))
                       printf("El valor no esta en la lista");
                else{
                     int aux = list->num;/*Para saber cuando finaliza nuestra lista*/
                    
                     celda *rec;
                     rec = list->ant;
                     while(rec->num != valor && rec->num != aux){
                         rec = rec->ant;
                     }
                     if (rec->num == aux)
                             printf("El valor no se encuentra en la lista");
                     else if(rec->num = valor){
                          rec = rec->ant;
                          while( rec->num != aux){
                                 printf("%d", rec->num);
                                 rec = rec->ant;
                          }
                    }
                }
                }
                     
          
             
             
                       
          
     
     
     
     
