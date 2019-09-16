
//Algortimo de Kruskal para MSB


#include<stdio.h> 
#include<stdlib.h>

typedef struct edge{
	int origen;
	int destino;
	int peso;
}Edge;

void sortVertexList(int nEdge, Edge edge, Edge vertexList[nEdge]);
void kruskal(int nEdge, Edge vertexList[nEdge], int nVertex);

void main(int argc, char const *argv[])
{

	system("clear");

	//Numero de vertices y aristas del grafo 
	int nVertex;
	int nEdge;

	//Creamos una variable de tipo Edge: origen, destino, peso
	Edge edge;

	printf("Introduce el nuemero de vertices:\t\n");
	scanf("%d", &nVertex);

	printf("Introduce el numero de aristas:\t \n");
	scanf("%d", &nEdge);

	//Lista donde almacenaremos las aritas del grafo
	Edge vertexList[nEdge];

	printf("Introduce para cada arista el origen, destino y peso \n");
	
	int i = 0;

	while(i < nEdge){
		scanf("%d %d %d", &edge.origen, &edge.destino, &edge.peso);
		vertexList[i] = edge;
		i++;
	}

	sortVertexList(nEdge, edge, vertexList);
	kruskal(nEdge, vertexList, nVertex);
	
}

	void sortVertexList(int nEdge, Edge edge, Edge vertexList[nEdge]){
		//Ponemos como minimo el primer elemento del vector

		//varible para el swap
		Edge x;
		for (int i = 0; i < nEdge-1; ++i)
			for (int j = 0; j < nEdge-i-1; ++j)
				if(vertexList[j].peso > vertexList[j+1].peso){
					x = vertexList[j];
					vertexList[j] = vertexList[j+1];
					vertexList[j+1] = x;
				}
			printf("\n");
			for (int i = 0; i < nEdge; ++i)
			{
				printf("Arista: (%d, %d) de peso: %d\n", vertexList[i].origen,vertexList[i].destino, vertexList[i].peso);
			}
			printf("\n");
	}


	void kruskal(int nEdge, Edge vertexList[nEdge], int nVertex){
		//Lista que contiene los vertices 
		int flagsList[nEdge];

		int coste = 0;

		//Llenamos nuestro vector con los vertices
		for (int i = 0; i < nVertex; ++i)
			flagsList[i] = i;

		for (int i = 0; i < nEdge; ++i){

			if(flagsList[vertexList[i].destino] == vertexList[i].destino){
				printf("Arista: %d - %d, de peso: %d\n", vertexList[i].origen, vertexList[i].destino, vertexList[i].peso);
				
				for (int j = 0; j < nVertex; ++j)
					if(flagsList[j] == vertexList[i].destino)
						flagsList[j] = vertexList[i].origen;

				/*flagsList[vertexList[i].destino] = flagsList[vertexList[i].origen];*/
				coste += vertexList[i].peso;
			}
		}
		printf("\n");
		printf("El coste total del MSB es: %d\n\n", coste);
	}