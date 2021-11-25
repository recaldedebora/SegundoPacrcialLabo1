#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Editorial.h"
#include "parser.h"
#include "UTN_input.h"



int controller_loadFromText_Libros(char* path , LinkedList* pArrayListeLibro);
int controller_loadFromText_Editoriales(char* path , LinkedList* pArrayListeLibro);
int controller_sortLibros_Autor(LinkedList* pArrayListeLibro);
int controller_ListLibros(LinkedList* pArrayListeLibro);
int controller_ListEditoriales(LinkedList* pArrayListEditoriales);
int controller_ListLibrosConEditorial(LinkedList* pArrayListeLibro, LinkedList* pArrayListEditoriales);
int controller_filterMinotauro(LinkedList* listaLibros, LinkedList* pArrayListEditoriales);
int controller_saveAsText(char* path , LinkedList* pArrayListLibros);
int controller_PrecioConDescuento(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales);
