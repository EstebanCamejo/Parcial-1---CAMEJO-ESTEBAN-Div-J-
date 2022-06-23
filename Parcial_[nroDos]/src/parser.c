#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Servicios.h"
#include "UTN.h"
#include "parser.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_ServiciosFromText(FILE* pFile , LinkedList* pArrayListServicios)
{
	int retorno = 0;
	char buffer1[50], buffer2[50], buffer3[50], buffer4[50], buffer5[8], buffer6[50];
	eServicios* pAuxServicio;
	int cant;

	if (pFile == NULL)
	{
		printf("Error al escanear el archivo.");
		retorno = 0;
		system("pause");
		exit (EXIT_FAILURE);
	}
	else
	{
		printf("\n** CARGA DE ARCHIVO EN PROCESO **\n");
	}
// LECTURA FANTASMA 	- 1   -2    -3    -4   -5   -6
	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4,buffer5,buffer6);
	while(!feof(pFile))
	{
		cant = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",buffer1,buffer2,buffer3,buffer4,buffer5,buffer6);
		if (cant < 6)
		{
			printf("Error al leer el archivo.");
			break;
		}
		pAuxServicio = Servicios_newParametros(buffer1,buffer2,buffer3,buffer4,buffer5,buffer6);
		if(pAuxServicio != NULL)
		{
			ll_add(pArrayListServicios,pAuxServicio);
			printf("\nArchivo cargado con exito! ");
			retorno = 1;
		}
	}
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

/*
int parser_ServiciosFromBinary(FILE* pFile , LinkedList* pArrayListServicios)
{
	eServicios* pAuxServicio;
	int retorno;
	int auxPax;
	int id;

	if(pFile != NULL && pArrayListServicios != NULL )
	{
		while(!feof(pFile))
		{
			pAuxServicio = Servicios_new();
			fread(pAuxServicio,sizeof(eServicios),1,pFile);

			if(!feof(pFile))
			{
				auxPax = ll_add(pArrayListServicios,pAuxServicio);
				if(auxPax != 0)
				{
					//Passenger_delete(pAuxPassenger);
					retorno = 0;
					break;
				}
				else
				{
					id = pAuxServicio-> id;
					retorno =1;
				}
			}
			else
			{
				retorno = 0;
				break;
			}
		}
		controller_GuardarSiguienteID (id);
	}
	return retorno;
}
*/
