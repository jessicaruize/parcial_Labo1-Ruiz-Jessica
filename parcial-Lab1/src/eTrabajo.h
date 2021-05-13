/*
 * eTrabajo.h
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */

#ifndef ETRABAJO_H_
#define ETRABAJO_H_


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "pedir_valores.h"
#include "operaciones_matematicas.h"



//*** DEFINE

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TAM_Trabajo 5

typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;

//*** ESTRUCTURA
typedef struct
{
	int idTrabajo;
	char marcaBicicleta[MAX_CHARS_CADENAS];
	int rodado;
	int idServicio;
	eFecha fecha;
	int isEmpty;
} eTrabajo;
//***


/** INICIO CABECERAS DE FUNCION*/
void eTrabajo_cargaAutomaticaTrabajo(eTrabajo array[], int TAM);
void eTrabajo_inicializar(eTrabajo array[], int TAM);
int eTrabajo_obtenerID(void);
int eTrabajo_obtenerIndiceLibre(eTrabajo array[], int TAM);
int eTrabajo_buscarIndicePorId(eTrabajo array[], int TAM, int id, int* idEncontrado);
int eTrabajo_mostrarUno(eTrabajo* pTrabajo);
int eTrabajo_mostrarTodos(eTrabajo array[], int TAM, int* cantidad);
int eTrabajo_mostrarDadosDeBaja(eTrabajo array[], int TAM, int* cantidad);
int eTrabajo_buscarIdMaximo(eTrabajo miTrabajo[], int TAM, int* idMaximo);



/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR

//ABM
int eTrabajo_cargarDatos(eTrabajo* pArray);
int eTrabajo_alta(eTrabajo array[], int TAM);

/** FIN CABECERAS DE FUNCION*/

//int eTrabajo_PedirFecha (char* mensaje, char* mensajeError, int reintentos, eFecha miFecha[], int TAMFEC, int minAnio, int maxAnio);
eFecha eTrabajo_PedirFecha (char* mensaje, char* mensajeError, int reintentos, int minAnio, int maxAnio);

//int eTrabajo_PedirFecha (char* mensaje, char* mensajeError, int reintentos, eFecha miFecha, int minAnio, int maxAnio);
int eTrabajo_mostrarFecha(eFecha* miFecha, char* mensaje);




#endif /* ETRABAJO_H_ */
