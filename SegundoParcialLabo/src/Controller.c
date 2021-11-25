#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Libro.h"
#include "Controller.h"


//static int idStatic = 0;


/** \brief Carga los datos de los libros desde el archivo Libros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_loadFromText_Libros(char* path , LinkedList* pArrayListLibro)
{
	FILE* pArchivo;

	pArchivo = fopen(path, "r");
	int retorno;
	retorno = -1;

	if(path!=NULL && pArrayListLibro!=NULL)
	{
		if(parser_LibroFromText_Libros(pArchivo, pArrayListLibro)== 0)
		{

			retorno = 0;
		}
	}

	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de las editoriales desde el archivo Editoriales,csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditoriales LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_loadFromText_Editoriales(char* path , LinkedList* pArrayListEditoriales)
{
	FILE* pArchivo;

	pArchivo = fopen(path, "r");
	int retorno;
	retorno = -1;

	if(path!=NULL && pArrayListEditoriales!=NULL)
	{
		if(parser_LibroFromText_Editoriales(pArchivo, pArrayListEditoriales)== 0)
		{
			retorno = 0;
		}
	}

	fclose(pArchivo);

    return retorno;
}

/** \brief Listar libros
 *
 * \param pArrayListLibro LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_ListLibros(LinkedList* pArrayListeLibro)
{
	eLibro* unLibro;
	int retorno;
	int lenLibros;
	int i;
	retorno = -1;

	if(pArrayListeLibro!=NULL )
	{
		lenLibros = ll_len(pArrayListeLibro);
		printf("LEN LIBROS: %d", lenLibros);

		printf("\nListado de Empleados:");
		printf("\n Id |          Titulo             | Autor             |  Pecio |  idEditorial\n");

		for(i=0; i<lenLibros;i++)
		{
			unLibro = ll_get(pArrayListeLibro, i);
			Libro_show(unLibro);

		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Listar editoriales
 *
 * \param pArrayListEditoriales LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_ListEditoriales(LinkedList* pArrayListEditoriales){

		eEditorial* unaEditorial;
		int retorno;
		int lenLibros;
		int i;
		retorno = -1;

		if(pArrayListEditoriales!=NULL )
		{
			lenLibros = ll_len(pArrayListEditoriales);
			printf("\nListado de Editoriales:");
			printf("\n Id |    Nombre\n");

			for(i=0; i<lenLibros;i++)
			{
				unaEditorial = ll_get(pArrayListEditoriales, i);
				Editorial_show(unaEditorial);

			}
			retorno = 0;
		}
		return retorno;


}


/** \brief Listar libros con nombre editorial
 * \param pArrayListLibro LinkedList*
 * \param pArrayListEditoriales LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_ListLibrosConEditorial(LinkedList* pArrayListeLibro, LinkedList* pArrayListEditoriales)
{
	eLibro* unLibro;
	int retorno;
	int lenLibros;
	int i;
	retorno = -1;

	if(pArrayListeLibro!=NULL && pArrayListEditoriales!=NULL)
	{
		lenLibros = ll_len(pArrayListeLibro);

		printf("\nListado de Empleados:");
		printf("\n Id |          Titulo             | Autor             |  Pecio |  idEditorial\n");

		for(i=0; i<lenLibros;i++)
		{
			unLibro = ll_get(pArrayListeLibro, i);
			Libro_show_conEditorial(unLibro, pArrayListEditoriales);

		}
		retorno = 0;
	}
	return retorno;
}


/** \brief Ordenar libros por autor
 *
 * \param pArrayListLibro LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_sortLibros_Autor(LinkedList* pArrayListLibros)
{
	int retorno;
	retorno = -1;

	if(pArrayListLibros!=NULL)
	{
		ll_sort(pArrayListLibros,Libro_CompareByAutor, 1);
		retorno = 0;

	}



	return retorno;
}



/** \brief Filtrar libros editorial minotauro
 *
 * \param pArrayListLibro LinkedList*
 * \param pArrayListEditoriales LinkedList*
 * \return int 0 Exito
 * 		   int -1 Error
 *
 */
int controller_filterMinotauro(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales){

	LinkedList* librosMinotauro;
	int retorno = 0;

	librosMinotauro = ll_filter(pArrayListLibros, Libro_filtrarMinotauro);
	if(librosMinotauro != NULL){
		controller_ListLibrosConEditorial(librosMinotauro,pArrayListEditoriales);
		retorno = 1;
		controller_saveAsText("LibrosMinotauro.csv" , librosMinotauro);
	}

	return retorno;
}



/** \brief Guarda los datos de los libros en el archivo .csv (modo texto).
 *
 * \param pArrayListEmployee LinkedList*
 * \return int 1 Exito
 *  	   int 0 Cancelado
 * 		   int -1 Error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibros)
{
	FILE* pArchivo;
	eLibro* unLibro;
	int retorno;
	int len;
	int i;
	int id;
	int idEditorial;
	char titulo[50];
	char autor[50];
	float precio;
	char cabecera[50]="id,nombre,horasTrabajadas,sueldo";
	retorno = -1;

	if(path!= NULL && pArrayListLibros!=NULL)
	{
		retorno = 0;
		pArchivo= fopen(path,"w");

		if(pArchivo!=NULL){
			len= ll_len(pArrayListLibros);
			fprintf(pArchivo, "%s\n",cabecera);
			for(i=0;i<len;i++){
				unLibro = ll_get(pArrayListLibros, i);
				Libro_getId(unLibro,&id);
				Libro_getTitulo(unLibro,titulo);
				Libro_getAutor(unLibro,autor);
				Libro_getPrecio(unLibro,&precio);
				Libro_getIdEditorial(unLibro,&idEditorial);
				fprintf(pArchivo, "%d,%s,%s,%f,%d\n", id,titulo,autor,precio,idEditorial);
				retorno = 1;
			}
		}
	}
	fclose(pArchivo);
	return retorno;
}


int controller_PrecioConDescuento(LinkedList* pArrayListLibros, LinkedList* pArrayListEditoriales)
{


	int retorno;
	retorno = -1;
	if(pArrayListLibros != NULL && pArrayListEditoriales!=NULL){


		if(ll_map(pArrayListLibros, Libro_HacerDescuento)== 0){
			retorno = 0;
		}

		printf("\nLista auxiliar con descuentos incluidos: \n");
		controller_ListLibrosConEditorial(pArrayListLibros, pArrayListEditoriales);
	}

	return retorno;
}


