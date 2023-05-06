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
    int nLineas=0,pos;
    int numero;
energias = malloc(sizeof(tipos) * N);
fech = malloc(sizeof(fecha) * 1);
  // Defino un vector para cada variable a leer del fichero	
  int i = 0;
  guardar_datos_generacion_energias(energias);
guardar_datos_generacion_fechas(fech);
 //Mostramos resultados
 printf("Introduzca el numero de la operaci?n que desea realizar\n");
menu();
	scanf("%d",&numero);
	switch(numero){
		case 1:
		printf("CALCULOS ESTADISTICOS\n");
		break;
		case 2:
		printf("CARGA DE NUEVOS DATOS\n");
		break;
		case 3:
		printf("GUARDAR RESULTADOS\n");
		break;
		case 4:
		printf("BUSQUEDAS\n");
    printf("%s\n", energias[5].tipo_energia);
    printf("%d/%d\n", fech[5].month,fech[5].year); 
		break;
		case 5:
		printf("ORDENACION DE VALORES\n");
		break;
		default:
			printf("Error\n");
			break;
	}
        free(energias);
   free(fech);
  return 0;	
}

