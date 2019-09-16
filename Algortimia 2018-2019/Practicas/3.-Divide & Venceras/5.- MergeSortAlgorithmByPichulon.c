//************************
//Merge Sort Algorithm*
//************************

//Librerias 
#include <stdio.h> 
#include <stdlib.h>

//Variables Globales
int *arr;
int nElem;

//Declaracion de funciones
void infoProgram();

void mergeSort(int inic, int fin);

void merge(int inic, int mid, int fin);

void readArray();

void showArray();

//Programa Principal
void main(){

	infoProgram();

	readArray();

	mergeSort(0, nElem - 1);

	showArray();
}

void mergeSort(int inic, int fin){

	//Base case
	if(fin > inic){

		int mid = inic + (fin - inic)/2;

		//Ordenamos las mitades izquierda y derecha
		mergeSort(inic, mid);
		mergeSort(mid + 1, fin);

		merge(inic, mid, fin);
	}

}

void merge(int inic, int mid, int fin){

	//Numero de elementos de cada uno de los vectores
	int n1 = mid - inic + 1; 
	int n2 = fin - mid;

	//Creamos dos vectores: vect1[inic..mid] & vect2[mid + fin]
	int vect1[n1];
	int vect2[n2];

	//Inicializamos los vectores con los elementos de cada uno
	for (int i = 0; i < n1; ++i)
		vect1[i] = arr[inic + i];
	
	for (int j = 0; j < n2; ++j)
		vect2[j] = arr[mid + 1 + j];
	
	int i = 0;		//Indice de vect1[]
	int j = 0;		//Indice de vect2[]
	int k = inic;		//Indice de arr[]

	//Empezamos a ordenar
	while( (i < n1) && (j < n2) ){

		if(vect1[i] <= vect2[j]){
			arr[k] = vect1[i];
			i++;
		}else if(vect2[j] < vect1[i]){
			arr[k] = vect2[j];
			j++;
		}
		k++;
	}

	//Salida del bucle:
	//1.- Hemos insertado todos los elementos de vect1 y vect2
	//2.- Nos falta insertar los elementos de vect1: i < n1
	//3.- Nos falta insertar los elementos de vect2: j < n2
	if(i < n1)
		for ( i; i < n1; ++i){
			arr[k] = vect1[i];
			k++;
		}

	if(j < n2)
		for ( j; j < n2; ++j){
			arr[k] = vect2[j];
			k++;
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
	printf("*************************************************\n");
	printf("- Program name: Merge Sort            			*\n");
    printf("- Program type: Sort Algorithm             		*\n");
    printf("- User: Pichulon_14                          	*\n");
    printf("- Development System: Kali Linux 2018.4 64Bit	*\n");
    printf("- Compilador: gcc                            	*\n");
    printf("*************************************************\n");
    printf("\n");
}

void readArray(){

	printf("- Introduce el numero de elementos del array\t");
	scanf("%d", &nElem);
	printf("\n\n");

	arr = (int*)malloc(nElem * sizeof(int));

	printf("- Introduce los elementos del array \n\n");
	for (int i = 0; i < nElem; ++i){
		scanf("%d", &arr[i]);
	}
	printf("\n\n");

}
	
void showArray(){

	printf("- El vector ordenado es: \n\n");
	
	for (int i = 0; i < nElem; ++i)
		printf("%d\t", arr[i]);
	
	printf("\n\n");
}


