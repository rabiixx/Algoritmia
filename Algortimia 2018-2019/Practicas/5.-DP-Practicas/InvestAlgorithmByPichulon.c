//Algoritmo de mejor Inversion

//Librerias esatandar C/C++
#include<stdio.h>
#include<stdlib.h>
#include <limits.h> 

//Muestra por pantalla la matriz que se le indique
void showMatrix(int nBancos, int mil, int matrix[mil][nBancos]);

//Se enacarga leer y completar las matrices 
void readMatrix(int nBancos, int mil, int userMatrix[mil][nBancos], int newMatrix[mil][nBancos]);

//Algortimo Invest
void invest(int nBancos, int mil, int userMatrix[mil][nBancos], int newMatrix[mil][nBancos]);

//Programa Principal
void main(int argc, char const *argv[]){
	
	if(argc != 1){
		perror("Has introducido mal los datos");
		exit(1);
	}

	system("clear");

	int nBancos, nDinero;

	printf("Introduce el numero de bancos:\t");
	scanf("%d", &nBancos);
	printf("\n");

	printf("Introduce el dinero que desea invertir:\t ");
	scanf("%d", &nDinero); 
	printf("\n");

	int mil = (nDinero / 1000) + 1;
	int userMatrix[mil][nBancos];
	int newMatrix[mil][nBancos];
	
	readMatrix(nBancos, mil, userMatrix, newMatrix);
	
	printf("Matriz introducida por el usuario:\n\n");
	showMatrix(nBancos, mil, userMatrix); 
	
	invest(nBancos, mil, userMatrix, newMatrix);

	printf("Matriz construida: \n\n");
	showMatrix(nBancos, mil, newMatrix);

}


void invest(int nBancos, int mil, int userMatrix[mil][nBancos], int newMatrix[mil][nBancos]){

	//Para guardar el maximo en cada caso
	int max;

	//Rellenamos la matriz por columnas
	for (int i = 1; i < nBancos + 1; ++i)
		for (int j = 1; j < nBancos; ++j){
			max = 0;
			for (int r = 0; r < i + 1; ++r)
				if( (userMatrix[r][j] + newMatrix[i - r][j - 1]) > max)
					max = userMatrix[r][j] + newMatrix[i - r][j - 1];
			newMatrix[i][j] = max;
		}
}


void showMatrix(int nBancos, int mil, int matrix[mil][nBancos]){
	
	for (int i = 0; i < nBancos; ++i){
		for (int j = 1; j < mil; ++j)
			printf("%d\t", matrix[j][i]);
		printf("\n");
	}
	printf("\n");
}


void readMatrix(int nBancos, int mil, int userMatrix[mil][nBancos], int newMatrix[mil][nBancos]){

	//Rellenamos la primera columna de newMatrix y userMatrix con ceros
	for (int i = 0; i < nBancos ; ++i){
		userMatrix[0][i] = newMatrix[0][i] = 0;
	}

	//Leemos las matriz introducida por el usuario 
	for (int i = 0; i < nBancos; ++i){
		printf("Introduce los beneficios del banco %d:\n\n", i + 1);
		for (int j = 1; j < mil; ++j)
			scanf("%d", &userMatrix[j][i]);
		printf("\n");
	}

	//Caso base: la primera fila de newMatrix es igual a la de userMatrix 
	for (int i = 1; i < mil; ++i)
		newMatrix[i][0] = userMatrix[i][0];

}










