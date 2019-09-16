//Nombre del programa: Prims Algorithm
//Developer: Ruben Cherif
//NIE: 121871
//User: Pichulon14
//Normas de estilo: http://www.lcc.uma.es/~tutor-fi/normasC.html

//Librerias std C
#include<stdio.h>
#include<stdlib.h>
#include <limits.h> 
#include<stdbool.h> 

#define TRUE 1
#define FALSE 0

//Declaracion de funciones 

//Se encarga de crear la matriz de adyacencia y la lista de banderines
void readGraph(int numVertex, bool flagList[numVertex], int adyMatrix[numVertex][numVertex]);

//Calcula MSB mediante el algoritmo de Prim
void prim(int numVertex, bool flagList[numVertex], int adyMatrix[numVertex][numVertex]);

//Muestra una matriz por pantalla, en este caso de adyacencia
void mostrarAdyMatrix(int numVertex, int adyMatrix[numVertex][numVertex]);

/****************************************************************/
/********************Prims Algorithm*****************************/
/***********************ByPichulon*******************************/
/****************************************************************/

//Porgrama Principal
void main(int argc, char *argv[]){
	
	int numVertex;
	//Leemos el numero de nodo por teclado mediante argv (mas eficiente)
	if(argc == 2){
		printf("Nombre del programa: %s\n", argv[0]);
		numVertex = atoi(argv[1]);
	}else{
		printf("Pinfloi, espabilas o klk?\n");
	}

	//Lista de banderines para saber si el el nodo i-esimo ya esta incluido o no en la solucion
	bool flagList[numVertex];

	//Matriz de adyacencia
	int adyMatrix[numVertex][numVertex];	

	//Leemos el grafo introducido por el usuario 
	readGraph(numVertex, flagList, adyMatrix);

	//Mostramos matriz de adyacencia del grafo introducido
	mostrarAdyMatrix(numVertex, adyMatrix);

	//Ejecutamos algoritmo
	prim(numVertex, flagList, adyMatrix);

	//Mostramos la matriz de adyacencia de nuestro MSB
	mostrarAdyMatrix(numVertex, adyMatrix);
}

void readGraph(int numVertex, bool flagList[numVertex], int adyMatrix[numVertex][numVertex]){

	
	//Rellenamos el vector con 0, todavia no hay ningun elemento excepto el caso base 
	//Rellenamos diagonal de la matriz con 1000 (null)
	for (int i = 0; i < numVertex; ++i){
		flagList[i] = FALSE;
		adyMatrix[i][i] = 1000;
	}

	//Caso base 
	flagList[0] = TRUE;

	//Rellenamos nuestra matriz de adyacencia
	printf("Por cada arista introduce su peso (1000 si no existe)\n");
	for (int i = 0; i < numVertex - 1; ++i)
		for (int j = i + 1; j < numVertex; ++j){
			printf("Introduce el peso de la arista %d - %d:\t", i, j);
			scanf("%d", &adyMatrix[i][j]);	
			adyMatrix[j][i] = adyMatrix[i][j];
		}
	printf("\n");
	}


void prim(int numVertex, bool flagList[numVertex], int adyMatrix[numVertex][numVertex]){

	//Poenmos el minimo como el entero maximo 
	int min;//***///

	//Varible para saber cuando finalizar
	int edgesRec = 0;

	//Almacena el coste del arbol recubridor de coste minimo 
	int coste  = 0;

	//Variables auxiliares para poder guardar los nodos del minimo peso encontrado
	int node1, node2;

	printf("Albol recubrido de coste minimo\n\n");

	while(edgesRec < numVertex - 1){

		min = INT_MAX;

		for (int i = 0; i < numVertex - 1; ++i)
			for (int j = i + 1; j < numVertex; ++j)
				if( (flagList[i] == TRUE) && (flagList[j] == FALSE) && (adyMatrix[j][i] < min) && (adyMatrix[j][i] != 1000)){
					min = adyMatrix[j][i];
					node1 = j;
					node2 = i;
				}
		coste += adyMatrix[node1][node2];
		printf("Arista %d - %d, de coste %d, y coste parcial de la solucion %d\n\n", node2, node1, adyMatrix[node1][node2], coste);
		//Ponemos el vertice añadido como TRUE
		flagList[node1] = TRUE;

		//Eliminamos el vertice añadido a la solucion
		adyMatrix[node1][node2] = 1000;
		adyMatrix[node2][node2] = 1000;

		edgesRec++;
	}
}


void mostrarAdyMatrix(int numVertex, int adyMatrix[numVertex][numVertex]){

	for (int i = 0; i < numVertex; ++i)
	{
		for (int j = 0; j < numVertex; ++j)
			printf("| %d\t", adyMatrix[i][j]);
		
		printf("|\n");
	}
	printf("\n");
}