// examen1_Jose_Fabio_Navarro_Naranjo.cpp

//Directivas para el compilador
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//estructuras
struct plantas {
	int numero=0;
	string tipo="";
	int cantidad=0;
};

//Prototipos de funciones
int resumir_productos(plantas[15],plantas[15],int);
void costos_de_proyectos(int[3][4],int[3][4],int[3][2]);

//Programa principal
int main()
{
	int x = 1;
	while (x != 0)
	{
		int opcion;
		cout << "MENU" << endl;
		cout << "1- Resumen de la produccion." << endl;
		cout << "2- Costos de proyectos." << endl;
		cout << "0- Fin." << endl;
		cin >> opcion;

		switch (opcion)
		{
		case 1:
		{
			int tamano;
			cout << "Ingrese la cantidad de plantas que desea registrar (menos de 15): ";
			cin >> tamano;
			int x = 0;
			plantas vector[15];
			plantas plant;
			while (x < tamano) //ciclo para el ingreso de datos
			{
				cout << "Planta " << x + 1 << endl;
				cout << "Numero de planta: ";
				cin >> plant.numero;
				cout << "Tipo de planta: ";
				cin >> plant.tipo;
				cout << "Cantidad: ";
				cin >> plant.cantidad;
				vector[x] = plant;
				x++;
			}
			plantas resultado[15]; //vector vacio para llenar con los resultados
			int total = resumir_productos(vector, resultado, tamano);
			cout << "\nTipo        Cantidad" << endl;
			x = 0;
			while (x < total) //ciclo para el desplegue de los resultados
			{
				cout << resultado[x].tipo << "           "<< resultado[x].cantidad << endl;
				x++;
			}
			cout << endl;
		}
			break;
		case 2:
		{
			int matriz_costos[3][4] = { {8,13,6,6},{6,12,7,8},{7,14,6,7} };
			int matriz_cantidad[3][4] = { {24,5,12,18},{20,7,15,20},{20,4,15,15} };
			int resultado[3][2]; //matriz vacia para llenar con los resultados
			costos_de_proyectos(matriz_costos, matriz_cantidad,resultado);
			cout << "Proyecto        " << "Proveedor       " << "Costo total       " << endl;
			int x = 0;
			while (x<3) //ciclo para desplegar resultados
			{
				int y = 0;
				cout << x + 1;
				while (y < 2) //ciclo para desplegar resultados
				{
					 cout << "               " << resultado[x][y];
					y++;
				}
				cout << endl;
				x++;
			}
			cout << endl;
			break;
		}
		case 0:
			x=0;
			break;
		default:
			break;
		}

	}
}

// Definicion de funciones

int resumir_productos(plantas vector[15], plantas resultado[15], int tamano)
{
	plantas plant;
	int x = 0;
	int total = 0;
	while (x < tamano) //ciclo que recorre las plantas
	{
		string tipo;
		if (vector[x].tipo != "")
		{
			plant.tipo = vector[x].tipo;
			plant.cantidad = vector[x].cantidad;
			int y = x + 1;
			while (y < tamano) //ciclo que se usa para comparar las plantas
			{
				if (vector[x].tipo == vector[y].tipo)
				{
					plant.cantidad += vector[y].cantidad;
					vector[y].tipo = "";
					vector[y].cantidad = 0;
				}
				y++;
			}
			resultado[total] = plant;
			total++;
		}
		x++;
	}
	return total;
}

void costos_de_proyectos(int costos[3][4], int cantidad[3][4], int resultado[3][2])
{
	int total[3] = { 1000000,1000000,1000000 };
	int x = 0;
	while (x < 3)
	{
		int y = 0;
		while (y < 3)
		{
			int preliminar = 0;
			int z = 0;
			while (z < 4)
			{
				preliminar += costos[x][z] * cantidad[y][z];
				z++;

			}
			if (preliminar < total[y])
			{
				total[y] = preliminar;
				resultado[y][0] = x+1;
				resultado[y][1] = total[y];
			}
			y++;
		}
		x++;
	}
}

