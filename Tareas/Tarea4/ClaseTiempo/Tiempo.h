//Archivo de interfaz de la clase de tipo tiempo
#pragma once
class Tiempo //definicion de la clase de tipo tiempo (interfaz)
{
private:
	int horas;
	int minutos;
	int segundos;

public:
	Tiempo();
	Tiempo(int,int,int);
	void imprime_tiempo() const;
	Tiempo tiempo_mayor(Tiempo);
	Tiempo & operator+(Tiempo);
};

