// quiz3_Jose_Fabio_Navarro_Naranjo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
#include <iostream>
#include <list>
#include <forward_list>
#include "Lista.h"
using namespace std;

//Funciones
void mostrar_list(list<int>lista)
/*
Funcion: mostrar una lista de tipo list
Entradas: lista tipo list
Salidas: N/A
*/
{
	cout << "Desplegar lista" << endl;
	for (int numero : lista)
	{
		cout << numero << endl;
	}
}

void mostrar_forward_list(forward_list<int>lista)
/*
Funcion: mostrar una lista de tipo forward_list
Entradas: lista tipo forward_list
Salidas: N/A
*/
{
	cout << "Desplegar lista" << endl;
	for (int numero : lista)
	{
		cout << numero << endl;
	}
}

void eliminar_repetidos_list(list<int>& lista)
/*
Funcion: eliminar los elementos repetidos de una lista de tipo list
Entradas: lista tipo list
Salidas: N/A
*/
{
	list<int>::iterator inicio = lista.begin();
	list<int>::iterator inicioaux;
	list<int>::iterator eliminar;
	while(inicio!=lista.end())
	{
		inicioaux = inicio;
		inicioaux++;
		while (inicioaux != lista.end())
		{
			if (*inicio == *inicioaux)
			{
				eliminar = inicioaux;
				inicioaux++;
				lista.erase(eliminar);
			}
			else
				inicioaux++;
		}
		inicio++;
	}
}

void eliminar_repetidos_forward_list(forward_list<int>& lista)
/*
Funcion: eliminar los elementos repetidos de una lista de tipo forward_list
Entradas: lista tipo forward_list
Salidas: N/A
*/
{

	forward_list<int>::iterator inicio = lista.begin();
	forward_list<int>::iterator inicioaux;
	forward_list<int>::iterator eliminar;
	forward_list<int>::iterator anterior = inicioaux;
	while (inicio != lista.end())
	{
		inicioaux = inicio;
		anterior = inicioaux;
		inicioaux++;
		while (inicioaux != lista.end())
		{
			if (*inicio == *inicioaux)
			{
				eliminar = anterior;
				inicioaux++;
				lista.erase_after(eliminar);
			}
			else
			{
				anterior = inicioaux;
				inicioaux++;
			}
		}
		inicio++;
	}
}

int main()
{
	//lista simplemente enlazada
	cout << "Lista Simplemente Enlazada" << endl;
	Lista lista1;
	lista1.insertar_en_lista(30);
	lista1.insertar_en_lista(15);
	lista1.insertar_en_lista(100);
	lista1.insertar_en_lista(30);
	lista1.insertar_en_lista(25);
	lista1.insertar_en_lista(15);
	lista1.insertar_en_lista(15);
	lista1.insertar_en_lista(20);
	lista1.insertar_en_lista(20);
	lista1.desplegar_lista();
	lista1.eliminar_repetidos();
	lista1.desplegar_lista();
	//Lista tipo <list>
	cout << "Lista tipo <list>" << endl;
	list<int>numeros = { 30,15,100,30,25,15,15,20,20 };
	mostrar_list(numeros);
	eliminar_repetidos_list(numeros);
	mostrar_list(numeros);
	//Lista tipo <forward_list>
	cout << "Lista tipo <forward_list>" << endl;
	forward_list<int>elementos = { 30,15,100,30,25,15,15,20,20 };
	mostrar_forward_list(elementos);
	eliminar_repetidos_forward_list(elementos);
	mostrar_forward_list(elementos);
};
