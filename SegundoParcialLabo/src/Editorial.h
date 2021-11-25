/*
 * Editorial.h
 *
 *  Created on: 24 nov. 2021
 *      Author: Usuario
 */

#ifndef EDITORIAL_H_
#define EDITORIAL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
typedef struct
{
    int idEditorial;
    char nombre[20];
}eEditorial;

eEditorial* Editorial_new();//constructor//genera espacio e inicializa en cero
eEditorial* Editorial_newParametros(char* idEditorialStr,char* nombreStr);//llama a new Libro y a los seters
void Editorial_delete(eEditorial*);//destructor eloimina un libro de la memoria

int Editorial_setIdEditorial(eEditorial* this,int id);
int Editorial_getIdEditorial(eEditorial* this,int* id);
int Editorial_CompareByIdEditorial(void* libro1, void* libro2);

int Editorial_setNombre(eEditorial* this,char* titulo);
int Editorial_getNombre(eEditorial* this,char* titulo);
int Editorial_getNombreByID(LinkedList* pArrayListEditoriales,char* nombre, int idEditorial);
int Editorial_CompareByNombre(void* libro1, void* libro2);

void Editorial_show(eEditorial* this);


#endif /* EDITORIAL_H_ */
