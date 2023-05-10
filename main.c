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
		{

    int n, i; //n es el numero de valores segun el año que elijamos 
    float num, sum = 0, media;

    for (i = 1; i <= n; ++i)
	{
        printf("Ingrese el valor %d: ", i);
        scanf("%f", &num);
        sum += num;
    }

  media = sum / n;
    printf("La media es: %.2f", media);		
	}
	{
    int n, mediana, mediana2;
    printf("Ingrese el número de elementos en el conjunto de datos: ");
    scanf("%d", &n);
    //para n numero de datos 

    // Leer los datos y calcular la mediana
    for (int i = 0; i < n; i++) {
        scanf("%d", &mediana2);
        if (i == n / 2) {  // Si se ha leído la mitad de los datos, almacenar la mediana y salir del bucle
            mediana = mediana2;
            if (n % 2 == 0) {  // Si el número de elementos es par, leer un valor adicional y calcular la mediana como el promedio de los dos valores centrales
                scanf("%d", &mediana2);
                mediana= (mediana + mediana2) / 2;
            }
            break;
        }
    }

    printf("La mediana es: %d", mediana);

    return 0;
}

    return 0;
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
        printf("%s\n", energias[5].tipo_energia);
        printf("%d/%d\n", fech[5].month,fech[5].year); 
        // Inicialización de la variable 'maximo' con el primer valor de 'cant_generada'
        int maximo = energias[1].cant_generada[0];
        int i;
        int j;
        for (i = 2; i < N; i++) 
		{
			for (j = 0; j < 12; j++) {
            if (energias[i].cant_generada[j] > maximo) 
            {
            	//Actualización del valor 'maximo'
            	maximo = energias[i].cant_generada[j];
			}
        }
    printf("El valor maximo de la cantidad generada de energia es: %d\n", maximo);
    // Inicialización de la variable 'minimo' con el primer valor de 'cant_generada'
    int minimo = energias[1].cant_generada[0];
    for (i = 2; i < N; i++) 
	{
        for (j = 0; j < 12; j++) 
		{
            if (energias[i].cant_generada[j] < minimo) 
			{
				//Actualización del valor 'minimo'
                minimo = energias[i].cant_generada[j];
            }
        }
    }
    printf("El valor mínimo de la cantidad generada de energia es: %d\n", minimo);
    break;

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

