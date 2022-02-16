//Directivas para el compilador
#include <iostream>
#include <vector>
#include <string>
#include "Estudiante.h"

using namespace std;

//Funciones
void ingresar(int cant, vector<Estudiante> &lista)
/*
Funcion: ingresar los datos para el objeto de tipo estudiante
Entradas: cantidad de estudiantes a ingresar y vector que contiene a los objetos de tipo estudiante
Salidas: N/A
*/
{
	Estudiante est;
	string nombre;
	int carnet;
	int x = 0;
	while (x < cant) //ciclo para ingresar la cantidad de estudiantes solicitada
	{
		cout << "Ingrese el nombre: ";
		cin.ignore();
		getline(cin, nombre);
		cout << "Ingrese el carnet: ";
		cin >> carnet;
		est.asignar_nombre(nombre);
		est.asignar_carnet(carnet);
		lista.push_back(est);
		x++;
	}
}

void imprimir_estudiante(vector<Estudiante>lista)
/*
Funcion: imprimir los dstos de los objetos de tipo estudiante que se encuentran en el vector lista
Entradas: vector lista
Salidas: N/A
*/
{
	int x = 1;
	for (Estudiante estu : lista)
	{
		cout << "Estudiante " << x << ": " << endl;
		cout << "Nombre: " << estu.obtener_nombre() << endl;
		cout << "Carnet: " << estu.obtener_carnet() << endl << endl;
		x++;
	}
}

//Programa principal
int main()
{
	int cantidad;
	vector<Estudiante>lista;
	cout << "Ingrese la cantidad de estudiantes que desea ingresar (mimino 4): ";
	cin >> cantidad;
	ingresar(cantidad, lista);
	imprimir_estudiante(lista);
	return 0;
}