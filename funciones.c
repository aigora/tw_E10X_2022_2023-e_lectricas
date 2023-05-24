//implementaciÃƒÂ³n de las funciones
#include<stdio.h>
#include"funciones.h"
#include <string.h>
#define N 24
void menu(){
		printf("1.Calculos Estadisticos\n2.Carga de nuevos datos\n3.Guardar resultados\n4.Busquedas\n5.Ordenacion de valores\n6.Maximos y minimos\n");
}

void menu_calculos_estadisticos() {
	printf("1 - Mediana global\n2 - Media global\nOpcion seleccionada: ");
}
void menu_maximos_y_minimos(){
	printf("1.Maximo mensual\n 2.Minimo mensual\n 3.Maximo en un intervalo\n 4.Minimo en un intervalo\n");
}
void ordenar(){
	printf("1.Ordenación de mayor a menor\n 2.Ordenación de menor a mayor\n");
}

void guardar_datos_generacion_energias(tipos *datos){
	 FILE *pf;
	 int pos;
	  // Abrir el archivo de lectura
   pf = fopen("generacion_por_tecnologias.txt", "r");

  if (pf == NULL)
  {
    printf("Error al abrir el fichero de lectura");
  }
  else
  {
  	printf("Se ha abierto correctamente\n");
int linea_actual = 0;
    fseek(pf, 413, SEEK_SET);//situarnos en el fichero para que comience a leer y almacenar
 pos = ftell(pf);
    printf("La posiciÃƒÂ³n actual del puntero es %ld bytes.\n", pos);
while ( linea_actual <= 23) {
	fscanf(pf,"%[^,],%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f\n",
        datos[linea_actual].tipo_energia, &datos[linea_actual].cant_generada[0],
        &datos[linea_actual].cant_generada[1], &datos[linea_actual].cant_generada[2],
        &datos[linea_actual].cant_generada[3], &datos[linea_actual].cant_generada[4],
        &datos[linea_actual].cant_generada[5], &datos[linea_actual].cant_generada[6],
        &datos[linea_actual].cant_generada[7], &datos[linea_actual].cant_generada[8],
        &datos[linea_actual].cant_generada[9], &datos[linea_actual].cant_generada[10],
        &datos[linea_actual].cant_generada[11], &datos[linea_actual].cant_generada[12],
        &datos[linea_actual].cant_generada[13], &datos[linea_actual].cant_generada[14],
        &datos[linea_actual].cant_generada[15], &datos[linea_actual].cant_generada[16],
        &datos[linea_actual].cant_generada[17], &datos[linea_actual].cant_generada[18],
        &datos[linea_actual].cant_generada[19], &datos[linea_actual].cant_generada[20],
        &datos[linea_actual].cant_generada[21], &datos[linea_actual].cant_generada[22],
        &datos[linea_actual].cant_generada[23]);
    // Leer los datos de la lÃƒÂ­nea actual
    linea_actual++;
}
}
    // Se ha terminado de leer, luego se cierra el archivo
    fclose(pf);	
}
void guardar_datos_generacion_fechas(fecha *f){
	 FILE *pf;
	 int i = 0;
	 int pos;
	 char titulo[25];
  // Abrir el archivo de lectura
   pf = fopen("generacion_por_tecnologias.txt", "r");

  if (pf == NULL)
  {
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  }
  else
  {
  	  fseek(pf, 0, SEEK_SET);
  	printf("Se ha abierto correctamente\n");
int linea_actual = 0;
 pos = ftell(pf);
    fseek(pf, 250, SEEK_SET);
 pos = ftell(pf);
    printf("La posicion actual del puntero es %ld bytes.\n", pos);
    while ( linea_actual ==5) {
	fscanf(pf,"%s %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d %d/%d",titulo,&f[0].month,&f[0].year,&f[1].month,&f[1].year,&f[2].month,&f[2].year,&f[3].month,&f[3].year,
	&f[4].month,&f[4].year,&f[5].month,&f[5].year,&f[6].month,&f[6].year,&f[7].month,&f[7].year,&f[8].month,&f[8].year,
	&f[9].month,&f[9].year,&f[10].month,&f[10].year,&f[11].month,&f[11].year,&f[12].month,&f[12].year,&f[13].month,&f[13].year,
	&f[14].month,&f[14].year,&f[15].month,&f[15].year,&f[16].month,&f[16].year,&f[17].month,&f[17].year,&f[18].month,&f[19].year,
	&f[20].month,&f[20].year,&f[21].month,&f[21].year,&f[22].month,&f[22].year,&f[23].month,&f[23].year);
	linea_actual++;
}
}
    // Se ha terminado de leer, luego se cierra el archivo
    fclose(pf);	
}


