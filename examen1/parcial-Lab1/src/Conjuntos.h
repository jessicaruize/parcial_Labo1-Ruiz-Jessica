/*
 * Conjuntos.h
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */

#ifndef CONJUNTOS_H_
#define CONJUNTOS_H_


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#include "pedir_valores.h"
#include "operaciones_matematicas.h"


#include "eTrabajo.h"
#include "eServicios.h"

//*** DEFINE

#define MAX_CHARS_CADENAS 30
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1

int eConjuntos_cargarDatos(eTrabajo* pTrabajo, eServicios arrayServicios[], int TAMSERV);
int eConjuntos_alta(eTrabajo array[], int TAM, eServicios arrayServicios[], int TAMSERV);
int eConjuntos_mostrarUno(eTrabajo* pTrabajo, eServicios arrayServicios[], int TAMSERV);
int eConjuntos_mostrarTodos(eTrabajo arrayTrabajo[], int TAMTRAB, eServicios arrayServicios[], int TAMSERV, int* cantidadTrabajo);
int eConjuntos_baja(eTrabajo arrayTrabajo[], int TAMTRAB, eServicios arrayServicios[], int TAMSERV);
/** INICIO CABECERAS DE FUNCION*/


/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR


//ABM


/** FIN CABECERAS DE FUNCION*/




#endif /* CONJUNTOS_H_ */
