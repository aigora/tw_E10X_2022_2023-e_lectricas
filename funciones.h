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
void menu_calculos_estadisticos();
void guardar_datos_generacion_energias(tipos*datos);
void guardar_datos_generacion_fechas(fecha*f);
float mediana(tipos *datos);
float valor_maximo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
float valor_minimo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
void ordenacion_maximo(int filas,tipos *energias);
void ordenacion_minimo(int filas,tipos *energias);
