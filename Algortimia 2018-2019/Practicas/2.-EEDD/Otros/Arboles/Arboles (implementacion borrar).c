#include <stdlib.h>
#include <stdio.h>

typedef struct celda{
	int num;
	struct celda *dcha;
	struct celda *izda;
}celda;

void insertar(celda** cabecera, int numero);
void profundidad(celda* cabecera);
void borrar(celda** cabecera, int numero);

celda* sucesor(celda* cabecera);

int main(){
	insertar(&arbol,8);//insertar(0x100,8)
	profundidad(arbol);
	printf("\n\n");
	borrar(&arbol,5);
	return 0;
	
}

//Programa Principal
void main(){
        infoprogram();
        celda *arbol;
        int men;
        arbol = NULL;
        do{
                men = menu();
                switch(men){
                        case 1: insertar(&arbol);
                                break;
                        case 2: profundidad(arbol);
                                break;
                        case 3: borrar(&arbol);
                        		break;
                        case 4: exit(0);
                                break;
                        }
                }while(1);
}

//Definicion de fucniones 
int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1- Insertar elemento\n");
        printf("2- Recorrido en profundidad\n");
        printf("3- Borrar un elemento\n");
        printf("4- Salir\n");
        do{
                 scanf("%d",&op);
        }while(op<1 || op>3);
        return(op);
}

void infoprogram(){
        printf("Nombre del programa: arbol.c\n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Descripcion: pereza...\n");
        printf("\n\n");
}


void insertar(celda** cabecera, int numero){
	if (*cabecera==NULL){

		celda *nuevo;
		nuevo=(celda*)malloc(sizeof(celda));

		nuevo->num=numero;
		nuevo->izda=NULL;
		nuevo->dcha=NULL;

		*cabecera=nuevo;//0x100 valor almacenado en 0x100
	}
	else
		if (numero < (*cabecera)->num)
		//*cabecera=*0x100=0x200(es una direccion)
		//*cabecera->num = *(cabecera->num)
		//*cabecera 0 arbol
		//arbol->num(asi si) = (+cabecera)->num
			insertar( &((*cabecera)->izda),numero);
			// &(*cabecera)->izda= (&(*cabecera))->izda	
		
	else
		if (numero>(*cabecera)->num)
			insertar(&((*cabecera)->dcha),numero);
	else
		printf("El numero ya esta en el arbol.\n");
}

void profundidad(celda *cabecera){
	if(cabecera==NULL){
		printf("Arbol vacio\n");
	}
	else{
		if (cabecera->izda !=NULL)
			profundidad(cabecera->izda);
		printf("%d\n",cabecera->num);
		if(cabecera->dcha!=NULL)
			profundidad(cabecera->dcha);
	}
}

void borrar(celda** cabecera, int numero){
	if (*cabecera==NULL)
		printf("Error, no hay elementos para borrar.!!\n");
	else{
		//Se trata de realizar una busqueda del elemento en el arbol
		if (numero < (*cabecera)->num)
			borrar(&((*cabecera)->izda),numero);
		else if (numero > (*cabecera)->num)
			borrar(&((*cabecera)->dcha),numero);
		else if (numero == (*cabecera)->num){
		/*Una vez encontrado el elemento habra que analizar el caso:
		-Caso 1: Borrar nodo sin hijos
		-Caso 2: Borrar un nodo con un subarbol hijo(izq o der)
		-Caso 3: Borrar un nodo con dos subarboles hijos + Caso1 o Caso2
		*/	if (((*cabecera)->dcha==NULL) && (((*cabecera)->izda)==NULL)){

				free(*cabecera);
				*cabecera=NULL;

			}else if ((*cabecera)->izda==NULL){

				celda* aux;
				aux = *cabecera;
				*cabecera = (*cabecera)->dcha; 
				free(aux);

			}else if ((*cabecera)->dcha==NULL){

				celda *aux;
				aux=*cabecera;
				*cabecera = (*cabecera)->izda;
				free(aux);
			
			}else{ //2 hijos-->Busco el sucesor del elemento a eliminar(elemento + pequeño del subárbol hijo derecho)

				celda* suc = sucesor((*cabecera)->dcha);
				//	Coloco el sucesor en la posición del elemento a eliminar
				(*cabecera)->num = suc->num;
				//	Elimino el sucesor de su posición original
				borrar(&((*cabecera)->dcha),suc->num);
			}
		}
	}
}

//Funcion para buscar el sucesor del que eliminaremos: elemento mas a la izq del subarbol del elemento a eliminar
celda* sucesor(celda* cabecera){
	//elemento mas pequeño del subárbol hijo derecho(no tiene hijo subarbol en la izq)
	if (cabecera->izda == NULL)
		return cabecera;
	else
		return sucesor(cabecera->izda);
	
}
			
		
		
