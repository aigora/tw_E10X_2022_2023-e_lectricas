#include <stdio.h>
#include "funciones.h"
#include <string.h>
#include <stdlib.h>
#define N 23
int main()
{
	tipos *energias,*ener;
	char x;
	int num;
	int tipo;
	int tam;
	float mediana_global;
	float media_global;
	float varianza_global;
	float desviacion_tipica_global;
	int nLineas=0,pos;
	int numero;
	int num_calculos_estadisticos,num_calculos_estadisticos_mensuales;
	float med_tipo_energia;
	float mediana2_tipo_energia;
	float moda2_tipo_energia;
	float varianza2_tipo_energia;
	int calculos_estadisticos_energia_especifica;
	int r,z,f,p,op,t;
	float max_total,min_total;
	float min_year, max_year;
	int linea_actual;
	char cad[40];
	// Reserva de memoria dinamica
	energias = malloc(sizeof(tipos) * N);
	ener = malloc(sizeof(tipos) * 1);
   	// Guardado de datos del fichero a las siguientes funciones
  	guardar_datos_generacion_energias(energias);
  	guardar_datos_generacion_fechas(energias);
  do{
	printf("Introduzca el numero de la operacion que desea realizar:\n");
	  menu(); //carga del menu
		scanf("%d",&numero);
		switch(numero){
			case 1:
				printf("Seleccione si desea realizar los calculos estadisticos\n1.Globales\n2.De un tipo de energia especifica\n");
				scanf("%d",&num);
				if(num==1)
				{
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
			}
			   else if(num==2)
			   {
			   	    printf("Pulsa el tipo de energia que desee \n");
	        	    menu_calculos_estadisticos_energia_especifica();
	        	    scanf("%d",&calculos_estadisticos_energia_especifica);
	        	    	system("cls");
					printf("Seleccione el calculo estadistico a realizar:\n");
					menu_calculos_estadisticos_mensuales();
					   scanf("%d",&num_calculos_estadisticos_mensuales);
					   switch(num_calculos_estadisticos_mensuales)
					   {
					   	case 1:
					   		med_tipo_energia=media2(calculos_estadisticos_energia_especifica,energias);//funcion calculo anual y mensual
					   		 printf("%f\n",med_tipo_energia);
					   		break;
					   	case 2:
					   		mediana2_tipo_energia=mediana2(calculos_estadisticos_energia_especifica,energias);
					   		printf("%f\n",mediana2_tipo_energia);
					   			break;
					   	case 3:
					   		moda2_tipo_energia=moda2(calculos_estadisticos_energia_especifica,energias);
					   		printf("%f\n",moda2_tipo_energia);
					   		break;
					   	case 4:
					   		varianza2_tipo_energia=moda2(calculos_estadisticos_energia_especifica,energias);
					   		printf("%f\n",varianza2_tipo_energia);
					   		break;
					   	default:
					   		printf("Error\n");
					   		break;
					   	
					   	
					   }
				    }
				    else
					{
						printf("Error\n");
					}
				break;
			case 2:
				printf("CARGA DE NUEVOS DATOS\n");
                printf("Introduzca el n�mero de datos que desea agregar: ");
                scanf("%d", &tam);

                // Aumentar el tama�o del arreglo din�mico para contener los nuevos datos
                energias = realloc(energias, sizeof(tipos) * (N + tam));
                int i;
                int j;
                int n=23;
                for (i = n; i < n + tam; i++) 
				{
                    printf("Datos para el nuevo registro %d:\n", i + 1);

                    // Solicitar los datos al usuario
                    printf("Ingrese el tipo de energ�a: ");
                    scanf("%s", &energias[i].tipo_energia);

                    printf("Ingrese la fecha (formato: mes a�o): ");
                    scanf("%d %d", &energias[i].f[0].month, &energias[i].f[0].year);

                    printf("Ingrese la cantidad generada: ");
                    for(j=0;j<24;j++){
                    	     scanf("%f", &energias[i].cant_generada[j]);
					}
                }
                n = n + tam; // Actualizo el tama�o total del arreglo.
                printf("Los nuevos datos se han agregado correctamente.\n");
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
				printf("Introduzca el tipo de energía del cual quiere ver el máximo de (0-17)\n");//por ahora se pone de 0 a 17 y luego imprimo 
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
					   printf("Minimo y maximo totales\n");
			  min_total=valor_minimo(0,0,17,24,energias);	
	                   max_total=valor_maximo(0,0,17,24,energias);
	                   break;
	                default:
	                	printf("Error\n");
	                	break;
				}
				break;
			case 7:
				printf("%d/%d\n",energias[3].f[0].month,energias[3].f[0].year);
				break;
			default:
			printf("Error\n");
			break;
		}
	}while(cerrar()!=1);
		printf("Hasta pronto\n");
	        free(energias);
	   free(ener);
	  return 0;	
	}

