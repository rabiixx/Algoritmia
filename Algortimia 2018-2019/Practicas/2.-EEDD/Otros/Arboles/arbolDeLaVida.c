/* Arbol Binario de Búsqueda en C  */

//Nombre del programa: arbolDeLaVida
//Autor: Ruben Cherif Narvaez
//NIA: 121871
//Entorno de desarrollo: Linux Ubuntu 18.04 LTS
//Compilador: Gcc/g++
//Estilo programacion: GNOME
//Descripcion: Te hackea la vida
//Usuario: HaRdChilling875

//Librerias 
#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* Estructuras y tipos */
typedef struct tipoNodo {
   int valor;
   struct tipoNodo *der;
   struct tipoNodo *izq;
} tipoNodo;

//Variables Globales: CUIDADO!!!
typedef tipoNodo *arbol;
typedef tipoNodo *pNodo;

/* Declaracion de funciones del Arbol Binario: */

//Insertar un nuevo elemento en el arbol
void pideInsertarRec(arbol *a);
void auxInsertarRec(arbol *a, pNodo nodo);

//Borrar un elemento del arbol 
void pideBorrarRec(arbol *a);
void auxBorrarRec(arbol *a, int valor);
pNodo sucesor(pNodo nodo);

//Muestra el arbol en base al recorido especificado
void mostrarArbol(arbol a);
void inOrden(arbol a);
void preOrden(arbol a);
void postOrden(arbol a);

//Buscar un elemento del arbol de forma recursiva
void pideBuscarRec(arbol a);
void auxBuscarRec(arbol a, int valor);

//Buscar un elemento del arbol de forma iterativa 
void pideBuscarIte(arbol a);
void auxBuscarIte(arbol a, int valor);

//Calcula la altura de un nodo dado
int alturaNodo(arbol a);

//Cuenta el numero de nodos que contiene el arbol
int numNodos(arbol a, int *cont);
void auxCont(arbol a, int *);

//Calcula la altura de nuestro arbol binario 
int alturaArbol(arbol a, int *alt);
void auxAltura(arbol a, int auxAlt, int*);

void pideAlturaNodoRec(arbol a, int *alt);
int auxAlturaNodoRec(arbol a, int*, int valor);

//Indica si el nodo que le pasemos es hoja o no
int esHoja(pNodo nodo);

//Indica si el arbol esta vacio o no
int vacio(arbol a);

/* Nos muestra informacion sobre el programa */
void infoprogram();

/* Menu */ 
int menu();


/* Programa principla */
void main(){
        system("clear");
        infoprogram();
        
        /*varibles auxiliares*/
        arbol ArbolInt = NULL;
        int cont;
        int altura;



        int men;

        do{
        men = menu();
        switch(men){
                case 1: pideInsertarRec(&ArbolInt);
                        break;
                case 2: pideBorrarRec(&ArbolInt);
                        break;
                case 3: mostrarArbol(ArbolInt);
                        break;
                case 4: pideBuscarRec(ArbolInt);
                        break;
                case 5: pideBuscarIte(ArbolInt);
                         break;
                case 6: printf("La altura del nodo es: %d\n", alturaNodo(ArbolInt));
                        break;
                case 7:	printf("El numero de nodos que contiene el arbol es: %d\n", numNodos(ArbolInt, &cont));
                        break;
                case 8: printf("La altura del arbol es: %d", alturaArbol(ArbolInt, &altura));
                        break;	
               	case 9: exit(0);
               			break;
               	default: printf("Opcion erronea\n");
               			break; 
                }
        }while(1);
}


//Definicion de funciones 
void infoprogram(){
        printf("Nombre del programa: Arbol De La Vida\n");
        printf("Usuario: HaRdChilling875 \n");
        printf("Autor: Ruben Cherif Narvaez\n");
        printf("NIA: 121871\n");
        printf("Entorno de desarrollo: Linux Ubuntu 18.04 LTS\n");
        printf("Compilador: gcc\n");
        printf("Compilacion: ggc -g .c -o .exe\n");
        printf("Pruebas: GDB (debuger)");
        printf("Descripcion: Te hackea la vida misma\n");
        printf("\n\n");
}

