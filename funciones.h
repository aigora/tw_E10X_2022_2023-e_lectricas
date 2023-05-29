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
void menu_tipo_energia_ordenacion_valores();
void guardar_datos_generacion_energias(tipos*datos);
void guardar_datos_generacion_fechas(fecha*f);



//funciones para calculos anual y mensual 

float mediana2(int m,tipos *energias);
float media2(int m,tipos *energias);
float rango2(int m, tipos *energias);
float moda2(int m, tipos *energias);
float desviacion_tipica_2(int m, tipos *energias);
float varianza2(int m, tipos *energias);


void swap(float* n1, float* n2);
void ordenar_vector(float vector[], int n);
void guardar_fecha_tipos(fecha *fech,tipos *energias);//funcion asignacion fecha a la estructura tipos

//funciones para calculos estadisticos globales

float mediana(tipos *energias);
float media(tipos *energias);
float varianza(tipos *energias);
float desviacion_tipica(tipos *energias);
float moda_global(tipos*energias);
float rango_global(tipos*energias);



float valor_maximo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
float valor_minimo(int filas,int columnas,int filas2,int columnas2,tipos *energias);
void ordenacion_maximo(int filas,tipos *energias); 
void ordenacion_minimo(int filas,tipos *energias);
void guardar_datos_generacion_energias(tipos* energias);
void imprimir_datos_fichero();

void buscar(char cadena[60],tipos *energia);
void guardado_de_datos(char *tipo_calc,float datos,  char* archivo);
int cerrar(int k);
void vaciar_archivo(char* archivo);//se vacia el fichero al abrirlo en modo escritura y no realizar ninguna operación
void guardar_datos_fichero(int tam,tipos *energia);//guardar datos en el fichero de generacon de energias que se ha agregado por el usuario
void imprimir_archivo_pantalla(char* archivo);//me imprime los datos almacenados en lso ficheros a la hroa de realizar los calculos
