/*
 * eServicios.c
 *
 *  Created on: 13 may. 2021
 *      Author: jessica
 */




#include "eServicios.h"

//fijarse TAM de la carga automatiCa

static int Servicios_idIncremental =  2004;

void eServicios_cargaAutomaticaServicios(eServicios array[], int TAM)
{
	char descripcion[][30]={"limpieza", "Parche", "Centrado", "Cadena"};
	float precio []= {250, 300, 400, 350};
	int id []= {2001, 2002, 2003, 2004};

	int i;
	if(array != NULL && TAM > 0)
	{
		for(i=0; i<TAM; i++)
		{
			strcpy(array[i].descripcion, descripcion[i]);
			array[i].precio = precio[i];
			array[i].idServicios = id[i];
			array[i].isEmpty = OCUPADO;
		}
	}
}

void eServicios_inicializar(eServicios array[], int TAM)
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

int eServicios_obtenerID()
{
	return Servicios_idIncremental += 1;
}

int eServicios_obtenerIndiceLibre(eServicios array[], int TAM)
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

int eServicios_buscarIndicePorId(eServicios array[], int TAM, int id, int* indiceEncontrado)
{
	int retorno = -2; // error.
	int i;
	if (array != NULL && TAM > 0 && indiceEncontrado != NULL)
	{
		retorno = -1; // No hay ningun Servicios con ese ID
		for (i = 0; i < TAM; i++)
		{
			if (array[i].idServicios == id && array[i].isEmpty == OCUPADO)
			{
				*indiceEncontrado = i;
				retorno = 0; // Servicios ocupado
				break;
			}
			else
			{
				if(array[i].idServicios == id && array[i].isEmpty == BAJA)
				{
					*indiceEncontrado = i;
					retorno = 1; //Servicios dado de baja
					break;
				}
			}
		}
	}

	return retorno;
}

int eServicios_mostrarUno(eServicios* pServicios) /////////////////////////////////////////////////////////EDITAR
{
	int retorno = -1; //error.
	if(pServicios != NULL)
	{
		retorno = 0; //bien.
		printf("Descripción: %15s \t precio: %.2f \t ID: %4d\n", pServicios->descripcion,
																 pServicios->precio,
																 pServicios->idServicios);
	}//////////////////EJEMPLO////////////////////////////////////////////////////////////
	return retorno;
}