int menu(){
        int op;
        printf("Elija la opcion deseada: \n");
        printf("1- Insertar elemento de forma recursiva\n");
        printf("2- Eliminar elemento de forma recursiva\n");
        printf("3- Mostrar el arbol con distintos recorridos\n");
        printf("4- Buscar un elemento de forma recursiva\n");
        printf("5- Buscar un elemento de forma iterativa \n");
        printf("6- Altura de un nodo dado\n");
        printf("7- Numero de nodos que contiene el arbol\n");
        printf("8.-Altura total del arbol\n");
        printf("9.-Salir\n");
        do{
        	scanf("%d", &op);
        }while(op < 1 || op > 9);
        return(op);
}


void pideInsertarRec(arbol *a){
        int val;
        printf("Dame el valor a insertar: ");
        scanf("%d", &val);

        pNodo aux;
        aux = (tipoNodo*)malloc(sizeof(tipoNodo));

        aux->valor = val;
        aux->izq = NULL;
        aux->der = NULL;

        auxInsertarRec(a, aux);
}

void auxInsertarRec(arbol *a, pNodo aux){
        if (a == NULL) {
                a = aux;
        } else if ( a->valor == aux->valor){
                printf("El valor ya se encuentra en el arbol");
        } else if ( a->valor > (aux->valor) ){// buscamos en la rama derecha
                auxInsertarRec(&(a->izq), aux );
        } else if ( a->valor < aux->valor){// buscamos en la rama izquierda
                auxInsertarRec(&(a->der), aux);
        }
        printf("\n");
}


void pideBorrarRec(arbol *a){

	int valor;

	printf("Cual es el elemento que desea eliminar\n");
	scanf("%d", &valor);

	auxBorrarRec(a, valor);
}

void auxBorrarRec(arbol *a, int numero){
	if (a->head == NULL)
		printf("El arbol se encuentra vacio\n");
	else{
		//Se trata de realizar una busqueda del elemento en el arbol
		if (numero < a->valor)
			auxBorrarRec(&(a->izq),numero);
		else if (numero > a->valor)
			auxBorrarRec(&(a->der),numero);
		else if (numero == (a->valor)){
		/*Una vez encontrado el elemento habra que analizar el caso:
		-Caso 1: Borrar nodo sin hijos
		-Caso 2: Borrar un nodo con un subarbol hijo(izq o der)
		-Caso 3: Borrar un nodo con dos subarboles hijos + Caso1 o Caso2
		*/	if ((a->der == NULL) && ((a->izq) == NULL)){
				free(a);
				a = NULL;

			}else if (a->izq == NULL){

				pNodo aux;
				aux = a->head;
				a = a->der; 
				free(aux);

			}else if (a->der == NULL){

				pNodo aux;
				aux = a;
				a = a->izq;
				free(aux);
			
			}else{ //2 hijos-->Busco el sucesor del elemento a eliminar(elemento + pequeño del subárbol hijo derecho)

				pNodo suc = sucesor(a->der);
				//	Coloco el sucesor en la posición del elemento a eliminar
				a->valor = suc->valor;
				//	Elimino el sucesor de su posición original
				auxBorrarRec(&(a->der), suc->valor);
			}
		}
	}
}

//Funcion para buscar el sucesor del que eliminaremos: elemento mas a la izq del subarbol del elemento a eliminar
pNodo sucesor(pNodo nodo){
	//elemento mas pequeño del subárbol hijo derecho(no tiene hijo subarbol en la izq)
	if (nodo->izq == NULL)
		return nodo;
	else
		return sucesor(nodo->izq);
	
}

/*
void profundidad(arbol *a){
    if (a->head == NULL){
        printf("El arbol se encuentra vacio\n");
    }else{
        printf("%d", a->head->valor);
        if(a->head->izq != NULL)
            profundidad(a->head->izq);
        if(a->head->der != NULL)
            profundidad(a->head->der);
    }
}
*/

void inOrden(arbol a){
    if(a != NULL){
        inOrden(a->izq);
        printf("%d", a->valor);
        inOrden(a->der);
    }else{
        return;
    }
}


void postOrden(arbol a){
    if(a != NULL){
        postOrden(a->izq);
        postOrden(a->der);
        printf("%d", a->valor);
    }else{
        return;
    }
}


void preOrden(arbol a){
    if(a != NULL){
        printf("%d", a->valor);
        preOrden(a->izq);
        preOrden(a->der);
    }else{
        return;
    }
}

