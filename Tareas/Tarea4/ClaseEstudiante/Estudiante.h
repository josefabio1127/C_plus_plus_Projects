#pragma once

#include <string>
#include <vector>
using namespace std;
class Estudiante
{
private: // datos miembro
	string nombre;
	int carnet;
public: // prototipos de las funciones miembro
	Estudiante(); // constructor por defecto
	Estudiante(string, int); // constructor particular
	~Estudiante(); // destructor por defecto
	string obtener_nombre() const; // otros prototipos de funciones miembro
	int obtener_carnet() const; // const: indica que no se modifican datos miembro
	void asignar_nombre(string);
	void asignar_carnet(int);
	friend void imprimir_estudiante(vector <Estudiante>);
};