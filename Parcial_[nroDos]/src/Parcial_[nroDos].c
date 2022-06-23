/*
 ============================================================================
 Name        : Parcial_[nroDos].c
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
#include "LinkedList.h"
#include "Controller.h"
#include "Servicios.h"
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	int option = 0;
	int flagAlta = 0;

    LinkedList* listaServicios = ll_newLinkedList();

	    do{
	    	if(utn_getNumero(&option,"\n\n \t *** INGRESO AL PROGRAMA *** \n"
	    					"\nPor favor ingrese una opcion: \n\n"

	    					"1) Cargar archivo.\n"
	    			 		"2) Imprimir lista.\n"
	    					"3) Asignar totales.\n"
	    					"4) Filtrar por tipo.\n"
	    					"5) Mostrar servicios.\n"
							"6) Guardar servicios.\n"
							"7) Salir. \n",

	    					"ERROR opcion incorrecta. \n",1,7,3)==0){

				switch(option)
				{
					case 1:
						if (controller_loadFromText("data.csv",listaServicios))
						{
							flagAlta = 1;
						}

						break;

					case 2 :
						if (flagAlta == 1)
						{
							controller_ListPassenger(listaServicios);
						}
						else {
							printf ("\n\nERROR!! \n\n Para poder listar el programa primero debera cargar el archivo.");
						}


						break;

					case 3 :  if (flagAlta == 1)
							{
								controller_Map(listaServicios);
								controller_ListPassenger(listaServicios);
							}
					else {
							printf ("\n\nERROR!! \n\n Para poder asignar los totales primero debera cargar el archivo.");
						  }


						break;

					/*case 4 :	if (flagAlta == 1 && controller_Filter(listaServicios))
								{
									printf ("\nFiltro OK");
								}
								else{
									printf ("\nERROR al ap`licar el Filtro.");
								}
						  	 //: Se deberá generar un archivo igual al original, pero donde solo aparezcan
							 //servicios del tipo seleccionado

						break;*/

					case 5 : if (flagAlta == 1 && controller_sortPassenger(listaServicios))
							{
									controller_ListPassenger(listaServicios);
							}
							else
							{
								printf ("\n\nERROR!! \n\n Para poder realizar el ordenamiento y mostrarlo "
										"primero debera cargar el archivo.");
							}
						     // Se deberá mostrar por pantalla un listado de los servicios ordenados por
						 	 //descripción de manera ascendente.
						break;

					case 6 :
						if (flagAlta == 1){
							if(controller_saveAsText("data.txt",listaServicios))
							{
								printf("\nArchivo creado OK.");
							}
						}
						else{
							printf ("\n\nERROR!! \n\n Para poder guardar el programa primero debera cargar el archivo.");
						}

						break;

				}// FIN DEL SWITCH
	    	}// FIN DEL MENU
	    }while(option != 7);

	return EXIT_SUCCESS;
}
