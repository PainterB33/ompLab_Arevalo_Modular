/**********************************************
 * Título: Implementación Básica de OpenMP
 * 
 * Universidad: Pontificia Universidad Javeriana
 * Fecha: 22 de mayo 2025
 * Autor: Thomas Arévalo Rodríguez
 * 
 * Materia: Sistemas Operativos
 * Tópico: Programación Paralela con OpenMP
 * Archivo: Programa principal (main.c)
 * 
 * Descripción:
 * ------------
 * Este programa implementa un ejemplo básico de paralelización utilizando OpenMP.
 * Su objetivo principal es demostrar:
 * 1. La configuración y gestión de hilos en OpenMP
 * 2. El manejo de variables en un contexto paralelo
 * 3. La implementación de bucles paralelos
 * 
 * Características principales:
 * - Permite especificar el número de hilos mediante argumentos de línea de comandos
 * - Muestra el máximo número de hilos disponibles en el sistema
 * - Implementa un bucle paralelo simple para demostrar el manejo de variables
 * - Ilustra el comportamiento de variables privadas y compartidas
 * 
 * Uso:
 * - Compilación: make ompLab_Arevalo
 * - Ejecución: ./omLab_Arevalo NumHilos
 * 
 * Dependencias:
 * - OpenMP (omp.h)
 **********************************************/
 #include "cabecera_lab_omp.h" //--> Se incluye la cabecera donde se encuentran las funciones.

// Programa principal
int main(int argc, char *argv[]){
    // Se obtienen los hilos mediante la función, enviando los valores ingresados por consola como argumentos.
    int hilos = obtener_numero_hilos(argc, argv);
    // Se obtiene la cantidad maxima de hilos, mediante la función estándar de omp.
    int maxHilos = omp_get_max_threads();

    // Se envia el número de hilos predicho por el usuario hacia la función que los establece.
    configurar_openmp(hilos);
    // Se imprime la información de los hilos, cuantos estan disponibles y cuantos se van a usar.
    imprimir_info_hilos(maxHilos, hilos);

    //--- DECLARACIÓN DE VARIABLES ---
    int* a; //--> Apuntador que almacenara la dirección de memoria de v1.
    int v1 = 50;
    a = &v1; //--> Se establece la dirección de memoria de v1 en a. 
    int* b; //--> Apuntador que almacenara la dirección de memoria de v2
    int v2 = 0;
    b = &v2; //--> Se establece la dirección de memoria de v2 en b.
    const int N = 1000; //--> Se establece una constante que alamcena el tamaño del bucle.
    // Funcion que ejecuta la operación principal del programa
    ejecutar_bucle_paralelo(N, a, b);

    printf("El valor de a = %d \t el valor de b = %d (se espera que sea a=50, b=1049)\n", *a, *b);
    
    return 0;
}

/**********************************************
 * CONCLUSIONES Y ANÁLISIS
 * ======================
 * 
 * 1. Arquitectura y Diseño
 *    ---------------------
 *    - El programa implementa un patrón básico de paralelización con OpenMP
 *    - Utiliza dos regiones paralelas: una para impresión y otra para cómputo
 *    - Demuestra la separación entre configuración y ejecución paralela
 * 
 * 2. Análisis de Rendimiento
 *    ----------------------
 *    - La paralelización del bucle puede mejorar el rendimiento en sistemas multinúcleo
 *    - La sobrecarga de creación de hilos debe considerarse para bucles pequeños
 *    - El número óptimo de hilos depende del hardware y la naturaleza del problema
 * 
 * 3. Aspectos Técnicos
 *    ----------------
 *    - Uso efectivo de directivas OpenMP (#pragma omp parallel, #pragma omp parallel for)
 *    - Manejo adecuado de variables privadas y compartidas
 *    - Implementación de la cláusula 'private' para evitar condiciones de carrera
 * 
 * 4. Limitaciones y Mejoras Posibles
 *    -----------------------------
 *    - No implementa mecanismos de sincronización para la variable compartida 'b'
 *    - Podría beneficiarse de la adición de directivas 'atomic' o 'critical'
 *    - La validación de entrada podría ser más robusta
 * 
 * 5. Aplicabilidad
 *    ------------
 *    - Este ejemplo sirve como base para implementaciones más complejas
 *    - Demuestra conceptos fundamentales de programación paralela
 *    - Útil para entender el modelo de memoria compartida de OpenMP

 * 6. Manejo de Variables en OpenMP
 *    ----------------------------
 *    - Las variables declaradas como 'private' (a e i) mantienen su valor original
 *      fuera de la región paralela, mientras que dentro cada hilo tiene su propia copia.
 *    - La variable 'b' al ser compartida por defecto, sufre de condiciones de carrera,
 *      lo que explica por qué su valor final puede variar entre ejecuciones.
 
 * 7. Recomendaciones
 *    -------------
 *    - Para aplicaciones reales, implementar mecanismos de sincronización
 *    - Considerar el uso de reducciones para operaciones acumulativas
 *    - Realizar pruebas de rendimiento con diferentes números de hilos
 * 
 **********************************************/