#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>
#define C1 3
#define C2 3
//COMPILAR ASI: gcc -Wall origen.c -lm -o origen
///Funciones
/********************************/
void copi(int v[][C1], FILE *fp, int n);
/**********************/
int random_number(int xi, int xm);
/*********************************/
void voraz(int v[][C1], int fil, int con[][C2], int gr);
/***************************************/
int busca1(int v[][C1], int fil, int con[][C2], int gr);
/******************************/
float calc1(int v[][C1], int fil, int a, int b);
/*********************************************/
void clasifica(int v[][C1], int fil, int con[][C2], int gr);
/**********************************/
int lee(FILE *fp);
/*********************/
int main(){
	int n,g;//n-> numero de puntos 
			//g-> numero de subgrupos
	FILE *fp;
	
	printf("El algoritmo siguinte clasifica los puntos en grupos\n");
	printf("\n");
	fp = fopen ("dataset1.txt", "r" );        
	if (fp==NULL){
		fputs ("File error",stderr);
		exit (1);
	}
	n=lee(fp);//Leemos el nuemor de puntos
	g=lee(fp);//Leemos el numero de grupos
	printf("El numero de vertices es: %d, el numero de aritas es: %d \n",n,g);
	int v[n][C1];//mat de datos
	copi(v,fp,n);
	fclose(fp);
	int sol[g][C2];
	sol[0][0]=random_number(0,n);
	sol[0][1]=random_number(0,n-1);
	
	voraz(v,n,sol,g);//El algoritmo voraz calcula los grupos
	clasifica(v,n,sol,g);//La clasificacion se hace con un solo recorrido
	printf("\n");
	printf("Para el fichero de datos introducidos el resultado es:\n");
	for(int i=0; i<n; i++){
			printf(" %d ",v[i][2]);
		printf("\n");
	}
	
	printf("\n");
}
/*******************************************/
void voraz(int v[][C1], int fil, int con[][C2], int gr){
	int fila0;
	fila0=busca1(v,fil,con,0);
	con[1][0]=v[fila0][0];
	con[1][1]=v[fila0][1];
	int k=2;
	
	/*********************************/
	while(k < gr){
		int x=0;
		float dis,min,max=0;
		int faux;
		
		while(x < fil){
			min=5000;
			for (int i=0; i <k; i++){
				dis=calc1(v,x,con[i][0],con[i][1]);
				if (dis < min)
					min=dis;
			}
			if (min > max){
				max=min;
				faux=x;
			}
			x++;
		}
		con[k][0]=v[faux][0];
		con[k][1]=v[faux][1];
		k++;
	}
}
/***************************************/
void clasifica(int v[][C1], int fil, int con[][C2], int gr){
	printf("Los Puntos elegidos como centros son:\n");
	for (int i=0; i<gr; i++){
		for(int j=0; j<C2-1; j++){
			printf("%d ",con[i][j]);
		}
		printf("\n");
	}
	for (int i=0; i<fil; i++){
		float min=5000,dis;
		int valor,j;
		for (j=0; j<gr; j++){//compramos uno con los centors
				dis=calc1(v,i,con[j][0],con[j][1]);
				if (dis < min){
					min=dis;
					valor=j;
				}
		}
		v[i][2]=valor+1;
	}
}
/***************************************/
int busca1(int v[][C1], int fil, int con[][C2], int gr){
	int aux=0;
	float dis,adi=0;
	int sol;
	while (aux < fil){
		dis=calc1(v,aux,con[gr][0],con[gr][1]);
		if (dis  > adi){
			adi=dis;
			sol=aux;
		}
		aux++;
	}
	return sol;
}
float calc1(int v[][C1], int fil, int a, int b){
	return sqrt((v[fil][0]-a)*(v[fil][0]-a)+(v[fil][1]-b)*(v[fil][1]-b));
}
/******************************************/
void copi(int v[][C1], FILE *fp, int n){
	int i,j;
	i=0;
	while (feof(fp) == 0 && i < n){
		j=0;
		while (feof(fp) == 0 && j <C1-1 ){
			v[i][j]=lee(fp);
			j++;
		}
		i++;
	}
}
/****************************************************/
int random_number(int xi, int xm){
	int i,count=5,upper=xm;
	int num;
	int  lower=xi;
	srand(time(NULL));
    for (i = xi; i < count; i++) { 
		num = (rand() % (upper - lower + 1)) + lower; 
    } 
    return num;
}
/********************/
int lee(FILE *fp){
	char p;
	int c;
	p=fgetc(fp);
	c=0;
	while(feof(fp) == 0 && p != ' '){
			c=c*10+atoi(&p);
			p=fgetc(fp);
	}
	return c;
}