int eServicios_mostrarTodos(eServicios array[], int TAM, int* cantidad)//_DUDA_//
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
				eServicios_mostrarUno(&array[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (contador > 0) ///////////-------DUDA *------///////////////////////////
	{
		retorno = 0; //hay Servicios para mostrar.
	}

	return retorno;
}

int eServicios_mostrarDadosDeBaja(eServicios array[], int TAM, int* cantidad)
{
	int i;
	int retorno = -1;//no hay nada para mostrar
	int contador = 0;
	puts("\n\t> LISTADO Servicios");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA
	if (array != NULL && TAM > 0 && cantidad != NULL)
	{
		for (i = 0; i < TAM; i++)
		{
			if (array[i].isEmpty == BAJA)
			{
				eServicios_mostrarUno(&array[i]);
				contador++;
			}
		}
	}
	*cantidad = contador;
	if (cantidad > 0)
	{
		retorno = 0; //hay Servicios dado de baja para mostrar.
	}

	return retorno;
}

int eServicios_buscarIdMaximo(eServicios miServicios[], int TAM, int* idMaximo)
{
	int i;
	int retorno = -1;
	if(miServicios != NULL && idMaximo !=NULL)
	{
		for(i=0; i<TAM; i++)
		{
			if((i == 0 || miServicios[i].idServicios > *idMaximo) && miServicios[i].isEmpty == OCUPADO)
			{
				*idMaximo = miServicios[i].idServicios;
				retorno= 0;
			}
		}
	}
	return retorno;
}


int eServicios_cargarDatos(eServicios* pArray) ///////////////////////////////////////////////////////////////////////////////////////////////////////////MELOROBO
{
	int retorno = -1;
	if(pArray != NULL)
	{

		if(!utn_pedirAlfabetico(pArray->descripcion, "Ingrese nombre: ", "Error.\n", 2) &&
		!utn_pedirFlotante(&pArray->precio, "Ingrese precio", "Error.", 0, 99999999, 2, 1))
		{//para acceder a los campos de una estructura se usa flecha porq es de tipo puntero.
			 retorno = 0;
		}
		////////////////////////////////EJEMPLO/////////////////////////////////////
	}
	return retorno;
}

int eServicios_modificarUno(eServicios* Servicios)
{
	int retorno = -1;
	int respuesta;
	do
	{
		printf("\n\n\tMODIFICAR: \n\n1_Descripción.\n2_Precio.\n5_Modificar otro dato.\n6_Salir.");
		if(!utn_pedirEntero(&respuesta, "\n\nIngrese la opción que desea realizar: ", "\nError", 1, 6, 2, 1))
		{
			retorno = 0;
			switch(respuesta)

			{
				case 1: //Descripcion
					utn_pedirAlfabetico(Servicios->descripcion, "Ingrese la descripcion: ", "Error", 2);
				break;
				case 2: //precio
					utn_pedirFlotante(&Servicios->precio, "Ingrese precio: ", "Error", 0, 1000000, 2, 1);
				break;
				case 5:
				break;
				case 6: // salir
					if(!utn_verificar("¿Desea salir? [s/n]", "Error", 2))
					{
						retorno = 6;
					}
				break;
			}
		}

	}while(retorno != 6);

	return retorno;
}


int eServicios_alta(eServicios array[], int TAM)
{
	int retorno = -1; //ERROR
	eServicios auxServicios;
	int indice;
	if(array != NULL && TAM > 0)
	{
		indice = eServicios_obtenerIndiceLibre(array, TAM);

		if (indice > -1 && (!eServicios_cargarDatos(&auxServicios)))
		{

			if(utn_verificar("¿Desea guardar los cambios[s/n]?", "Error", 2) == 0)
			{
				auxServicios.idServicios = eServicios_obtenerID();
				auxServicios.isEmpty = OCUPADO;
				array[indice] = auxServicios;
				retorno = 0; //se dio de alta satisfactoriamente
			}
			else
			{
				retorno = 1; //Operacion cancelada
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

int eServicios_baja(eServicios array[], int TAM)
{
	int retorno = -2; //ERROR
	int idServicios;
	int indice;
	int cantidadAltas;
	int idMaximo;
	int respuesta;
	eServicios buffer;

	int flag = 0;
	if (eServicios_mostrarTodos(array, TAM, &cantidadAltas)==0)
	{
		flag = 1;
	}
	if (flag)
	{
		eServicios_buscarIdMaximo(array, TAM, &idMaximo);
		if(utn_pedirEntero(&idServicios, "\nIngrese el ID del Servicios que quiere dar de baja: \n", "\nError. \n", 1, idMaximo, 2, 1)==0)
		{

			respuesta = eServicios_buscarIndicePorId(array, TAM, idServicios, &indice);
			switch (respuesta)
			{
				case -2: //ERROR
					retorno = -2;
				break;
				case 0: //OCUPADO
					buffer = array[indice];
					eServicios_mostrarUno(&buffer); //____DUDA___//BUFFER->ARRAY[indice]
					if(utn_verificar("\n¿Desea dar de baja este Servicios [s/n]?", "\nError", 2)==0)
					{
						array[indice].isEmpty = BAJA; //baja logica.
						retorno = 0; //BAJA CORRECTAMENTE.
					}
					else
					{
						retorno = 2;
					}
				break;
				case 1: //BAJA
					retorno = 1; // Servicios YA DADO DE BAJA
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

int eServicios_Modificacion(eServicios array[], int TAM)
{
	int retorno = -2; //ERROR;
	int idServicios;
	int indice;
	int cantidadServicios;
	int respuesta;
	int idMaximo;
	int flag = 0;
	eServicios auxiliar;
	if(array != NULL && TAM > 0)
	{
		eServicios_mostrarTodos(array, TAM, &cantidadServicios);
		if (cantidadServicios>0)
		{
			flag = 1;
		}
		if (flag)
		{
			eServicios_buscarIdMaximo(array, TAM, &idMaximo);
			if(!utn_pedirEntero(&idServicios, "\ningrese el ID del Servicios que quiere modificar", "\nError", 1, idMaximo, 2, 1))
			{
				respuesta = eServicios_buscarIndicePorId(array, TAM, idServicios, &indice);
				switch (respuesta)
				{//////////////////////////////////////////////////////////////////////////////
					case -2: //ERROR
						retorno = -2;
					break;
					case 0: //OCUPADO
						auxiliar = array[indice];
						eServicios_mostrarUno(&auxiliar); //____DUDA___//BUFFER->ARRAY[indice]
						eServicios_modificarUno(&auxiliar);
						if(!utn_verificar("\n¿Desea confirmas la modificación?[s/n]?\n", "nError", 2))
						{
							eServicios_mostrarTodos(array, TAM, &cantidadServicios);
							array[indice]= auxiliar;
							retorno = 0; //MODIFICADO CORRECTAMENTE.
						}
						else
						{
							retorno = -1; // modificacion cancelada
						}
					break;
					case 1: //BAJA
						retorno = 1; // Servicios  DADO DE BAJA
					break;
				}
			}
			else
			{
				printf("ID no existe.");
			}
		}
	}
	return retorno;
}

int eServicios_Sort(eServicios array[], int TAM, int criterio) {
	int retorno = 0;
	int i;
	int j;
	eServicios aux;

	/** EJEMPLO DE SORT CON ID DE Servicios */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && TAM > 0)
	{
		switch (criterio)
		{
			case 4:
				for (i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{
						if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO)
						{
							if (array[i].idServicios > array[j].idServicios)
							{
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}
					}
				}
			retorno = 1; //ID
			break;
			case 3:
				for (i = 0; i < TAM - 1; i++)
				{
					for (j = i + 1; j < TAM; j++)
					{
						if (array[i].isEmpty == OCUPADO
							&& array[j].isEmpty == OCUPADO)
						{
							if (array[i].idServicios < array[j].idServicios)
							{
								aux = array[i];
								array[i] = array[j];
								array[j] = aux;
							}
						}
					}
				}
				retorno = 1;
				break;
				case 1: //Precio
					printf("\n\t LISTA POR PRECIO: \n\n");
					for (i = 0; i < TAM - 1; i++)
					{
						for (j = i + 1; j < TAM; j++)
						{
							if (array[i].isEmpty == OCUPADO
								&& array[j].isEmpty == OCUPADO)
							{
								if (array[i].precio > array[j].precio)
								{
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;
								}
							}
						}
					}
				retorno = 1;
				break;
				case 2: //Descrtipcion
					printf("\n\t LISTA POR DESCRIPCIÓN: \n\n");
					for (i = 0; i < TAM - 1; i++)
					{
						for (j = i + 1; j < TAM; j++)
						{
							if (array[i].isEmpty == OCUPADO
								&& array[j].isEmpty == OCUPADO)
							{
								if (strcmp(array[i].descripcion, array[j].descripcion)>0)
								{
									aux = array[i];
									array[i] = array[j];
									array[j] = aux;
								}
							}
						}
					}
					retorno = 1;
				break;
				default:
					//CRITERIO DE ORDENAMIENTO MAL INGRESADO
					retorno = 0;
					break;
				}
	}
	return retorno;
}
