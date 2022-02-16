//Practica examen 3

//Directivas para el compilador
#include <iostream>
#include <string>
#include <forward_list>
#include <vector>
#include <list>
using namespace std;

//estructuras
struct num_divisores{
	int cantidad = 0;
	list<int>divisores = {};
};

//Funciones
int base10_a_otras_bases(int numero, int inicio, int final, int base) {
	int digitos = 0;
	int numeroaux = numero;
	while (numeroaux >= 1) {
		numeroaux /= 10;
		digitos++;
	}
	int residuo = digitos - final;
	while (residuo > 0)
	{
		numero /= 10;
		residuo--;
	}
	int numerofinal=0;
	int indice = 0;
	while (final>=inicio)
	{
		numerofinal += (numero % 10)*pow(10,indice);
		numero /= 10;
		indice++;
		final--;
	}
	indice = 0;
	int resultado = 0;
	while (numerofinal>0)
	{
		resultado += (numerofinal % base) * pow(10, indice);
		numerofinal /= base;
		indice++;
	}
	return resultado;
}

forward_list<int>extraer_numeros(string dato) {
	forward_list<int>resultado;
	int x = 0;
	int insertar;
	forward_list<int> ::iterator it = resultado.begin();
	while (x < dato.size()) {
		int a = isdigit(dato[x]);
		if (a != 0)
		{
			insertar = 0;
			while (x < dato.size()) {
				a = isdigit(dato[x]);
				if (a == 0)
					break;
				insertar = insertar * 10 + dato[x] - '0';
				x++;
			}
			if (resultado.empty())
			{
				resultado.push_front(insertar);
			}
			else {
				it = resultado.end();
				resultado.insert_after(it, insertar);
				
			}
		}
		x++;
	}
	return resultado;
}

void extraer_numeros_imprimir(forward_list<int>resultado) {
	for (int elemento : resultado)
		cout << elemento << endl;
}

vector < vector<int> > triangulo_de_pascal(int total) {
	vector<int> nivel;
	vector < vector<int> > triangulo;
	int x = 0;
	int y;
	int numero;
	while (x<total)
	{
		nivel.clear();
		if (x == 0) {
			nivel = { 1 };
		}
		else if (x == 1)
			nivel = { 1,1 };
		else 
		{
			y = 0;
			numero = 0;
			while (y<=x)
			{
				if (y == 0 || y==x)
					numero = 1;
				else
					numero = triangulo[x - 1][y-1] + triangulo[x - 1][y]; 
				//cout << numero << endl;
				nivel.push_back(numero);
				y++;
			}
		}
		triangulo.push_back(nivel);
		x++;
	}
	return triangulo;
}

void triangulo_de_pascal_imprimir(vector < vector<int> >triangulo) {
	for (vector<int> nivel : triangulo) {
		for (int num : nivel) {
			cout << num;
		}
		cout << endl;
	}
}

num_divisores divisores_numero(int numero) {
	int x = 2;
	num_divisores divisores;
	while (x < numero) {
		if (numero % x == 0) {
			divisores.cantidad++;
			divisores.divisores.push_back(x);
		}

		x++;
	}
	return divisores;
}

list<list<int>>semiprimos(int inicio, int final) {
	list<list<int>>resultado = {};
	while (inicio <= final) {
		list<int>numeros = {};
		num_divisores div_num = divisores_numero(inicio);
		if (div_num.cantidad == 2) {
			list<int>::iterator it = div_num.divisores.begin();
			numeros.push_back(inicio);
			numeros.push_back(*it);
			it++;
			numeros.push_back(*it);
			resultado.push_back(numeros);
		}
		inicio++;
	}
	return resultado;
}

void imprimir_list(list<list<int>>lista) {
	for (auto grupo : lista) {
		for (auto numero : grupo) {
			cout << numero<<" ";
		}
		cout << endl;
	}
}

