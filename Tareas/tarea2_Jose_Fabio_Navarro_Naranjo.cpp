// Declaración de Bibliotecas
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

//Prototipos de funciones
int sumatoria_cuadrados(int, int);
int multiplicatoria(int,int);
int pares_amigables(int[]);
int suma_divisores(int);
int factores_primos(int);
int numero_abundante(int);
void leer_vector(int, float[]);
void imprimir_vector(int, float[]);
void sumar_restar_vectores(int, float[], float[],float[]);
int multiplicar_vectores(int, float[], float[]);
int sumar_diagonal(int, int[20][20], int);
void leer_matriz(int, int, int[20][20]);
int primos_y_palindromos(int, int);
int convertir_binario_decimal(int);
void triangulo_de_pascal(int, int[20][20]);
int reemplazar(int, int, int);
bool igualdad(int, int);
void maximos_y_minimos(int, int, int[20][20]);
void extraer_numeros(string);
struct datos contar_palabras(string[], string[], int, int);
bool complemento(string, string);
void trozos_iguales(string[],string[]);

//Estructuras
struct datos {
	int vector[5] = {0,0,0,0,0};
};

int main()
{
	int x = 0;
	while (x==0)
	{
		int opcion;
		cout << "1. Sumatoria de cuadrados\n";
		cout << "2. Multiplicatoria\n";
		cout << "3. Pares amigables\n";
		cout << "4. Calcular factores primos\n";
		cout << "5. Determinar si un numero es abundante\n";
		cout << "6. Sumar y restar vectores\n";
		cout << "7. Multiplicar vectores\n";
		cout << "8. Sumar diagonal de una matriz cuadrada\n";
		cout << "9. Números primos y palindromos\n";
		cout << "10.Triangulo de Pascal\n";
		cout << "11.Reemplazar números\n";
		cout << "12.Igualdad de conjuntos\n";
		cout << "13.Máximos y mínimos de la matriz\n";
		cout << "14.Extraer números\n";
		cout << "15.Contar palabras\n";
		cout << "16.Complemento de conjuntos\n";
		cout << "17.Trozos iguales de strings\n";
		cout << "18.FIN\n";
		cout << "Opción: ";
		cin >> opcion;
		

		switch (opcion)
		{
		case 1:
		{
			int m;
			int n;
			cout << "Indique el inicio de la sumatoria: ";
			cin >> m;
			cout << "Indique el final de la sumatoria: ";
			cin >> n;
			cout << "La sumatoria es: " << sumatoria_cuadrados(m, n) << endl;
			cout << "----------------------------" << "\n" << endl;
			break;
		}
		case 2:
		{
			int m;
			int n;
			cout << "Indique el inicio de la multiplicatoria: ";
			cin >> m;
			cout << "Indique el final de la multiplicatoria: ";
			cin >> n;
			cout << "La multiplicatoria es: " << multiplicatoria(m, n) << endl;
			cout << "----------------------------" << "\n" << endl;
			break;
		}
		case 3:
		{
			int y = 0; //contador
			int vector[10];
			while (y < 10) //ciclo para llenar el vector
			{
				cout << "Indique un número para llenar el vector: ";
				cin >> vector[y];
				int contador = 0; //contador
				while (contador < y) //ciclo que revisa que los datos ingresados no esten repetidos
				{
					if (vector[contador] != vector[y])
						contador++;
					else
					{
						cout << "El número ingresado está repetido.\n";
						cout << "Indique un número para llenar el vector: ";
						cin >> vector[y];
					}
				}
				y++;
			}
			pares_amigables(vector);
			break;
		}
		case 4:
		{
			int numero;
			cout << "Ingrese un número: ";
			cin >> numero;
			factores_primos(numero);
			break;
		}
		case 5:
		{
			int numero;
			cout << "Ingrese un número: ";
			cin >> numero;
			numero_abundante(numero);
			break;
		}
		case 6:
		{
			int tamano;
			cout << "Ingrese el tamaño del vector: ";
			cin >> tamano;
			float vector1[20];
			float vector2[20];
			float vector_resultante[20];
			cout << "Ingrese los datos del vector 1:\n";
			leer_vector(tamano, vector1);
			cout << "Ingrese los datos del vector 2:\n";
			leer_vector(tamano, vector2);
			sumar_restar_vectores(tamano, vector1, vector2, vector_resultante);
			imprimir_vector(tamano, vector_resultante);
			break;
		}
		case 7:
		{
			int tamano;
			cout << "Ingrese el tamaño del vector: ";
			cin >> tamano;
			float vector1[20];
			float vector2[20];
			cout << "Ingrese los datos del vector 1:\n";
			leer_vector(tamano, vector1);
			cout << "Ingrese los datos del vector 2:\n";
			leer_vector(tamano, vector2);
			cout << "Multiplicación: " << multiplicar_vectores(tamano, vector1, vector2) << endl;
			break;
		}
		case 8:
		{
			int tamano;
			cout << "Tamaño de la matriz cuadrada: ";
			cin >> tamano;
			int matriz[20][20];
			cout << "Valores de la matriz:\n";
			leer_matriz(tamano, tamano, matriz);
			int diagonal;
			cout << "Ingrese el número de diagonal que desea sumar: ";
			cin >> diagonal;
			while (diagonal >= tamano || diagonal <= tamano * -1) //ciclo que valida el ingreso de una diagonal existente
			{
				cout << "Diagonal inválida." << endl;
				cout << "Ingrese el número de diagonal que desea sumar: ";
				cin >> diagonal;
			}
			int suma = sumar_diagonal(diagonal, matriz, tamano);
			cout << "Suma: " << suma << endl;
			break;
		}
		case 9:
		{
			int inicio;
			int final;
			cout << "Incio del intervalo: ";
			cin >> inicio;
			cout << "Final del intervalo: ";
			cin >> final;
			primos_y_palindromos(inicio, final);
			break;
		}
		case 10:
		{
			int tamano;
			cout << "Ingrese el numero de filas: ";
			cin >> tamano;
			int matriz[20][20];
			triangulo_de_pascal(tamano, matriz);
			cout << matriz[0][0] << endl;
			int x = 1;
			while (x < tamano) //ciclo que recorre las filas del triangulo de pascal
			{
				cout << matriz[x][0] << " ";
				int y = 1;
				while (y < x) //ciclo que recorre los datos dentro de cada fila
				{
					cout << matriz[x][y] << " ";
					y++;
				}
				cout << 1 << endl;
				x++;
			}
			break;
		}
		case 11:
		{
			int numero;
			cout << "Ingrese un numero: ";
			cin >> numero;
			int buscar;
			cout << "Buscar: ";
			cin >> buscar;
			int nuevo;
			cout << "Reemplazar por: ";
			cin >> nuevo;
			int resultado = reemplazar(numero, buscar, nuevo);
			cout << "Resultado: " << resultado << endl;
			break;
		}
		case 12:
		{
			int grupo1;
			int grupo2;
			cout << "Conjunto 1: ";
			cin >> grupo1;
			cout << "Conjunto 2: ";
			cin >> grupo2;
			bool resultado = igualdad(grupo1, grupo2);
			if (resultado == true)
			{
				cout << "Iguales" << endl;
			}
			else
			{
				cout << "No iguales" << endl;
			}
			break;
		}
		case 13:
		{
			int filas;
			int columnas;
			cout << "Cantidad de filas: ";
			cin >> filas;
			cout << "Cantidad de comunas: ";
			cin >> columnas;
			int matriz[20][20];
			leer_matriz(filas, columnas, matriz);
			maximos_y_minimos(filas, columnas, matriz);
			break;
		}
		case 14:
		{
			string texto;
			cin.ignore(); //borra los datos que quedaron en el buffer del ingreso de datos anterior
			cout << "Ingrese una cadena de string: ";
			getline(cin, texto);
			extraer_numeros(texto);
			break;
		}
		case 15:
		{
			int tamano_palabras;
			int tamano_frases;
			cout << "Tamano del vector de palabras: ";
			cin >> tamano_palabras;
			cout << "Tamano del vector de frases: ";
			cin >> tamano_frases;
			string palabras[20];
			string frases[20];
			cout << "Ingrese los datos del vector de palabras: " << endl;
			int x = 0; //contador
			while (x < tamano_palabras)
			{
				cin.ignore();
				getline(cin, palabras[x]);
				cout << palabras[x] << endl;
				x++;
			}
			cout << "Ingrese los datos del vector de frases: " << endl;
			x = 0; //contador
			while (x < tamano_frases)
			{
				//cin.ignore();
				getline(cin, frases[x]);
				x++;
			}
			struct datos resultado = contar_palabras(palabras, frases,tamano_palabras,tamano_frases);
			x = 0;
			cout << "Resultados: " << endl;
			while (x < tamano_palabras)
			{
				cout << palabras[x] << ": " << resultado.vector[x] << endl;
				x++;
			}
			break;
		}
		case 16:
		{
			string con_u;
			string sub_u;
			cout << "Conjunto universo: " << con_u << endl;
			cin >> con_u;
			cout << "Subconjunto: " << sub_u << endl;
			cin >> sub_u;
			bool resultado=complemento(con_u, sub_u);
			if (resultado == 1)
				cout << "true" << endl << endl;
			else
				cout << "false" << endl << endl;
			break;
		}
		case 17:
		{
			string vector[20];
			x = -1;
			cout << "Ingrese los trozos del vector (ingrese fin cuando ya ingreso todos): ";
			do //ciclo para ingresar datos
			{
				x++;
				getline(cin, vector[x]);
			} while (vector[x] != "fin");
			string resultado[20];
			trozos_iguales(vector,resultado);
			int tamano = stoi(resultado[0]);
			int x = 1;
			cout << "Resultados: " << endl;
			while (x <= tamano) //ciclo para imprimir
			{
				cout << resultado[x] << endl;
				x++;
			}
			break;
		}	
		case 18:
		{
			x = 1;
			break;
		}
		default:
			cout << "Opción inválida\n";
		}
	}
	return 0;
}

