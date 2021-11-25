
#include "parser.h"
//static char* cabeceraEployee= "";


/** \brief Parsea los datos los datos de los libros desde el archivo Libros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibros LinkedList*
 * \return int -1 error
 * 			int 0 exito
 *
 */
int parser_LibroFromText_Libros(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno;
	eLibro* pAuxiliar;
	retorno=-1;
	char id[50];
	char titulo[50];
	char autor[50];
	char precio[50];
	char idEditorial[50];
	char cabecera[50];
	//char prueba[50];
	int cantidad;

	if(pFile!=NULL && pArrayListLibros!= NULL)
	{
		fscanf(pFile,"%[^\n]\n", cabecera);
		while(!feof(pFile))
		{

			cantidad = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor,precio,idEditorial);
			if(cantidad==5)
			{
				pAuxiliar = Libro_newParametros(id, titulo, autor,precio,idEditorial);

				if(ll_add(pArrayListLibros, pAuxiliar) == -1)
				{
					Libro_delete(pAuxiliar);
				}
				retorno = 0;
			}
			else
			{
				break;
			}

		}
	}


	return retorno;
}



/** \brief Parsea los datos los datos de las editoriales desde el archivo Editoriales.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEditoriales LinkedList*
 * \return int -1 error
 * 			int 0 exito
 *
 */
int parser_LibroFromText_Editoriales(FILE* pFile , LinkedList* pArrayListEditoriales)
{
	int retorno;
	eEditorial* pAuxiliar;
	retorno=-1;
	char id[50];
	char nombre[50];
	char cabecera[50];
	//char prueba[50];
	int cantidad;

	if(pFile!=NULL && pArrayListEditoriales!= NULL)
	{
		fscanf(pFile,"%[^\n]\n", cabecera);
		while(!feof(pFile))
		{

			cantidad = fscanf(pFile,"%[^,],%[^\n]\n", id, nombre);
			if(cantidad==2)
			{
				pAuxiliar = Editorial_newParametros(id, nombre);

				if(ll_add(pArrayListEditoriales, pAuxiliar) == -1)
				{
					Editorial_delete(pAuxiliar);
				}
				retorno = 0;
			}
			else
			{
				break;
			}

		}
	}


	return retorno;
}






/** \brief Parsea los datos los datos de los libros desde el archivo Libros.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListLibros LinkedList*
 * \return int
 *
 */
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno;
	eLibro* pAuxiliar;
	retorno=-1;

	if(pFile!=NULL && pArrayListLibros!=NULL)
	{
		while(!feof(pFile))
		{
			pAuxiliar = Libro_new();
			fread(pAuxiliar, sizeof(eLibro),1,pFile);
			if(!feof(pFile)){
				ll_add(pArrayListLibros,pAuxiliar);
			}
			retorno=0;
		}

	}
    return retorno;
}


