#include<stdio.h>

typedef struct _edge{
        int origen;
        int destino;
        int peso;
}Edge;

main(){
	//No puedes modificar este codigo
	int v,a,i,j;
	printf("Introduce el numero de vertices: ");
	scanf("%d",&v);
	printf("Introduce el numero de aristas: ");
	scanf("%d",&a);
	int matriz[v][v];
	printf("Introduce los pesos de las aristas. 0 si no existe la arista\n");
	for(i=0;i<v;i++){
		for(j=i+1;j<v;j++){
			printf("Arista %d-%d: ",i,j);
			scanf("%d",&matriz[i][j]);
		}
	}
	//A partir de aqui puedes escribir todo lo que necesites

}

//Vamos a crear una lista que almacenara los nodos de cada subgrafo
/*La idea es recorrer la matriz y crear tanatas listas como subgrafos 
existan. Para ello, cada vez que accedamos a un elemto de la matriz 
comprobaremos si su origen o destino no pertencen ya a la tabla, en el caso de 
ser asi añadiremos el origen/destino a la tabla y eliminaremos ese elemento
de la matriz*/



void ARCM(int v, int a, int m[v][v], int ){
     
     Edge edgeList[a];

     crearListaAristas(v, m, a, edgeList);
     
     sortListaAristas(a, edgeList);
     
     while(matrizNula == 0){
     int x = 0;
     int arr[1024];
          for(int i=0; i < v; i++)
                  for(int j = i + 1; j < v; j++){
                          if(m[i][j] != 0){
                              if(buscarNodo(i, arr) != 1){
                                               arr[x] = i;
                                               x++;
                              }
                                    
                              if(buscarNodo(j, arr) != 1){
                                               arr[x] = j;
                                               x++;
                              }
                              m[i][j] == 0;
                          }
          ARCM(v, a, edgeList);
     }
}

int matrizNula(int m[v], m[v]){
    int x = 1;//Nula
     for(int i=0; i < v; i++)
              for(int j = i + 1; j < v; j++)
                      if( (m[i][j] != 0){
                          x = 0;//no nula
                          break;
                      }
     return x;
}


int buscarNodo(int a, int arr1[]){
    int x = 0;
     for(int i=0; i < v; i++)
             if(arr1[i] == a){
                        x = 1;
                        break;
             }
     return x;
}
             
//Creamos un array de tipo edge que contiene las aristas 
void crearListaAristas(int v, int m[v][v], int a, Edge edgeList[a]){
         for(int i=0; i < v; i++)
		                  for(int j = i + 1; j < v; j++)
                                             if(m[i][j] != 0){
                                                      arr[i].origen = i;
                                                      arr[i].destino = j;
                                                      arr[i].peso = m[i][j];
                                             }
}

//Ordenacion mediante burbuja
void sortListaAristas( int a, Edge edgeList[a], int arr[]){
     for(int i = 0; i < a - 1; i++)
             if(edgeList[i + 1].peso < edgeList[i].peso){
                           int x = edgeList[i];
                           edgeList[i] = edgeList[i + 1];
                           edgeList[i + 1] = edgeList[i];
             }
}
     

//Creamos el arbol recubridor de coste minimo
void  ARCM(int v, int a, Edge edgeList[a]){  
          
      //Lista con el valor de los nodos
      int list[v];
      
      //Coste del subarbol
      int coste = 0; 
      
      //LLenamos la lista con el numero de nodos
      for(int i = 0; i < v-1; i++)
              list[v] = i;
              
      //Creamos nuestro arbol recubridor de minimo coste(evitando los ciclos)
      for(int i = 0; i < a; i++)
              if(edgeList[i].destino == list[edgeList[i].destino]){
                                     printf("Arista: %d - %d de peso %d", edgeList[i].origen, edgeList[i].destino, edgeList[i].peso);
                                     for(int j = 0; j < v; j++)
                                             if(list[j] = edgeList[i].destino)
                                                        list[j] = edgeList[i].origen;
                                     coste += edgeList[i].peso;
              }
      printf("El bosque recubridor tiene %d componentes");
      printf("El coste del arbol recubridor es %d", coste);
}

