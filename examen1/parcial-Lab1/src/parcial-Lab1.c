/*
 ============================================================================
 Name        : parcial-Lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>



#include"Conjuntos.h"


#define TAM_ESTRUCTURA_TRAB 15
#define TAM_ESTRUCTURA_SERV 10

int main(void) {


	setbuf(stdout, NULL);
	int cantidadTotal;
	int opcion;
	int criterioDeOrdenamiento;
	int bufferRespuestas;
	eTrabajo Trabajo[TAM_ESTRUCTURA_TRAB];
	eTrabajo_inicializar(Trabajo, TAM_ESTRUCTURA_TRAB);
	eTrabajo_cargaAutomaticaTrabajo(Trabajo, TAM_Trabajo);
	eServicios Servicios[TAM_ESTRUCTURA_SERV];
	eServicios_inicializar(Servicios, TAM_ESTRUCTURA_SERV);
	eServicios_cargaAutomaticaServicios(Servicios, TAM_Servicios);

	do {
		printf("\nMENU: \n1_Alta.\n2_Baja.\n3_Modificación\n4_Listado productos\n0_Salir.\n");
		if(!utn_pedirEntero(&opcion, "\nIngrese el numero correstpondiente a la acción que desea realizar: \n", "Error.\n", 0, 4, 2, 1))
		{
			printf("\nOpción elegida: %d\n", opcion);
			switch (opcion)
			{
				case 0:
					bufferRespuestas = utn_verificar("¿Desea salir [s/n]?", "Error.\n", 2);
					if(bufferRespuestas == 0)
					{
						opcion = 50; //si
					}
					break;
				case 1:
					//ALTA
					bufferRespuestas = eConjuntos_alta(&Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV);
					switch (bufferRespuestas)
					{
					case -2:
						puts("No hay espacio para guardar otro Trabajo.\n");
					break;
					case -1:
						puts("Error.\n");
					break;
					case 0:
						puts("Alta exitosa.\n");
						eConjuntos_mostrarTodos(Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV, &cantidadTotal);
					break;
					case 1:
						puts("Operacion cancelada con exito.\n");
					break;
					}
					eConjuntos_mostrarTodos(Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV, &cantidadTotal);
				break;
				case 2:
					//BAJA
					bufferRespuestas = eConjuntos_baja(Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV);
					switch (bufferRespuestas)
					{
						case -2:
							printf("5656");
							puts("Error.\n");
						break;
						case -1:
							bufferRespuestas = utn_verificar("ID no existe.\n¿Desea volver al menu?\n [s/n]", "Error.\n", 2);
							if(bufferRespuestas == 1)
							{
								opcion = 50; //si
							}
						break;
						case 0:
							puts("Baja exitosa.\n");
						break;
						case 1:
							puts("Trabajo ya dado de baja.\n");
						break;
						case 2:
							printf("\nBaja cancelada \n\n.");
						break;
					}

				break;
				case 3: /*//MODIFICACION
					opcion = eConjuntos_Modificacion(Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV);
					switch(opcion)
					{
						case -2:
							printf("\nError.");
						break;
						case -1:
							printf("\nModificación cancelada.");
						break;
						case 0:
							printf("\nModificación exitosa.");
						break;
						case 1:
							printf("\nTrabajo dado de baja, no se puede modificar.");
						break;
					}
				break;
				case 4: //ordenado por descripción.

					eConjuntos_mostrarTodos(Trabajo, TAM_ESTRUCTURA_TRAB, Servicios, TAM_ESTRUCTURA_SERV, &cantidadTotal);
					/*printf("\n\n\t LISTAS \nOrdenadas por: \n1_Precio.\n2_Descripción.");
					if(!utn_pedirEntero(&criterioDeOrdenamiento, "\nIngrese el numero correspondiente al criterio de ordenamiento: ", "Error.", 1, 2, 2, 1))
					{
						eTrabajo_Sort(Trabajo, TAM_ESTRUCTURA, criterioDeOrdenamiento);
						eTrabajo_mostrarTodos(Trabajo, TAM_ESTRUCTURA, &cantidadTotal);
						printf("\nTotal: %d \n\n", cantidadTotal);
					}*/
				break;
			}
		}
	}while(opcion != 50);
	printf("Gracias.");




	return EXIT_SUCCESS;
}
