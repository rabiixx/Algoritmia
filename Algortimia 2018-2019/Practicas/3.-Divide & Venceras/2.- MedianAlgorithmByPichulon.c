//Recursive implementation: median of two sorted arrays of same size

//**********
//Librerias*
//**********

#include <stdio.h>
#include <stdlib.h>

//*************************
//Declaracion de Funciones*
//************************* 

// Lee dos vectores
void readList();

//Funcion recursiva del calculo de la mediana
int mediana(int dim1, int nElemV1, int dim2, int nElemV2);

// Muestra informacion sobre el programa
void infoProgram();

//********************
// Variables Globales*
//********************

int nElem;
int *list1;
int *list2;

//*******************
//Programa Principal*
//*******************

int main(){
		
	system("clear");
	
	printf("- Introduce el numero de elementos: ");
	scanf("%d",&nElem);
	printf("\n\n");

	list1 = (int*)malloc(nElem * sizeof(int));
	list2 = (int*)malloc(nElem * sizeof(int));
	
	readList();

	printf("- La mediana global es: %d\n\n", mediana(0, nElem - 1 , 0, nElem - 1));
}
	
//************************
//Definicion de funciones*
//************************

void readList(){

	printf("- Escribe los elementos del primer vector:\n\n ");
	for(int i = 0; i < nElem; ++i){
		scanf("%d", &list1[i]);
	}
	printf("\n");

	printf("- Escribe los elementos del segundo vector:\n\n ");
	for (int i = 0; i < nElem; ++i){
		scanf("%d", &list2[i]);
	}
	printf("\n");

}



int mediana(int dim1, int nElemV1, int dim2, int nElemV2){

	
	if(nElemV1 != dim1){

		int mid1 = dim1 + (nElemV1 - dim1)/2; 
		int mid2 = dim2 + (nElemV2 - dim2)/2;

		if( (nElemV1 - dim1 + 1) % 2 == 0){

			if(list1[mid1] == list2[mid2])
				return list1[mid1];

			if(list1[mid1] > list2[mid2])
				return mediana(dim1, mid1, mid2 + 1, nElemV2);

			if(list1[mid1] < list2[mid2])
				return mediana(mid1 + 1, nElemV1, dim2, mid2);
		
		}else if( (nElemV1 - dim1 + 1) % 2 != 0){

			if(list1[mid1] == list2[mid2])
				return list1[mid1];

			if(list1[mid1] > list2[mid2])
				return mediana(dim1, mid1, mid2, nElemV2);

			if(list1[mid1] < list2[mid2])
				return mediana(mid1, nElemV1, dim2, mid2);	
		}


	}else{

		if (list1[nElemV1] < list2[nElemV2])
			return list1[nElemV1];
		
		else
			return list2[nElemV2];
	}
}


void infoProgram(){
	system("clear");
	printf("*******************************************************************************************************************\n");
	printf("* /$$$$$$$            /$$                                  /$$$$$$  /$$                           /$$  /$$$$$$ 	  *\n");
	printf("* |$$__  $$          | $$                                 /$$__  $$| $$                          |__/ /$$__  $$   *\n");
	printf("* |$$  | $$ /$$   /$$| $$$$$$$   /$$$$$$  /$$$$$$$       | $$  |__/| $$$$$$$   /$$$$$$   /$$$$$$  /$$| $$  |__/   *\n");
	printf("* |$$$$$$$/| $$  | $$| $$__  $$ /$$__  $$| $$__  $$      | $$      | $$__  $$ /$$__  $$ /$$__  $$| $$| $$$$       *\n");   
	printf("* |$$__  $$| $$  | $$| $$  | $$| $$$$$$$$| $$  | $$      | $$      | $$  | $$| $$$$$$$$| $$  |__/| $$| $$_/       *\n"); 
	printf("* |$$  | $$| $$  | $$| $$  | $$| $$_____/| $$  | $$      | $$    $$| $$  | $$| $$_____/| $$      | $$| $$         *\n");    
	printf("* |$$  | $$|  $$$$$$/| $$$$$$$/|  $$$$$$$| $$  | $$      |  $$$$$$/| $$  | $$|  $$$$$$$| $$      | $$| $$         *\n");    
	printf("* |_/  |__/|_______/ |_______/ |_______/ |__/  |__/      |_______/ |__/  |__/|________/|__/      |__/|__/         *\n" );
	printf("*******************************************************************************************************************\n");
	printf("\n\n");
	printf("*********************************************************\n");
	printf("- Program name: MedianAlgorithm.c            			*\n");
	printf("- Description: Median of two sorted arrays of same size *\n");
    printf("- Program type: Search Algorithm             			*\n");
    printf("- User: Pichulon_14                          			*\n");
    printf("- Development System: Kali Linux 18.04 LTS 				*\n");
    printf("- Compilador: gcc                            			*\n");
    printf("*********************************************************\n");
    printf("\n");
}

	













