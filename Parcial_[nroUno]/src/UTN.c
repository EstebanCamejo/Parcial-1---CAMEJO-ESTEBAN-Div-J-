/*
 * UTN.c
 *
 *  Created on: 14 may 2022
 *      Author: Usuario
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "UTN.h"

static	int getNombre (char pResultado[], int tamanio);
static	int esNombre (char array [], int tamanio);
static int getInt (int* pResultado);
static int esNumerica (char* cadena, int tamanio);
static int getFloat(float* pResultado);
static int esFlotante(char* cadena,int limite);

/**
 * brief valida que el array no desborde
 * param cadena es el array a validar
 * param tamanio limite del array
 * \return Retorna 0 si fue EXITOSA  o -1 en caso de ERROR
 */
int myGets(char* cadena, int tamanio)
{

	int retorno = -1;
	char bufferString [4096];//**********************************************

	if (cadena != NULL && tamanio >0 ){

		fflush(stdin);
		if(fgets(bufferString,sizeof (bufferString),stdin) != NULL){

			if (bufferString [strnlen (bufferString,sizeof (bufferString) )-1] == '\n'){

				bufferString [strnlen (bufferString, sizeof (bufferString))-1] = '\0';
			}
			if (strnlen (bufferString, sizeof (bufferString)) <= tamanio){

				strncpy (cadena,bufferString, tamanio);
				retorno = 0;
			}
		}
	}

	return retorno;
}
/**
 * \brief Solicita una palabra al usuario, luego de verificarlo devuelve el resultado
 * \param array Es el puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje Es el mensaje que pide el dato
 * \param mensajeError Es el mensaje de Error
 * \param minimo Es el numero maximo aceptado
 * \param maximo Es el minimo minimo aceptado
 * \return Retorna 0 si fue EXITOSA  o -1 en caso de ERROR
 */
int utn_getNombre(char array[], int tamanio, char* mensaje, char* mensajeError, int reintentos )
{
	int retorno = -1;
	char buffer [tamanio];

	if (array != NULL && tamanio >0 &&  mensaje != NULL &&  mensajeError != NULL && reintentos>= 0){

		do{
			printf ("%s", mensaje);
			if (getNombre(buffer, tamanio) == 0){

				retorno = 0;
				strcpy(array,buffer);

				break;

				}
			else{
				printf ("%s", mensajeError);
				reintentos --;
			}

			}while(reintentos >= 0);

	}

	return retorno;
}
/**
 * \brief Verifica si la cadena ingresada es de caracteres
 *\param array Array de  a ser validado
 *\param tamanio limite del array
 * \return Retorna 1 (EXITO) si son todos son caracteres , 0 en el caso de ERROR y -1 si no se cumple la funcion
	 */
static	int esNombre (char array [], int tamanio)
	{
		int retorno = -1;
		int i;

		if (array != NULL && tamanio > 0){

			for(i=0;i<tamanio && (*(array + i)) != '\0';i++)
			{

				(*(array + i)) = tolower ((*(array + i))); // pasa el array a minusculas

				retorno = 1;

				if ((*(array + i)) < 'a' || (*(array + i)) > 'z'){

					retorno = 0; // ERROR
					break;
				} // FIN DEL IF
			} // FIN DEL FOR
		} // FIN VALIDACION

		return retorno;
	}