//Definición de funciones


int sumatoria_cuadrados(int m, int n)
/*
Función: realizar la sumatoria de cuadrados.
Entradas: m (inicio de la sumatoria), n (final de la sumatoria).
Salidas: resultado de la sumatoria.
*/
{
	int suma = 0;
	for (m; m <= n; m++)
	{
		suma += (m*m);
	}
	return suma;
}

int multiplicatoria(int m, int n)
/*
Función: realizar una multiplicatoria.
Entradas: m (inicio de la multiplicatoria), n (final de la multiplicatoria).
Salidas: resultado de la multiplicatoria.
*/
{
	int total = 1;
	for (m; m <= n; m++)
	{
		total *= m;
	}
	return total;
}

int pares_amigables(int vector[])
/*
Función: retornar los pares amigables de una lista de números.
Entradas: vector con 10 números.
Salidas: pares de números amigables.
*/
{
	int total = 0; //contador para que solo se imprima "Pares amigables: " una vez
	int x = 0; //contador
	while (x<10)
	{
		int suma = suma_divisores(vector[x]);
		int y = x+1; //contador
		while (y<10)
		{
			if (suma == vector[y] && suma_divisores(vector[y]) == vector[x])
			{
				if (total == 0)
					cout << "Pares amigables:\n" << "\n";
				cout << vector[x] << " y " << vector[y] << endl;
				total++;
			}
			y++;
		}

		x++;
	}
		return 0;
}

