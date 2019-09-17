/*
  FICHERO: colaEnteros.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>

typedef int tipoElementoCola;


typedef struct _celdaC{
  int elem;
  celdaC *sig;
}celdaC; 

typedef struct _cola{
  celdaCola *head;
  celdaCola *fin;
}cola;

void nuevaCola(cola *c);

void encolar(cola *c, int auxElem);

void desencolar(cola *c);

int frente(cola *c);

bool esNulaCola(cola *c);

void mostrarCola(cola *c);

void buscar(cola *c);