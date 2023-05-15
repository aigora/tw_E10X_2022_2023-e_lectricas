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
	int tam;
	float mediana_global;
	float media_global;
	float varianza_global;
	int nLineas=0,pos;
	int numero;
	int num_calculos_estadisticos;
	int r,z,f;
	float max_total,min_total;
	float min_year, max_year;
	int linea_actual;
	// Reserva de memoria dinamica
	energias = malloc(sizeof(tipos) * N);
	fech = malloc(sizeof(fecha) * 1);
   	// Guardado de datos del fichero a las siguientes funciones
  	guardar_datos_generacion_energias(energias);
  	guardar_datos_generacion_fechas(fech);
  
	printf("Introduzca el numero de la operacion que desea realizar:\n");
	  menu(); //carga del menu
		scanf("%d",&numero);
		switch(numero){
			case 1:
			printf("Seleccione el calculo estadistico a realizar:\n");
				menu_calculos_estadisticos();
				scanf("%d",&num_calculos_estadisticos);
				switch(num_calculos_estadisticos){
					case 1:
						mediana_global=mediana(energias);
						printf("La mediana de todos los datos es: %f\n", mediana_global);
						break;
					case 2:
						media_global=media(energias);
						printf("La media de todos los datos es: %f\n", media_global);
						break;		
					case 3:
						//varianza_global= varianza(energias)
						printf("La varianza de todos los datos es : %f\n", varianza_global);
						break;
				}
	          	
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
				ordenacion_minimo(8,energias);
				ordenacion_maximo(8,energias);
				break;
			 
	            case 6:
	        printf("Maximos y minimos");
	        printf("Introduzca 1 quiere ver un valor maximo o minimo menusal y 2 si lo quiere ver en un periodo");
	        scanf("%d",&r);
	        if(r==1){
	        printf("Introduzca el mes del cual quiere ver el maximo\n");
	        scanf("%d",&z);
	        min_year=valor_minimo(0,z-1,17,z,energias);
	        max_year=valor_maximo(0,z-1,17,z,energias);
	}
	else {
		      printf("Introduzca el periodo del cual quiere ver el maximo de los meses entre(1-24)\n");
	        scanf("%d %d",&z,&f);
	        min_year=valor_minimo(0,z,17,f,energias);
	        max_year=valor_maximo(0,z,17,f,energias);
	}
	        min_total=valor_minimo(0,0,17,24,energias);
	        max_total=valor_maximo(0,0,17,24,energias);
			break;
			default:
				printf("Error\n");
				break;
		}
	        free(energias);
	   free(fech);
	  return 0;	
	}

