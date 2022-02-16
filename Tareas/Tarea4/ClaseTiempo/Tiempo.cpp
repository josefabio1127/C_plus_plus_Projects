// Archivo de implementacion de la clase de tipo tiempo

//Directivas para el compilador
#include "Tiempo.h"
#include <iostream>
using namespace std;

Tiempo::Tiempo()//construcctor por defecto
/*
Funcion: construir (crear) un objeto de la clase tiempo
Entradas: N/A
Salidas: N/A
*/
{
	horas = 0;
	minutos = 0;
	segundos = 0;
}

Tiempo::Tiempo(int hor,int min,int seg) //constructor sobrecargado
/*
Funcion: construir (crear) un objeto de la clase tiempo con datos incluidos
Entradas: cantidad de horas, minutos y segundos (variables tipo int)
Salidas: N/A
*/
{
	horas = hor;
	minutos = min;
	segundos = seg;
}

void Tiempo::imprime_tiempo() const //Funcion para imprimir un objeto de la clase de tipo Tiempo, usa el objeto implicito this
{
	cout << horas << ":" << minutos << ":" << segundos;
}

Tiempo Tiempo::tiempo_mayor(Tiempo b)
/*
Funcion: definir cual tiempo es "mayor" basado en la cantidad de horas, minutos y segundos
Entradas: un objeto de tipo Tiempo como parametro y un objeto implicito
Salidas: un objeto de tipo tiempo con el tiempo "mayor
*/
{
	if (b.horas > horas)
		return b;
	if (b.horas == horas) //si ambas horas son iguales evalua los minutos
	{
		if (b.minutos > minutos)
			return b;
		if (b.minutos == minutos) //si los minutos son iguales evalua los segundos
		{
			if (b.segundos < segundos)
				return *this;
			else
				return b;
		}
		else
			return *this;
	}
	else
		return *this;
}

Tiempo& Tiempo::operator+(Tiempo b)
/*
Funcion: sobrecargar el operador + para que pueda sumar objetos de tipo tiempo
Entradas: un objeto de tipo Tiempo como parametro y un objeto implicito 
Salidas: un objeto de tipo tiempo con la suma de los tiempos 
*/
{
	Tiempo resultado;
	resultado.segundos = segundos + b.segundos;
	resultado.minutos = minutos + b.minutos;
	resultado.horas = horas + b.horas;
	if (resultado.segundos > 59) // si los segundos son mayores a 59 suma un minuto
	{
		resultado.segundos -= 60;
		resultado.minutos += 1;
	}
	if (resultado.minutos > 59) // si los minutos son mayores a 59 suma una hora
	{
		resultado.minutos -= 60;
		resultado.horas += 1;
	}
	if (resultado.horas > 23) // si las horas son mayores a 23 retorna -1 en todos los valores
	{
		resultado.horas = -1;
		resultado.minutos = -1;
		resultado.segundos = -1;
	}
	return resultado;
}