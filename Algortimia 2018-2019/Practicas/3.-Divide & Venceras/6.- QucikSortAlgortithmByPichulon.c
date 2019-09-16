//User: Pichulon_14
//Development Date: 23/11/2018
//Version: Final Version
//Program name: QuickSort

//**********
//Librerias*
//**********
#include <stdio.h>
#include <stdlib.h>

//**************************
//Declaracion de funciones*
//**************************

//Execution of the Algorithm
void quicksort(int pivot, int dim);

//Informacion general sonbre el programa
void infoProgram();

//Permuta dos elementos que se le indiquen 
void swap(int *x, int *y);

//Lee una lista/vector(teclado)
void readList();

//Muestra el vector(pantalla)
void showList();


//*******************
//Variables Globales*
//*******************
int nElem;
int *list;

//**********************************************
//Programa Principal(Diseño totalmente MODULAR)*
//**********************************************
void main(){

	infoProgram(); 
	
	readList();

	showList();

	quicksort(0, nElem - 1);

	showList();

}

//************************
//Definicion de funciones* 
//************************

void quicksort(int pivot, int dim){

	if(pivot < dim){
		
		int up = pivot + 1;
		int down = dim;
		
		while(up <= down){
			
			if( (list[up] > list[pivot]) && (list[down] < list[pivot]) ){
				swap(&list[up], & list[down]);
				up++;
				down--;
			}else if(list[up] > list[pivot])
				down--;
			else if(list[down] < list[pivot])
				up++;
			else{
				up++;+
				down--;
			}
		}
		//CAmbiamos el pivote con down
		swap(&list[down], &list[pivot]);
		//Solucionar la parte de la izquierda
		quicksort(pivot, down - 1);
		//Solucionamos la parte de la derecha
		quicksort(down + 1, dim);

	}

}


void readList(){
	
	printf("- Introduce el numero de elementos:\t ");
	scanf("%d", &nElem);
	printf("\n");

	//Reserva de memoria vector
	list = (int*)malloc(nElem * sizeof(int));

	printf("- Introduce los numeros\n\n");

	for (int i = 0; i < nElem; ++i){
		scanf("%d", &list[i]);
	}
	printf("\n");

}

void showList(){
	printf("- Lista:\n\n");
	for (int i = 0; i < nElem; ++i)
	{
		printf("%d\t", list[i]);
	}
	printf("\n\n");

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
	printf("*********************************************\n\n");
	printf("- Program name: QuickSort.c                 *\n\n");
    printf("- Program type: Sort Algorithm              *\n\n");
    printf("- User: Pichulon_14                         *\n\n");
    printf("- Development System: Linux Ubuntu 18.04 LTS*\n\n");
    printf("- Compilador: gcc                           *\n\n");
    printf("*********************************************\n\n");
    printf("\n");
}

void swap(int *x, int *y){
    int a;
    
    a = *x;
    *x = *y;
    *y = a;
}
