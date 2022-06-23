#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Servicios.h"
#include "parser.h"
#include "UTN.h"
#include "Controller.h"


/*
static int controller_printPassenger (Passenger* pPassenger);

static int controller_ListPassengerStatic(LinkedList* pArrayListPassenger);
static int controller_getMaximoId(LinkedList* pArrayListPassenger);
static int controller_ValidarId (LinkedList* pArrayListPassenger, int id);
*/
static int controller_printServicio(eServicios* pServicio);

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicios)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListServicios != NULL && path != NULL)
	{
		printf("\n\n**Cargando los datos desde el archivo (TXT).**\n");
		pFile = fopen (path, "r");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if(parser_ServiciosFromText(pFile, pArrayListServicios))
			{
				printf("\nEl archivo (TXT) fue cargado exitosamente.\n");
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}
/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

/*

int controller_loadFromBinary(char* path , LinkedList* pArrayListServicios)
{
	FILE* pFile;
	int retorno = 0;

	if (pArrayListServicios != NULL && path != NULL)
	{
		printf("\n\n**Cargar los datos desde el archivo (BIN).**\n");
		pFile = fopen (path, "a+b");
		if (pFile == NULL)
		{
			printf("\nERROR al abrir el archivo.\n");
		}
		else
		{
			if (parser_ServiciosFromBinary(pFile,pArrayListServicios))
			{
				printf("\nEl archivo (TXT) fue cargado exitosamente.\n");
				retorno = 1;
			}
		}
	}
	fclose(pFile);
	return retorno;
}
*/
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
/*
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	eServicios* newPassenger = Servicios_new ();
	int retorno = 0;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	char codigoVuelo[8];
	int tipoPasajeroint;
	char tipoPasajero[15];
	int estadoVueloInt;
	char estadoVuelo [15];

	if (pArrayListPassenger != NULL)
	{
		id = controller_SiguienteId(pArrayListPassenger);

		printf("\n ****************************** ALTA DE PASAJEROS ************************************ \n\n");

		if(
			utn_getNombre(nombre,50,"\nIngrese el nombre. \n","\nError. \n", 3) == 0 &&
			utn_getNombre(apellido,50,"\nIngrese el pellido. \n","\nError. \n", 3) == 0 &&
			getNumeroFlotante(&precio,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3) == 0 &&
			getAlfanumerico(codigoVuelo,"\nIngrese los 7 digitos del codigo aereo.\n","\nError. \n",7,3) == 0 &&
			utn_getNumero(&tipoPasajeroint, "\nIngrese el tipo de pax: \n 1. FirstClass. \n 2. ExecutiveClass.\n"
											" 3. EconomyClass.\n","\nError. \n",1,3,3) == 0 &&
			utn_getNumero(&estadoVueloInt,"\nIngrese el estado del vuelo.\n "
			"1. Aterrizado. \n 2. En Horario.\n 3. Demorado.\n 4. En vuelo.\n","\nError. \n",1,4,3) == 0)
		{
			switch(tipoPasajeroint)
			{
				case 1 :
					strcpy(tipoPasajero,"FirstClass");
					break;
				case 2 :
					strcpy(tipoPasajero,"ExecutiveClass");
					break;
				case 3 :
					strcpy(tipoPasajero,"EconomyClass");
					break;
			}
			switch(estadoVueloInt)
			{
				case 1 :
					strcpy(estadoVuelo,"Aterrizado");
					break;
				case 2 :
					strcpy(estadoVuelo,"En Horario");
					break;
				case 3 :
					strcpy(estadoVuelo,"Demorado");
					break;
				case 4 :
					strcpy(estadoVuelo,"En vuelo");
					break;
			}
			newPassenger = Passenger_newParametrosAlta(id,nombre,apellido,precio,codigoVuelo,tipoPasajero,estadoVuelo);
				if(newPassenger != NULL)
				{
					if (ll_add(pArrayListPassenger,newPassenger) == 0)
					{
						controller_GuardarSiguienteID(id);
						printf("\nPasajero cargado con exito! \n");
						retorno = 1;
					}
					else
					{
						printf("\nERROR DE CARGA \n");
					}
				}
				else
				{
					free (newPassenger);
					newPassenger = NULL;
				}
		}
	}
	else
	{
		printf("**ERROR NO SE ENCUENTRA ESPACIO DISPONIBLE PARA REALIZAR LA CARGA**");
	}

    return retorno;
}
*/
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
/*
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	int id;
	char nombre[15];
	char apellido[15];
	float precio;
	int tipoPasajeroint;
	char tipoPasajero[15];
	char codigoVuelo[8];
	int estadoVueloInt;
	char estadoVuelo [15];
	int option;
	int indicePax;
	int reintentos = 3;
	eServicios* editPassenger;

	system("cls");
	printf("\n 				              **MODIFICACION PASAJEROS** \n");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\n\nPor favor, ingrese el numero de ID del pax que desea modificar.");
		scanf("%d",&id);
		while(controller_ValidarId(pArrayListPassenger,id) == 0 || reintentos == 0)
		{
			printf("\n\ERROR. \nPor favor, ingrese el **numero de ID** del pax que desea modificar.");
			scanf("%d",&id);
			reintentos--;
		}

		indicePax = Passenger_BuscarPaxId (pArrayListPassenger,id);
		editPassenger = ll_get(pArrayListPassenger,indicePax);

		if(indicePax == -1)
		{
			printf("\n\ERROR. \n **Numero de ID inexistente**");
		}
		else
		{
			printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
			controller_printPassenger(editPassenger);

			if(utn_getNumero(&option,"\n\nPor favor ingrese una opcion correcta: \n\n"
			    					"1) Modificar Nombre. \n"
			    			 		"2) Modificar Apellido. \n"
			    					"3) Modificar Precio. \n"
			    					"4) Modificar Codigo Aereo.\n"
			    					"5) Modificar Tipo de Pasajero.\n"
									"6) Modificar Estado de Vuelo. \n", "\nError. \n"
									,1,6,3)==0){

				switch (option){

				case 1:

						if(utn_getNombre(nombre,50,"\nIngrese el nombre. \n","\nError. \n", 3) == 0)
						{
							Passenger_setNombre(editPassenger,nombre);
							printf("\nModificacion exitosa!");
						}

					break;

				case 2:
						if(utn_getNombre(apellido,50,"\nIngrese el pellido. \n","\nError. \n", 3) == 0)
						{
							Passenger_setApellido(editPassenger,apellido);
							printf("\nModificacion exitosa!");
						}

					break;

				case 3:
						if(getNumeroFlotante(&precio,"\ningrese el precio del vuelo.","\nError. \n",1.0,500000.0,3)==0)
						{
							Passenger_setPrecio(editPassenger,precio);
							printf("\nModificacion exitosa!");
						}

					break;

				case 4:
						if(getAlfanumerico(codigoVuelo,"\nIngrese los 7 digitos del codigo aereo.\n","\nError. \n",7,3) == 0)
						{
							Passenger_setCodigoVuelo(editPassenger,codigoVuelo);
							printf("\nModificacion exitosa!");
						}

					break;

				case 5:
						if(utn_getNumero(&tipoPasajeroint, "\nIngrese el tipo de pax: \n 1. FirstClass. \n 2. ExecutiveClass.\n"
								" 3. EconomyClass.\n","\nError. \n",1,3,3) == 0)
						{
							switch(tipoPasajeroint)
							{
								case 1 :
									strcpy(tipoPasajero,"FirstClass");
									break;
								case 2 :
									strcpy(tipoPasajero,"ExecutiveClass");
									break;
								case 3 :
									strcpy(tipoPasajero,"EconomyClass");
									break;
							}
							Passenger_setTipoPasajero(editPassenger,tipoPasajero);
							printf("\nModificacion exitosa!");
						}

					break;

				case 6:
						if(utn_getNumero(&estadoVueloInt,"\nIngrese el estado del vuelo.\n "
								"1. Aterrizado. \n 2. En Horario.\n 3. Demorado.\n 4. En vuelo.\n","\nError. \n",1,4,3) == 0)
						{
							switch(estadoVueloInt)
							{
								case 1 :
									strcpy(estadoVuelo,"Aterrizado");
									break;
								case 2 :
									strcpy(estadoVuelo,"En Horario");
									break;
								case 3 :
									strcpy(estadoVuelo,"Demorado");
									break;
								case 4 :
									strcpy(estadoVuelo,"En vuelo");
									break;

							}
							Passenger_setEstadoVuelo(editPassenger,estadoVuelo);
							printf("\nModificacion exitosa!");
						}

					break;

					retorno = 1;
				}
			}
			else
			{
				printf("\nERROR! La modificacion ha sido cancelada.");
			}
		}
	}
    return retorno;
}
*/
/** \brief Baja de pasajero
 *
 * \param path ch
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

/*
	 * pide id a eliminar
	 * uscar el indice donde esta el id
	 * con **ll_get** (linkendlist) obtener el puntero de ese indice
	 * confirmar la baja / employe_delete ---- ll_remove (linkendlist);
	 *
	 * */

/*
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	eServicios* removePassenger;
	int id;
	int reintentos = 3;
	int retorno = 0;
	int indicePax;
	int option;

	system("cls");
	printf("\n 				              **REMOVER PASAJEROS** \n");
	printf("\n----------------------------------------------------------------------------------------------------------------------------------------\n");
	if (pArrayListPassenger != NULL)
	{
		controller_ListPassenger(pArrayListPassenger);
		printf("\n\nPor favor, ingrese el numero de ID del pax que desea REMOVER.");
		scanf("%d",&id);
		while(controller_ValidarId(pArrayListPassenger,id) == 0 || reintentos == 0)
		{
			printf("\n\ERROR. \nPor favor, ingrese el **Numero de ID** del pax que desea *REMOVER*.");
			scanf("%d",&id);
			reintentos--;
		}
		indicePax = Passenger_BuscarPaxId (pArrayListPassenger,id);
		removePassenger = ll_get(pArrayListPassenger,indicePax);
		if(indicePax == -1)
		{
			printf("\n\ERROR. \n **Numero de ID inexistente**");
		}
		else
		{
			printf("----------------------------------------------------------------------------------------------------------------------------------------\n");
			printf("ID	 	NOMBRE		 APELLIDO		 PRECIO		 CODIGO	AEREO	TIPO PASAJERO 		ESTADO");
			printf("\n--------------------------------------------------------------------------------------------------------------------------------------\n");
			controller_printPassenger(removePassenger);
		}
		if(utn_getNumero(&option,"\n\nPor favor ingrese una opcion correcta: \n\n"
					    					"1) REMOVER EL PASAJERO. \n"
					    			 		"2) SALIR. \n", "\nError. \n"
											,1,2,3)==0){
						switch (option){

						case 1:
								if(ll_remove(pArrayListPassenger,indicePax) == 0)
								{
									printf("\nEl pasajero se removio correctamente!");
								}
								retorno = 1;
							break;

						case 2:  printf("\nNo se realizaron cambios en la lista!");

							break;
						}
		}
		else
		{
			printf("\ERROR al remover el pasajero!");
		}
	}

	return retorno;
}
*/
/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListServicios)
{
	eServicios*  pAuxServicio = NULL;
	int retorno = 0;
	int tamanio;

	if (pArrayListServicios != NULL){

		tamanio = ll_len(pArrayListServicios);

		printf("\n 				              **LISTADO SERVICIO** \n");
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("ID SERVICIO	 	DESCRIPCION		 TIPO		 PRECIO/UNITARIO		CANTIDAD	TOTAL SERVICIO");
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");

		for (int i = 0;i<tamanio;i++)
		{
			pAuxServicio = (eServicios*)ll_get(pArrayListServicios,i);

			if(pAuxServicio != NULL)
			{
				controller_printServicio(pAuxServicio);
			}
		}
		printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
		retorno = 1;
	}
    return retorno;
}
/*
 * la funcion imprime solo 1 elemento que es enviado como parametro con su respectiva posicion.
 * */
