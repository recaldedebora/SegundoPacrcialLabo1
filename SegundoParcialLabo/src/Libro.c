/*
 * Libro.c
 *
 *  Created on: 23 nov. 2021
 *      Author: Usuario
 */

#include "Libro.h"
/*
static int idStatic = 0;

static int obtenerId(){
	static int id = 0;

	id++;
	return id;
}
*/


	//constructor//genera espacio e inicializa en cero
eLibro* Libro_new(){
	eLibro* unBook;

	unBook = (eLibro*) malloc(sizeof(eLibro));



	return unBook;

}



eLibro* Libro_newParametros(char* idStr,char* tituloStr,char* autorStr,char* precioStr, char* idEditorialStr){

	eLibro* unBook;
	int id;
	int precio;
	int idEditorial;
	//llama a new libro y a los seters

	id= atoi(idStr);
	precio=atof(precioStr);
	idEditorial =atoi(idEditorialStr);

	unBook= Libro_new();
	Libro_setId(unBook,id);
	Libro_setTitulo(unBook,tituloStr);
	Libro_setAutor(unBook,autorStr);
	Libro_setPrecio(unBook,precio);
	Libro_setIdEditorial(unBook,idEditorial);


	//printf("book dado de alta:\n ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n",id,tituloStr,precio,idEditorial);

	return unBook;
}



void Libro_delete(eLibro* this){
//ver si cambio y pongo retorno
	if(this != NULL){

		free(this);
	}

	//destructor elimina un book de la memoria
}


int Libro_setId(eLibro* this,int id){
	int retorno;
	retorno =0;

	if(this != NULL && id>0){//1500 ejemplo
		this->id = id;
		retorno=1;

	}

	return retorno;
}





int Libro_getId(eLibro* this,int* id){
	int retorno;
	retorno =0;

	if(this != NULL && id!=NULL){
		*id = this->id;
		retorno=1;

	}
	return retorno;

}


