//************************
//Binary Search Algorithm*
//************************

//Librerias 
#include <stdio.h> 
#include <stdlib.h>

//Declaracion de constantes
#define FALSE -1

//Declaracion de funciones 
int binarySearch(int dim1, int dim2);

//Muestra informacion sobre el programa
void infoProgram();

//Variables Globales
int num;
int nElem;
int *arr;

//Programa Principal
int main(){

	system("clear");

	infoProgram();

	printf("- Introduce el numero de elementos\t");
	scanf("%d", &nElem);
	printf("\n");

	arr = (int*)malloc(nElem * sizeof(int));

	printf("- Inserte los elementos del vector\n\n");
	for (int i = 0; i < nElem; ++i){
		scanf("%d", &arr[i]);
	}
	printf("\n");

	printf("- Introduce el elemento que desea buscar: \t");
	scanf("%d", &num);
	printf("\n"); 
	
	int resultado = binarySearch(0, nElem - 1);

	if(resultado == FALSE)
		printf("- El elemento no se encuentra en el array \n"); 
	else 
		printf("- El elemento esta en la posicion %d del array\n", resultado);	
	
	printf("\n");

	return 0;
} 
 

 //Definicion de funciones 

//arr[l..r] == arr[dim1..dim2]
int binarySearch(int dim1, int dim2) { 
   	
   	if (dim2 >= dim1) { 

	    int mid = dim1 + (dim2 - dim1)/2; 
	  
	    // Base case 
	    if (arr[mid] == num)   
			return mid; 
	  
	    //Buscamos izquierda
	    if (arr[mid] > num)  
	    	return binarySearch(dim1, mid - 1); 
	  
	    // Buscamos derecha
	    if(arr[mid] < num) 
	    	return binarySearch(mid + 1, dim2); 
	} 
  

   //El elemento que buacamos no esta en el array
   return FALSE; 
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
	printf("**********************************************\n");
	printf("- Program name: Binary Search.c              *\n");
    printf("- Program type: Search Algorithm             *\n");
    printf("- User: Pichulon_14                          *\n");
    printf("- Development System: Linux Ubuntu 18.04 LTS *\n");
    printf("- Compilador: gcc                            *\n");
    printf("**********************************************\n");
    printf("\n");
}

  
