typedef struct datos {
	int fechaD;
	int numF;
	int hack;
}datosD;


typedef struct _cola {
	int numDesastres;
	celda *head;
	celda *last;
}cola;



int main(int argc, char const *argv[])
{
	cola *c = NULL;
	int numDesastres;

	printf("Introduce numero de desastres: \n");
	scanf("%d", &numDesastres);

	datosD *arrayD = (datosD*)calloc(numDesastres, sizeof(datosD));

	for (int i = 0; i < ; ++i) {
		printf("Introduce fecha y victimas: \n");
		scanf("%d %d", &datosD[i].fecha, &datosD[i].numF);
	}

	if (arrayD[i-1].numF > arrayD[i].numF) {
		arrayD[i].hack = arrayD[i-1].fechaD;
	} else {
		
	}



	return 0;
}

void piruleta(cola *c) {

	c->head->hack = 0;
	c->head->sig->hack = 0;
	int maxVict = INT_MIN;

	celda->aux

	if()



}


void encolar(cola *c, celda *aux) {

	if (esNulaCola(c)) { 
		c->head = aux;
		c->last = aux;
	} else {
		(c->last).sig = aux;
		c->last = aux;
	}
}