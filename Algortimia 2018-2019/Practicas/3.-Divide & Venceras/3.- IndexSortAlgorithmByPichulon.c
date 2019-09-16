// Práctica 6, ejercicio 4 de Daniel Domínguez Catena, NIA 67328
// 23 de Noviembre de 2011

#include <stdio.h>
#include <stdlib.h>

void buscar(int *a, int prim, int ult);

void main(){
	int n, i;
	int *a;
	printf("Introduce el tamaño del vector: ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	printf("Recuerda introducir un vector ordenado crecientemente.\n");
	for (i=0;i<n;i++){
		printf("Introduce el elemento %d: ",i+1);
		scanf("%d",(a+i));
	}
	buscar(a,0,n-1);
}

void buscar(int *a, int f, int l){
	int i;
	if (f>l){
		printf("No existe el indice\n");
	} else {
		i=(f+l+1)/2;
		if (a[i]==i+1) {
			printf("Existe al menos un indice, en la posicion %d, valor %d\n",i+1,a[i]);
		} else if (a[i]>i+1){
			buscar(a,f,i-1);
		} else {
			buscar(a,i+1,l);
		}
	}
}
