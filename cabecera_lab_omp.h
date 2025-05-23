/**********************************************
 * Título: Implementación Básica de OpenMP
 * 
 * Universidad: Pontificia Universidad Javeriana
 * Fecha: 22 de mayo 2025
 * Autor: Thomas Arévalo Rodríguez
 * 
 * Materia: Sistemas Operativos
 * Tópico: Programación Paralela con OpenMP
 * Archivo: Archivo de declaración de funciones (cabecera_lab_omp.c)
 * 
 * Descripción:
 * ------------
 * Este archivo almacena la firma de las funciones a utilizar, es un menú de apertura
 * para que el usuario tenga conocimiento de lo que puede utilizar dentro de esta cabecera.
 **********************************************/
#ifndef CABECERA_LAB_OMP_H
#define CABECERA_LAB_OMP_H

#include <stdio.h> 
#include <stdlib.h>
#include <omp.h> //--> Se incluye la libreria estándar openMP

// Funciones del programa
int obtener_numero_hilos(int argc, char *argv[]); //--> Obtiene el número de hilos usados en la ejecución 
void configurar_openmp(int hilos); //--> Establece el número de hilos a usar en la ejecución
void imprimir_info_hilos(int maxHilos, int hilos); //--> Imprime la cantidad máxima de hilos del sistema y los usados en la ejecución
void ejecutar_bucle_paralelo(int N, int *a, int *b); //--> Simula un trabajo en paralelo, demostrando condiciones de carrera para una variable sin proteger

#endif // CABECERA_LAB_OMP_H