// Calcular la mediana
float mediana(tipos *energias){
	// Crear el vector inicial vacio
	float* vector = NULL;
	int n = 0;

	// Agregar elementos
	int i;
    int j;
    for (i = 0; i < 17; i++) {
		for (j = 0; j < 24; j++) {
        	float elem = energias[i].cant_generada[j];
        vector = (int*) realloc(vector, sizeof(int) * (n+1));
        	vector[n] = elem;
        	n++;
        }
	}

	// Ordenar vector
	ordenar_vector(vector, n);

	// Calcular posicion de la mediana en la lista ordenada
	int posicion_mediana = n/2;

	if(n%2 == 0) {
		// Si la lista tiene un tamaño par, la mediana sera el promedio de los dos valores centrales
		return (vector[posicion_mediana-1] + vector[posicion_mediana])/2.0;
	} else {
		// Si la lista tiene un tamaño impar, la mediana sera el valor en la posicion central
		return vector[posicion_mediana];
	}

}
//calcular la media 


float  media(tipos*energias)
{
	// Crear el vector inicial vacio
	float* vector = NULL;
	int n = 0;

	// Agregar elementos
	int i;
    int j;
    for (i = 0; i < 17; i++) 
	{
		for (j = 0; j < 24; j++) {
        	float elem = energias[i].cant_generada[j];
        	vector = (int*) realloc(vector, sizeof(int) * (n+1));
        	vector[n] = elem;
        	n++;
        }
	}

    
    // Calcular la suma de los elementos
    float suma = 0;
    for (i = 0; i < n; i++) 
	{
        suma =  vector[i] +1 ;
    }
    
    // Calcular la media
    float media = suma / n;
    
    // Devolver el resultado de la media
    return media;
}

float varianza(tipos *energias)
{
    float* vector = NULL;
    int n = 0;
    float varianza = 0.0;
    float media = media;

    // Agregar elementos al vector
    int i,j;
    for ( i = 0; i < 17; i++)
	 {
        for ( j = 0; j < 24; j++)
		 {
            float elem = energias[i].cant_generada[j];
            vector = (float*)realloc(vector, sizeof(float) * (n + 1));
            vector[n] = elem;
            n++;
        }
    }

    // Calcula la suma de los cuadrados de las diferencias respecto a la media
    for (i = 0; i < n; i++) {
        varianza = varianza + pow(vector[i] - media, 2);
    }

    // Calcula la varianza
    varianza =varianza/ (n - 1);

    // Devolver el resultado de la varianza
    return varianza;
}

float desviacion_tipica(tipos *energias)
{
	
	float varianza;
	varianza = varianza;
	float desviacion_tipica;
	desviacion_tipica = sqrt(varianza);
	
	
	return desviacion_tipica;
	
	
	//hacer la raiz cuadrada de la varianza
}







void ordenar_vector(float vector[], int n){
	int i, j , min_index;
	for (i=0; i<n-1;i++){
		min_index = i;
		for (j=i+1; j<n; j++) {
			if(vector[j]<vector[min_index]){
				min_index = j;
			}
		}
		swap(&vector[min_index], &vector[i]);
	}
}

