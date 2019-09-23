/*
  FICHERO: listaOrdenadaEnteros.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include <stdbool.h>

 typedef int tipoElementoLista;
 typedef struct celdaL{
	 tipoElementoLista elem;
	 struct celdaL *sig;
	 struct celdaL *ant;
 }celdaLista; 
typedef struct tipoL{
	celdaLista *ini;
	celdaLista *fin;
}tipoLista;

void nuevaLista(tipoLista *);

void insertar(tipoLista *, tipoElementoLista);

void eliminarMenor(tipoLista *);

void eliminarMayor(tipoLista *);

tipoElementoLista consultarMenor(tipoLista);

tipoElementoLista consultarMayor(tipoLista);

bool estaElemento(tipoLista, tipoElementoLista);

bool esNulaLista(tipoLista);

void concatenar (tipoLista *, tipoLista *);

void imprimirLista (tipoLista);