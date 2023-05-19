#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
#define N 23
int main()
{
	tipos *energias;
	fecha *fech;
	char x;
	int tipo;
	int tam;
	float mediana_global;
	float media_global;
	float varianza_global;
	float desviacion_tipica_global;
	int nLineas=0,pos;
	int numero;
	int num_calculos_estadisticos;
	int r,z,f,p,op,t;
	float max_total,min_total;
	float min_year, max_year;
	int linea_actual;
	char cad[40];
	// Reserva de memoria dinamica
	energias = malloc(sizeof(tipos) * N);
	fech = malloc(sizeof(fecha) * 1);
   	// Guardado de datos del fichero a las siguientes funciones
  	guardar_datos_generacion_energias(energias);
  	guardar_datos_generacion_fechas(fech);
  do{
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
					case 4:
						//desviacion_tipica_global = desviacion_tipica(energias)
						printf("La desviacion tipica de todos los datos es: %f\n",desviacion_tipica_global);
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
				printf("Introduzca la palabra que desea buscar con la primera letra en mayuscula\n");
				scanf("%s",cad);
		       buscar(cad,energias);
	        
	       		// printf("%d/%d\n", fech[5].month,fech[5].year); 
	         	break;
	         
			case 5:
				printf("ORDENACION DE VALORES\n");
				// InicializaciÃ³n de la variable 'maximo' con el primer valor de 'cant_generada'
				printf("Introduzca el tipo de energía del cual quiere ver el máximo\n");
				scanf("%d",&p);
			     ordenar();
				scanf("%d",&op);
				if(op==1){
			      ordenacion_minimo(p,energias);
				}
			    else
				  ordenacion_maximo(p,energias);
				break;
			 
	        case 6:   	
	        printf("Maximos y minimos");

	        printf("Introduzca 1 quiere ver un valor maximo o minimo mensual y 2 si lo quiere ver en un periodo");
	        scanf("%d",&r);
	        if(r==1){
	        printf("Introduzca el mes del cual quiere ver el maximo\n");
	        scanf("%d",&z);
	        min_year=valor_minimo(0,z-1,17,z,energias);
	        max_year=valor_maximo(0,z-1,17,z,energias);
	        
	        case 7:
	        	switch(tipo);
	        	{
	        		printf("Pulsa el numero del tipo de energia que desee \n");
	        		printf("1- Eolica\n 2-Turbinacion bombeo \n");
				}
	}
	else {
		      printf("Introduzca el periodo del cual quiere ver el maximo de los meses entre(1-24)\n");
	        scanf("%d %d",&z,&f);
	        min_year=valor_minimo(0,z,17,f,energias);
	        max_year=valor_maximo(0,z,17,f,energias);
	}
	        min_total=valor_minimo(0,0,17,24,energias);
	        max_total=valor_maximo(0,0,17,24,energias);

	        	printf("Seleccione si quiere calcular un máximo o mínimo:\n");
				menu_maximos_y_minimos();
				scanf("%d",&r);
				switch(r){
					case 1:
			           printf("Introduzca el mes del cual quiere ver el maximo (0-24)\n");
	                   scanf("%d",&z);
	                   max_year=valor_maximo(0,z-1,17,z,energias);
					   break;
					case 2:
						printf("Introduzca el mes del cual quiere ver el minimo\n");
	                    scanf("%d",&z);
						min_year=valor_minimo(0,z-1,17,z,energias);
						break;		
					case 3:
						printf("Introduzca el periodo del cual quiere ver el maximo de los meses entre(1-24)\n");
	                    scanf("%d %d",&z,&f);
						max_year=valor_maximo(0,z,17,f,energias);
						break;
				    case 4:
						printf("Introduzca el periodo del cual quiere ver el minimo de los meses entre(1-24)\n");
	                    scanf("%d %d",&z,&f);
					    min_year=valor_minimo(0,z,17,f,energias);
						break;	
					case 5:
					   printf("Minimo y máximo totales\n");
					   min_total=valor_minimo(0,0,17,24,energias);	
	                   max_total=valor_maximo(0,0,17,24,energias);
	                   break;
				}
				
			break;
			
			default:
				printf("Error\n");
				break;
		}
	}while(cerrar()!=1);
		printf("Hasta pronto\n");
	        free(energias);
	   free(fech);
	  return 0;	
	}

