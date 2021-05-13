/*
 * eTrabajo.c
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */




#include "eTrabajo.h"

//fijarse TAM de la carga automatiCa

static int Trabajo_idIncremental =  5;

void eTrabajo_cargaAutomaticaTrabajo(eTrabajo array[], int TAM)
{
	int idTrabajo []= {1, 2, 3, 4, 5};
	char marcaBicicleta[][30]={"Marca1", "marca2", "marca3", "marca4", "marca5"};
	int rodado []= {12, 14, 16, 20, 24};
	int idServicio []= {2001, 2004, 2001, 2003, 2002};
	eFecha fecha []= {{5, 2,2010},{20,3,2015},{15,10,2010},{5,11,2011},{9,2,2015}};

	int i;
	if(array != NULL && TAM > 0)
	{
		for(i=0; i<TAM; i++)
		{
			strcpy(array[i].marcaBicicleta, marcaBicicleta[i]);
			array[i].idTrabajo = idTrabajo[i];
			array[i].rodado = rodado[i];
			array[i].idServicio = idServicio[i];
			array[i].fecha = fecha[i];
			array[i].isEmpty = OCUPADO;
		}
	}
}

void eTrabajo_inicializar(eTrabajo array[], int TAM)
{
	int i;
	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			array[i].isEmpty = LIBRE;
		}
	}
}

int eTrabajo_obtenerID()
{
	return Trabajo_idIncremental += 1;
}

int eTrabajo_obtenerIndiceLibre(eTrabajo array[], int TAM)
{
	int retorno = -1; //ERROR
	int i;
	if (array != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == LIBRE) {
				retorno = i;// retorna indice libre.
				break;
			}
			retorno = -2; //array lleno
		}
	}
	return retorno;
}

int eTrabajo_buscarIndicePorId(eTrabajo array[], int TAM, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (array != NULL && TAM > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Trabajo con ese ID
		for (i = 0; i < TAM; i++)
		{
			if (array[i].idTrabajo == id && array[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Trabajo ocupado
				break;
			}
			else
			{
				if(array[i].idTrabajo == id && array[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Trabajo dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

int eTrabajo_mostrarUno(eTrabajo* pTrabajo)
{
	int retorno = -1; //error.
	if(pTrabajo != NULL)
	{
		retorno = 0; //bien.
		printf("ID: %4d \t marca: %15s \t rodado: %4d \t ID servicio: %4d \t fecha: %d/%d/%d \t\n", pTrabajo->idTrabajo,
																								    pTrabajo->marcaBicicleta,
																								    pTrabajo->rodado,
																								    pTrabajo->idServicio,
																								    pTrabajo->fecha.dia,
																								    pTrabajo->fecha.mes,
																								    pTrabajo->fecha.anio);
	}
	return retorno;
}

int eTrabajo_mostrarTodos(eTrabajo array[], int TAM, int* cantidad)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	if (array != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == OCUPADO)
			{
				eTrabajo_mostrarUno(&array[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (contador > 0)
	{
		retorno = 0; //hay Trabajo para mostrar.
	}

	return retorno;
}

int eTrabajo_mostrarDadosDeBaja(eTrabajo array[], int TAM, int* cantidad)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	puts("\n\t> LISTADO TRABAJO: \n");
	if (array != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == BAJA)
			{
				eTrabajo_mostrarUno(&array[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (cantidad > 0)
	{
		retorno = 0; //hay Trabajo dado de baja para mostrar.
	}

	return retorno;
}

int eTrabajo_buscarIdMaximo(eTrabajo miTrabajo[], int TAM, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(miTrabajo != NULL && idMaximo !=NULL)
	{
		for(i=0; i<TAM; i++)
		{
			if((i == 0 || miTrabajo[i].idTrabajo > *idMaximo) && miTrabajo[i].isEmpty == OCUPADO)
			{
				*idMaximo = miTrabajo[i].idTrabajo;
				retorno= 0;
			}
		}
	}
	return retorno;
}


eFecha eTrabajo_PedirFecha (char* mensaje, char* mensajeError, int reintentos, int minAnio, int maxAnio)
{
	eFecha miFecha;
	eFecha retorno;
	if(mensaje != NULL && mensajeError != NULL && reintentos > 0
	   && minAnio > 0 && maxAnio > 0)
	{
		do
		{
			printf("%s", mensaje);
			if(!utn_pedirEntero(&miFecha.dia, "Ingrese día", "Error", 1, 31, 2, 1) &&
			   !utn_pedirEntero(&miFecha.mes, "Ingrese mes", "Error", 1, 12, 2, 1)&&
			   !utn_pedirEntero(&miFecha.anio, "Ingrese año", "Error", minAnio, maxAnio, 2, 1))
			{
				if(miFecha.mes == 2 && miFecha.dia < 29)
				{
					retorno = miFecha;
					break;
				}
				else
				{
					if((miFecha.mes == 4 || miFecha.mes == 6 ||
					   miFecha.mes == 9 || miFecha.mes == 11) &&
					   miFecha.dia > 0 && miFecha.dia < 31)
					{
						retorno = miFecha;
						break;
					}
				}
			}
			reintentos--;
			printf("%s", mensajeError);
		}while(reintentos > -1);
	}
	return retorno;
}

int eTrabajo_mostrarFecha(eFecha* miFecha, char* mensaje)
{
	int retorno = -1;
	if(miFecha != NULL)
	{
		printf("%s %d/%d/%d", mensaje, miFecha->dia, miFecha->mes, miFecha->anio);
		retorno = 0;
	}
	return retorno;
}
