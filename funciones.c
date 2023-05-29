//implementacion de las funciones
#include<stdio.h>
#include"funciones.h"
#include <string.h>
#define N 24
#include <math.h>
#include <stdlib.h>
void menu(){
		printf("1.Calculos Estadisticos\n2.Carga de nuevos datos\n3.Guardar resultados\n4.Busquedas\n5.Ordenacion de valores\n6.Maximos y minimos\n7.Imprimir valores\n");
}

void menu_calculos_estadisticos() {
	printf("1 - Mediana global\n2 - Media global\n 3-Varianza global\n 4-Desviacion tipica global\n 5-Moda global \n 6-Rango global\nOpcion seleccionada: ");
}
void menu_maximos_y_minimos(){
	printf("1.Maximo mensual\n 2.Minimo mensual\n 3.Maximo en un intervalo\n 4.Minimo en un intervalo\n");
}
	void menu_calculos_estadisticos_mensuales(){
	printf(" 1.Media mensual\n 2.Mediana mensual\n 3.Moda mensual\n 4.Varianza mensual\n 5.Desviacion tipica mensual\n 6. Rango mensual\n Opcion seleccionada:");
	}
void ordenar(){
	printf("1.Ordenacion de mayor a menor\n 2.Ordenacion de menor a mayor\n");
}
void menu_calculos_estadisticos_energia_especifica(){
	printf(" 1-Hidraulica\n 2-Turbinacion bombeo \n 3-Nuclear\n 4-Carbon\n 5-Motores diesel\n 6-Turbina de gas\n 7-Turbina de motor\n");
	printf(" 8-Ciclo combinado \n 9-Hidroeolica\n 10-Eolica\n 11-Solar fotovoltaica\n 12-Solar termica\n 13-Otros renovables\n 14-Congeneracion\n");
	printf(" 15-Residuos no renovables \n 16-Residuos renovables\n 17-Generacion total\n ");
}
void menu_tipo_energia_ordenacion_valores(){
	printf(" 0-Hidraulica\n 1-Turbinacion bombeo \n 2-Nuclear\n 3-Carbon\n 4-Motores diesel\n 5-Turbina de gas\n 6-Turbina de motor\n");
	printf(" 7-Ciclo combinado \n 8-Hidroeolica\n 9-Eolica\n 10-Solar fotovoltaica\n 11-Solar termica\n 12-Otros renovables\n 13-Congeneracion\n");
	printf(" 14-Residuos no renovables \n 15-Residuos renovables\n 16-Generacion total\n ");
}
void imprimir_datos_fichero(){
	printf("1.Imprimir todos los datos ordenados en meses\n 2.Imprimir los datos de un mes\n 3. Imprimir los datos de una energia\n");
}
void guardar_datos_generacion_energias(tipos *datos){
	 FILE *pf;
	 int pos;
	  // Abrir el archivo de lectura
   pf = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

  if (pf == NULL)
  {
    printf("Error al abrir el fichero de lectura");
  }
  else
  {
  	printf("Se ha abierto correctamente\n");
int linea_actual = 0;
    fseek(pf, 390, SEEK_SET);//situarnos en el fichero para que comience a leer y almacenar
 pos = ftell(pf);
   // printf("La posicion actual del puntero es %ld bytes.\n", pos);
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
    // Leer los datos de la lÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­nea actual
    linea_actual++;
}
}
    // Se ha terminado de leer, luego se cierra el archivo
    fclose(pf);	
}
void guardar_datos_generacion_fechas(fecha *f){
     FILE *pf;
     int i = 0,j;
     int pos;
     char lectura;
  // Abrir el archivo de lectura
   pf = fopen("generacion_por_tecnologias_21_22_puntos_simplificado.csv", "r");

  if (pf == NULL)
  {
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  }
  else
  {
      printf("Se ha abierto correctamente\n");
             fseek(pf,216, SEEK_SET);
             pos=tell(pf);
                // printf("La posicion actual del puntero es %ld bytes.\n", pos);
                for(i=0;i<24;i++){
                    fscanf(pf,"%d-%d",&f[i].month,&f[i].year);
                    fscanf(pf,"%c",&lectura);
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
		// Si la lista tiene un tamanyo par, la mediana sera el promedio de los dos valores centrales
		return (vector[posicion_mediana-1] + vector[posicion_mediana])/2.0;
	} else {
		// Si la lista tiene un tamanyo impar, la mediana sera el valor en la posicion central
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
    for (i = 0; i < n; i++) {
        varianza = varianza + pow(vector[i] - media, 2); //operacion correspondiente al calculo de la varianza
    }

    
    varianza =varianza/ (n - 1);

    // Devolver el resultado de la varianza
    return varianza;
}

float desviacion_tipica(tipos *energias)
{
	
	float varianza;
	varianza = varianza;
	float desviacion_tipica;
	desviacion_tipica = sqrt(varianza);//opereacion correspondiente al calculo de la desviacion tipica
	
	
	return desviacion_tipica;
	
	
	
}

float moda_global(tipos*energias)
{
	int i,j;
	
	float* vector= NULL;
	int frecuencia=0;
    int n = 0;
    float moda = 0; // Valor inicial para la moda
    int frecuencia_max = 0; // Valor inicial para la frecuencia mÃ¡xima
    float elem;
    for ( i = 0; i < 18; i++)
	 {
        for ( j = 0; j < 24; j++)
		 {     
             elem = energias[i].cant_generada[j];
            vector = (float*)realloc(vector, sizeof(float) * (n + 1));
            vector[n] = elem;
            n++;
        }
    }

        if (frecuencia > frecuencia_max)  //operacion asignada al calculo de la moda
		{
            frecuencia_max= frecuencia; 
            moda = energias[i].cant_generada[j]; 
        }
   return moda;
}
float rango_global(tipos*energias)
{
	int filas=0, columnas=0, filas2=0, columnas2=0;
	float maximo= valor_maximo(filas, columnas, filas2, columnas2, energias); 
	float minimo = valor_minimo(filas, columnas, filas2, columnas2, energias);
	float rango = fabs(maximo-minimo);//operacion asignada al calculo del rango
	return rango;
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
            	//ActualizaciÃƒÆ’Ã‚Â³n del valor 'maximo'
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
				//Actualizacion del valor 'minimo'
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
  for(i = 0; i < N - 2; i++)
  {
    for(j = i + 2; j < N; j++)
    {
      if (energias[filas].cant_generada[i] > energias[filas].cant_generada[j])
      {
        // Si es mayor intercambiamos el contenido de los dos elementos
        ener = energias[filas].cant_generada[i]; 
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


void buscar(char cadena[40],tipos *energia) {
	int j;
	int p=0;
	int num=0;
    	for(j=0;j<18;j++){
    		if(strcmp(cadena, energia[j].tipo_energia) == 0){
    			p=1;
			}
	}
	if(p==1){
		printf("Se ha encontrado el tipo de energia");
	}
	else{
	printf("No se ha encontrado\n");
	printf("Desea añadirla\n");
	printf("Si desea añadirla pulse 1 sino 2");
	scanf("%d",&num);
	if(num==1){
		//funcion añadir datos
	}
	else
	printf("No se ha guardado el dato\n");
}
}

int cerrar(int k){
	int p;
	if(k==1){
	printf("Desea cerrar sesion\n");
	printf("1. Si\n 2. No\n");
	scanf("%d",&p);
	if(p==2){
		system("cls");
	}
}
else if(k==2){
	printf("Desea seguir haciendo calculos\n");
	printf("1. No\n 2. Si\n");
	scanf("%d",&p);
	if(p==2){
		system("cls");
	}
}
else
printf("Error");
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
float mediana2(int m, tipos *energias)//funcion para calculo anual y mensual
{
    int i, j;
    int n = 24; 

    float valores[n];
    for (i = 0; i < n; i++) 
    {
        valores[i] = energias[m].cant_generada[i];
    }

    // Ordenamos los datos de forma ascendente 
    for (i = 0; i < n - 1; i++) 
    {
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
        // Si hay un numero par de elementos, la mediana sera el promedio de los dos valores centrales
        mediana2 = (valores[n / 2 - 1] + valores[n / 2]) / 2.0;
    } 
	else 
	{
        // Si hay un numero impar de elementos, tomamos el valor del medio
        mediana2 = valores[n / 2];
    }

    return mediana2;
}
float moda2(int m, tipos *energias)//funcion para calculo anual y mensual
{
    int i, j;
    // Valor inicial para la moda
    int moda2 = 0; 
    // Valor inicial para la frecuencia maxima
    int maxFrecuencia = 0; 

    for (i = 0; i < 24; i++) {
        int frecuencia = 0; 

        for (j = 0; j < 24; j++) {
            if (energias[m].cant_generada[i] == energias[m].cant_generada[j]) 
	    {
		// Incrementar la frecuencia
                frecuencia++; 
            }
        }

        if (frecuencia > maxFrecuencia) 
	{
	    // Actualizar la frecuencia maxima
            maxFrecuencia = frecuencia; 
	    // Actualizar la moda
            moda2 = energias[m].cant_generada[i]; 
        }
    }

    return moda2;
}
	
void guardar_fecha_tipos(fecha *fech,tipos *energias){
	int m,n;
	  	for(m=0;m<18;m++){
  		  	for(n=0;n<24;n++){
  		energias[m].f[n].month=fech[n].month;
  			energias[m].f[n].year=fech[n].year;
	  }
}
}
float varianza2(int m, tipos *energias)//funcion para calculo anual y mensual
{
    int i;
    int n = 24;
    // Calcula la media utilizando otra función
    float media = media2(m, energias);
    float suma = 0;

    for (i = 0; i < n; i++) 
    {
	// Calcula la diferencia entre la cantidad generada y la media
        float diferencia = energias[m].cant_generada[i] - media;
        suma = suma+(diferencia * diferencia);
    }
    // Calcula la varianza al cuadrado dividiendo la suma entre n
    float varianza2 = suma / n;

    return varianza2;
}

float desviacion_tipica_2(int m, tipos *energias)//funcion para calculo anual y mensual
{
    // Calcula la varianza utilizando otra función
    float varianza = varianza2(m, energias);
    // Calcula la raíz cuadrada de la varianza para obtener la desviación típica
    float desviacion_tipica_2 = sqrt(varianza);

    return desviacion_tipica_2;
}

float rango2(int m, tipos *energias) //funcion para calculo anual y mensual
{
    // Inicializa el mínimo y el máximo con el primer valor de la cantidad generada
    float min = energias[m].cant_generada[0];
    float max = energias[m].cant_generada[0];
    int i;

    for (i = 1; i < 24; i++) 
	{
        if (energias[m].cant_generada[i] < min) 
	{
	    // Actualiza el mínimo si se encuentra un valor menor
            min = energias[m].cant_generada[i];
        }

        if (energias[m].cant_generada[i] > max) 
	{
	    // Actualiza el máximo si se encuentra un valor mayor
            max = energias[m].cant_generada[i];
        }
    }
    // Calcula el valor absoluto de la diferencia entre el máximo y el mínimo
    float rango2=fabs(max-min);

    return rango2;
}


void guardado_de_datos(char *tipo_calc,float datos,  char* archivo){	
FILE *pf;
 pf = fopen(archivo, "a");
  if (pf == NULL)
  {
    printf("ERROR AL ABRIR EL FICHERO DE LECTURA");
  }
  else
  {
   printf("Se ha abierto correctamente\n");

    fprintf(pf, "%s %f\n",tipo_calc,datos);
    printf("Se ha guardado");
    fclose(pf);
}
}
void vaciar_archivo(char* archivo){
    FILE* pf = fopen(archivo, "w");
    if (pf != NULL ){
        fclose(pf);
}
}
