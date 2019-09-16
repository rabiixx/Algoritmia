
#include <stdio.h>
#include <stdlib.h>


/*Explicacion funcionamiento del algoritmo:

Estructuras:
-Una estructura pila con dos punteros
-Estructura nose con dos punteros(izq, der) y un char para alacenar simbolos
*/

typedef struct pila{
	struct pila *sigPila;
	struct nodoArbol *nodo;
}pila;

typedef struct nodoArbol{
	struct nodoArbol *izq;
	struct nodoArbol *der;
	char val;
}nodoArbol;

typedef struct cabecera{
	struct pila *head;
}cabecera;


/*
Funcionamiento:

Operacion: 5 3 + 6 2 * + 4

1.- Ponemos el puntero "*elem" del primer elemento de la pila apuntando al primer elemento(5)
2.- Ponemos el puntero "*elem" del segundo elemento de la pila apuntando al segundo elemento(3)
3.- El simbolo tomara el valor de "+"
4.- El puntero "*izq" del nodoArbol apuntara al 5
5.- El puntero "*der" del nodoArbol apuntara al 3
6.- Liberamos el segundo elemento de la pila 
7.- Ahora el puntero "*nodo" pasa a apuntar a nodoArbol
8.- Liberamos el puntero "*elem" de la pila 
*/

void pideInsertar(cabecera *pilaArbol);
void insertarArbol(char valor, cabecera *pilaArbol);
void insertarPila(char valor, cabecera *pilaArbol);
//void mostrarInOrden(nodoArbol *aux);
void inOrden(nodoArbol *aux);
//void profundidad(nodoArbol *aux);
/*
typedef pila* tpila;
typedef strucut cola{
	celda* ini;
	celda* fin;
} tcola;


tcola cola;
cola.ini
cola.fin

tpila pila:		celda* pila:
pila=NULL		pila=NULL
*pila			*pila


insertar(tpila* ca)	insertar(celda** ca)
*/

void main(){

	cabecera *pilaArbol;
	pilaArbol = (cabecera*)malloc(sizeof(cabecera));
	pilaArbol->head = NULL;

	pideInsertar(pilaArbol);

	nodoArbol *aux;
	aux = (nodoArbol*)malloc(sizeof(nodoArbol));
	aux = (pilaArbol->head)->nodo;


	//profundidad(aux);
	inOrden(aux);
	//mostrarInOrden(aux);

}


void pideInsertar(cabecera *pilaArbol){
	char valor;

	printf("Introduce la operacion en notacion postfija: ");
	scanf("%c", &valor);

	while(valor != '\n' ){
		if (valor == '+' || valor == '-' || valor == '*' || valor == '/' ){
			insertarArbol(valor, pilaArbol);
		}else {
			insertarPila(valor, pilaArbol);
		}
		scanf("%c", &valor); 
	}
}


//Insertar elementos en la pila
void insertarPila(char valor, cabecera *pilaArbol){

	pila *auxPila;				
	auxPila = (pila*)malloc(sizeof(pila));	

	//Nodo en el cual introduciremos nuestro numero
	nodoArbol *auxNodo;					
	auxNodo = (nodoArbol*)malloc(sizeof(nodoArbol));

	//Definicion del nodo
	auxNodo->val = valor;
	auxNodo->izq = NULL;
	auxNodo->der = NULL;

	//insertamos celda al principio de la pila
	auxPila->nodo = auxNodo;	
	auxPila->sigPila = pilaArbol->head;
	pilaArbol->head = auxPila;		//Asignacion de la cabecera(siempre apuntara al primer elemento de la pila)
					//headPila->nodo siempre apuntara al primer elemento del arbol 
}	


//El ejercicio no lo especifica?¿, pero se da por hecho que si tenemos mas de 2 elementos en la pila el...
//...primer simbolo que encontremos se correspondera con los dos primeros elementos de la pila(cima)
//Esta funcion se ejecuta cuando se lee un simbolo por teclado
void insertarArbol(char valor, cabecera *pilaArbol){
	nodoArbol *auxArbol;					//puntero auxiliar para guardar el simbolo y los hijos
	auxArbol = (nodoArbol*)malloc(sizeof(nodoArbol));	//reserva de memoria 

	pila *cima;
	cima = (pila*)malloc(sizeof(pila));
	//Creamos un nodo donde almacenaremos el valor del simbolo introducido y dos punteros que apuntaran a los operandos
	auxArbol->val = valor;				//operador		
/**/auxArbol->izq = pilaArbol->head->sigPila->nodo;	//operando izquierda
	auxArbol->der = pilaArbol->head->nodo;			//operando derecha

	pilaArbol->head->sigPila->nodo = auxArbol;

	(pilaArbol->head)->nodo = auxArbol;
	cima = pilaArbol->head;
	pilaArbol->head = pilaArbol->head->sigPila;
	free(cima);
	
	
}


//Vamos a suponer que el arbol no puede estar vacio (esta comprobacion la haremos antes)...
//...debido a que sino nuentro caso base no servira 
/*
void mostrarInOrden(nodoArbol *aux){
	
	if ( aux == NULL) {	//arbol vacio
                return;
	}else {
		if(aux->izq != NULL){
			mostrarInOrden(aux->izq);
            printf("%c", aux->val);
        }
		if(aux->der != NULL){
			mostrarInOrden(aux->der);
		}

	}
}
*/

/*
void profundidad(nodoArbol *aux){
	if(aux == NULL)
		printf("El arbolesta vacio\n");
	else{
		printf("%c ",aux->val);
		if(aux->izq != NULL)
			profundidad(aux->izq);
		if(aux->der != NULL)
			profundidad(aux->der);
	}
	return;
}
*/

void inOrden(nodoArbol *aux){
	if(aux != NULL){
		inOrden(aux->izq);
		printf("%c", aux->val );
		inOrden(aux->der);
	}else{
		return;
	}
}

















