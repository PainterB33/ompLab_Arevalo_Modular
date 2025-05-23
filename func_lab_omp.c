/**********************************************
 * Título: Implementación Básica de OpenMP
 * 
 * Universidad: Pontificia Universidad Javeriana
 * Fecha: 22 de mayo 2025
 * Autor: Thomas Arévalo Rodríguez
 * 
 * Materia: Sistemas Operativos
 * Tópico: Programación Paralela con OpenMP
 * Archivo: Archivo de implementación de funciones (func_lab_omp.c)
 * 
 * Descripción:
 * ------------
 * Este archivo almacena todas las funciones que seran utilizadas y llamadas desde el programa principal
 * para hacer posible la demostración del trabajo en paralelo utilizando la libreria openMP.
 * Todas y cada una de las funciones aqui implementadas fueron declaradas en la cabecera.
 **********************************************/
#include "cabecera_lab_omp.h" //--> Se incluye la cabecera

// Función para obtener el número de hilos que el usuario envió desde la consola.
int obtener_numero_hilos(int argc, char *argv[]) {
    // Validación de argumentos desde consola al momento de ejecutar el programa
    if (argc < 2){
        printf("Error: Argumentos insuficientes\n");
		printf("Uso: $./ejecutable NumHilos\n");
		exit(1);
    }
    return (int) atoi(argv[1]); //--> Se retorna el número de hilos que se usarán para el paralelismo
}

// Función para establecer el número de hilos que trabajaran en paralelo.
void configurar_openmp(int hilos){
    omp_set_num_threads(hilos); //--> Se usa la función estandar de la libreria openMP
}

// Función para imrpimir la información actual del programa
void imprimir_info_hilos(int maxHilos, int hilos){
    // Se imprimen el maximo de hilos disponibles a usar basado en el sistema de computo
    // donde se encuentre el programa y los hilos impuestos por el usuario
#pragma omp parallel
    {
        printf("MaxHilos %d \t Equipo de hilos impuesto =%d\n", maxHilos, omp_get_num_threads());
    }
}

// Función para ejecutar un trabajo en paralelo, en este caso un bucle
void ejecutar_bucle_paralelo(int N, int *a, int *b){
    int i;

// Cada hilo tendra una copia propia de la variable i
// La variable b al no estar protegida entra en condición de carrera
// lo que ocaciona que en todas las ejecuciones su valor sea diferente del esperado.
#pragma omp parallel for private(i)
    for (i = 0; i < N; i++){
        (*b) = (*a) + i;
    }
}