int suma_divisores(int numero)
/*
Función: suma los divisores de un número.
Entradas: un número.
Salidas: suma de los divisores del número.
*/
{
	int suma = 0;
	int x = 1; //contador
	while (x < numero)
	{
		if ((numero % x) == 0)
			suma += x;
		x++;
	}
	return suma;
}

int factores_primos(int numero)
/*
Función: calcula los factores primos de un número.
Entradas: un número <=2.
Salidas: factores primos del número.
*/
{
	cout << "Calcular los factores primos de: " << numero << endl;
	int total = 0;
	while (numero > 1)
	{
		int x = 2; //contador
		while (x <= numero)
		{
			if (numero % x == 0)
			{
				if (suma_divisores(x)==1)
				{
					total++;
					if (total == 1)
						cout << x;
					else
						cout << "x" << x;
					numero /= x;
					break;
				}

			}
			x++;
		}
	}
	cout << "\n";
	return 0;
}

int numero_abundante(int numero)
/*
Funcion: determinar si un numero es abundante.
Entradas: numero.
Salidas: N/A.
*/
{
	cout << "Número para el cálculo: " << numero << endl;
	cout << "Divisores: ";
	int x = 1; //contador
	int total = 0;
	while (x <= numero)
	{
		if ((numero % x) == 0)
		{
			total++;
			if (total == 1)
				cout << x;
			else
				cout << ", " << x;
		}
		x++;
	}
	if ((suma_divisores(numero)+numero) > 2 * numero)
	{
		cout << "\n" << "Es abundante." << "\n";
		cout << "Abundancia: ";
		cout << suma_divisores(numero) - numero << endl;
	}
	else
	{
		cout << "\n" << "No es abundante." << "\n";
		cout << "Abundancia: No hay. \n";
	}
	return 0;
}

