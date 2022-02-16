// examen2_Jose_Fabio_Navarro_Naranjo.cpp

//Directivas para el compilador
#include <iostream>
#include <vector>
#include <iomanip>
#include "Produce.h"
using namespace std;

//Funciones
void imprimir_produccion_resumida(vector<Produce>Produccion)
/*
Funcion: desplegar en plantalla por cada id_arduino la suma total a producir en todas las plantas.
Entradas: vector de produccion.
Salidas: N/A
*/
{
	vector<int>Tipos; //vector que va a contener todos los id_arduino diferentes
	for (Produce elemento : Produccion) // ciclo que recorre el vector de produccion para encontrar todos los id_arduino diferentes
	{
		int x = 0;
		for (int tip : Tipos) //ciclo que recorre el vector de tipos para encontrar los id_arduinos qu ya estan agregados
		{
			if (elemento.id_arduino == tip)
				x++; // la x aumenta si el id_arduino ya esta en el vector de tipos
		}
		if (x == 0) // si la x se mantiene en 0 es porque la id_arduino no esta en el vector tipo
			Tipos.push_back(elemento.id_arduino);
	}
	cout << "Resumen de Produccion" << endl;
	cout << left << setw(10) << "Arduino" << "Cantidad a producir" << endl;
	for (int tip : Tipos) //ciclo para desplegar los datos
	{
		int total = 0;
		for (Produce elemento : Produccion) // ciclo para realizar la suma de cantidades de id_arduino iguales
		{
			if (elemento.id_arduino == tip)
				total += elemento.cantidad_a_producir;
		}
		cout << left << setw(10) << tip << total << endl;
	}
}

//Programa principal
int main()
{
	vector <Produce> Produccion;
	Produce a1(1, 250101, 1000); a1.aumentar_produccion(Produccion);
	Produce a2(1, 250105, 25000); a2.aumentar_produccion(Produccion);
	Produce a3(2, 250101, 4000); a3.aumentar_produccion(Produccion);
	Produce a4(2, 250105, 6000); a4.aumentar_produccion(Produccion);
	Produce a5(1, 250101, 1200); a5.aumentar_produccion(Produccion);
	Produce a6(3, 250101, 5000); a6.aumentar_produccion(Produccion);
	Produce a7(3, 253002, 6000); a7.aumentar_produccion(Produccion);
	Produce a8(3, 250105, 7500); a8.aumentar_produccion(Produccion);

	Produce d1(1, 250105, 20000); d1.disminuir_produccion(Produccion);
	Produce d2(1, 250105, 5000); d2.disminuir_produccion(Produccion);

	imprimir_produccion_resumida(Produccion);
	return 0;
}