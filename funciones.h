//cabeceras de las funciones y las estructuras
typedef struct{
	int month;
	int year;
}fecha;
typedef struct {
    char tipo_energia[50];
   float cant_generada[24];
   fecha f[24];
} tipos;
void menu();
void menu_calculos_estadisticos();
void guardar_datos_generacion_energias(tipos*datos);
void guardar_datos_generacion_fechas(tipos*datos);
float mediana(tipos *energias);
void swap(float* n1, float* n2);
void ordenar_vector(float vector[], int n);
float media(tipos *energias);
//float varianza(tipos *energias);
//float desviacion_tipica(tipos *energias);
float valor_maximo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
float valor_minimo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
void ordenacion_maximo(int filas,tipos *energias); 
void ordenacion_minimo(int filas,tipos *energias);
