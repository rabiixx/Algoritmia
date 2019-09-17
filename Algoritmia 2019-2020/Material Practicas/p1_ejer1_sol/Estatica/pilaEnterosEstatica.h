/*
  FICHERO: pilaEnterosEstatica.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>
#define TAMANIO_PILA_DE_ENTEROS 100

typedef int tipoElementoPila;
typedef struct pilaDeEnteros{
	int cima; // Desplazamiento para alcanzar el elemento de la cima
	tipoElementoPila valores[TAMANIO_PILA_DE_ENTEROS];
} tipoPila;

void nuevaPila(tipoPila *);

void apilar(tipoPila *, tipoElementoPila);

void desapilar(tipoPila *);

tipoElementoPila cima(tipoPila);

bool esNulaPila(tipoPila);

