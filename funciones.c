//implementaciÃ³n de las funciones
#include<stdio.h>
#include"funciones.h"
#include "string.h"
void menu(){
		printf("1.Calculos Estadisticos\n2.Carga de nuevos datos\n3.Guardar resultados\n4.Busquedas\n5.Ordenacion de valores\n");
}

void guardar_datos_generacion_energias(tipos *datos){
	 FILE *pf;
	 int pos;
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
    fseek(pf, 413, SEEK_SET);
 pos = ftell(pf);
    printf("La posiciÃ³n actual del puntero es %ld bytes.\n", pos);
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
    // Leer los datos de la lÃ­nea actual
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
    printf("La posiciÃ³n actual del puntero es %ld bytes.\n", pos);
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
float mediana(tipos *datos){
	 int n, i; //n es el numero de valores segun el año que elijamos 
	   float mediana, mediana2;
    float num, sum = 0, media;

    for (i = 1; i <= n; ++i)
	{
        printf("Ingrese el valor %d: ", i);
        scanf("%f", &num);
        sum += num;
    }

  media = sum / n;
    printf("La media es: %.2f", media);		
    //para n numero de datos 

    // Leer los datos y calcular la mediana
    for (i = 0; i < n; i++) {
        scanf("%f", &mediana2);
        if (i == n / 2) {  // Si se ha leído la mitad de los datos, almacenar la mediana y salir del bucle
            mediana = mediana2;
            if (n % 2 == 0) {  // Si el número de elementos es par, leer un valor adicional y calcular la mediana como el promedio de los dos valores centrales
                mediana= (mediana + mediana2) / 2;
            }
            break;
        }
    }

    printf("La mediana es: %f", mediana);

    return 0;
}

float valor_maximo(int filas,int columnas,tipos *energias){
	 float maximo = energias[0].cant_generada[0];
        int i;
        int j;
        for (i = 0; i < filas; i++) 
		{
			for (j = 0; j < columnas; j++) {
            if (energias[i].cant_generada[j] >= maximo) 
            {
            	//Actualización del valor 'maximo'
            	maximo = energias[i].cant_generada[j];
            	printf("%f\n",maximo);
			}
        }
    }
      return maximo;
    // Inicialización de la variable 'minimo' con el primer valor de 'cant_generada'
}
float valor_minimo(int filas,int columnas,tipos *energias){
	int i;
	int j;
	float minimo = energias[0].cant_generada[0];
    for (i = 0; i < filas; i++) 
	{
        for (j = 0; j < columnas; j++) 
		{
            if (energias[i].cant_generada[j] <= minimo) 
			{
				//Actualización del valor 'minimo'
                minimo = energias[i].cant_generada[j];
            }
        }
    }
    return minimo;
}
