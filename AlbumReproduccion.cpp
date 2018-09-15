
#include "AlbumReproduccion.h"
#include <fstream>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;


void AlbumReproducciones::IngresoCanciones()
{
	ofstream AlbumIn("album.dat", ios::out | ios::app | ios::binary);

	cancion datos;
	int cantidad;
	int option;
	if (!AlbumIn)
	{
		cout << "Error al encontrar archivo album.dat" << endl;
		return;
	}



	cout << "******** A L B U M    D E    R E P R O D U C C I O N ********" << endl;

	cout << "Ingrese la cantidad de canciones a ingresar: " << endl;
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++) {

		cout << "Ingrese nombre de la canción: " << endl;
		cin >> datos.nombre;
		cout << "Ingrese interprete: " << endl;
		cin >> datos.interprete;
		cout << "Ingrese duración de la canción en minutos: " << endl;
		cin >> datos.duracion;
		if (datos.total)
		{
			datos.duracion++;
		}
		cout << "Ingrese genero de la cancion: " << endl;
		cin >> datos.genero;
		cout << "Ingrese album de la canción: " << endl;
		cin >> datos.album;
		cout << "Ingres no. de canción: " << endl;
		cin >> datos.no_cancion;

		AlbumIn.seekp(0, ios::end);
		AlbumIn.write(reinterpret_cast<const char*>(&datos), sizeof(cancion));

	}




	AlbumIn.close();


}

void AlbumReproducciones::ConsultarCantCanciones()
{
	cancion datos;
	ifstream Albumout("album.dat", ios::in | ios::binary);

	if (!Albumout)
	{
		cout << "Error al intentar accesar al archivo album.dat" << endl;
		return;
	}


	cout << "**** C O N S U L T A   D E   C A N T I D A D   D E   C A N C I O N E S****" << endl;



	Albumout.seekg(0, ios::end);
	int tamanio = Albumout.tellg();
	int cant_canciones = tamanio / sizeof(cancion);
	Albumout.read(reinterpret_cast<char *>(&datos), sizeof(cancion));
	cout << "La cantidad de canciones que existen en el album es de: " << cant_canciones << "\n"<<endl;




	Albumout.close();


}

void AlbumReproducciones::DuracionTodasLasCanciones()
{

	ifstream AlbumOutT("album.dat", ios::app);
	if (!AlbumOutT)
	{
		cout << "Error al abrir archivo album.dat" << endl;
		return;
	}

	cancion time;
	double tiempomint=0, tiempohoras=0, totaltime=0;
	AlbumOutT.seekg(0, ios::beg);
	AlbumOutT.read(reinterpret_cast<char *>(&time), sizeof(cancion));
	while(!AlbumOutT.eof())

	{
		totaltime = totaltime + time.duracion;

		AlbumOutT.read(reinterpret_cast<char *>(&time), sizeof(cancion));
	}

	tiempohoras= totaltime / 60;

	cout << "El tiempo total de duración en minutos de las canciones es de " << totaltime<<"\n"<<endl;
	cout << "El tiempo total de duración en horas de las canciones es de " << tiempohoras << "\n" << endl;

}

void AlbumReproducciones::BuscarAlbum(const char * gender)
{
	cancion dato;
	char* tmp = new char [strlen(gender)];
	strcpy(tmp, strlen(gender) + 1, gender);
	ifstream Albumin ("album.dat", ios::in | ios::binary);

	if (!Albumin)
	{
		cout << "Error al intentar encontrar archivo album.dat" << endl;
	}

	    Albumin.seekg(0,ios::beg);
		Albumin.read(reinterpret_cast<char*>(&dato), sizeof(cancion));
		//int tamano = Albumin.tellg();
		while (!Albumin.eof()) {
			if (strcmp(tmp, dato.genero) == 0)
			{



				//Albumin.read(reinterpret_cast<char*>(&dato), sizeof(dato));
				cout << "Nombre : " << dato.nombre << endl;
				cout << "Interprete :" << dato.interprete << endl;
				cout << "Duración : " << dato.duracion << endl;
				cout << "Genero  : " << dato.genero << endl;
				cout << "Album : " << dato.album << endl;
				cout << "No. Cancion 5 : " << dato.no_cancion << endl;
				cout << endl;


			}

			Albumin.read(reinterpret_cast<char*>(&dato), sizeof(cancion));


		}


		Albumin.close();

}


void AlbumReproducciones::ImpresionAlbum(const char* album); {
	ifstream albumIn("album.dat", ios::in | ios::binary);
	bool seEncontro = false;
	if (!albumIn) {
		cout << "No se pudo abrir el archivo album\n";
		return;
	}

	cancion c;
	albumIn.read(reinterpret_cast<char *>(&c), sizeof(cancion));

	while (!albumIn.eof()) {

		nodo * tmp = primero;
		nodo * anterior = 0;
		bool rsl = false;
		nodo *nuevo = new nodo(c.no_cancion, c.nombre, c.interprete);
		if (strcmp(album, c.album) == 0) {

			if (primero == 0) {
				primero = nuevo;
				ultimo = nuevo;
			}
			else if (nuevo->numero < primero->numero) {
				nuevo->siguiente = primero;
				primero = nuevo;
			}
			else {
				tmp = primero;
				while (tmp != 0) {
					if (tmp->numero < nuevo->numero) {
						if (tmp->siguiente == 0) {
							tmp->siguiente = nuevo;
							rsl = false;
							break;
						}
						anterior = tmp;
						tmp = tmp->siguiente;
					}
					else {
						rsl = true;
						tmp = 0;
					}

				}

				if (rsl) {
					tmp = anterior->siguiente;
					anterior->siguiente = nuevo;
					anterior->siguiente->siguiente = tmp;

				}

			}
			seEncontro = true;
		}
		albumIn.read(reinterpret_cast<char *>(&c), sizeof(cancion));

	}
	albumIn.close();
	nodo * tmp = primero;
	if (seEncontro == false) {
		cout << "No se encontro el album con el nombre: " << album;
	}
	else {
		while (tmp != 0) {
			cout << "# de track: " << tmp->numero << "\n cancion: " << tmp->nombre << "\n Interprete: "
				<< tmp->interprete << "\n---------------------------------------------\n";
			tmp = tmp->siguiente;
		}
	}
	primero = 0;

}



}






