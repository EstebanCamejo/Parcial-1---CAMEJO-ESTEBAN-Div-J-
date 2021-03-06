/*
 ============================================================================
 Name        : Parcial_[nroUno].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UTN.h"

#include "censista.h"
#include "vivienda.h"
#define TAM 5 //array viviendas
#define LEN 3 //array censistas
#define LENNAME 25

int main(void) {
	setbuf(stdout,NULL);
	int id = 20000;
	char opcion;
	int espacioLibre;
	int flagAlta = 0;
	int auxId;
	int auxIndice;
	int auxFx;
	int cencista100 = 0;
	int cencista101 = 0;
	int cencista102 = 0;
//	int MayoCensista;

	eVivienda aViviendas [TAM];
	eCensista aCencistas [LEN] = {{100,"Ana",34,"1203-2345"},{101,"Juan",24,"4301-54678"}, {102,"Sol",47,"5902-37487"}};

	void (*pFx)(eVivienda*,int,int*);

	pFx = inicializarVivienda;
	auxFx = PrimerPuntero(aViviendas, TAM, pFx);

	if (auxFx == 0){

		do{	 if( utn_getNumeroCaracter(&opcion, "\n\n \t *** MENU DE OPCIONES *** \n\nPor favor ingrese una opcion: \n\n\n"

				"\n a) Alta Vivienda.\n"
				"\n b) Modificar.\n"
				"\n c) Baja Vivienda.\n"
				"\n d) Listar Viviendas.\n"
				"\n e) Listar Censistas.\n"
				"\n f) Listar Altas por cada Censista.\n"
				"\n g) Mayor Censista.\n"
				"\n h) Salir.\n"

				, "ERROR. \nLa opcion es incorrecta.\nPor favor ingrese una de las opciones del menu.", 'a', 'h', 4) == 0) {

				switch (opcion){

				case 'a':// ALTA
						imprimirCensistas(aCencistas, LEN);

						if(	buscarEmptyLibre(aViviendas, TAM, &espacioLibre)== 0 &&
							utn_getNumero(&aViviendas[espacioLibre].legajoCensista,
							"\nIngrese el numero de legajo del censista.","\nError. \n",100,102,3)==0 &&
							altaVivienda(&aViviendas[espacioLibre],LENNAME,&id)== 0)
						{
							printf("\n\nCarga realizada con EXITO\n\n");
							flagAlta = 1;
						}
						else
						{
							printf("\n\nERROR");
						}

					break;

				case 'b': // MODIFICAR
						pFx = imprimirViviendas;
						auxFx = PrimerPuntero(aViviendas, TAM, pFx);
						if(flagAlta == 1 && auxFx == 0 &&
							utn_getNumero(&auxId,"\nIngrese el id de la vivienda que desea modificar.\n "
							"\n**Solo Numeros**\nEntre 20000 y 21000.\n\n\n","\nError \n",20000,21000,3) == 0 &&
							validarIdVivienda(aViviendas,TAM,auxId,&auxIndice) == 0)
						{
							printf("CALLE	 	  C.PERSONAS		 C.HABITACIONES		 TIPO VIVIENDA		    ID VIVIENDA	");
							imprimirVivienda(&aViviendas[auxIndice]);
							vivienda_modificarMenu(&(*(aViviendas +auxIndice)));
						}
					break;

				case 'c': // BAJA
						pFx = imprimirViviendas;
						auxFx = PrimerPuntero(aViviendas, TAM, pFx);
						if(flagAlta == 1 &&  auxFx == 0 && utn_getNumero(&auxId,
						"\n\n\nIngrese el id de la vivienda que desea dar de baja.\n**Solo Numeros**\nEntre 20000 y 21000.\n",
						"\nError \n",20000,21000,2) == 0 &&
						validarIdVivienda(aViviendas,TAM ,auxId,&auxIndice) == 0 && removerVivienda(&aViviendas[auxIndice]) ==0)
						{
							printf("\n\n***BAJA EXITOSA***");
						}
						else{
							printf("\n\nERROR. La baja no pudo realizarse con exito");
						}

					break;

				case 'd': // LISTAR VIVIENDAS CALLE / CANT PERS
						pFx = ListarViviendasCalleCant;
						auxFx = PrimerPuntero(aViviendas, TAM, pFx);
						if (flagAlta == 1 && auxFx == 0)
						{
							pFx = imprimirViviendas;
							auxFx = PrimerPuntero(aViviendas, TAM, pFx);
						}
						else
						{
							printf("\n\nERROR. Para listar viviendas primero debe realizar las altas.");
						}

					break;

				case 'e': // LISTAR CENSISTAS
						imprimirCensistas(aCencistas,LEN);

					break;

				case 'f' :


							for(int i = 0;i<LEN;i++){

								printf("\n 					**ALTAS POR CENSISTA** \n");
								printf("-------------------------------------------------------------------\n");
								printf("LEGAJO	 	NOMBRE		 EDAD		   TELEFONO		 \n");
								printf("-------------------------------------------------------------------\n");
								imprimirUnCensista (&aCencistas[i]);
								printf("--------------------------------------------------------------------------------------------------------\n");
								printf("CALLE	 	  C.PERSONAS		 C.HABITACIONES		 TIPO VIVIENDA		    ID VIVIENDA	\n");
								printf("--------------------------------------------------------------------------------------------------------\n");
								for(int j = 0;j<TAM;j++){

									if ( aCencistas[i].legajoCensista ==  aViviendas[j].legajoCensista)
									{
										imprimirVivienda(&aViviendas[j]);
									}

								}
							}



						break;

				case 'g':


						for(int j = 0;j<TAM;j++){

							if ( aCencistas[0].legajoCensista ==  aViviendas[j].legajoCensista){
								 cencista100++ ;

							}
							if ( aCencistas[1].legajoCensista ==  aViviendas[j].legajoCensista){
								 cencista101++;

							}
							if ( aCencistas[2].legajoCensista ==  aViviendas[j].legajoCensista){
								cencista102++;

							}
						}
						if(cencista100>cencista101 && cencista100>cencista102 ){
						//	MayoCensista = cencista100;
							printf("\n 					**EL CENSISTA CON MAS ALTAS ES** \n");
							printf("-------------------------------------------------------------------\n");
							printf("LEGAJO	 	NOMBRE		 EDAD		   TELEFONO		 \n");
							printf("-------------------------------------------------------------------\n");
							imprimirUnCensista (&aCencistas[0]);

						}
						else if(cencista101>cencista100 && cencista101>= cencista102){
						//	MayoCensista = cencista101;
							printf("\n 					**EL CENSISTA CON MAS ALTAS ES** \n");
							printf("-------------------------------------------------------------------\n");
							printf("LEGAJO	 	NOMBRE		 EDAD		   TELEFONO		 \n");
							printf("-------------------------------------------------------------------\n");
							imprimirUnCensista (&aCencistas[1]);

						}
						else {
							//MayoCensista = cencista102;
							printf("\n 					**EL CENSISTA CON MAS ALTAS ES** \n");
							printf("-------------------------------------------------------------------\n");
							printf("LEGAJO	 	NOMBRE		 EDAD		   TELEFONO		 \n");
							printf("-------------------------------------------------------------------\n");
							imprimirUnCensista (&aCencistas[2]);

						}


					break;

				}

		}

		}while (opcion != 'h');

	}

	return EXIT_SUCCESS;
}