vector<int>extrae_diagonal(int matriz[20][20], int tamano, int diagonal) {
	vector<int>resultado = {};
	int x;
	if (diagonal < 0) {
		diagonal *= -1;
		x = 0;
		while (diagonal < tamano) {
			resultado.push_back(matriz[diagonal][x]);
			diagonal++;
			x++;
		}
	}
	else {
		x = 0;
		while (diagonal < tamano) {
			resultado.push_back(matriz[x][diagonal]);
			diagonal++;
			x++;
		}
	}
	return resultado;
}

void imprimir_vector(vector<int>numeros) {
	for (int numero : numeros) cout << numero << " ";
	cout << endl;
}

list<int>sumar_numeros_largos(list<int>num1, list<int>num2) {
	list<int>resultado;
	list<int> ::reverse_iterator it1 = num1.rbegin();
	list<int> ::reverse_iterator it2 = num2.rbegin();
	int numero = 0;
	int residuo = 0;
	while (it1 != num1.rend() && it2 != num2.rend()) {
		numero = *it1 + *it2 + residuo;
		if (numero > 9) {
			residuo = 1;
			numero -= 10;
		}
		else
			residuo = 0;
		resultado.push_front(numero);
		it1++;
		it2++;
	}
	if (num1.size() < num2.size()) {
		while (it2 != num2.rend()) {
			numero = *it2 + residuo;
			if (numero > 9) {
				residuo = 1;
				numero -= 10;
			}
			else
				residuo = 0;
			resultado.push_front(numero);
			it2++;
		}
	}
	else {
		while (it1 != num1.rend()) {
			numero = *it1 + residuo;
			if (numero > 9) {
				residuo = 1;
				numero -= 10;
			}
			else
				residuo = 0;
			resultado.push_front(numero);
			it1++;
		}
	}
	return resultado;
}

void imprimir_list_2(list<int>lista) {
	for (int numero : lista) cout << numero << "  ";
	cout << endl;
}

//Programa principal
int main()
{
	int x = 0;
	int opcion;
	while (x==0)
	{
		cout << "Menu" << endl;
		cout << "1. Base a otras bases" << endl;
		cout << "2. Programa numeros" << endl;
		cout << "3. Triangulo de pascal" << endl;
		cout << "4. Semiprimos" << endl;
		cout << "5. Extraer diagonal" << endl;
		cout << "6. Numeros largos" << endl;
		cout << "7. Salir" << endl;
		cout << "Seleccione una opcion:";
		cin >> opcion;
		switch (opcion)
		{
		case 1:
		{
			int numero;
			int inicial;
			int final;
			int base;
			cout << "Ingrese un numero:";
			cin >> numero;
			cout << "Ingrese la posicion inicial:";
			cin >> inicial;
			cout << "Ingrese la posicion final:";
			cin >> final;
			cout << "Ingrese la base:";
			cin >> base;
			cout << "Resultado: " << base10_a_otras_bases(numero, inicial, final, base) << endl;
			break;
		}
		case 2:
		{
			/*string dato;
			cin.ignore();
			cout << "Ingrese un string: ";
			getline(cin, dato);*/
			extraer_numeros_imprimir(extraer_numeros("xy 225pa.b3.1415g89iou1000 ab78.9 25"));
			break;
		}
		case 3:
		{
			vector < vector<int> > triangulo= triangulo_de_pascal(5);
			triangulo_de_pascal_imprimir(triangulo);
			break;
		}
		case 4:
		{
			imprimir_list(semiprimos(14, 24));
			break;
		}
		case 5:
		{
			int matriz[20][20] = { {20,50,60,70,80},{15, 20, 16, 40, 50},{30, 56, 60, 25, 30 }, {41, 85, 90, 64, 70},{68, 43, 12, 24, 16} };
			imprimir_vector(extrae_diagonal(matriz, 5, -2));
			break;
		}
		case 6:
		{
			list<int>num1 = { 8,7,5 };
			list<int>num2 = { 1,2,3,4,8 };
			imprimir_list_2(sumar_numeros_largos(num1, num2));
			break;
		}
		case 7:
		{
			x = 1;
			break;
		}
		default:
		{
			cout << "Opcion invalida." << endl;
			break;
		}
		}
	}
}