void leer_vector(int tam, float vector[])
/*
Función: leer los datos ingresados por el usuario y añadirlos a un vector.
Entradas: tamaño del vector, vector vacío para ser llenado.
Salidas: ninguna.
*/
{
	int x = 0; //contador
	while (x < tam)
	{ 
		cout << "Dato " << x+1 << " : ";
		cin >> vector[x];
		x++;
	}
	return;
}

void imprimir_vector(int tamano, float vector[])
/*
Función: imprime los datos de un vector.
Entradas: tamaño del vector, vector a imprimir.
Salidas: ninguna.
*/
{
	int x = 0; //contador
	int total = 0;
	cout << "Vector resultante:\n";
	while (x < tamano)
	{
		total++;
		if (total == 1)
			cout << vector[x];
		else
			cout << ", " << vector[x];
		x++;
	}
	cout << "\n" << "\n";
	return;

}

void sumar_restar_vectores(int tamano, float vector1[], float vector2[],float vector_resultante[])
/*
Función: sumar o restar dos vectores.
Entradas: tamaño del vector, vector 1, vector 2, vector resultante (vacío).
Salidas: ninguna.
*/
{
	int opcion;
	cout << "Operación (1.Sumar, 2.Restar): ";
	cin >> opcion;
	cout << endl;
	switch (opcion)
	{
		case 1:
		{
			int x = 0;
			while (x < tamano)
			{
				vector_resultante[x] = vector1[x] + vector2[x];
				x++;
			}
			break;
		}
		case 2:
		{
			int x = 0;
			while (x < tamano)
			{
				vector_resultante[x] = vector1[x] - vector2[x];
				x++;
			}
			break;
		}
		default:
			cout << "Opción inválida\n";
	}
	return;
}

int multiplicar_vectores(int tamano, float vector1[], float vector2[])
/*
Función: calcular el producto de 2 vectores.
Entradas: tamaño de los vectores, vector 1 y vector 2.
Salidas: producto de los vectores.
*/
{
	int x = 0;
	int suma = 0;
	while (x < tamano)
	{
		suma += vector1[x] * vector2[x];
		x++;
	}
	return suma;
}

void leer_matriz(int filas, int columnas, int matriz[20][20])
/*
Función: leer los datos ingresados por el usuario y añadirlos a una matriz.
Entradas : tamaño de la matriz, matriz vacía para ser llenada.
Salidas : ninguna.
*/
{
	int x = 0; //contador
	while (x < filas)
	{
		int y = 0; //contador
		while (y < columnas)
		{
			cout << "Fila " << x+1 << " Columna " << y+1 << " : ";
			cin >> matriz[x][y];
			y++;
		}
		x++;
	}
	return;
}

