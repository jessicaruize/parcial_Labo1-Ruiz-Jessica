/*
 * eServicios.h
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_



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
#define TAM_Servicios 4


//*** ESTRUCTURA
typedef struct
{	char descripcion[MAX_CHARS_CADENAS];
	float precio;
	int idServicios;
	int isEmpty;
} eServicios;
//***


/** INICIO CABECERAS DE FUNCION*/
void eServicios_cargaAutomaticaServicios(eServicios array[], int TAM);
void eServicios_inicializar(eServicios array[], int TAM);
int eServicios_obtenerID(void);
int eServicios_obtenerIndiceLibre(eServicios array[], int TAM);
int eServicios_buscarIndicePorId(eServicios array[], int TAM, int id, int* idEncontrado);
int eServicios_mostrarUno(eServicios* pServicios);
int eServicios_mostrarTodos(eServicios array[], int TAM, int* cantidad);
int eServicios_mostrarDadosDeBaja(eServicios array[], int TAM, int* cantidad);
int eServicios_buscarIdMaximo(eServicios miServicios[], int TAM, int* idMaximo);



/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eServicios_Sort(eServicios array[], int TAM, int criterio);

//ABM
int eServicios_cargarDatos(eServicios* pArray);
int eServicios_modificarUno(eServicios* Servicios);
int eServicios_alta(eServicios array[], int TAM);
int eServicios_baja(eServicios array[], int TAM);
int eServicios_modificacion(eServicios array[], int TAM);
/** FIN CABECERAS DE FUNCION*/







#endif /* ESERVICIOS_H_ */
