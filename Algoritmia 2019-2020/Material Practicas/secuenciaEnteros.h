/*
  FICHERO: secuenciaEnteros.h
  VERSION: 1.0.0
  HISTORICO:
  Creado por Aránzazu Jurío Munárriz el 09/09/19.
  
  Este fichero se crea sólo con intenciones de coordinación docente y como
  ayuda a sus alumnos y alumnas. La autora desautoriza expresamente su difusión, copia
  o exhibición pública (salvo entre los alumnos de las asignaturas 240301 y 250301 del
  grado en Ingeniería Informática de la UPNA).
*/

#include "pilaEnterosDinamica.h"

 typedef struct sec{
	 tipoPila pilaIzq;
	 tipoPila pilaDcha;
 } tipoSecuencia; 

void nuevaSecuencia(tipoSecuencia*);

void insertarDelantePunto(tipoSecuencia*, tipoElementoPila);

void insertarEnPunto(tipoSecuencia*, tipoElementoPila);

void eliminarEnPunto(tipoSecuencia*);

tipoElementoPila consultarEnPunto(tipoSecuencia);

void avanzarPunto (tipoSecuencia*);

void moverPuntoAlPrincipio (tipoSecuencia*);

bool esPuntoUltimo(tipoSecuencia);

bool esVaciaSecuencia(tipoSecuencia);