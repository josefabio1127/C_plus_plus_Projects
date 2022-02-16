#include <string>
#include "Estudiante.h" // incluir encabezado de la clase
#include <iostream>
#include <vector>
using namespace std;


Estudiante::Estudiante() // constructor por defecto
{
	nombre = ""; carnet = 0;
};
Estudiante::Estudiante(string nom, int car) : nombre(nom), carnet(car) // constructor sobrecargado
{};
Estudiante::~Estudiante() // destructor
{};
string Estudiante::obtener_nombre() const // implementación de las funciones miembro
{
	return nombre;
};
int Estudiante::obtener_carnet() const
{
	return carnet;
}
void Estudiante::asignar_nombre(string nom)
{
	nombre = nom;
};
void Estudiante::asignar_carnet(int car)
{
	carnet = car;
};

