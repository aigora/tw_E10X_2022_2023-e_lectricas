//implementaciÃƒÂ³n de las funciones
#include<stdio.h>
#include"funciones.h"
#include <string.h>
#define N 24
void menu(){
		printf("1.Calculos Estadisticos\n2.Carga de nuevos datos\n3.Guardar resultados\n4.Busquedas\n5.Ordenacion de valores\n6.Maximos y minimos\n7.Mostrar datos archivo\n");
}

void menu_calculos_estadisticos() {
	printf("1 - Mediana global\n2 - Media global\n Opcion seleccionada: ");
}
	void menu_calculos_estadisticos_mensuales(){
		printf("1.Media mensual\n2.Mediana mensual\n3.Moda\nOpcion seleccionada:");
	}
void menu_maximos_y_minimos(){
	printf("1.Maximo mensual\n 2.Minimo mensual\n 3.Maximo en un intervalo\n 4.Minimo en un intervalo\n");
}
void ordenar(){
	printf("1.Ordenación de mayor a menor\n 2.Ordenación de menor a mayor\n");
}
void menu_calculos_estadisticos_energia_especifica(){
	printf(" 1-Hidraulica\n 2-Turbinacion bombeo \n 3-Nuclear\n 4-Carbon\n 5-Motores diésel\n 6-Turbina de gas\n 7-Turbina de motor\n");
	printf(" 8-Ciclo combinado \n 9-Hidroeolica\n 10-Eolica\n 11-Solar fotovoltaica\n 12-Solar termica\n 13-Otros renovables\n 14-Congeneracion\n");
	printf(" 15-Residuos no renovables \n 16-Residuos renovables\n 17-Generacion total\n ");
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
void guardar_datos_generacion_fechas(tipos *datos){
     FILE *pf;
     int i = 0,j;
     int pos;
     char lectura;
     char titulo[25];
     int linea_actual = 0;
  // Abrir el archivo de lectura
   pf = fopen("generacion_por_tecnologias.txt", "r");

  if (pf == NULL)
  {
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  }
  else
  {
      printf("Se ha abierto correctamente\n");
int linea_actual = 0;
    printf("La posicion actual del puntero es %ld bytes.\n", pos);
    while(fscanf(pf,"%c",&lectura)!=EOF){
        if(lectura=='\n'){
            linea_actual++;
            if(linea_actual==4){
             fseek(pf,220, SEEK_SET);
                            for(i=0;i<24;i++){
                                        for(j=0;j<18;j++){
                    fscanf(pf,"%d/%d,",&datos[j].f[i].month,&datos[j].f[i].year);
                    }
}
             }

        }

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

float varianza_global(tipos *energias)
{
	
	
	
	
}



float desviacion_tipica_global(tipos *energias)
{
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
float media2(int m,tipos *energias)//funcion para calculo anual y mensual
{
	int i;
	float med=0;
	for(i=0;i<24;i++){
		med+=energias[m].cant_generada[i];
	}
	med=med/24;
	return med;
}
float mediana2(int m, tipos *energias)
{
    int i, j;
    int n = 24; // Número de elementos en el arreglo

    float valores[n];
    for (i = 0; i < n; i++) {
        valores[i] = energias[m].cant_generada[i];
    }

    // Ordenamos los datos de forma ascendente 
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) 
		{
            if (valores[j] > valores[j + 1]) 
			{
                float temp = valores[j];
                valores[j] = valores[j + 1];
                valores[j + 1] = temp;
            }
        }
    }


    float mediana2;
    if (n % 2 == 0) 
	{
        // Si hay un número par de elementos, la mediana sera el promedio de los dos valores centrales
        mediana2 = (valores[n / 2 - 1] + valores[n / 2]) / 2.0;
    } 
	else 
	{
        // Si hay un número impar de elementos, tomamos el valor del medio
        mediana2 = valores[n / 2];
    }

    return mediana2;
}
float moda2(int m, tipos *energias)
{
	int i, j;

    int moda2 = 0; // Valor inicial para la moda
    int maxFrecuencia = 0; // Valor inicial para la frecuencia máxima

    for (i = 0; i < 24; i++) {
        int frecuencia = 0; 

        for (j = 0; j < 24; j++) {
            if (energias[m].cant_generada[i] == energias[m].cant_generada[j]) {
                frecuencia++; // Incrementar la frecuencia
            }
        }

        if (frecuencia > maxFrecuencia) 
		{
            maxFrecuencia = frecuencia; // Actualizar la frecuencia máxima
            moda2 = energias[m].cant_generada[i]; // Actualizar la moda
        }
    }

    return moda2;
}
	



