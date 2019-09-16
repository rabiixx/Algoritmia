#include <stdbool.h>

typedef int tipoElementoCola;

 
typedef struct _celdaC{
	int elem;
	celdaC *sig;
}celdaC; 


typedef struct _cola{
	celdaCola *head;
	celdaCola fin;
}cola;

void nuevaCola(tipoC *c) {
	cola *c = (cola*)calloc(1, sizeof(cola));
	c = NULL;
}

void encolar(cola *c){

	printf("Introduzca el numero que desea encolar: \n");
	scanf("%d", &auxElem);

	celdaC *aux = (celdaC*)calloc(1, sizeof(celdaC));
	aux->elem = auxElem;
	aux->sig = NULL;

	if (esNulaCola) { 
		c->head = aux;
		c->fin = aux;
	} else {
		(c->fin).sig = aux;
		c->fin = aux;
	}
}

void desencolar(cola *c) {

	if (esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		celdaC *aux;
		aux = c->head;
		c->head = aux->sig;		//c->head = (c->head)->sig
		free(aux);
	}
}

int frente(cola *c) {	return c->head->elem;	}

bool esNulaCola(tipoCola) {	return (c->head)? true:false; 	}

void mostrarCola(cola *c) {

	if (esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		celdaC *aux = c->head;
		printf("Cola: ");
		while (aux) {
			printf("%d, \t", aux->elem);
			aux = aux->sig
		}
	}
}

void buscar(cola *c) {
	
	if(esNulaCola(c)) {
		printf("[+] La cola esta vacia.\n");
	} else {
		
		int elem;
		celda *aux = c->head;

		printf("[+] Introduzca el elemento que desea buscar : \n");
		scanf("%d", &elem);

		while (aux) {
			if (aux->elem == elem)
				printf("[+] El elemento se encuentra en la cola. \n", );
			else 
				aux = aux->sig;
		}
	}
}


int menu(){
	
	int op;
	
	printf("[+] Elija la opcion deseada: \n");
	printf("\t1- Insertar elemento\n");
	printf("\t2- Eliminar elemento\n");
	printf("\t3- Mostrar cola\n");
	printf("\t4- Buscar elemento\n");
	printf("\t5- Salir\n");
	printf("\t6- Vaciar cola\n");
	printf("\t7- ¿Vacia?\n");
	scanf("%d", op);
		
	return(op);
}

//Programa Principal
void main(){
	
	system("clear");
	int men;
	
	cola *c;
	nuevaCola(c);

	do{
		men = menu();
		switch(men){
			case 1: encolar(c);
				break;
			case 2: desencolar(c);
				break;
			case 3: mostrarCola(c);
				break;
			case 4: buscar(c);
				break;
			case 5: frente(c);
				break;
			case 6: vaciar(c);
				break;
			case 7: esNulaCola(c);
				break;
			default: printf("Opcion erronea\n");
				break;
		}
	} while(1);
}