void mostrarArbol(arbol a){
	int men;

	pNodo nodo = a;

	printf("Eliga una opcion\n");
	printf("1.-Mostrar arbol en pre-orden\n");
	printf("2.-Mostrar arbol en in-orden\n");
	printf("3.-Mostrar arbol en post-orden\n");
	printf("4.-Salir\n");

	do{
		scanf("%d", &men);
		switch(men){
			case 1: preOrden(a);
				break;
			case 2: inOrden(a);
				break;
			case 3: postOrden(a);
				break;
			case 4: exit(0);
				break;
			default: printf("Opcion erronea\n");
				break;
		}
		while(1);
	}while(men < 1 || men > 4);
}
	

int vacio(arbol a){
    return a == NULL;
}

int esHoja(pNodo nodo){
   return !nodo->der && !nodo->izq;
}

void pideBuscarRec(arbol a) {
        int valor;
        printf("Dame el valor a buscar: ");
        scanf("%d", &valor);
        auxBuscarRec(a, valor);
}
//Recorrido profundidad
void auxBuscarRec(arbol a, int valor) {
        if (a == NULL) {
                printf("El valor buscado no esta en el arbol\n\n");
        } else if (a->valor == valor){
                printf("El valor esta en el arbol\n\n");
        } else if (a->valor > valor){
                auxBuscarRec(a->izq, valor);
        } else if (a->valor < valor){
                auxBuscarRec(a->der, valor);
        }
}
void pideBuscarIte(arbol a){
	    int valor;

        printf("Dame el valor a buscar: ");
        scanf("%d", &valor);

        auxBuscarIte(a, valor);
}

void auxBuscarIte(arbol a, int valor){

  	pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   	while(!vacio(actual)) {
      	if(valor == actual->valor)	printf("El valor buscado esta en el arbol\n");/* dato encontrado */
      	else if(valor < actual->valor) actual = actual->izq; /* Seguir */
     	else if(valor > actual->valor) actual = actual->der;
   	}
   	printf("EL valor buscado no esta en el arbol\n");/* No está en árbol */
}


int alturaNodo(arbol a){

	int valor;
	printf("Introduce el valor del nodo del cual deseas saber la altura\n");
	scanf("%d", &valor);

   	int altura = 0;
   	pNodo actual = a;

   	/* Todavía puede aparecer, ya que quedan nodos por mirar */
   	while(!vacio(actual)) {
      	if(valor == actual->valor) return altura; /* encontrado: devolver altura */
      	else {
         	altura++; /* Incrementamos la altura, seguimos buscando */
         	if(valor < actual->valor) actual = actual->izq;
         	else if(valor > actual->valor) actual = actual->der;
      	}	
   	}
   	return -1; /* No está en árbol, devolver -1 */
}


void pideAlturaNodoRec(arbol a, int *alt){
	int valor;
	printf("Introduce el valor del nodo del cual deseas saber la altura\n");
	scanf("%d", &valor);

	*alt = 0;

	auxAlturaNodoRec(a, alt, valor);
}

int auxAlturaNodoRec(arbol a, int *alt, int valor){

	if (a->valor == valor)	return *alt;
	else{
		alt++;
		if(a->valor < valor)	auxAlturaNodoRec(a->izq, alt, valor);
		if(a->valor < valor)	auxAlturaNodoRec(a->der, alt, valor);
	}
}


/* Contar el número de nodos */
int numNodos(arbol a, int *cont)
{
   *cont = 0;

   auxCont(a, cont); /* Función auxiliar */
   return *cont;
}

/* Función auxiliar para contar nodos. Función recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxCont(pNodo nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izq) 	auxCont(nodo->izq, c);
   if(nodo->der)   	auxCont(nodo->der, c);
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int alturaArbol(arbol a, int *alt)
{
   *alt = 0;

   auxAltura(a, 0, alt); /* Función auxiliar */
   return *alt;
}

/* Función auxiliar para calcular altura. Función recursiva de recorrido en
   postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
   altura de la máxima actual */
void auxAltura(pNodo nodo, int a, int *alt)
{
   /* Recorrido postorden */
   if(nodo->izq) 	auxAltura(nodo->izq, a + 1, alt);
   if(nodo->der)   	auxAltura(nodo->der, a + 1, alt);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      árbol, actualizamos la altura actual del árbol */
   if(esHoja(nodo) && a > *alt) *alt = a;
}

