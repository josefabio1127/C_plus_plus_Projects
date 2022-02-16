//Directivas para el compilador
#include <iostream>
#include <vector>

using namespace std;

//Definicion de funciones
bool cuadrado_magico(int matriz[50][50], int tamano) {
	/*
	Funcion: determinar si la matriz ingresada es un cuadrado magico
	Entradas: matriz y tamano de la matriz
	Salidas: booleano: true si es magica, false si no lo es
	*/
	int sumador = 0;
	int suma = 0;;
	int x = 0;
	int y;
	while (x < tamano) { //analizar filas
		sumador = 0;
		y = 0;
		while (y < tamano) {
			sumador += matriz[x][y];
			y++;
		}
		if (x == 0)
			suma = sumador;
		if (sumador != suma)
			return false;
		x++;
	}
	x = 0;
	while (x < tamano) { //analizar columnas
		sumador = 0;
		y = 0;
		while (y < tamano) {
			sumador += matriz[y][x];
			y++;
		}
		if (sumador != suma)
			return false;
		x++;
	}
	sumador = 0;
	x = 0;
	y = 0;
	while (x < tamano) { //analizar diagonal principal
		sumador += matriz[x][y];
		x++;
		y++;
	}
	if (sumador != suma)
		return false;
	sumador = 0;
	x = 0;
	y = tamano - 1;
	while (x < tamano) { //analizar diagonal secundaria
		sumador += matriz[x][y];
		x++;
		y--;
	}
	if (sumador != suma)
		return false;
	else
		return true;
}

vector<vector<int>>triangulo_de_pascal(int niveles) {
	/*
	Funcion: llenar un vector con el triangulo de pascal
	Entradas: cantidad de niveles del triangulo
	Salidas: un vector con vectores que contienen los numeros de cada nivel
	*/
	vector<vector<int>>triangulo = {};
	if (niveles >= 1) {
		vector<int> nivel = {};
		int x = 0;
		while (x < niveles) {
			nivel.clear();
			if (x == 0)
				nivel = { 1 };
			else if (x == 1)
				nivel = { 1,1 };
			else {
				int y = 1;
				nivel.push_back(1);
				while (y < x) {
					nivel.push_back(triangulo[x - 1][y - 1] + triangulo[x - 1][y]);
					y++;
				}
				nivel.push_back(1);
			}
			triangulo.push_back(nivel);
			x++;
		}
		return triangulo;
	}
	else
		return triangulo;
}

void imprimir_triangulo(vector<vector<int>>triangulo) {
	/*
	Funcion: mostrar los datos en pantalla de un vector de vectores
	Entradas: vector de vectores
	Salidas: N/A
	*/
	if (triangulo.empty()) {
		cout << "Matiz vacia, ingrese un numero mayor o igual a 1." << endl;
		return;
	}
	else {
		for (vector<int> nivel : triangulo) {
			for (int numero : nivel)
				cout << numero;
			cout << endl;
		}
	}
}

//programa principal
int main()
{ 
	//Ejercicio 1
	int matriz[50][50] = { { 16,3,2,13 }, { 5,10,11,8 }, { 9,6,7,12 }, { 4,15,14,1 } };
	//int matriz[50][50] = { { 8,1,6,}, { 3,5,7 }, { 4,9,2 } };
	//int matriz[50][50] = { { 8,1,6,}, { 3,5,7 }, { 4,2,9 } };
	bool y=cuadrado_magico(matriz, 4);
	if (y == true)
		cout << "Es magico" << endl;
	else
		cout << "No es magico" << endl;
	

	//Ejercicio 2
	imprimir_triangulo(triangulo_de_pascal(5));
}

