/*
 * censista.c
 *
 *  Created on: 21 may 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "censista.h"
/**
 * \brief Imprime el array de censistas
 * \param array eCensista de viviendas a que estan de alta
 * \param tamanio Limite del array de viviendas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int imprimirCensistas (eCensista* array, int tamanio)
{
	int retorno = -1;

	if (array != NULL && tamanio >0)
	{

		printf("\n 			**LISTADO DE CENSISTAS** \n");
		printf("-------------------------------------------------------------------\n");
		printf("LEGAJO	 	NOMBRE		 EDAD		   TELEFONO		 \n");
		printf("-------------------------------------------------------------------\n");
		for (int i = 0;i<tamanio;i++)
		{
			imprimirUnCensista (&array[i]);
		}

		printf("-------------------------------------------------------------------\n");
		retorno = 0;
	}
	return retorno;
}
/**
 * \brief Imprime los datos de un censista
 * \param eCencista Puntero a la vivienda que se busca imprimir
 * \return Retorna VOID
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
void imprimirUnCensista (eCensista* array)
{
		printf("\n%d	 	%s		  %d     	   %s \n",
		array->legajoCensista,array->nombre,array->edad,array->telefono);
}


