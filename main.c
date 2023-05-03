#include <stdio.h>
#include <string.h>
int main(){
	FILE *pf;
	FILE *archivo_menu;
	int numero=0;

	printf("Introduzca el numero de la operación que desea realizar\n");
	printf("1.Calculos Estadisticos\n2.Carga de nuevos datos\n3.Guardar resultados\n4.Busquedas\n5.Ordenacion de valores\n");
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
		break;
		case 5:
		printf("ORDENACION DE VALORES\n");
		break;
		default:
			printf("Error\n");
			break;
	}
	
		pf=fopen("generacion_por_tecnologias_21_22.csv","r");
		if(pf==NULL){
			printf("No se ha podido abrir el archivo\n");
			return -1;
		}
		else{ 
		printf("Se ha abierto correctamente\n");
	}
	fclose(pf);
	return 0;
}