static int controller_printServicio (eServicios* pServicio)
{
	int retorno = 0;
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;

	if (pServicio != NULL &&
		Servicios_getId(pServicio,&id) &&
		Servicios_getDescripcion(pServicio,descripcion)&&
		Servicios_getTipo(pServicio,&tipo)&&
		Servicios_getPrecio(pServicio,&precio)&&
		Servicios_getCantidad(pServicio,&cantidad)&&
		Servicios_getTotal(pServicio,&total))
	{
		printf("\n	%d	 	%-10s	 	 %-10d		  %.2f	 		%d	 	%.2f             \n",
					id,     descripcion,       tipo,      precio,     cantidad,     total);
		retorno = 1;
	}
	return retorno;
}




/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_sortPassenger(LinkedList* pArrayListServicios)
{
	int retorno =0;
	int i;
	int flagSwap;
	int limite;
	char bufferDescripcion[50];
	char bufferSigDescripcion[50];

	eServicios* pAuxServicio=NULL;
	eServicios* pAuxSigServicio=NULL;


//printf("\n previo a validar");
	if(pArrayListServicios != NULL)
	{
		//printf("\n despues de validar");
		retorno = 1;
		limite = ll_len(pArrayListServicios);
	//	printf("\n limite: %d",limite);
		do
		{
			flagSwap = 0;

			for(i=0;i<limite-1;i++)
			{
				for(int j=i+1;j<limite;j++)
				{
					pAuxServicio = ll_get(pArrayListServicios,i);
					pAuxSigServicio = ll_get(pArrayListServicios,j);

					if(pAuxServicio != NULL && pAuxSigServicio  != NULL)
					{
						//printf("\n ambos punteros difernetes de NULL");
						Servicios_getDescripcion(pAuxServicio,bufferDescripcion);
						Servicios_getDescripcion(pAuxSigServicio,bufferSigDescripcion);

						if(strncmp(bufferDescripcion,bufferSigDescripcion,50) < 0)
						{
							ll_set(pArrayListServicios, i, pAuxSigServicio);
							ll_set(pArrayListServicios, j, pAuxServicio);
							flagSwap=1;
						}
						else if(strncmp(bufferDescripcion,bufferSigDescripcion,50) == 0)
						{
							continue;
						}
					}
				}
			}
			limite--;
		}while(flagSwap);
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicios)
{
	int retorno = 0;
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;
	eServicios*  pAuxServicio;
	FILE* pFile;

	if (path != NULL && pArrayListServicios != NULL)
	{
		pFile = fopen(path,"w");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListServicios);i++ )
		{
			pAuxServicio = ll_get(pArrayListServicios,i);
			if (pAuxServicio != NULL &&
				Servicios_getId(pAuxServicio,&id) &&
				Servicios_getDescripcion(pAuxServicio,descripcion)&&
				Servicios_getTipo(pAuxServicio,&tipo)&&
				Servicios_getPrecio(pAuxServicio,&precio)&&
				Servicios_getCantidad(pAuxServicio,&cantidad)&&
				Servicios_getTotal(pAuxServicio,&total))

			{
				fprintf(pFile,"%d,%s,%d,%.2f,%d,%.2f\n",id,descripcion,tipo,precio,cantidad,total);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno = 0;
	eServicios*  pAuxPassenger;
	FILE* pFile;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		pFile = fopen(path,"wb");
		if(pFile == NULL)
		{
			printf("\nEl archivo no pudo abrirse.\n");
			system("pause");
			exit (EXIT_FAILURE);
		}
		for (int i = 0; i< ll_len(pArrayListPassenger);i++ )
		{
			pAuxPassenger = ll_get(pArrayListPassenger,i);
			if (pAuxPassenger != NULL)
			{
				fwrite(pAuxPassenger, sizeof(eServicios),1,pFile);
				retorno = 1;
			}
		}
	}
	fclose(pFile);
    return retorno;
}

int controller_Map (LinkedList* listaServicios)
{
	int retorno = 0;
	if (listaServicios != NULL)
	{
		ll_map(listaServicios, calcular);
		printf("\n**Los totales se asignaron correctamente**\n");
		retorno = 1;
	}
	return retorno;
}
void calcular(void* pElemento)
{
	int cantidad;
	float precio;
	float total;

	if (pElemento != NULL)
	{
		Servicios_getCantidad(pElemento,&cantidad);
		Servicios_getPrecio(pElemento,&precio);
		total = multiplicar(cantidad,precio);
		Servicios_setTotal(pElemento,total);
	}
}
float multiplicar (int cantidad, float precio)
{
	float total;

	total = cantidad*precio;

	return total;
}
//: Se deberá generar un archivo igual al original, pero donde solo aparezcan
//servicios del tipo seleccionado
/*
int controller_Filter(LinkedList* listaServicios)
{
	void* listaFiltrada = NULL;
	int retorno = 0;

	if (listaServicios != NULL)
	{
		listaFiltrada = ll_filter(listaServicios, filtrar);
		controller_saveAsText("Nueva.csv",listaFiltrada);
		retorno = 1;
	}
	return retorno;
}


eServicios* filtrar (void* pElemento , LinkedList* listaServicios)
{
	eServicios* pAuxServicio;
	eServicios* auxPElemento;
	int filtroTipo;
	int getTipo;

	if (pElemento != NULL)
	{
		if(utn_getNumero(&filtroTipo,"\n\nPor favor, ingrese el numero del parametro que desea filtrar.\n\n"
						"1 - Filtro Minorista.\n"
						"2 - Filtro Mayorista.\n"
						"3 - Filtro Exportar.\n","**ERROR**",1,3,3)== 0){

			for (int i = 0;i<ll_len(listaServicios);i++)
			{
				pAuxServicio = (eServicios*)ll_get(listaServicios,i);

				Servicios_getTipo(pAuxServicio,&getTipo);
				if(pAuxServicio != NULL)
				{
					if(getTipo == filtroTipo)
					{
						pElemento = pAuxServicio;
					}
				}
			}
		}
	}
	return pElemento;
}
*/