int sumar_diagonal(int diagonal, int matriz[20][20], int tamano)
/*
Funcion: sumar los numeros de una determinada diagonal en una matriz.
Entradas: diagonal, matriz, tamaño de la matriz.
Salidas: suma de la diagonal de la matriz.
*/
{
	int suma = 0;
	if (diagonal >= 0)
	{
		int x = 0; //contador
		while (diagonal < tamano)
		{
			suma += matriz[x][diagonal];
			x++;
			diagonal++;
		}
	}
	if (diagonal < 0)
	{
		diagonal *= -1; //convierte a la diagonal en un numero positivo para usarla como contador
		int x = 0; // contador
		while (diagonal < tamano)
		{
			suma += matriz[diagonal][x];
			x++;
			diagonal++;
		}
	}
	return suma;
}

int primos_y_palindromos(int inicio, int final)
/*
Funcion: encuentra los numeros que son primos y palindromos en un intervalo.
Entradas: inicio del intervalo, final del intervalo.
Salidas: N/A (no retorna nada, pero imprime los numeros primos y palindromos)
*/
{
	int total = 0;
	int d_inicio = convertir_binario_decimal(inicio);
	int d_final = convertir_binario_decimal(final);
	while (d_inicio < d_final)
	{
		if (suma_divisores(d_inicio) == 1)
		{
			int espejo = 0;
			int numero = d_inicio;
			while (numero>=1)
			{
				int digito = numero % 10;
				espejo = espejo * 10 + digito;
				numero /= 10;
			}
			if (espejo == d_inicio)
			{
				total++;
				cout << d_inicio << " es primo y palindromo." << endl;
			}
		}
		d_inicio++;
	}
	if (total == 0)
		cout << "NO HAY NÚMEROS CUYA REPRESENTACIÓN DECIMAL SEA UN PRIMO Y PALÍNDROMO A LA VEZ." << endl;
	return 0;
}

int convertir_binario_decimal(int numero)
/*
Funcion: convertir un numero binario a decimal.
Entradas: numero binario.
Salidas: representacion decimal del numero binario.
*/
{
	int resultado = 0;
	int x = 0;
	while (numero>=1)
	{
		if (numero % 10 == 1)
			resultado += pow(2, x);
		numero /= 10;
		x++;
	}
	return resultado;
}

void triangulo_de_pascal(int tamano, int matriz[20][20])
/*
Funcion: llenar una matriz con los numeros del triangulo de pascal.
Entradas: numero de filas del triangulo de pascal.
Salidas:no hay.
*/
{
	matriz[0][0] = 1;
	int x = 1;
	while (x < tamano)
	{
		matriz[x][0] = 1;
		int y = 1;
		while (y < x)
		{
			matriz[x][y] = matriz[x - 1][y - 1] + matriz[x - 1][y];
			y++;
		}
		matriz[x][x] = 1;
		x++;
	}
	return;
}

int reemplazar(int numero, int buscar, int nuevo)
/*
Funcion: reemplazar digitos en un numero.
Entradas: numero, digitos a reemplazar, nuevos digitos.
*/
{
	string snumero = to_string(numero);
	string sbuscar = to_string(buscar);
	string snuevo = to_string(nuevo);
	string resultado = to_string(numero); //iguala la variable resultado al numero ingresado.
	int x = 0;//contador
	while (x < (snumero.length())) //ciclo que recorre cada digito del numero.
	{
		int y = 0;
		if (snumero[x] == sbuscar[y]) // selector para saber si un dígito del numero coincide con el digito buscado.
		{
			int z = x;
			int total = 0; //variable para contar digitos iguales en el numero y en los digitos buscados.
			while (y < sbuscar.length()) //ciclo para contar digitos iguales en el numero y en los digitos buscados.
			{
				if (snumero[z] == sbuscar[y])
					total++;
				y++;
				z++;
			}
			if (total == sbuscar.length()) // selector que determina si el total de digitos iguales es igual al tamano de los digitos que se buscan.
			{
				resultado.erase(x, snumero.length()); //borra todos los digitos de la variable desde el primer digito buscado.
				snumero.erase(0, x+ sbuscar.length()); //borra todos los digitos de la variable desde inicio hasta el ultimo digito a reemplazar.
				y = 0;
				while (y < snuevo.length()) //ciclo para concatenar los nuevos digitos.
				{
					resultado+= snuevo[y];
					x++;
					y++;
				}
				resultado += snumero; // concatena los digitos que se encuentren en el numero despues de los digitos cambiados.
				int result = stoi(resultado); //cambia el string a int.
				return result;
			}
		}
		x++;
	}
}

