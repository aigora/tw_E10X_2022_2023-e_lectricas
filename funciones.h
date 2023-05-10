//cabeceras de las funciones y las estructuras
typedef struct{
	int month;
	int year;
}fecha;
typedef struct {
    char tipo_energia[50];
   float cant_generada[24];
} tipos;
void menu();
void guardar_datos_generacion_energias(tipos*datos);
void guardar_datos_generacion_fechas(fecha*f);
float mediana(tipos *datos);
float valor_maximo(int columnas,int filas,tipos *energias);
float valor_minimo(int columnas,int filas,tipos *energias);
