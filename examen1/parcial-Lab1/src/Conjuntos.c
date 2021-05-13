/*
 * Conjuntos.c
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */



#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>


#include"Conjuntos.h"

int eConjuntos_cargarDatos(eTrabajo* pTrabajo, eServicios arrayServicios[], int TAMSERV)
{
	int retorno = -1;
	int cantidadServicios;
	int idMaximoServicios;
	int indiceServicios;
	eFecha miFecha;

	if((pTrabajo != NULL) && (arrayServicios != NULL))
	{

		utn_pedirAlfanumericoEspacio(pTrabajo->marcaBicicleta, "\n\nIngrese marca de la bicicleta: ", "\nError.\n", 2);
		utn_pedirEntero(&pTrabajo->rodado, "\nIngrese el rodado de la bicicleta: \n", "\nError.\n", 0, 0, 2, 0);
		eServicios_mostrarTodos(arrayServicios, TAMSERV, &cantidadServicios);
		eServicios_buscarIdMaximo(arrayServicios, TAMSERV, &idMaximoServicios);
		utn_pedirEntero(&pTrabajo->idServicio, "\nIngrese el ID del servicio: \n", "\nError\n", 1, idMaximoServicios, 2, 1);
		miFecha = eTrabajo_PedirFecha("Ingrese la fecha", "Error.", 2, 2000, 2021);
		pTrabajo->fecha = miFecha;
		if(!eServicios_buscarIndicePorId(arrayServicios, TAMSERV, pTrabajo->idServicio, &indiceServicios))
		{
			 retorno = 0;
		}
	}
	return retorno;
}

int eConjuntos_alta(eTrabajo array[], int TAM, eServicios arrayServicios[], int TAMSERV)
{
	int retorno = -1; //ERROR
	eTrabajo auxTrabajo;
	int indice;
	if(array != NULL && TAM > 0)
	{
		indice = eTrabajo_obtenerIndiceLibre(array, TAM);

		if (indice > -1)
		{
			if(!eConjuntos_cargarDatos(&auxTrabajo, arrayServicios, TAMSERV))
			{
				if(utn_verificar("\n¿Desea guardar los cambios[s/n]?", "Error", 2) == 0)
				{
					auxTrabajo.idTrabajo = eTrabajo_obtenerID();
					auxTrabajo.isEmpty = OCUPADO;
					array[indice] = auxTrabajo;
					retorno = 0; //se dio de alta satisfactoriamente
				}
				else
				{
					retorno = 1; //Operacion cancelada
				}
			}
			else
			{
				puts("\nDatos mal ingresados.");
			}
		}
		else
		{
			if(indice == -2)
			{
				retorno = -2; //array lleno
			}
		}
	}

	return retorno;
}


int eConjuntos_mostrarUno(eTrabajo* pTrabajo, eServicios arrayServicios[], int TAMSERV)
{
	int retorno = -1; //error.
	int indiceServicios;

	if((pTrabajo != NULL) && (arrayServicios != NULL))
	{
		retorno = 0; //bien.
		eServicios_buscarIndicePorId(arrayServicios, TAMSERV, pTrabajo->idServicio, &indiceServicios);

		printf("ID trabajo: %4d \t marca de bicicleta: %15s \t rodado: %d \t descripción servicio: %15s \t precio: %.2f \t  ID servicio: %4d \n fecha de trabajo: %d/%d/%d\n", pTrabajo->idTrabajo,
																																											   pTrabajo->marcaBicicleta,
																																											   pTrabajo->rodado,
																																											   arrayServicios[indiceServicios].descripcion,
																																											   arrayServicios[indiceServicios].precio,
																																											   pTrabajo->idServicio,
																																											   pTrabajo->fecha.dia,
																																											   pTrabajo->fecha.mes,
																																											   pTrabajo->fecha.anio);
	}
	return retorno;
}

int eConjuntos_mostrarTodos(eTrabajo arrayTrabajo[], int TAMTRAB, eServicios arrayServicios[], int TAMSERV, int* cantidadTrabajo)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (arrayTrabajo != NULL && arrayServicios != NULL &&  TAMTRAB > 0 && TAMSERV > 0 &&  cantidadTrabajo != NULL)
	{
		for (i = 0; i < TAMTRAB; i++)
		{
			if (arrayTrabajo[i].isEmpty == OCUPADO)
			{
				eConjuntos_mostrarUno(&arrayTrabajo[i], arrayServicios, TAMSERV);
				contador++;
			}
		}
	}
	*cantidadTrabajo = contador;
	if (contador > 0) ///////////-------DUDA *------///////////////////////////
	{
		retorno = 0; //hay Trabajo para mostrar.
	}

	return retorno;
}



int eConjuntos_baja(eTrabajo arrayTrabajo[], int TAMTRAB, eServicios arrayServicios[], int TAMSERV)
{
	int retorno = -2; //ERROR
	int idTrabajo;
	int indice;
	int cantidad;
	int idMaximo;
	int respuesta;
	eTrabajo buffer;

	int flag = 0;
	if (eConjuntos_mostrarTodos(arrayTrabajo, TAMTRAB, arrayServicios, TAMSERV, &cantidad)==0)
	{
		flag = 1;
	}
	if (flag)
	{
		eTrabajo_buscarIdMaximo(arrayTrabajo, TAMTRAB, &idMaximo);
		if(utn_pedirEntero(&idTrabajo, "\nIngrese el ID del Trabajo que quiere dar de baja: \n", "\nError. \n", 1, idMaximo, 2, 1)==0)
		{

			respuesta = eTrabajo_buscarIndicePorId(arrayTrabajo, TAMTRAB, idTrabajo, &indice);
			switch (respuesta)
			{
				case -2: //ERROR
					retorno = -2;
				break;
				case 0: //OCUPADO
					buffer = arrayTrabajo[indice];
					eTrabajo_mostrarUno(&buffer); //____DUDA___//BUFFER->ARRAY[indice]
					if(utn_verificar("\n¿Desea dar de baja este Trabajo [s/n]?", "\nError", 2)==0)
					{
						arrayTrabajo[indice].isEmpty = BAJA; //baja logica.
						retorno = 0; //BAJA CORRECTAMENTE.
					}
					else
					{
						retorno = 2;
					}
				break;
				case 1: //BAJA
					retorno = 1; // Trabajo YA DADO DE BAJA
				break;
			}
		}
		else
		{
			retorno = -1; // ID no existe.
		}
	}

	return retorno;
}