bool igualdad(int grupo1, int grupo2)
/*
Funcion: determinar si dos conjuntos son iguales.
Entradas: conjuntos.
Salidas: booleano (true si son iguales, false si son diferentes).
*/
{
	string uno = to_string(grupo1);
	string dos = to_string(grupo2);
	int tamano = uno.size();
	if (uno.size() == dos.size())
	{
		int x = 0;
		int total = 0;
		while (x < uno.size())
		{
			int largo = uno.size();
			int y = 0;
			while (y < dos.size())
			{
				if (uno[x] == dos[y])
				{
					total++;
					dos.erase(y,1);
					uno.erase(x,1);
				}
				y++;
			}
			if (largo == uno.size())
				return false;
		}
		if (total == tamano)
			return true;
		else
			return false;
	}
	return false;
}

void maximos_y_minimos(int filas, int columnas, int matriz[20][20])
/*
Funcion: determinar los maximos y minimos de cada columna de una matriz.
Entradas: cantidad de filas, cantidad de columnas, matriz del tamano anterior.
Salidas: no hay.
*/
{
	int maximo = 0;
	int minimo = 0;
	int x = 0;
	cout << endl;
	while (x < filas) //ciclo que recorre todas las filas
	{
		maximo = 0;
		int y = 0;
		while (y < columnas)//ciclo para encontrar el maximo de una fila
		{
			if (matriz[x][y] > maximo)
				maximo = matriz[x][y];
			y++;
		}
		minimo = maximo;
		y = 0;
		while (y < columnas)// ciclo para encontrar el minimo de una fila
		{
			if (matriz[x][y] < minimo)
				minimo = matriz[x][y];
			y++;
		}
		cout << "Fila " << x+1 << " : maximo: " << maximo << " minimo: " << minimo << endl;
		x++;
	}
	cout << endl;
	x = 0;
	maximo = 0; // reinicializacion de variables
	minimo = 0;
	while (x < columnas) //ciclo que recorre todas las columnas
	{
		maximo = 0;
		int y = 0;
		while (y < filas) //ciclo para encontrar el maximo de una columna
		{
			if (matriz[y][x] > maximo)
				maximo = matriz[y][x];
			y++;
		}
		minimo = maximo;
		y = 0;
		while (y < filas) // ciclo para encontrar el minimo de una columna
		{
			if (matriz[y][x] < minimo)
				minimo = matriz[y][x];
			y++;
		}
		cout << "Columna " << x+1 << " : maximo: " << maximo << " minimo: " << minimo << endl;
		x++;
	}
	cout << endl;
}

void extraer_numeros(string texto)
/*
Funcion: extraer los numeros de una cadena de string.
Entradas: cadena de string.
Salidas: no hay.
*/
{
	int x = 0;
	int total = 0;
	cout << "Numeros encontrados: " << endl;
	while (x < texto.size()) //ciclo que recorre cada caracter de la cadena
	{
		if (isdigit(texto[x])) //selector para saber si el caracter es un digito
		{
			total++; //variable para saber a lo largo del recorrido se encontraron digitos
			string caracter;
			while (isdigit(texto[x])) //ciclo para concatenar los numeros seguidos en la cadena
			{
				caracter += texto[x];
				x++;
			}
			cout << caracter << endl;
			continue;
		}
		x++;
	}
	if (total == 0)
		cout << "Ninguno." << endl;
	cout << endl;
}

