/*
 * Libro.h
 *
 *  Created on: 23 nov. 2021
 *      Author: Usuario
 */

#ifndef LIBRO_H_
#define LIBRO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editorial.h"
#define MINOTAURO 4
typedef struct
{
    int id;
    char titulo[120];
    char autor[120];
    float precio;
    int idEditorial;
}eLibro;

eLibro* Libro_new();//constructor//genera espacio e inicializa en cero
eLibro* Libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* idEditorialStr);//llama a new Libro y a los seters
void Libro_delete(eLibro*);//destructor eloimina un libro de la memoria

int Libro_setId(eLibro* this,int id);
int Libro_getId(eLibro* this,int* id);
int Libro_CompareById(void* libro1, void* libro2);

int Libro_setTitulo(eLibro* this,char* titulo);
int Libro_getTitulo(eLibro* this,char* titulo);
int Libro_CompareByTitulo(void* libro1, void* libro2);

int Libro_setAutor(eLibro* this,char* autor);
int Libro_getAutor(eLibro* this,char* autor);
int Libro_CompareByAutor(void* autor1, void* autor2);

int Libro_setPrecio(eLibro* this,float precio);
int Libro_getPrecio(eLibro* this,float* precio);
int Libro_CompareByPrecio(void* libro1, void* libro2);

int Libro_setIdEditorial(eLibro* this,int idEditorial);
int Libro_getIdEditorial(eLibro* this,int* idEditorial);
int Libro_CompareByIdEditorial(void* libro1, void* libro2);

void Libro_show(eLibro* this);
void Libro_show_conEditorial(eLibro* this, LinkedList* editorial);


int Libro_filtrarMinotauro(void* this);
#endif /* LIBRO_H_ */