int Libro_CompareById(void* libro1, void* libro2){

	int retorno;
	int id1;
	int id2;
	eLibro* book1;
	eLibro* book2;

	book1 = (eLibro*)libro1;
	book2 = (eLibro*)libro2;


	if(libro1 != NULL && libro2!=NULL)
	{
		Libro_getId(book1,&id1);
		Libro_getId(book2,&id2);

		if(id1 == id2)
		{
			retorno=0;
		}
		else
		{
			if(id1 > id2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}




int Libro_setTitulo(eLibro* this,char* titulo){

	int retorno;
		retorno =0;

		if(this != NULL ){
			strcpy(this->titulo, titulo);
			retorno=1;

		}

		return retorno;
}




int Libro_getTitulo(eLibro* this,char* titulo){
	int retorno;
	retorno =0;

	if(this != NULL && titulo!=NULL){
		strcpy(titulo, this->titulo);
		retorno=1;

	}
	return retorno;

}






int Libro_CompareByTitulo(void* libro1, void* libro2){

	int retorno;
	char titulo1[50];
	char titulo2[50];
	eLibro* book1;
	eLibro* book2;
	book1 = (eLibro*)libro1;
	book2 = (eLibro*)libro2;

	if(libro1 != NULL && libro2!=NULL){
		Libro_getTitulo(book1,titulo1);
		Libro_getTitulo(book2,titulo2);

		retorno= strcmp(titulo1 , titulo2);
	}

	return retorno;
}


int Libro_setAutor(eLibro* this,char* autor){

	int retorno;
		retorno =0;

		if(this != NULL ){
			strcpy(this->autor, autor);
			retorno=1;

		}

		return retorno;
}




int Libro_getAutor(eLibro* this,char* autor){
	int retorno;
	retorno =0;

	if(this != NULL && autor!=NULL){
		strcpy(autor, this->autor);
		retorno=1;

	}
	return retorno;

}






int Libro_CompareByAutor(void* libro1, void* libro2){

	int retorno;
	char autor1[50];
	char autor2[50];
	eLibro* book1;
	eLibro* book2;
	book1 = (eLibro*)libro1;
	book2 = (eLibro*)libro2;

	if(libro1 != NULL && libro2!=NULL){
		Libro_getAutor(book1,autor1);
		Libro_getAutor(book2,autor2);

		retorno= strcmp(autor1 , autor2);
	}

	return retorno;
}






int Libro_setPrecio(eLibro* this,float precio){

	int retorno;
		retorno =0;

		if(this != NULL){
			this->precio = precio;
			retorno=1;

		}

		return retorno;
}






int Libro_getPrecio(eLibro* this,float* precio){

	int retorno;
	retorno =0;

	if(this != NULL && precio!=NULL){
		*precio = this->precio;
		retorno=1;

	}
	return retorno;
}






int Libro_CompareByPrecio(void* libro1, void* libro2){

	int retorno;
	float precio1;
	float precio2;
	eLibro* book1;
	eLibro* book2;
	book1 = (eLibro*)libro1;
	book2 = (eLibro*)libro2;

	if(libro1 != NULL && libro2!=NULL)
	{
		Libro_getPrecio(book1,&precio1);
		Libro_getPrecio(book2,&precio2);

		if(precio1 == precio2)
		{
			retorno=0;
		}
		else
		{
			if(precio1 > precio2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}





int Libro_setIdEditorial(eLibro* this,int idEditorial){

	int retorno;
		retorno =0;

		if(this != NULL){
			this->idEditorial = idEditorial;
			retorno=1;

		}

		return retorno;
}






int Libro_getIdEditorial(eLibro* this,int* idEditorial){

	int retorno;
	retorno =0;

	if(this != NULL && idEditorial!=NULL){
		*idEditorial = this->idEditorial;
		retorno=1;

	}
	return retorno;
}





int Libro_CompareByIdEditorial(void* libro1, void* libro2){

	int retorno;
	int idEditorial1;
	int idEditorial2;
	eLibro* book1;
	eLibro* book2;
	book1 = (eLibro*)libro1;
	book2 = (eLibro*)libro2;

	if(libro1 != NULL && libro2!=NULL)
	{
		Libro_getIdEditorial(book1,&idEditorial1);
		Libro_getIdEditorial(book2,&idEditorial2);

		if(idEditorial1 == idEditorial2)
		{
			retorno=0;
		}
		else
		{
			if(idEditorial1 > idEditorial2)
			{
				retorno=1;
			}
			else
			{
				retorno=-1;
			}
		}
	}

	return retorno;
}



void Libro_show(eLibro* this){

	int id;
	char titulo[50];
	char autor[50];
	float precio;
	int idEditorial;

	if(this !=NULL)
	{
		Libro_getId(this,&id);
		Libro_getTitulo(this,titulo);
		Libro_getAutor(this,autor);
		Libro_getPrecio(this,&precio);
		Libro_getIdEditorial(this,&idEditorial);
		printf("%3d | %35s | %20s | %8.2f | %8d\n",id,titulo,autor,precio,idEditorial);
	}

}


void Libro_show_conEditorial(eLibro* this, LinkedList* editorial){

	int id;
		char titulo[50];
		char autor[50];
		float precio;
		int idEditorial;
		char nombreEditorial[50];

		if(this !=NULL && editorial!=NULL)
		{
			Libro_getId(this,&id);
			Libro_getTitulo(this,titulo);
			Libro_getAutor(this,autor);
			Libro_getPrecio(this,&precio);
			Libro_getIdEditorial(this,&idEditorial);
			Editorial_getNombreByID(editorial,nombreEditorial, idEditorial);



			printf("%3d | %35s | %20s | %8.2f | %15s\n",id,titulo,autor,precio,nombreEditorial);
		}
}


int Libro_filtrarMinotauro(void* this){

	eLibro* unLibro;
	unLibro = (eLibro*)this;
	int retorno;
	int idEditorial;

	if(this!=NULL){
	unLibro = (eLibro*)this;
	Libro_getIdEditorial(unLibro,&idEditorial);
	retorno = 0;

		if(idEditorial == MINOTAURO){
			retorno = 1;
		}
	}
	return retorno;
}


int Libro_HacerDescuento(void* element){

	float precio;
	int idEditorial;

	Libro_getPrecio((eLibro*)element,&precio);
	Libro_getIdEditorial((eLibro*)element,&idEditorial);


	if(idEditorial == 1 && precio >= 300){
		//printf("Antes de llamar a la funcion: %f", precio);
		precio = precio - ( precio* 20 / 100);
		//printf("Despues de llamar a la funcion: %f", precio);
	}

	if(idEditorial == 1 && precio <= 200){
		//printf("Antes de llamar a la funcion: %f", precio);
		precio = precio - (precio * 10 / 100);
		//printf("Despues de llamar a la funcion: %f", precio);
	}

	Libro_setPrecio(element,precio);
	return precio;
}
