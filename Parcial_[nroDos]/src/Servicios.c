/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "LinkedList.h"
#include "UTN.h"
#include "parser.h"


/*
static int isValidNombre(char* cadena,int longitud);
static int esNumerica(char* cadena, int limite);
static int esFlotante(char* cadena,int limite);

*/
eServicios* Servicios_new()
{
	eServicios* newServicio = NULL;
	newServicio = (eServicios*)malloc(sizeof(eServicios));
	if(newServicio != NULL)
	{
		newServicio->id = 0;
		strcpy(newServicio->descripcion," ");
		newServicio->tipo = 0;
		newServicio-> precio = 0;
		newServicio->cantidad = 0;
		newServicio-> total = 0;

		newServicio-> isEmpty = 1;
	}
	return newServicio;
}

eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioStr,char* cantidadStr,char* totalStr)
{
	eServicios* newServicio = Servicios_new ();
	if (newServicio != NULL)
	{
		if(
			Servicios_setId(newServicio,atoi(idStr)) &&
			Servicios_setDescripcion(newServicio,descripcionStr) &&
			Servicios_setTipo(newServicio,atoi(tipoStr))&&
			Servicios_setPrecio(newServicio,atof(precioStr)) &&
			Servicios_setCantidad(newServicio,atoi(cantidadStr))&&
			Servicios_setTotal(newServicio,atof(totalStr)))
		{
			printf("\nPasajero en preoceso de carga.... \n");
		}
		else
		{
			free (newServicio);
			newServicio = NULL;
		}
	}
	return newServicio;
}


void Servicios_delete(eServicios* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Servicios_setId(eServicios* this,int id)
{
	int retorno = 0;
	if(this != NULL && id >= 0)
	{
		this->id = id;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getId(eServicios* this,int* id)
{
	int retorno = 0;
	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setDescripcion(eServicios* this,char* descripcion)
{
	int retorno = 0;
	if(this != NULL && descripcion!= NULL ) // && strlen(nombre)>0 && strlen(nombre)<=15
	{
		strncpy(this->descripcion,descripcion,30);
		retorno = 1;
	}
	return retorno;
}
int Servicios_getDescripcion(eServicios* this,char* descripcion)
{
	int retorno = 0;
	if(this != NULL &&  descripcion != NULL)
	{
		strncpy(descripcion,this->descripcion,30);
		retorno = 1;
	}
	return retorno;
}


int Servicios_setTipo(eServicios* this,int tipo)
{
	int retorno = 0;
	if(this != NULL && tipo > 0 && tipo < 4)
	{
		this->tipo = tipo;

		retorno = 1;
	}
	return retorno;
}
int Servicios_getTipo(eServicios* this,int* tipo)
{
	int retorno = 0;
	if(this != NULL && tipo != NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setPrecio(eServicios* this,float precio)
{
	int retorno = 0;
	if(this != NULL &&  precio >= 0 && precio<=100000000)
	{
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getPrecio(eServicios* this,float* precio)
{
	int retorno = 0;
	if(this != NULL &&  precio != NULL)
	{
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setCantidad(eServicios* this,int cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad >= 0)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getCantidad(eServicios* this,int* cantidad)
{
	int retorno = 0;
	if(this != NULL && cantidad != NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}
	return retorno;
}

int Servicios_setTotal(eServicios* this,float total)
{
	int retorno = 0;
	if(this != NULL &&  total >= 0 && total<=10000000)
	{
		this->total = total;
		retorno = 1;
	}
	return retorno;
}
int Servicios_getTotal(eServicios* this,float* total)
{
	int retorno = 0;
	if(this != NULL &&  total != NULL)
	{
		*total = this->total;
		retorno = 1;
	}
	return retorno;
}



int Servicios_BuscarPaxId (LinkedList* pArrayListPassenger, int id)
{
	int tamanio;
	int retorno = 0;
	int idAux;
	eServicios* auxPassenger;

		if (pArrayListPassenger != NULL && id >= 0)
		{
			tamanio = ll_len(pArrayListPassenger);
			for(int i = 0 ; i < tamanio ; i++)
			{
				auxPassenger = ll_get(pArrayListPassenger,i);
				if (auxPassenger != NULL)
				{
					Servicios_getId (auxPassenger,&idAux);

					if(id == idAux)
					{
						retorno = i;
						break;
					}
				}
			}
		}
	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es un nombre valido
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es valida y 0 (falso) si no lo es
 *
 */
/*

static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
*/
/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
 *
 */
/*
static int esNumerica(char* cadena, int limite)
{
	int retorno = -1; // ERROR
	int i;
	if(cadena != NULL && limite > 0)
	{
		retorno = 1; // VERDADERO
		for(i=0;i<limite && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))
			{
				continue;
			}
			if(cadena[i] < '0'||cadena[i] > '9')
			{
				retorno = 0;
				break;
			}
			//CONTINUE
		}
		//BREAK
	}
	return retorno;
}

static int esFlotante(char* cadena,int limite)
 {
 	int retorno = 1;
 	int flagDecimal=1;

 	int i;
 	if(cadena != NULL && limite>0)
 	{
 		for(i=0; i < limite && cadena[i] != '\0';i++)
 		{
 			if(flagDecimal==1 && i !=0 && cadena[i]=='.')
 			{
 				flagDecimal=0;
 				continue;
 			}
 			if(cadena[i] < '0' || cadena[i] > '9')
 			{
 				retorno = 0;
 				break;
 			}
 		}
 	}
 	return retorno;
 }
*/
/**********************************************************************/

