#include<stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	
	char str[50];
	printf("Introduce: ");
	//scanf("%[^\n]", str);
	//fgets(str, 100, stdin);	// lee el salto de linea
	//fread(str, 100, sizeof(char), stdin);
	//getline(&str,0, stdin);
		char c;

	while( (c = fgetc(stdin)) != '\n') {
		printf("%c\n", c);
	}

	if( (c != ('a' || 'e' || 'i' || 'o' || 'u') ) ) {
		printf("hola\n");
	} else {
		printf("adios\n");
	}






	return 0;
}



void