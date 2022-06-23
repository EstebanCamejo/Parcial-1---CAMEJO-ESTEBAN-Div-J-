/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char descripcion[50];
	int tipo;
	float precio;
	int cantidad;
	float total;
	int isEmpty;

}eServicios;

eServicios* Servicios_new();
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoStr,char* precioStr,char* cantidadStr,char* totalStr);
/*
eServicios* Servicios_newParametrosAlta(int idStr,char* nombreStr,char* apellidoStr,float precioStr,char* codVueloStr,
		char* tipoPasajeroS, char* estadoVueloStr);
*/
void Servicios_delete();

int Servicios_setId(eServicios* this,int id);
int Servicios_getId(eServicios* this,int* id);

int Servicios_setDescripcion(eServicios* this,char* descripcion);
int Servicios_getDescripcion(eServicios* this,char* descripcion);

int Servicios_setTipo(eServicios* this,int tipo);
int Servicios_getTipo(eServicios* this,int* tipo);

int Servicios_setPrecio(eServicios* this,float precio);
int Servicios_getPrecio(eServicios* this,float* precio);

int Servicios_setCantidad(eServicios* this,int cantidad);
int Servicios_getCantidad(eServicios* this,int* cantidad);

int Servicios_setTotal(eServicios* this,float total);
int Servicios_getTotal(eServicios* this,float* total);


///////////////////////////////////

/*
int Passenger_BuscarPaxId (LinkedList* pArrayListPassenger, int id);
*/
#endif /* PASSENGER_H_ */
