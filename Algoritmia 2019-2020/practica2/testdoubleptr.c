#include <stdio.h>

int main(int argc, char const *argv[]){


	int var = 789;

	// Pointer to var 
	int *ptr2;


	// Double pointer to ptr2
	int **ptr1;

	ptr2 = &var;

	ptr1 = &ptr2;

	printf("Value of var = %d\n", var);
	printf("Value of var using sigle pointer = %d\n", *ptr2);
	printf("Value of var using double pointer = %d\n", **ptr1);

	printf("Memory address of var: %zu\n", &var);
	printf("Memory addess pointed by ptr2: %zu\n", ptr2); 
	printf("Memory address of ptr2: %zu\n", &ptr2); 
	printf("Memory addess pointed by ptr1: %zu\n", ptr1); 
	printf("Memory address of ptr1: %zu\n", &ptr1);

}