/**
 * \brief  Obtiene un array de caracteres validado
 *\param pResultado Array de  a ser validado
 *\param tamanio limite del array
 * \return Retorna 0 (EXITO) si logro convertirlo a caracteres y -1 (ERROR)
 */
 static	int getNombre (char pResultado[], int tamanio)
	{
		int retorno = -1;
		char buffer[tamanio];

		if (pResultado != NULL && myGets(buffer, sizeof(buffer)) == 0
				&& esNombre(buffer,sizeof(buffer))>0) // osea si se cumple la fx y me devuelve un verdadero
				{
					strcpy(pResultado,buffer);
					retorno = 0;
				}
		return retorno;
	}
 /**
  * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
  * \param pResultado Es el puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje que pide el dato
  * \param mensajeError Es el mensaje de Error
  * \param minimo Es el numero maximo aceptado
  * \param maximo Es el minimo minimo aceptado
  * \return Retorna 0 si fue EXITOSA  o -1 en caso de ERROR
  */
 int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
   {
   	int bufferInt;
   	int retorno = -1;

   	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
   	{
   		do{
   			printf("%s", mensaje); // cualquier tipo de string en el msj

   			if (getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
   			{
   				*pResultado = bufferInt;
   				retorno = 0;
   				break;
   			}
   			else
   			{
   				printf("%s", mensajeError);
   				reintentos --;
   			}
   		}while(reintentos >= 0 );

   	}

   	return retorno;
   }

 /**
  * \brief Obtien un numero entero
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
  */
 static int getInt (int* pResultado)
 {
 	int retorno = -1;
 	char buffer [4096];
 	fflush(stdin);

 	if (pResultado != NULL){
 		if (myGets(buffer, sizeof(buffer)) == 0 && (esNumerica(buffer,sizeof(buffer)))) // osea si se cumple la fx y me devuelve un verdadero
 		{
 			*pResultado = atoi (buffer);
 			retorno = 0;
 		}
 	}

 	return retorno;
 }

 /**
  * \brief Verifica si la cadena ingresada es numerica
  * \param cadena Cadena de caracteres a ser analizada
  * \return Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es y -1 en caso de error
  *
  */
 static int esNumerica (char* cadena, int tamanio)
 {
 	int retorno = -1; // ERROR
 	int i;
 	if (cadena != NULL && tamanio > 0){

 		retorno = 1; // VERDADERO
 		for ( i = 0 ; i < tamanio && cadena [i] != '\0' ; i++) // el primer argumento esta vacio porque no sabemos que informacion viene en la cadena de arrays
 		{
 			if (i == 0 && ((*(cadena + i)) == '-' || (*(cadena + i)) == '+'))
 			{
 				continue;

 			}
 			if ((*(cadena + i)) > '9' || (*(cadena + i)) < '0')
 			{
 				retorno = 0;
 				break;
 			}
 		}
 	}

 	return retorno;
 }
 /**
  * \brief Solicita un numero flotante al usuario, leuego de verificarlo devuelve el resultado
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param minimo Es el numero maximo a ser aceptado
  * \param maximo Es el minimo minimo a ser aceptado
  * \return Retorna 0 si se obtuvo el numero y -1 si no
  *
  */
 int getNumeroFlotante(float* pResultado, char mensaje[], char errorMensaje[], float minimo, float maximo, int reintentos)
 {
	 int retorno = -1;
	 	float bufferFloat;

	 	do{
	 		printf("%s",mensaje);

	 		if(getFloat(&bufferFloat)==0&&
	 		   bufferFloat >= minimo &&
	 		   bufferFloat <= maximo)
	 		{
	 			retorno = 0;
	 			*pResultado=bufferFloat;
	 			break;
	 		}
	 		printf("%s",  errorMensaje);
	 		reintentos--;
	 	}while(reintentos>=0);


	 	return retorno;
 }

 /**
  * \brief Verifica si la cadena ingresada es flotante
  * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
  * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
  *
  */
 static int getFloat(float* pResultado)
 {
     int retorno=-1;
     char bufferString[50];

    if(pResultado != NULL &&
 	myGets(bufferString,sizeof(bufferString)) == 0 &&
 	esFlotante(bufferString,sizeof(bufferString)))
    {
 	retorno=0;
 	*pResultado = atof(bufferString) ;
    }

 	return retorno;

 }

 /**
  * \brief Verifica si la cadena ingresada es flotante
  * \param cadena Cadena de caracteres a ser analizada
  * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
  *
  */

 static int esFlotante(char* cadena,int limite)
 {
 	int retorno = 1;
 	int flagDecimal=1;

 	int i;
 	if(cadena != NULL && limite>0)
 	{
 		for(i=0; i < limite && (*(cadena + i)) != '\0';i++)
 		{
 			if(i== 0 && ( (*(cadena + i)) == '+' || (*(cadena + i)) =='-'))
 			{
 				continue;
 			}
 			if(flagDecimal==1 && i !=0 && (*(cadena + i)) =='.')
 			{
 				flagDecimal=0;
 				continue;
 			}
 			if((*(cadena + i)) < '0' || (*(cadena + i)) > '9')
 			{
 				retorno = 0;
 				break;
 			}
 		}
 	}
 	return retorno;
 }

 /**
  * \brief Verifica si la cadena ingresada contiene solo letras
  * \param inPut Cadena de caracteres a ser analizad
  * \param mensaje Es el mensaje a ser mostrado
  * \param mensajeError Es el mensaje de Error a ser mostrado
  * \param tamanio de la cadena a analizar
  * \param reintentos la cantidad de reintentos hasta que sale de la funcion
  * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
  *
  */

 int esSoloLetra(char inPut[],char mensaje[], char errorMensaje[],int tamanio, int reintentos)
  {

  	char bufferChar[tamanio];
  	int retorno;

  	if(inPut != NULL && mensaje != NULL && errorMensaje != NULL && tamanio >= 1 && reintentos >= 0 )
  	{
  												//creo bucle que se repita si reintentos>= 0 y retorno ==0
  		do{
  			 retorno = 1;
  //pido el ingreso de datos
  			 printf("\n %s",mensaje);
  			 fflush(stdin);
  		 	 gets(bufferChar);
  		 	 	 	 	 	 	 	 	 	 	 	 	 // printf("%d",strlen(bufferChar));
  //valido que lo ingresado no exceda
  			 if(strlen(bufferChar)<=tamanio )
  			 {
  //recorro arrrayC

  				 for(int i=0; i<strlen(bufferChar);i++) //while(i<=strlen(bufferChar))
  				 {
  //niego cadena y espacio

  					if(!isalpha(bufferChar[i]))
  					{
  						printf("\n %s",errorMensaje);
  						retorno = 0;
  						break;
  					}
  				 }
  				// printf("su contrsena es %s",bufferChar);
  			 }
  			 else
  			 {
  				 printf("\n %s",errorMensaje);
  				 retorno=0;
  			 }

  			 reintentos--;
  		 }while(reintentos>=0 && retorno==0);

  		 if(retorno==1)
  		 {
  			 strcpy(inPut,bufferChar);
  			 //strncpy(inPut,bufferChar,strlen(bufferChar));
  			//inPut = bufferChar;
  		 }

  	 }
  	return	retorno;
  }


 /**
   * \brief Solicita un caracter al usuario, leuego de verificarlo devuelve el resultado
   * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
   * \param mensaje Es el mensaje a ser mostrado
   * \param mensajeError Es el mensaje de Error a ser mostrado
   * \param minimo Es el numero maximo a ser aceptado
   * \param maximo Es el minimo minimo a ser aceptado
   * \param reintentos es el maximo de reintentos aceptado por la funcion
   * \return Retorna 0 si se obtuvo el numero y -1 si no
   *
   */

  int utn_getNumeroCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
  {
  	int retorno = -1;
  	char bufferChar;
  	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0) //validacion de parametros
  	{
  		do{
  			printf("%s", mensaje);// cualquier tipo de string en el msj
  			fflush(stdin);
  			scanf ("%c", &bufferChar);// guardamos la respuesta en el buffer
  			if (bufferChar >= minimo && bufferChar <= maximo)
  			{
  				*pResultado = bufferChar;
  				retorno = 0;
  				break;
  			}
  				else
  				{
  					printf("%s", mensajeError);
  					reintentos --;
  				}

  			}while(reintentos >= 0 );

  		}

  	return retorno;
  }

