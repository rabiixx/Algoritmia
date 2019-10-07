
#include <stdlib.h>
#include <stdio.h>

typedef struct _elem{
	


}celda;



int main(int argc, char const *argv[])
{


	unsigned int N;
	printf("Introduce el numero de elementos: %d\n");
	scanf("%d", &N);

	int *pre = (int*)malloc(sizeof(int)*N);
	int *in = (int*)malloc(sizeof(int)*N);

	printf("Introduce preorden: ");
	for (int i = 0; i < N; ++i){
		scanf("%d", pre[i]);
	}

	printf("Introduce inorden: ");
	for (int i = 0; i < N; ++i){
		scanf("%d", in[i]);
	}

	/* Busqueda de a raiz */
	unsigned int raiz_index;
	unsigned int i = 0;
	while ( (i < N) && (pre[0] != in[i]) ) {
		++i;
	}	
	if(pre[0] == in[i]) {
		raiz_index = i;
		insertar(arbol, pre[0]);
	}

	free(&i);

	/* Contruccion del arbol */
	for (int j = 1; j < N; ++j)	{
		for (int i = 0; i < N; ++i) {
			if ( (pre[j] == in[i]) && (i < raiz_index) )
				insertar(arbol, NULL, pre[i]);
					for (int i = j+1; i < N; ++i){
						for (int k = raiz; k < N; ++k){
							if (pre[j] == in[k])
								insertar()
						}
	
			else
				insertar(arbol, pre[i], NULL);
		}



	}




	return 0;
	
}

