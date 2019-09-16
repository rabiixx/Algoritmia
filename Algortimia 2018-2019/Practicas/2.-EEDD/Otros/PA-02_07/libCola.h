#include <stdlib.h>
#include <stdio.h>
typedef struct celda{
    int num;
    struct celda *izda ;
    struct celda *dcha ;
}celda;
typedef struct cola{
    struct celdaCola *ini,*fin;
}cola;
typedef struct celdaCola{
    celda* dat;
    struct celdaCola *sig;
}celdaCola;
/*Funciones*/
int esNulaCola(cola *c);
/*******************************************/
celda* primero(cola *c);
/********************************************/
void avance(cola **c);
/*******************************************/
void pideTurno(cola **c, celda* elem);
/*************************************/
void nuevaCola(cola **c);
/*********************************************************/
/*Funciones*/
void nuevoArbol(celda* *arbolCabecera);
/******************************************/
void anchura(celda* cabecera);
/****************************************************/
void postOrden(celda* cabecera);
/*********************************************************/
void inOrden( celda* ptrArbol);
/********************************************************/
celda* sucesor(celda* cabecera);
/********************************************************/
void borrar(celda **cabecera, int numero);
/***************************************************/
void insertar(celda **cabecera, int numero);
/*************************************************/
void  profundida(celda* cabecera);
