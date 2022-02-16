// quiz2_Jose_Fabio_Navarro_Naranjo.cpp 

//Directivas para el compilador
#include <iostream>
#include "Lista.h"
using namespace std;

int main()
{
	Lista lista1;
	int opcion;
	int x = 0;
	while (x == 0)
	{
		cout << "MENU" << endl;
		cout << "1-Insertar en lista" << endl;
		cout << "2-Eliminar" << endl;
		cout << "3-Contar nodos" << endl;
		cout << "4-Desplegar lista" << endl;
		cout << "0-FIN" << endl;
		cout << "OPCION: ";
		cin >> opcion;
		switch (opcion)
		{
		case 0:
			x = 1;
			break;
		case 1:
		{
			int dato;
			cout << "Indique el numero a ingresar: ";
			cin >> dato;
			lista1.insertar_en_lista_ordenada(dato);
			break;
		}
		case 2:
		{
			int dato;
			int cantidad;
			int x = 0;
			cout << "Indique el numero a eliminar: ";
			cin >> dato;
			cout << "Indique la cantidad a eliminar: ";
			cin >> cantidad;
			if (cantidad == 0)
			{
				int total = lista1.nodos_iguales(dato);
				int x = 0;
				while (total > 0)
				{
					lista1.eliminar(dato);
					total--;
					x++;
				}
				if (x == 0)
				{
					cout << "El dato ingresado no existe en la lista." << endl;
				}
				break;
			}
			else
			{
				while (x < cantidad)
				{
					lista1.eliminar(dato);
					x++;
				}
				break;
			}
		}
		case 3:
		{
			cout << "La cantidad de nodos es: " << lista1.contar_nodos_diferentes() << endl;
			break;
		}
		case 4:
		{
			lista1.desplegar_lista();
		}
		}
	}
}