void swap(float* n1, float* n2){
	float n_temporal = *n1;
	*n1 = *n2;
	*n2 = n_temporal;
}


float valor_maximo(int filas,int columnas,int filas2,int columnas2,tipos *energias){
	 float maximo = energias[0].cant_generada[0];
        int i;
        int j;
        for (i = filas; i < filas2; i++) 
		{
			for (j = columnas; j < columnas2; j++) {
            if (energias[i].cant_generada[j] >= maximo) 
            {
            	//ActualizaciÃ³n del valor 'maximo'
            	maximo = energias[i].cant_generada[j];
			}
        }
    }
      printf("El valor maximo de la cantidad generada de energia de todo el periodo analizado es: %f\n", maximo);
      return maximo;
}
float valor_minimo(int filas,int columnas,int filas2,int columnas2,tipos *energias){
	int i;
	int j;
	float minimo = energias[0].cant_generada[0];
    for (i = filas; i < filas2; i++) 
	{
        for (j = columnas; j < columnas2; j++) 
		{
            if (energias[i].cant_generada[j] <= minimo) 
			{
				//ActualizaciÃ³n del valor 'minimo'
                minimo = energias[i].cant_generada[j];
            }
        }
    }
      printf("El valor minimo de la cantidad generada de energia de todo el periodo analizado es: %f\n", minimo);
    return minimo;
}
void ordenacion_minimo(int filas,tipos *energias){
	int i;
	int j;
	int k;
	float ener;
  //Ahora lo ordenamos
  for(i = 0; i < N - 1; i++)
  {
    // Comparamos cada elemento con el siguiente
    for(j = i + 1; j < N; j++)
    {
      if (energias[filas].cant_generada[i] > energias[filas].cant_generada[j])
      {
        // Si es mayor intercambiamos el contenido de los dos elementos
        ener = energias[filas].cant_generada[i]; //Necesitamos una variable auxiliar de almacenamiento temporal
        energias[filas].cant_generada[i] = energias[filas].cant_generada[j];
        energias[filas].cant_generada[j] =ener;
      }
    }
  }
    for(k=0;k<24;k++){
    	printf("%f\t",  energias[filas].cant_generada[k]);
	}
	printf("\n");
}
void ordenacion_maximo(int filas,tipos *energias){
	int i;
	int j;
	int k;
	float ener;
	   //Ahora lo ordenamos
  for(i = 0; i < N - 1; i++)
  {
    // Comparamos cada elemento con el siguiente
    for(j = i + 1; j < N; j++)
    {
      if (energias[filas].cant_generada[i] < energias[filas].cant_generada[j])
      {
        // Si es mayor intercambiamos el contenido de los dos elementos
        ener = energias[filas].cant_generada[i]; //Necesitamos una variable auxiliar de almacenamiento temporal
        energias[filas].cant_generada[i] = energias[filas].cant_generada[j];
        energias[filas].cant_generada[j] =ener;
      }
    }
  }

    for(k=0;k<24;k++){
    	printf("%f\t",  energias[filas].cant_generada[k]);
	}
	printf("\n");
}

void buscar(char cadena[40],tipos *energias){
	FILE *pf;
	int i=0;
	char buscar[40];
	pf = fopen("generacion_por_tecnologias.txt", "r");
while (fscanf(pf, "%s", buscar) != EOF) {
    if (strcmp(buscar, cadena) == 0) {
   printf("Se ha encontrado este tipo de energía\n");
   break;
}
i++;
}
printf("No se ha encontrado este tipo de energía\n");
printf("Desea añadir a la lista anterior\n");
fclose(pf);
}
int cerrar(){
	int p;
	printf("Desea cerrar sesión\n");
	printf("1. Si\n 2. No\n");
	scanf("%d",&p);
	if(p==2){
		system("cls");
	}
return p;
}
