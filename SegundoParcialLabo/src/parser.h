/*
 * parser.h
 *
 *  Created on: 9 nov. 2021
 *      Author: Usuario
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"

int parser_LibroFromText_Libros(FILE* pFile , LinkedList* pArrayListLibros);
int parser_LibroFromText_Editoriales(FILE* pFile , LinkedList* pArrayListLibros);
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibros);
int parser_IDFromBinary(FILE* pFile , int* id);
#endif /* PARSER_H_ */
