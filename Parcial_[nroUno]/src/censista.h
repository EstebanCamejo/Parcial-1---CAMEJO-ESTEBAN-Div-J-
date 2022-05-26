/*
 * censista.h
 *
 *  Created on: 21 may 2022
 *      Author: Usuario
 */

#ifndef CENSISTA_H_
#define CENSISTA_H_

typedef struct {

	int legajoCensista;
	char nombre [10];
	int edad;
	char telefono[10];
//	char telefono;
}eCensista;
int imprimirCensistas (eCensista* array, int tamanio);
void imprimirUnCensista (eCensista* array);
#endif /* CENSISTA_H_ */
