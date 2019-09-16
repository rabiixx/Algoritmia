typedef struct celda{
    int num;
    struct celda *izda ;
    struct celda *dcha ;
}celda;
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
