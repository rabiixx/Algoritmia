/*
  FICHERO: colaDobleCaracteres.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>

 typedef char tipoElementoColaDoble;
 typedef struct celdaCD{
	 tipoElementoColaDoble elem;
	 struct celdaCD *ant;
	 struct celdaCD *sig;
 } celdaColaDoble; 
typedef struct tipoCD{
	celdaColaDoble* ini;
	celdaColaDoble* fin;
}tipoColaDoble;

void nuevaColaDoble(tipoColaDoble *);

void encolarPrimero(tipoColaDoble *, tipoElementoColaDoble);

void encolarUltimo(tipoColaDoble *, tipoElementoColaDoble);

void desencolarPrimero(tipoColaDoble *);

void desencolarUltimo(tipoColaDoble *);

tipoElementoColaDoble elemPrimero(tipoColaDoble);

tipoElementoColaDoble elemUltimo(tipoColaDoble);

bool esNulaColaDoble(tipoColaDoble);

void mostrar(tipoColaDoble);

void vaciarColaDoble(tipoColaDoble*);