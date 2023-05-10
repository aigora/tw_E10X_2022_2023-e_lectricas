#include <stdio.h>
#include "funciones.h"
#include "string.h"
#include <stdlib.h>
#define N 23
int main()
{
  tipos *energias;
  fecha *fech;
  char x;
  float med;
    int nLineas=0,pos;
    int numero;
    float max_total,min_total;
    int linea_actual;
    //reserva de memoria dinámica
  energias = malloc(sizeof(tipos) * N);
   fech = malloc(sizeof(fecha) * 1);
   //guardado de datos del fichero a las siguientes funciones
  guardar_datos_generacion_energias(energias);
  guardar_datos_generacion_fechas(fech);
  
printf("Introduzca el numero de la operaci?n que desea realizar\n");
  menu();//carga del menu
	scanf("%d",&numero);
	switch(numero){
		case 1:
		printf("CALCULOS ESTADISTICOS\n");
          med=mediana(energias);
		break;
		case 2:
		printf("CARGA DE NUEVOS DATOS\n");
		break;
		case 3:
		printf("GUARDAR RESULTADOS\n");
		break;
		case 4:
		printf("BUSQUEDAS\n");
        printf("%s\n", energias[0].tipo_energia);
        for(linea_actual=0;linea_actual<18;linea_actual++){
        	printf("%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",
       energias[linea_actual].cant_generada[0],
       energias[linea_actual].cant_generada[1], energias[linea_actual].cant_generada[2],
       energias[linea_actual].cant_generada[3], energias[linea_actual].cant_generada[4],
        energias[linea_actual].cant_generada[5], energias[linea_actual].cant_generada[6],
        energias[linea_actual].cant_generada[7], energias[linea_actual].cant_generada[8],
        energias[linea_actual].cant_generada[9], energias[linea_actual].cant_generada[10],
        energias[linea_actual].cant_generada[11], energias[linea_actual].cant_generada[12],
        energias[linea_actual].cant_generada[13], energias[linea_actual].cant_generada[14],
        energias[linea_actual].cant_generada[15], energias[linea_actual].cant_generada[16],
        energias[linea_actual].cant_generada[17], energias[linea_actual].cant_generada[18],
        energias[linea_actual].cant_generada[19], energias[linea_actual].cant_generada[20],
        energias[linea_actual].cant_generada[21], energias[linea_actual].cant_generada[22],
        energias[linea_actual].cant_generada[23]);
		}
       // printf("%d/%d\n", fech[5].month,fech[5].year); 
         break;
		case 5:
		printf("ORDENACION DE VALORES\n");
		 // Inicialización de la variable 'maximo' con el primer valor de 'cant_generada'
        max_total=valor_maximo(18,24,energias);
        min_total=valor_minimo(18,24,energias);
        printf("El valor mínimo de la cantidad generada de energia de todo el periodo analizadoes: %f\n", min_total);
        printf("El valor maximo de la cantidad generada de energia de todo el periodo analizado es: %.4f\n", max_total);
        
		break;
		default:
			printf("Error\n");
			break;
	}
        free(energias);
   free(fech);
  return 0;	
}

