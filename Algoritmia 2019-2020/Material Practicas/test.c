#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilaEnterosDinamica.h"

#define N 50

void cod1(tipoPila *p, char *str);

bool esConsonante(char ch){
	return ( (ch != 'a') && (ch != 'e') && (ch != 'i') && (ch != 'o') && (ch != 'u') );
}

int main(int argc, char const *argv[])
{
	
	char *str = (char*)calloc(N, sizeof(char));
	printf("Introduce una frase: ");
	scanf("%[^\n]", str);

	/*fgets(str, N, stdin);
	if(str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = 0;*/

	tipoPila pila;
	nuevaPila(&pila);

	cod1(&pila, str);




	return 0;
}

/* Codificacino 1*/
void cod1(tipoPila *p, char *str) {

	int cont = 0;
	int j;
	int i = 0;
	while( i < strlen(str) ) {
		if ( esConsonante(str[i]) && esConsonante(str[i + 1]) ) {
			j = i;	
			while( esConsonante(str[i]) ) {
				++i;
				apilar(p, str[i]);
			}
			for (j; j < i; ++j)
				str[j] = cima(*p);
		} else {
			++i;
		}
	}

	printf("COD1: %s\n", str);
}


/* Codificacion 2 */
/*for (int i = 0; i < strlen(str) - 1; i += 2) {
	str[i] = desencolarPrimero(&cola);
	str[i+1] = desencolarUltimo(&cola);
}*/


			/* while(!esNulaPila(*p)) {
				str[j] = cima(pila);
				++j;
			} */ 