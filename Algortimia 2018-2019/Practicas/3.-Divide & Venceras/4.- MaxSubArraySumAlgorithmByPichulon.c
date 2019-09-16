//***************************
//Max Subarray Sum Algorithm*
//***************************

//Librerias 
#include <stdio.h> 
#include <stdlib.h>
#include <limits.h> 

//Variables Globales
int *arr;
int nElem;

//Declaracion de funciones
void infoProgram();

void scanArray();

int maxSubArraySum(int inic, int fin);

int max(int a, int b, int c);

int maxMixSum(int inic, int mid, int fin){

	int tempSum = 0;
	int maxSumIzq = INT_MIN;	
	
	for (int i = mid; i >= inic; --i){
		tempSum += arr[i];
		if(tempSum > maxSumIzq)
			maxSumIzq = tempSum;
	}

	
	tempSum = 0;
	int maxSumDer = INT_MIN;
	
	for (int i = mid + 1; i <= fin ; ++i){
		tempSum += arr[i];
		if(tempSum > maxSumDer)
			maxSumDer = tempSum;

	}	

	return maxSumIzq + maxSumDer;

}

//Programa Principal
void main(){

	infoProgram();

	scanArray();

	printf("%d\n\n", maxSubArraySum(0, nElem - 1));

}


int maxSubArraySum(int inic, int fin){

	if(inic == fin)
		return(arr[inic]);
	
	else{

		int mid = inic + (fin - inic)/2;
		//int mid = (inic + fin)/2;

		/* Return maximum of following three possible cases 
      	a) Maximum subarray sum in left half 
      	b) Maximum subarray sum in right half 
      	c) Maximum subarray sum such that the subarray crosses the midpoint */
		max(maxSubArraySum(inic, mid), maxSubArraySum(mid + 1, fin), maxMixSum(inic, mid, fin));
	}
}

int max(int a, int b, int c){
	if( (a > b) && (a > c))
			return a;
	else if(b > c)
		return b;
	else 
		return c;
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
    printf("           (0 0)\n");		    
    printf("   ---oOO-- (_) ----oOO---  \n");    
    printf("╔═══════════════════════════╗ \n"); 
    printf("║  Welcome! Pichulon_14  ♥  ║ \n"); 
    printf("╚═══════════════════════════╝ \n");
    printf("   -------------------\n");   
    printf("          |__|__|\n");          
    printf("           || || \n");         
    printf("          ooO Ooo \n");      
	printf("\n\n");
	printf("*************************************************\n");
	printf("- Program name: Max Subarray Sum            	*\n");
    printf("- Program type: Sort Algorithm             		*\n");
    printf("- User: Pichulon_14                          	*\n");
    printf("- Development System: Kali Linux 2018.4 64Bit	*\n");
    printf("- Compilador: gcc                            	*\n");
    printf("*************************************************\n");
    printf("\n");
}

void scanArray(){

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
	

