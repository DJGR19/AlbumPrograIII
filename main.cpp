#include "AlbumReproduccion.h"
#include <iostream>
using namespace std;

int main()
{
	char buscarG[20];
	char buscarA[20];
	char tmp[20];
	AlbumReproducciones dat;
	cancion m;
	//dat.IngresoCanciones();
	int options;
	do
	{
	cout << "******** A L B U M    D E    R E P R O D U C C I O N ********" << endl;

	cout << "1. Averiguar total de canciones almacenadas en el album" << endl;
	cout << "2. Total en tiempo de duracion (mminutos y horas) de canciones almacenadas" << endl;
	cout << "3. Imprimir por genero las canciones almacenadas (solicitar genero)" << endl;
	cout << "4. Imprimir por album las canciones almacenadas (solicitar album)" << endl;
	cout << "5. Salir" << endl;
	//ORDENAR POR NUMERO DE CANCION EN ORDER ASCENDENTE
	

	cin >> options;
	
		switch (options)
		{
		
		
		case 1:
			dat.ConsultarCantCanciones();
			break;
		case 2:
			dat.DuracionTodasLasCanciones();
			break;
		case 3:
			cout << "Ingrese nombre de genero a buscar" << endl;
			cin >> buscarG;
			dat.BuscarAlbum(buscarG);
			break;
		case 4:
			cout << "Ingrese nombre de album a buscar" << endl;
			cin >> buscarA;
			dat.ImpresionAlbum(buscarA);
			break;
		case 5:
			break;
	    }


	} while (options!=5);

	
	system("pause");

}