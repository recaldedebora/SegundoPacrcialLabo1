/*
 ============================================================================
 Name        : SegundoParcialLabo.c
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
#include "Libro.h"
#include "Editorial.h"
#include "UTN_input.h"

/****************************************************
   Desarrollar en ANSI C:
Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades
eLibro.OK
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.
2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades
eEditorial.
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.
3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de
ordenamiento �Autor� de manera ascendente. OK
4. Imprimir por pantalla todos los datos de los libros.
ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la
funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaLibros;
    LinkedList* listaEditoriales;
    listaLibros = ll_newLinkedList();
    listaEditoriales = ll_newLinkedList();
    char nombreArchivoRecibido[20];

    int flag;
    flag = 0;

    do{

    	printf("\n\n****************************************************");
    	printf("\nMenu:");
    	printf("\n1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades eLibro.");
    	printf("\n2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades eEditorial.");
    	printf("\n3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de ordenamiento �Autor� de manera ascendente.");
    	printf("\n4. Imprimir por pantalla todos los datos de los libros.");
    	printf("\n5. Realizar un listado de los libros de la editorial MINOTAURO.Guardar el listado en un archivo csv.");
    	//printf("\n6.");
    	//printf("\n7.");
    	//printf("\n8.");
    	//printf("\n9.");
    	printf("\n10. Salir");
    	printf("\n*****************************************************");
    	utn_getNumeroRango(&option, "\nIngrese opcion: ", "Error.", 0, 10, 2);


        switch(option)
        {
            case 1:

            	utn_getDescripcion(nombreArchivoRecibido, 20,"Lista de archivos de libros disponible:\n *'Libros'.csv.\n Ingrese el nombre del archivo.csv que quiere abrir: ", "Error.", 2);
            	if(strcmp(nombreArchivoRecibido,"Libros" )== 0){
					if(controller_loadFromText_Libros("Libros.csv",listaLibros)==0){
						printf("\nLista cargada correctamente");
						flag++;
					}else
					{
						printf("\nLista NO cargada correctamente");
					}

            	}else{
            		printf("\nArchivo no encontrado. Lista de archivos de libros disponible:\n 'Libros'.csv");
            	}
			break;

            case 2:
            	utn_getDescripcion(nombreArchivoRecibido, 20,"Lista de archivos de Editoriales disponible: 'Editoriales'.csv.\nIngrese el nombre del archivo .csv que quiere abrir: ", "Error.", 2);
				if(strcmp(nombreArchivoRecibido,"Editoriales" )== 0){
					if(controller_loadFromText_Editoriales("Editoriales.csv" , listaEditoriales)==0){
						printf("\nLista cargada correctamente");
						flag++;
					}else
					{
						printf("\nLista NO cargada correctamente");
					}

				}else{
            		printf("\nArchivo no encontrado. Lista de archivos de Editoriales disponible: 'Editoriales'.csv");
            	}
			break;

            case 3:
				if(flag == 0){
					printf("\nAntes de ordenar la lista de empleados debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{
					if(controller_sortLibros_Autor(listaLibros)==-1){
						printf("\nError al ordenar.");
					}
					else
					{
						printf("Ordenado correctamente");
					}
				}
			break;

            case 4:
            	if(flag == 0){
					printf("\nAntes de listar los empleados debe cargar la lista guardada en el archivo. (opcion 1 o 2)");
				}
				else{

					//if(controller_ListEditoriales(listaEditoriales)==-1){
					//	printf("\nError al listar.");
					//}
					//if(controller_ListLibros(listaLibros)==-1){
					//	printf("\nError al listar.");
					//}
					if(controller_ListLibrosConEditorial(listaLibros, listaEditoriales)==-1){
						printf("\nError al listar.");
					}
				}
			break;



           case 5:
				if(controller_filterMinotauro(listaLibros, listaEditoriales) ==1){
					printf("\nGuardado lista de libros editorial Minotauro realizado correctamente");
				}
				else{
					printf("\nLista de libros editorial Minotauro NO guardada correctamente");
				}

			break;

            case 6:
              controller_acumuladorPrecio(listaLibros);
            break;
            /*case 7:
            break;
            case 8:
            break;

            */


        }
    }while(option != 0);

    return 0;
}

