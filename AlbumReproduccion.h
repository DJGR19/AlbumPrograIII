#pragma once
#ifndef ALBUMREPRODUCCION_H
#define ALBUMREPRODUCCION_H


//TAREA PARA EL SÁBADO

struct cancion
{
	char nombre[50];
	char interprete[30];
	float duracion; //minutos --- 4 bytes
	char genero[20];
	char album[20];
	int no_cancion;//track ----- 4 bytes


	int total=0;

	//124+4 = 128 bytes

};

class AlbumReproducciones
{
public:
	static void IngresoCanciones();
	static void ConsultarCantCanciones();
	static void DuracionTodasLasCanciones();
	static void BuscarAlbum(const char*);

	static void ImpresionAlbum(const char *);

	int canciones;





};




#endif ALBUMREPRODUCCION_H
