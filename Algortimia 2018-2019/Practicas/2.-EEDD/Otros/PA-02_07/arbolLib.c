#include <stdlib.h>
#include <stdio.h>
#include "arbolLib.h"
//suponenmos
//direc     variable    valor
//0x100     arbol       0x200
//0x200     celda       8-null-NULL

//llamada       &Arbol
//func insertar(0x100,6)
//*cabecera = 0x100 = 0x200 valor
//
/*******************Funciones Declaracoin**********/
void nuevoArbol(celda* *arbolCabecera){
    (*arbolCabecera)=NULL;
}
/**********************************************************/
void insertar(celda **cabecera, int numero){
    /*Variables*/
    celda *nuevo;
    /*Body*/
    /**Arbol vacio la cabecera apunta al nuevo**/
    if (*cabecera==NULL){
        nuevo = (celda*)malloc(sizeof(celda));
        nuevo->num = numero;
        nuevo->izda = NULL;
        nuevo->dcha = NULL;
        *cabecera=nuevo;
    }
    //caso arbol no vacio pasar al hijo correspondiente
    else{
        if ((*cabecera)->num == numero){
            printf("El nuemro ya esta en el arbol\n");
        }
        else{
            if((*cabecera)->num > numero){
            insertar(&((*cabecera)->izda),numero);
            }
            else{
                insertar(&((*cabecera)->dcha),numero);
            }
        }
    }
}
/*******************************************************************************/
void inOrden(celda* ptrArbol){ 
   ///si el Arbol no esta vacio, entonces recorrelo
   if (ptrArbol != NULL){
      inOrden( ptrArbol->izda );
      printf( "%d ", ptrArbol->num );
      inOrden( ptrArbol->dcha );
   }
}
/*********************************************************************************/
void postOrden(celda* cabecera){
	if (cabecera != NULL){
        postOrden(cabecera->izda);
		postOrden(cabecera->dcha);
		printf("%d ",cabecera->num);
	}
}/* Otro Algoritmo para post orden
void anchura(celda* cabecera){
	///Body
    if (cabecera == NULL){
        printf("El arbol es vacio\n");
    }
    else{
        if (cabecera->izda != NULL){
            anchura(cabecera->izda);
        }
        if (cabecera->dcha != NULL){
            anchura(cabecera->dcha);
        }
        printf("%d ",cabecera->num);
    }
}*/
/********************************************************************************/
void  profundida(celda* cabecera) {
    ///Body
    if (cabecera == NULL){
        printf("El arbol es vacio\n");
    }
    else{
        printf("%d ",cabecera->num);
        if (cabecera->izda != NULL){
            profundida(cabecera->izda);
        }
        if (cabecera->dcha != NULL){
            profundida(cabecera->dcha);
        }
    }
}
/******************************************************************************/
void anchura(celda* cabecera){
	///Body
    if (cabecera == NULL){
        printf("El arbol es vacio\n");
    }
    else{
        if (cabecera->izda != NULL){
            anchura(cabecera->izda);
        }
        if (cabecera->dcha != NULL){
            anchura(cabecera->dcha);
        }
        printf("%d ",cabecera->num);
    }
}
/*****************************************************************************/
void borrar(celda **cabecera, int numero){
    ///Variables
    celda* aux;
    ///Body
    if (*cabecera == NULL)
        return;
    if ((*cabecera)->num == numero){
        //borrar
        if (((*cabecera)->izda == NULL) && ((*cabecera)->dcha == NULL)){
            //El elemento a eliminar es una hoja
            //Simplemente elimino el nodo
            free(*cabecera);
            *cabecera = NULL;
        }
        else if ((*cabecera)->izda== NULL){
            //El elemento a eliminar solo tine un hijo
            //El padre del elemento se convierte en padre del hijo del elemento
            aux = *cabecera;
            *cabecera = (*cabecera)->dcha;
            free(aux);
        }
        else if ((*cabecera)->dcha == NULL){
            //El elemento a elminar solo tiene un hijo
            //El padre del elemento se convierte en  padre del hijo del elemento
            aux = *cabecera;
            *cabecera = (*cabecera)->izda;
            free(aux);
        }
        else{
            //El elemento a elminar tiene dos hijos
            //Busco el sucesor del elemento a eliminar (elemento mas pequeño del subrbol derecho)
            celda* suc = sucesor((*cabecera)->dcha);
            //Coloco el suceso en la posicion del elemento
            (*cabecera)->num = suc->num;
            //elimino el sucesor de su posicion original
            borrar(&((*cabecera)->dcha),suc->num);
        }
    }
    else if ((*cabecera)->num > numero)
            borrar(&((*cabecera)->izda),numero);
        else
            borrar(&(*cabecera)->dcha,numero);
}
/*************************************************************************************************/
celda* sucesor(celda* cabecera){
    //elemento más pequeño del Arbol del subarbol hijo derecho
    if (cabecera->izda == NULL)
        return cabecera;
    else
        return sucesor(cabecera->izda);
}
