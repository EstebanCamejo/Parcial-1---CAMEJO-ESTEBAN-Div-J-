/*
 * UTN.h
 *
 *  Created on: 14 may 2022
 *      Author: Usuario
 */

#ifndef UTN_H_
#define UTN_H_

int myGets(char* cadena, int tamanio);

int utn_getNombre(char array [], int tamanio, char* mensaje, char* mensajeError, int reintentos);

int getCadenaTelefonica(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);

int getAlfanumerico(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);

int esLetraConEspacio(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);

int esSoloLetra(char inPut[],char mensaje[], char errorMensaje[],int tamano, int reintentos);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);//menu OK

int getNumeroFlotante(float* pResultado, char mensaje[], char errorMensaje[], float minimo, float maximo, int reintentos);

int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);


#endif /* UTN_H_ */
