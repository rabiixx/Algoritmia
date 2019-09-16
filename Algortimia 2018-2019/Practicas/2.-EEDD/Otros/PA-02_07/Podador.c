#include "libCola.h"
#include <stdlib.h>
#include <stdio.h>
/*Funciones*/
/**********************************/
void borrarFamilia(celda **celda, int v[], int dimension);
/**********************************/
void quintos(celda* nodo, int a, int amin, int v[], int *y);
/*************************************************/
int AlturaArbol(celda* a, int *altura,  int *hmin);
/******************************************/
void auxAltura(celda* nodo, int a, int *alturam,  int **alturamin);
/*******************************/
void recorridoAnchura(celda* Tree);
/****************************************/
void calcula(int *aux,int max, int min);
/************************************/
int EsHoja(celda* r);
/*****************************************/
int semiHoja(celda* bin);
//Main Program
int main(){
	///Varaibles
	int n,himax,himin,dom;
	int *vec;
	char ver;
	celda* Arbolbin;
	///Body
	do{
		nuevoArbol(&Arbolbin);
		printf("Introduce el la cantidad de valores: ");
		scanf("%d", &n);
		vec=(int*)malloc(n*sizeof(int));
		printf("Introduce los valores: ");
		for (int i=0; i<n; i++){
			scanf("%d", &vec[i]);
		}
		for (int i=0; i<n; i++){
			insertar(&Arbolbin,vec[i]);
		}
		free(vec);
		printf("\n");
		printf("El arbol en profundidad es \n");
		profundida(Arbolbin);
		printf("\n");
		printf("El arbol en In-Orden es es\n");
		inOrden(Arbolbin);
		printf("\n");
		printf("\n");
		AlturaArbol(Arbolbin,&himax,&himin);
		printf("La altura maxima del arbol es %d\n", himax);
		printf("La altura minima del arbol es %d\n", himin);
		printf("\n");
		///
		dom=0;
		calcula(&n,himax,himin);
		vec=(int*)malloc(n*sizeof(int));
		quintos(Arbolbin,1,himin,vec,&dom);
		///PoDaDo
		borrarFamilia(&Arbolbin,vec,dom);
		free(vec);
		///
		//recorridoAnchura(Arbolbin);
		printf("El arbol en profundidad es \n");
		profundida(Arbolbin);
		printf("\n");
		printf("El arbol en In-Orden es es\n");
		inOrden(Arbolbin);
		printf("\n");
		printf("Desea repetir el proceso, s \\ n ?  ");
		scanf("%*c %c", &ver);
		printf("_____________________________________________\n");
		printf("\n");
	}while (ver == 's');
	///
}
/**************************************/
void borrarFamilia(celda **celda, int v[], int dimension){
	if (dimension > 0){
		printf("Los nodos a eliminar son: \n");
		for (int i=0; i<dimension; i++)
			printf("%d ",v[i]);
		printf("\n");
		for (int i=0; i<dimension; i++)
			borrar(&(*celda),v[i]);
	}
	else {
		printf("No hay nada que podar\n");
		printf("\n");
	}
}
/***********************************************/
void quintos(celda* nodo, int a, int amin, int v[], int *y)
{
	/* Recorrido postorden */
	if(nodo->izda)
		quintos(nodo->izda, a+1,amin,v,y);
	if(nodo->dcha)
		quintos(nodo->dcha, a+1,amin,v,y);
	/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
		árbol, actualizamos la altura actual del árbol */
	if(a > amin){
		v[*y]=nodo->num;
		*y = (*y)+1;
		}
		
}
/*************************************************/
int AlturaArbol(celda* a, int *altura, int *hmin)
{	if (a != NULL){
		*altura = 1;
		*hmin=32000;
		auxAltura(a, 1, altura,&hmin); /* Función auxiliar */
		return *altura;
	}
	else{
		*hmin=0;
		return *altura = 0;
	}
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(celda* nodo, int a, int *alturam, int **alturamin)
{
	/* Recorrido postorden */
	if(nodo->izda)
		auxAltura(nodo->izda, a+1, alturam,alturamin);
	if(nodo->dcha)
		auxAltura(nodo->dcha, a+1, alturam,alturamin);
	/* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
		árbol, actualizamos la altura actual del árbol */
	if(EsHoja(nodo) && a > *alturam)
		*alturam = a;
	if(semiHoja(nodo) && a < *(*alturamin))
		*(*alturamin) = a;
}
int semiHoja(celda* bin){
	return !(bin->dcha) || !(bin->izda);
}
/****************************************************/
int EsHoja(celda* r)
{
   return !(r->dcha) && !(r->izda);
}
/****************************************************/
void recorridoAnchura(celda* Tree){
	///
	celda* aux;
	cola* Colabin;
	///
	printf("hola oini noin oino inon oi noinoi n  \n");
	Colabin=(cola*)malloc(sizeof(cola));
	nuevaCola(&Colabin);
	pideTurno(&Colabin,Tree);
	aux=Tree;
	//aux=(celda*)malloc(sizeof(celda));
	while (!esNulaCola(Colabin)){
		//
		//aux=primero(Colabin);
		//printf(" %d",aux->num);
		printf("holassss\n");
		avance(&Colabin);
		if (aux->izda != NULL)
			pideTurno(&Colabin,aux->izda);
		if (aux->dcha != NULL)
			pideTurno(&Colabin,aux->dcha);
	}
	free(aux);
}
void calcula(int *aux, int max, int min){
	int i,a,b;
	a=1;
	b=1;
	for (i=1; i<=min; i++)
		a=a*2;
	for (i=1; i<=max; i++)
		b=b*2;
	*aux=b-a;
}