/**
* \brief Solicita una cadena de caracter al usuario, luego verifica que los datos sean correctos "alfanumericos"
* \param inPut Puntero al espacio de memoria donde se aloja la cadena a analizar
* \param mensaje Es el mensaje a ser mostrado
* \param mensajeError Es el mensaje de Error a ser mostrado
* \param tamanio Es el el tam?o maximo aceptado
* \param maximo Es el minimo minimo a ser aceptado
* \param reintentos es el maximo de reintentos aceptado por la funcion
* \return Retorna 0 si se obtuvo el numero y -1 si no
*/
 int getAlfanumerico(char inPut[],char mensaje[], char errorMensaje[],int tamanio, int reintentos)
 {
 	char bufferChar[tamanio];
 	int retorno;

 	if(inPut != NULL && mensaje != NULL && errorMensaje != NULL && tamanio >= 1 && reintentos >= 0 )
 	{
 												//creo bucle que se repita si reintentos>= 0 y retorno ==0
 		do{
 			 retorno = 0;
 //pido el ingreso de datos
 			 printf("\n %s",mensaje);
 			 fflush(stdin);
 		 	 gets(bufferChar);
 		 	 	 	 	 	 	 	 	 	 	 	 	 // printf("%d",strlen(bufferChar));
 //valido que lo ingresado no exceda
 			 if(strlen(bufferChar)<=tamanio)
 			 {
 //recorro arrray
 				 for(int i=0;i<strlen(bufferChar);i++) //while(i<=strlen(bufferChar))
 				 {
 //niego alfanumerico
 					if(!isalnum(bufferChar[i]))
 					{
 						printf("\n %s",errorMensaje);
 						retorno = -1;
 						break;
 					}
 				 }
 				// printf("su contrsena es %s",bufferChar);
 			 }
 			 else
 			 {
 				 retorno = -1;
 			 }

 			 reintentos--;

 		 }while(reintentos>=0 && retorno==-1);

 		 if(retorno == 0)
 		 {
 			 strcpy(inPut,bufferChar);
 			//inPut = bufferChar;
 		 }

 	 }
 	return	retorno;
 }



