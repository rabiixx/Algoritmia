#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilaEnterosDinamica.h"
#include "colaEnteros.h"

#define N 50

size_t str_len;

void cod1(tipoPila *p, char *str);

void cod2(tipoCola *p, char *str);

bool esConsonante(char ch){
	return ( (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u') && (ch != ' '));
}

int main(int argc, char const *argv[])
{
	
	char *str = (char*)calloc(N, sizeof(char));
	
	//strcpy(str, "anacletj");
	printf("Introduce una frase: ");
	scanf("%[^\n]", str);
	str_len = strlen(str);
	printf("long: %zu\n", str_len);
	/*fgets(str, N, stdin);
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = 0;*/

	tipoPila pila;
	nuevaPila(&pila);

	tipoCola cola;
	nuevaCola(&cola);

	cod1(&pila, str);
	cod2(&cola, str);


	return 0;
}

/* Codificacino 1*/
void cod1(tipoPila *p, char *str) {

	int j;
	int i = 0;
	while( i < (strlen(str) - 1) ) {
		if ( esConsonante(str[i]) && esConsonante(str[i + 1]) ) {
			printf("1\n");
			j = i;	
			while( (i < strlen(str)) && esConsonante(str[i]) ) {
				//printf("cahr: %c\n", str[i]);
				apilar(p, str[i]);
				++i;
			}
			for (j; j < i; ++j) {
				//printf("J: %d\n", j);
				//printf("joder: %c\n", cima(*p));
				str[j] = cima(*p);
				desapilar(p);
			}
		} else {
			++i;
		}
	}

	printf("Tras la primera Codificacion: %s\n", str);
}


/* Codificacion 2 */


void cod2(tipoCola *c, char *str) {


	printf("%zu\n", (strlen(str)/2));
	for (int i = 0; i < (strlen(str)/2 + 1); ++i){
		printf("1Encolado %c\n", str[i]);
		encolar(c, str[i]);
		printf("2Encolado %c\n", str[strlen(str) - i - 1]);
		encolar(c, str[strlen(str) - i - 1]);
	}

	for (int i = 0; i < str_len; ++i){
		str[i] = frente(*c);
		desencolar(c);
		printf("%d\n", i);
	}

	printf("Tras la segunda Codificacion: %s\n", str);

}

/* Decode */
void decode(cola *c, pila *p, char *str) {

	
	for (int i = 0; i < (str_len/2 + 1); ++i){
		
	}




}
// Inversa codificacion 2
// Apliacar codificacion 1