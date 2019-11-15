#include <stdlib.h>
#include <stdio.h>


void func(int *arr){

	printf("hola\n");

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\n", arr[i]);
	}
	
}


int main(int argc, char const *argv[])
{
	

	int arr2[5] = {5, 3, 34, 12, 75};

	int *arr3 = (int*)malloc(5*sizeof(int));
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &arr3[i]);
	}


	int arr1[] = {5, 3, 34};

	printf("Size int: %zu\n", sizeof(int));
	printf("%zu\n", sizeof(arr1));

	int nElemArr = (int)(sizeof(arr1)/sizeof(arr1[0]));

	printf("Numero elementos: %d\n", nElemArr);
	
	printf("Memory Address1: %p\n", &arr1[0]);
	printf("Memory Address2: %p\n", arr1);
	printf("Contenido arr1[0]: %d\n", *arr1);
	
	int *offset = arr1;
	offset++;
	int *offset2 = arr1;
	offset2 = offset2 + sizeof(int);
	//printf("hack: %p\n", &offeset);

	printf("Contenido arr1[1]: %d\n", *offset);
	//printf("Contenido arr1[1]: %d\n", *offset2);

	func(arr3);

	/*printf("%zu\n", sizeof(arr1));

	int nElemArr = (int)(sizeof(arr1)/sizeof(arr1[0]));

	printf("Numero elementos: %d\n", nElemArr);*/

	return 0;
}

