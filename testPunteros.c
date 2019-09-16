#include <stdio.h>
#include <stdlib.h>


typedef struct _cola {
	int h;
	int *sig;
} cola;



void f() { 


	int num = 4;
	int num2 = 56;
	int *p;
	

	printf("Sizeof1: %zu\n", sizeof(*p));


	p = &num;

	printf("Sizeof2: %zu\n", sizeof(*p));

	printf("Direccion Poniter: %p\n", &p);


	printf("Direccion: %p\n", p);
	printf("Valor: %d\n", *p);



	*p = num2;

	printf("Direccion: %p\n", p);
	printf("Valor num2: %d\n", *p);
	printf("Valir num: %d\n", num);


}



void f2() {

	cola *c2 = (cola*)calloc(1, sizeof(cola));
	c2 = NULL;

	if (c2) {
		printf("hola\n");
	}else{
		printf("adios\n");
	}




}

int main(int argc, char const *argv[])
{


	int var = 8;
	
	cola *c;
	//cola *c = (cola*)malloc(sizeof(cola));
	printf("Sizeof: %zu\n", sizeof(*c));
	printf("SIZEOF: %zu\n", sizeof(cola));
	f();

	c->h = 5;

	c->sig = &var;
	printf("jbdfsjfbjds:  \n");

	*(c->sig) = 9;

	printf("dsfds\n");

	printf("C.h: %d\n", c->h);
	printf("C.sig: %d\n", *c->sig);

	f2();

	return 0;
}


