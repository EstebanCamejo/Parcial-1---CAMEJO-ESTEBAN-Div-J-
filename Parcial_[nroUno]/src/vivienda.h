/*
 * vivienda.h
 *
 *  Created on: 21 may 2022
 *      Author: Usuario
 */
#ifndef VIVIENDA_H_
#define VIVIENDA_H_

#define LENNAME 25

typedef struct {
	int idVivienda;//OK
    char calle[LENNAME];
    int cantidadPersonas;
    int cantidadHabitaciones;
    int typeVivienda;
    int legajoCensista;
    int isEmpty;
}eVivienda;

typedef struct {
	int typeVivienda;//OK
	char descripcion[20];
}etypeVivienda;

#endif /* VIVIENDA_H_ */

void(*pFuncion)(eVivienda*,int,int*);


int buscarEmptyLibre(eVivienda espacio[], int tamanio, int* espacioLibre);
int altaVivienda (eVivienda* array,int tamanio, int* id);

void imprimirVivienda(eVivienda* vivienda);
int validarIdVivienda (eVivienda array[], int tamanio,int id,int* indice);
void vivienda_modificarMenu(eVivienda* bufferVivienda);
int removerVivienda (eVivienda* bufferEmpleado);

void inicializarVivienda (eVivienda* array, int tamanio, int* pResultado);
void ListarViviendasCalleCant (eVivienda* array, int tamanio, int* pResultado);
void imprimirViviendas (eVivienda* array, int tamanio,int* pResultado);

int PrimerPuntero (eVivienda* array, int tamanio, void(*pFuncion)(eVivienda*,int,int*));

