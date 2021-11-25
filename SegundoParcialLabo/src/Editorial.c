/*
 * Editorial.c
 *
 *  Created on: 24 nov. 2021
 *      Author: Usuario
 */

#include "Editorial.h"


eEditorial* Editorial_new(){
	eEditorial* unaEditorial;

	unaEditorial = (eEditorial*) malloc(sizeof(eEditorial));



	return unaEditorial;

}



eEditorial* Editorial_newParametros(char* idEditorialStr,char* nombreStr){

	eEditorial* unaEditorial;
	int idEditorial;
	//llama a new libro y a los seters

	idEditorial= atoi(idEditorialStr);

	unaEditorial= Editorial_new();
	Editorial_setNombre(unaEditorial,nombreStr);
	Editorial_setIdEditorial(unaEditorial,idEditorial);


	//printf("book dado de alta:\n ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n",id,tituloStr,precio,idEditorial);

	return unaEditorial;
}



void Editorial_delete(eEditorial* this){
//ver si cambio y pongo retorno
	if(this != NULL){

		free(this);
	}

	//destructor elimina un book de la memoria
}


int Editorial_setIdEditorial(eEditorial* this,int idEditorial){
	int retorno;
	retorno =0;

	if(this != NULL && idEditorial>0){//1500 ejemplo
		this->idEditorial = idEditorial;
		retorno=1;

	}

	return retorno;
}





int Editorial_getIdEditorial(eEditorial* this,int* idEditorial){
	int retorno;
	retorno =0;

	if(this != NULL && idEditorial!=NULL){
		*idEditorial = this->idEditorial;
		retorno=1;

	}
	return retorno;

}


int Editorial_CompareByIdEditorial(void* libro1, void* libro2){

	int retorno;
	int idEditorial1;
	int idEditorial2;
	eEditorial* book1;
	eEditorial* book2;

	book1 = (eEditorial*)libro1;
	book2 = (eEditorial*)libro2;


	if(libro1 != NULL && libro2!=NULL)
	{
		Editorial_getIdEditorial(book1,&idEditorial1);
		Editorial_getIdEditorial(book2,&idEditorial2);

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




int Editorial_setNombre(eEditorial* this,char* nombre){

	int retorno;
		retorno =0;

		if(this != NULL ){
			strcpy(this->nombre, nombre);
			retorno=1;

		}

		return retorno;
}




int Editorial_getNombre(eEditorial* this,char* nombre){
	int retorno;
	retorno =0;

	if(this != NULL && nombre!=NULL){
		strcpy(nombre, this->nombre);
		retorno=1;

	}
	return retorno;

}

int Editorial_getNombreByID(LinkedList* pArrayListEditoriales,char* nombre, int idEditorial){
	int retorno;
	retorno =0;
	int i;
	int lenEditoriales;
	eEditorial* unaEditorial;
	int idAuxiliar;

	if(pArrayListEditoriales != NULL && nombre!=NULL){
		lenEditoriales = ll_len(pArrayListEditoriales);
		for(i=0; i<lenEditoriales;i++)
		{
			unaEditorial = ll_get(pArrayListEditoriales, i);
			Editorial_getIdEditorial(unaEditorial,&idAuxiliar);
			if(idEditorial == idAuxiliar){
				strcpy(nombre, unaEditorial->nombre);
				break;
			}
		}

	}
	return retorno;

}




int Editorial_CompareByNombre(void* libro1, void* libro2){

	int retorno;
	char nombre1[50];
	char nombre2[50];
	eEditorial* book1;
	eEditorial* book2;
	book1 = (eEditorial*)libro1;
	book2 = (eEditorial*)libro2;

	if(libro1 != NULL && libro2!=NULL){
		Editorial_getNombre(book1,nombre1);
		Editorial_getNombre(book2,nombre2);

		retorno= strcmp(nombre1 , nombre2);
	}

	return retorno;
}


void Editorial_show(eEditorial* this){

	char nombre[50];
	int idEditorial;

	if(this !=NULL)
	{
		Editorial_getIdEditorial(this,&idEditorial);
		Editorial_getNombre(this,nombre);
		printf("%3d | %15s\n",idEditorial,nombre);
	}

}