datos contar_palabras(string palabras[], string frases[], int tamano_palabras, int tamano_frases)
/*
Funcion: cuenta la cantidad de veces que aparece una palabra en una oracion.
Entradas: vector con las palabras para buscar, y vector con oraciones donde se cuentan las palabras.
Salidas: variable de tipo de dato "datos" que contiene un vector con la cantidad de apariciones de la palabra.
*/
{
	datos resultado;
	int x = 0;
	while (x < tamano_palabras) // ciclo que recorre el vector de palabras
	{
		string palabra = palabras[x]; //variable a la que se le asigna cada elemento del vector palabras
		int y = 0;
		while (y < tamano_frases) // ciclo que recorre el vector de frases
		{
			string frase = frases[y]; //variable a la que se le asigna cada elemento del vector frases
			int posicion = frase.find(palabra);
			if (posicion !=-1)
				resultado.vector[x]++;
			y++;
		}
		x++;
	}
	return resultado;
}

bool complemento(string universo, string subconjunto)
/*
Funcion: determinar el complemento de un conjunto.
Entradas: conjunto y subconjunto.
Salidas: booleano (true si tiene complemento, false si no tiene)
*/
{
	int total = 0;
	int x = 0;
	string sub = subconjunto;
	string uni = universo;
	while (x < uni.size()) //ciclo para determinar si el conjunto 2 es conjunto del conjunto universo
	{
		int y = 0;
		while (y < sub.size())
		{
			if (uni[x] == sub[y])
			{
				sub.erase(y, 0);
				total++;
			}
			y++;
		}
		x++;
	}
	if (total == subconjunto.size()) // selector en caso de que si sea subconjunto
	{
		sub = subconjunto;
		uni = universo;
		int x = 0;
		while (x < sub.size())
		{
			int posicion = uni.find(sub[x]);
			uni.erase(posicion,1);
			x++;
		}
		cout << "Complemento: " << uni << endl;
		return true;
	}
	else // en caso de que no sea subconjunto
	{
		sub = subconjunto;
		uni = universo;
		int x = 0;
		while (x < uni.size())
		{
			int y = 0;
			while (y<sub.size())
			{
				if (uni[x] == sub[y])
				{
					sub.erase(y, 1);
					y = 0;
					continue;
				}
				y++;
			}
			x++;
		}
		cout << "Simbolos que no estan en el conjunto universo: " << sub << endl;
		return false;
	}
}

void trozos_iguales(string vector[],string resultado[])
/*
Funcion: almacenar en un vector los trozos maximos de otro vector.
Entradas: vector con trozos de string.
Salidas: no hay.
*/
{
	int maximo = 0; //variable para el valor maximo de trozos iguales del vector
	int x = 1; //contador
	while (vector[x-1] != "fin")
	{
		int max = 1; //variable para el valor maximo de cada trozo (cantidad de veces que se repite el trozo analizado)
		while (vector[x] == vector[x - 1]) //ciclo que se ejecuta si un elemento es igual al anterior
		{
			max++;
			x++;
		}
		if (maximo < max)
			maximo = max;
		x++;
	}
	x = 1;
	int cantidad = 0; //variable para conocer el tamaño del vector resultado
	int y = 1;
	while (vector[x-1] != "fin")
	{
		int repeticiones = 1;
		int z = x-1;
		while (vector[x] == vector[x - 1]) //ciclo para contar la repeticiones de un trozo
		{
			repeticiones++;
			x++;
		}
		if (repeticiones == maximo)
		{
			int w = z + maximo;
			int s=z; // variable para que cuando el imprima el resultado no sobre una "," al final
			while (z < w)
			{
				if (s == z)
					resultado[y] += vector[z];
				else
				{
					resultado[y] += ',';
					resultado[y] += vector[z];
				}
				z++;
				
			}
			cantidad++;
			y++;
		}
		x++;
	}
	resultado[0] = to_string(cantidad); // asignacion del tamano del vector a la posicion 0 del vector
}
