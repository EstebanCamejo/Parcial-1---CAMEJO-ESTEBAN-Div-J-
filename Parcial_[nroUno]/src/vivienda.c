/*
 * vivienda.c
 *
 *  Created on: 21 may 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vivienda.h"
#include "UTN.h"

/**
 * \brief Inicializa el array
 * \param array viviendas de clientes a ser actualizado
 * \param limite tamanio del array de viviendas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
void inicializarVivienda (eVivienda* array, int tamanio, int* pResultado)
{
		 int retorno = -1;
		 int i;

		  if(array != NULL && tamanio > 0)
		  {
			  for (i = 0; i <tamanio ; i++)
			  {
				  (*(array+i)).isEmpty = 1;
			  }
			  retorno = 0;
		  }
		  *pResultado = retorno;
}

/**
 * \brief Buscar primer posicion vacia
 * \param espacio Array de viviendas
 * \param tamanio Limite del array de viviendas
 * \param espacio libre retorna el primer espacio libre encontrado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int buscarEmptyLibre(eVivienda espacio[], int tamanio, int* espacioLibre)
{

	int i;
	int retorno  = -1;

	if (tamanio > 0 && espacio != NULL && espacioLibre != NULL)
	{

		for (i = 0;i<tamanio; i++)
		{
			if ( (*(espacio + i)).isEmpty == 1)
			{
				*espacioLibre = i;

				retorno = 0;
			}
		}
	}

	return retorno;
}

/**
 * \brief Da de alta una vivienda en una posicion del array
 * \param array viviendas a ser actualizado
 * \param tamanio Limite del array de pantallas
 * \param indice (SOLO ENVIADO EN EL LLAMADO) indice Posicion a ser actualizada
 * \param id Identificador a ser asignado a la vivienda
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int altaVivienda (eVivienda* array,int tamanio, int* id)
{
	int retorno = -1;

	if (array != NULL && tamanio >0 && id != NULL)
	{

		if (
			utn_getNombre(array->calle,LENNAME,"\nIngrese el nombre de la calle. \n","\nError. \n", 3)==0&&
			utn_getNumero(&array->cantidadPersonas,"\nIngrese la cantidad de personas.\n","\nError. \n (Maximo aceptado 50)\n",1,50,3)==0&&
			utn_getNumero(&array->cantidadHabitaciones,"\ningrese la cantidad de habitaciones.","\nError. \n",1,20,3)==0&&
			utn_getNumero(&array->typeVivienda, "\nIngrese el tipo de vivienda: \n 1. Casa. \n 2. Departamento. \n "
			"3. Casilla. \n 4. Rancho.","ERROR. \nIngrese una opcion del 1 al 4\n",1,4,3) == 0)
			{
				array->idVivienda =*id;
				array->isEmpty = 0;
				*id = *id + 1;
			}
			retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime el array de viviendas
 * \param array eVivienda de viviendas a que se dieron de alta
 * \param tamanio Limite del array de viviendas
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */

