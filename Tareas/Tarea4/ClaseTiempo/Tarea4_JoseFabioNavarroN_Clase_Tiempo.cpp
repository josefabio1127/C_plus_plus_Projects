// Tarea4_JoseFabioNavarroN_Clase_Tiempo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//Directivas para el compilador
#include <iostream>
#include "Tiempo.h"
#include <vector>
using namespace std;

//Funciones
Tiempo ingresar_tiempo() //esta funcion sirve para ingresar los datos dinamicamente
/*
Funcion: ingresar los datos de un objeto de clase tipo tiempo de manera dinamica
Entradas: N/A
Salidas: objeto de la clase tiempo con los datos ingresados por el usuario
*/
{
	int horas;
	int minutos;
	int segundos;
	cout << "Nuevo tiempo" << endl;
	cout << "Ingrese las horas (de 00 a 23): ";
	cin >> horas;
	if (horas > 23)
	{
		cout << "Valor invalido." << endl;
		cout << "Ingrese las horas (de 00 a 23): ";
		cin >> horas;
	}
	cout << "Ingrese los minutos (de 00 a 59): ";
	cin >> minutos;
	if (minutos > 59)
	{
		cout << "Valor invalido." << endl;
		cout << "Ingrese los minutos (de 00 a 59): ";
		cin >> minutos;
	}
	cout << "Ingrese los segundos (de 00 a 59): ";
	cin >> segundos;
	if (segundos > 59)
	{
		cout << "Valor invalido." << endl;
		cout << "Ingrese los segundos (de 00 a 59): ";
		cin >> segundos;
	}
	cout << endl;
	Tiempo time(horas, minutos, segundos);
	return time;

}

//Programa principal
int main()
{
	/* 
	Tiempo tiempo1={11,22,45} //Datos alambrados para usar en casos de prueba
	Tiempo tiempo2={9,45,15}
	*/
	Tiempo tiempo1= ingresar_tiempo(); //asignacion de los datos del tiempo1
	Tiempo tiempo2= ingresar_tiempo(); //asignacion de los datos del tiempo2
	Tiempo tiempo_suma = tiempo1 + tiempo2;
	cout << "La suma de los tiempos es: ";  
	tiempo_suma.imprime_tiempo();
	Tiempo mayor=tiempo1.tiempo_mayor(tiempo2);
	cout << "\nEl tiempo mayor es: ";
	mayor.imprime_tiempo();
	cout << endl;
	return 0;
}
