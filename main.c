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
	int num;
	int tipo;
	int tam;
	float mediana_global;
	float media_global;
	float moda_glob;
	float rango_glob, rango2_tipo_energia;
	float varianza_global,varianza2_tipo_energia;
	float desviacion_tipica_global,desviacion_tipica_2_tipo_energia;
	int nLineas=0,pos;
	int numero;
	int mes;
	int num_calculos_estadisticos,num_calculos_estadisticos_mensuales;
	float med_tipo_energia;
	float mediana2_tipo_energia;
	float moda2_tipo_energia;
	int calculos_estadisticos_energia_especifica;
	int r,z,f,p,op,t;
	float max_total,min_total;
	float min_year, max_year;
	int linea_actual,impresion;
	char cad[40];
	int m;
	// Reserva de memoria dinamica
	energias = malloc(sizeof(tipos) * N);
	fech = malloc(sizeof(fecha) * 24);
   	// Guardado de datos del fichero a las siguientes funciones
  	guardar_datos_generacion_energias(energias);
  	guardar_datos_generacion_fechas(fech);
    guardar_fecha_tipos(fech,energias);
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
						guardado_de_datos(mediana_global, "guardado_de_calculos_estadisticos_globales.txt");
						break;
					case 2:
						media_global=media(energias);
						printf("La media de todos los datos es: %f\n", media_global);
						guardado_de_datos(media_global, "guardado_de_calculos_estadisticos_globales.txt");
						break;		
					case 3:
						varianza_global= varianza(energias);
						printf("La varianza de todos los datos es : %f\n", varianza_global);
							guardado_de_datos(varianza_global, "guardado_de_calculos_estadisticos_globales.txt");
						break;
					case 4:
						desviacion_tipica_global = desviacion_tipica(energias);
						printf("La desviacion tipica de todos los datos es: %f\n",desviacion_tipica_global);
							guardado_de_datos(desviacion_tipica_global, "guardado_de_calculos_estadisticos_globales.txt");
						break;
					case 5:
					   moda_glob = moda_global(energias);
						printf("La moda de todos los datos es :%f\n", moda_glob);
							guardado_de_datos(moda_glob, "guardado_de_calculos_estadisticos_globales.txt");
					
						break;
					case 6:
				      	rango_glob = rango_global(energias);
						printf("EL rango de todos los datos es :%f \n", rango_glob);
						guardado_de_datos(rango_glob, "guardado_de_calculos_estadisticos_globales.txt");
						break;
					default:
						printf("Error \n");
					
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
					   		 printf("La media es %f\n",med_tipo_energia);
					   		 	guardado_de_datos(med_tipo_energia, "guardado_de_calculos_estadisticos_mensuales.txt");
					   		break;
					   	case 2:
					   		mediana2_tipo_energia=mediana2(calculos_estadisticos_energia_especifica,energias);
					   		printf("La mediana es %f\n",mediana2_tipo_energia);
					   		guardado_de_datos(mediana2_tipo_energia, "guardado_de_calculos_estadisticos_mensuales.txt");
					   			break;
					   	case 3:
					   		moda2_tipo_energia=moda2(calculos_estadisticos_energia_especifica,energias);
					   		printf("La moda es %f\n",moda2_tipo_energia);
					   		guardado_de_datos(moda2_tipo_energia, "guardado_de_calculos_estadisticos_mensuales.txt");
					   				break;
					   	case 4:
					   		varianza2_tipo_energia=varianza2(calculos_estadisticos_energia_especifica,energias);
					   		printf("La varianza es %f\n",varianza2_tipo_energia);
					   		guardado_de_datos(varianza2_tipo_energia, "guardado_de_calculos_estadisticos_mensuales");
					   		break;
					   	case 5:
					        desviacion_tipica_2_tipo_energia=desviacion_tipica_2(calculos_estadisticos_energia_especifica,energias);
					   		printf("La desviacion tipica es %f\n",desviacion_tipica_2_tipo_energia);
					   		guardado_de_datos(varianza2_tipo_energia, "guardado_de_calculos_estadisticos_mensuales.txt");
					   		break;
						case 6:
							rango2_tipo_energia=rango2(calculos_estadisticos_energia_especifica,energias);
					   		printf("El rango es %f\n",rango2_tipo_energia);
					   		guardado_de_datos(rango2_tipo_energia, "guardado_de_calculos_estadisticos_mensuales.txt");
					   	break;
					   	default:
					   		printf("Error");
					   		break;
					   }
				    }
				else
				{
					printf("Error");
				}
				break;
				
			case 2:
				printf("CARGA DE NUEVOS DATOS\n");
				printf("Introduzca el nÃºmero de datos que desea agregar: ");
                scanf("%d", &tam);

                // Aumentar el tamaÃ±o del arreglo dinÃ¡mico para contener los nuevos datos
                energias = realloc(energias, sizeof(tipos) * (N + tam));
                int i;
                int j;
                int n=23;
                for (i = n; i < n + tam; i++) 
				{
                    printf("Datos para el nuevo registro %d:\n", i + 1);

                    // Solicitar los datos al usuario
                    printf("Ingrese el tipo de energÃ­a: ");
                    scanf("%s", &energias[i].tipo_energia);

                    printf("Ingrese la fecha (formato: mes aÃ±o): ");
                    scanf("%d %d", &energias[i].f[0].month, &energias[i].f[0].year);

                    printf("Ingrese la cantidad generada: ");
                    for(j=0;j<24;j++){
                    	     scanf("%f", &energias[i].cant_generada[j]);
					}
                }
                n = n + tam; // Actualizo el tamaÃ±o total del arreglo.
                printf("Los nuevos datos se han agregado correctamente.\n");
				break;
			case 3:
				printf("GUARDAR RESULTADOS\n");
				break;
			case 4:
				printf("BUSQUEDAS\n");
				printf("Introduzca la energia que desea buscar con la primera letra en mayuscula\n");
				scanf("%s",cad);
		        buscar(cad,energias);
		       
	         	break;
			case 5:
				printf("ORDENACION DE VALORES\n");
				// Inicializacion de la variable maximo con el primer valor de 'cant_generada'
				printf("Introduzca el tipo de energia del cual quiere ver el maximo\n");
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
	        printf("Seleccione si quiere calcular un maximo o minimo:\n");
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
				}	
			break;
				case 7:
				imprimir_datos_fichero();
				scanf("%d",&impresion);
				switch(impresion){
					case 1:
					printf("Imprimir todos los datos\n");
						for(m=0;m<24;m++){
								printf("%d/%d\n\n",energias[1].f[m].month,energias[1].f[m].year);
				           for(n=0;n<18;n++){
							
									printf("%s %f",energias[n].tipo_energia,energias[n].cant_generada[m]);
									printf("\n");
							}
							printf("\n");
						}

						break;
					case 2:
							printf("Selecciona un year:\n");
							int year;
							scanf("%d", &year);
							if (year == 2021 || year == 2022)
							{
								printf("Selecciona un mes:\n");
								int mes;
								scanf("%d", &mes);
								if (mes >= 1 && mes <= 12)
								{
									printf("Datos del year %d, mes %d:\n", year, mes);
									int n;
										printf("%d/%d\n", mes, year);
									for (n = 0; n < 18; n++)
									{
									 
										printf("%s %f", energias[n].tipo_energia, energias[n].cant_generada[(year - 2021) * 12 + (mes - 1)]);
										printf("\n");
									}
								}
								else
								{
									printf("Mes invalido.\n");
								}
							}
							else
							{
								printf("Year invalido.\n");
							}
						    break;
					case 3:
							printf("Selecciona una energia:\n");
							menu_calculos_estadisticos_energia_especifica();
							int opcion;
							scanf("%d", &opcion);
							if (opcion >= 1 && opcion <= 4)
							{
								printf("Datos de la energia %d:\n", opcion);
								int m;
									printf("%s",energias[opcion].tipo_energia);
								for (m = 0; m < 24; m++) 
								{
									printf("%.2f\n", energias[opcion-1].cant_generada[m]);
								}
							    printf("\n");
							}
							else if (opcion >= 5 && opcion <= 17)
							{
								printf("Datos de la energia %d:\n", opcion);
								int m;
								printf("%s\n",energias[opcion].tipo_energia);
								for (m = 0; m < 24; m++) 
								{
									printf("%.2f\t", energias[opcion].cant_generada[m]);
								}
							    printf("\n");
							}
							else 
							{
								printf("Opcion invalida.\n");
							}
							break;
					default:
						printf("Error");
						break;

					
				}
				printf("%d/%d\n",energias[3].f[1].month,energias[3].f[1].year);
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