void imprimirViviendas (eVivienda* array, int tamanio,int* pResultado)
{
	int retorno = -1;
	if (array != NULL && tamanio >0)
	{
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("\n 				  **LISTADO DE ALTAS** \n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		printf("CALLE	 	  C.PERSONAS		 C.HABITACIONES		 TIPO VIVIENDA		    ID VIVIENDA	\n");
		printf("--------------------------------------------------------------------------------------------------------\n");
		for (int i = 0; i<tamanio; i++)
		{
			if( (*(array + i)).isEmpty == 0)
			{
				imprimirVivienda((*(array+i));
			}
		}

		printf("\n--------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}
	 *pResultado = retorno;
}

/**
 * \brief Imprime los datos de una vivienda
 * \param eVivienda Puntero a la vivienda que se busca imprimir
 * \return Retorna VOID
* \return Retorna 0 (EXITO) y -1 (ERROR)
 */
void imprimirVivienda (eVivienda* vivienda)
{

	etypeVivienda auxType [4] = {{1,"Casa"},{2,"Departamento"},{3,"Casilla"},{4,"Rancho"}};

	int i ;

		for ( i = 0; i<4; i++){

			if (vivienda->typeVivienda == auxType[i].typeVivienda)
			{
				break;
			}
		}

		printf("\n%s	 	  %d		     	    %d     		  %s	            %d\n",
		vivienda->calle, vivienda->cantidadPersonas, vivienda->cantidadHabitaciones, auxType[i].descripcion, vivienda->idVivienda);

}

/**
 * \brief Valido un id y retorno el indice
 * \param eVivienda array a la vivienda que se desea validar
 * \param tamanio Limite del array de viviendas
 * \param id que se desea validar
 * \param indice retorna la posicion validada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int validarIdVivienda (eVivienda array[], int tamanio,int id,int *indice)
{
	int retorno = -1;

	if (array != NULL && tamanio >0 && indice != NULL)
	{
			for(int i= 0; i<tamanio;i++)
			{
				if( (*(array + i)).isEmpty==0 && id == (*(array + i)).idVivienda)
				{
					*indice=i;
					retorno=0;
					break;
				}
		}
	}

	return retorno;
}

/**
 * \brief Actualiza los datos de una vivienda en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \\param indice (SOLO ENVIADO EN EL LLAMADO) indice Posicion a ser actualizada
 * \return Retorna Void
 *
 */
void vivienda_modificarMenu(eVivienda* bufferVivienda)
{
	int opcion;

				do{
						if (utn_getNumero(&opcion,"\n\nPor favor ingrese la opcion que "
														"desea modificar: \n\n"

														"\n 1) Calle.\n"
														"\n 2) Cantidad de Personas.\n"
														"\n 3) Cantidad de Habitaciones.\n"
														"\n 4) Tipo de vivienda.\n"
														"\n 5) Salir.\n",
														"ERROR opcion incorrecta \n",1, 5, 4) == 0)
						{

							switch (opcion)
							{

								case 1 :

									if(utn_getNombre(bufferVivienda->calle,LENNAME,
									"\nIngrese el nombre de la calle. \n","\nError. \n", 3) == 0)
									{
										printf("\n**MODIFICACION EXITOSA**");
									}

									break;

								case 2 :

									if(utn_getNumero(&bufferVivienda->cantidadPersonas,
									"\nIngrese la cantidad de personas.\n","\nError. (Maximo aceptado 50) \n",1,50,3) == 0)
									{
										printf("\n**MODIFICACION EXITOSA**");
									}

									break;

								case 3 :

									if(utn_getNumero(&bufferVivienda->cantidadHabitaciones,
									"\ningrese la cantidad de habitaciones.","\nError. \n",1,20,3)== 0)
									{
										printf("\n**MODIFICACION EXITOSA**");
									}
									break;

								case 4 :

									if(utn_getNumero(&bufferVivienda->typeVivienda, "\nIngrese el tipo de pax: "
									"\n 1. Casa. \n 2. Departamento. \n 3. Casilla. \n 4. Rancho.","\nError. \n",1,4,3) == 0)

									{
										printf("\n**MODIFICACION EXITOSA**");
									}

									break;

								} // FIN DEL SWITCH

						} // FIN DEL MENU

						}while(opcion != 5);

}
/**
 * \brief Actualiza una posicion del array
 * \param array Array de viviendas a ser actualizado
 * \param indice (SOLO ENVIADO EN EL LLAMADO) indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removerVivienda (eVivienda* bufferEmpleado)
{
	int retorno = -1;

	if (bufferEmpleado != NULL && bufferEmpleado->isEmpty == 0)
	{

		bufferEmpleado ->isEmpty = 1;

		retorno = 0;
	}

	return retorno;
}
/**
 *\brief Ordenar el array de clientes por nombre (calle)y OTRO PARAMETRO
 *\brief array de viviendas a ordenar
 *\param tamanio limite del array de viviendas
 *\param param retorna un 0 (EXITO) y -1 (ERROR)
 */

void ListarViviendasCalleCant (eVivienda* array, int tamanio, int* pResultado)
{
	int retorno = -1;
	int flagSwap;
	int i;

	eVivienda bufferSwap;

	if (array != NULL && tamanio >0){
			do {
				  flagSwap = 0;

				  for (i = 0 ; i< tamanio - 1; i++)
				  {
						if ( (*(array + i)).isEmpty == 1 || array[i + 1].isEmpty == 1) // (*array i + 1)
						{
									continue;
						}
						if(strncmp((*(array + i)).calle, array[i + 1].calle,LENNAME) > 0)
						{
							flagSwap = 1;
							bufferSwap = array[i];
							array[i] = array[i + 1];
							array[i + 1] = bufferSwap;
						}
						else if (strncmp((*(array + i)).calle, array[i + 1].calle,LENNAME) == 0
						&& (*(array + i)).cantidadPersonas > array[i + 1].cantidadPersonas)
						{
							flagSwap = 1;
							bufferSwap = (*(array + i));
							(*(array + i)) = array[i + 1];
							array[i + 1] = bufferSwap;
						}
				  }// FIN DEL FOR

				  tamanio --;

			}while (flagSwap);

			retorno = 0;
	} // FIN DEL IF
	 *pResultado = retorno;
}
/**
 *\brief Puntero a funcion, recibe 2 parametros
 *\brief array de viviendas en el que se desea trabajar
 *\param tamanio limite del array de viviendas
 *\param retorno retorna el resultado que devuelve la funcion que es llamada
 *\param param retorna un 0 (EXITO) y -1 (ERROR)
 */

int PrimerPuntero (eVivienda* array, int tamanio, void(*pFuncion)(eVivienda*,int,int*))
{
	int retorno;

	pFuncion(array, tamanio, &retorno);

	return retorno;
}





