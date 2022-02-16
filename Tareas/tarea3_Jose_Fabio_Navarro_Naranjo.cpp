// tarea3_Jose_Fabio_Navarro_Naranjo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.

//Directivas para el compilador
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#pragma warning(disable:4996) // Directiva para evitar que se genere la advertencia 4996

using namespace std;

//Constantes globales
const string tipos_de_arduino[] = {"UNO","TRE","Zero","Zero Pro","BT","Mega","Ethernet","Pro","Pro Mini","Micro","Primo","Nano","Industrial 101","LilyPad","Esplora" };

//Definición de Estructuras
struct produccion {
	string arduino="";
	int cantidad=0;
};

//Prototipos de funciones
void insertar_producto(string, int, vector<produccion> &);
void consultar_producto(string, vector<produccion>);
void eliminar_producto(string, int, vector<produccion> &);
void produccion_total(vector<produccion>);
void consultar_arduinos();
void encabezado();

//Programa principal
int main()
{
	encabezado(); // llamado a la funcion que imprime la fecha, hora y demas
	vector<produccion>vector_produccion; 
	int x = 0; // variable que sirve de condicion para el while
	int y = 0; // contador para imprimir (a partir de la segunda vez que se muestra el menu) una linea de guiones para separar el menu actual de la accion anterior
	while (x == 0)
	{
		if (y>0) // selector para imprimir (a partir de la segunda vez que se muestra el menu) una linea de guiones para separar el menu actual de la accion anterior
			cout << setw(66) << setfill('-') << '\n' << setfill(' ');
		y++;
		int opcion;
		cout << right << setw(20) << " " << "PRODUCCION DE ARDUINOS\n"; 
		cout << right << setw(22)<< " " << "CONTROL DE PEDIDOS\n" << endl;
		cout << "1 - Insertar pedido de produccion" << endl;
		cout << "2 - Consultar produccion de un arduino" << endl;
		cout << "3 - Eliminar pedido de produccion" << endl;
		cout << "4 - Consultar tipos de arduinos que puede producir la fabrica" << endl;
		cout << "5 - Consultar produccion total" << endl;
		cout << "0 - Fin" << endl;
		cout << "Opcion seleccionada: ";
		cin >> opcion;
		cout << endl;
		switch (opcion)
		{
		case 1:
		{
			string tipo;
			int cantidad;
			cout << "Ingrese el tipo de arduino: ";
			cin.ignore();
			getline(cin, tipo, '\n');
			cout << "Ingrese la cantidad: ";
			cin >> cantidad;
			insertar_producto(tipo, cantidad, vector_produccion); //llamado a la funcion que inserta los datos en el vector
			break;
		}
		case 2:
		{
			string buscar;
			cout << "Inserte el arduino a buscar: ";
			cin.ignore();
			getline(cin, buscar, '\n');
			consultar_producto(buscar, vector_produccion); //llamado a la funcion que despliega los datos de una seccion especifica del vector
			break;
		}
		case 3:
		{
			string tipo;
			int cantidad;
			cout << "Ingrese el tipo de arduino que desea eliminar: ";
			cin.ignore();
			getline(cin, tipo, '\n');
			cout << "Ingrese la cantidad que desea eliminar: ";
			cin >> cantidad;
			eliminar_producto(tipo, cantidad, vector_produccion); // llamado a la funcion para restar/eliminar datos del vector
			break;
		}
		case 4:
			consultar_arduinos(); // llamado a la funcion que despliega los datos del array tipos_de_arduino[]
			break;
		case 5:
			produccion_total(vector_produccion); // llamado a la funcion que despliega por completo los datos del vector de produccion
			break;
		case 0:
			x = 1;
			break;
		default:
			break;
		}
	}
}

//Defincion de funciones

void encabezado() 
/*
Funcion: desplegar la fecha y la hora.
Entradas: N/A
Salidas:  N/A
*/
{
	time_t actual = time(0);
	tm* time = localtime(&actual);
	vector<int> meses = { 31,28,31,30,31,30,31,31,30,31,30,31 }; //vector con la cantidad de dias de todos los mese del año
	int dia = time->tm_yday;
	int m = 0;
	while (true) //ciclo para encontrar el dia especifico del mes
	{
		if (dia - meses[m] < 0)
			break;
		else
			dia -= meses[m];
		m++;
	}
	int hora = time->tm_hour;
	string tipo = "AM";
	if (hora > 12) // selector para cambiar la hora de formato de 24h a formato de 12h
	{
		hora -= 12;
		tipo = "PM";
	}
	cout << left << setw(15) << "Fabrica de Arduinos" <<
		right << setw(24) << dia + 1 << "/" << time->tm_mon + 1 << "/" << time->tm_year + 1900 << "  -  " <<
		hora << ":" << time->tm_min << ":" << time->tm_sec << tipo << endl << endl;
}

void insertar_producto(string tipo, int cantidad, vector <produccion> &vector_produccion)
/*
Funcion: insetar datos en el vector de produccion
Entradas: tipo de arduino, cantidad de unidades y vector de produccion
Salidas: N/A
*/
{
	int total = 0; //contador para recorrer el array tipos_de_arduino[]
	int l = 0; // contador para verificar que el tipo de arduino ingresado se encuentre en el array tipos_de_arduino[]
	for (string arduino : tipos_de_arduino)
	{
		if (tipo == tipos_de_arduino[total])
		{
			l++;
			break;
		}
		total++;
	}
	if (l == 1) //selector para saber si el tipo de arduino ingresado se encuentre en el array tipos_de_arduino[]
	{
		int contador = -1; //contador para agregar los datos modificados al vector
		for (produccion elemento : vector_produccion) //ciclo que recorre el vector de produccion
		{
			contador++;
			if (elemento.arduino == tipo) //selector para saber si el elemento del vector es igual al arduino buscado
			{
				elemento.cantidad += cantidad;
				vector_produccion[contador].cantidad = elemento.cantidad;
				cout << "\nIngresado correctamente." << endl << endl;
				return;
			}
		}
		//estas instrucciones se ejecutan en caso de el tipo de arduino no se haya encontrado en el vector de produccion (nuevo dato)
		produccion product;
		product.arduino = tipo;
		product.cantidad = cantidad;
		vector_produccion.push_back(product);
		cout << "Ingresado correctamente." << endl << endl;
	}
	else
		cout << "El arduino ingresado no existe."<<endl<<endl;
}

void consultar_producto(string buscar, vector <produccion> vector_produccion)
/*
Funcion: desplegar datos especificos del vector de produccion
Entradas: tipo de arduino a desplegar y vector de produccion
Salidas: N/A
*/
{
	for (produccion elemento : vector_produccion) //ciclo que recorre el vector de produccion
	{
		if (elemento.arduino == buscar) //selector para encontrar el arduino buscado
		{
			cout << "Tipo: " << "Arduino " << elemento.arduino << endl;
			cout << "Cantidad: " << elemento.cantidad << endl<<endl;
			return;
		}
	}
	cout << "El elemento buscado no se encuentra en inventario." << endl<<endl;
}

void eliminar_producto(string tipo, int cantidad, vector<produccion> &vector_produccion)
/*
Funcion: eliminar/restar datos al vector dew produccion
Entradas: tipo de arduino, cantidad a eliminar/restar y vector de produccion
Salidas: N/A
*/
{
	int total = -1; //contador para agregar los datos modificados al vector
	for (produccion elemento : vector_produccion) // ciclo que recorre el vector de produccion
	{
		total++;
		if (elemento.arduino == tipo) //selector para saber si el elemento del vector es igual al arduino buscado
		{
			if (elemento.cantidad < cantidad) //selector para saber si la cantidad del elemento del vector es menor a la del arduino buscado
			{
				cout << "Error, no existe la cantidad de unidades a eliminar." << endl<<endl;
				return;
			}
			elemento.cantidad -= cantidad;
			vector_produccion[total].cantidad = elemento.cantidad;
			if (elemento.cantidad == 0) //selector para saber si el elemento quedo con cantidad 0
				vector_produccion.erase(vector_produccion.begin()+total);
			cout << "Eliminado correctamente." << endl << endl;
			return;
		}
	}
	cout << "El elemento buscado no se encuentra en inventario." << endl << endl;;
}

void consultar_arduinos()
/*
Funcion: desplegar los datos del array tipos_de_arduino[]
Entradas: N/A
Salidas: N/A
*/
{
	int x = 0;
	int tamano = sizeof(tipos_de_arduino) / sizeof(string); ///operacion para saber cuantos elementos hay en rl array
	cout << "Arduinos de la Fabrica" << endl<<endl;
	while(x<tamano) //ciclo que recorre el array tipos_de_arduino[]
	{
		cout << "Arduino " << tipos_de_arduino[x] << endl;
		x++;
	}
	cout << endl;

}

void produccion_total(vector<produccion> vector_produccion)
/*
Funcion: desplegar todos los datos del vector de produccion
Entradas: vector de produccion
Salidas: N/A
*/
{
	int total=0; //variable para alamcenar la cantidad de unidades a producir
	for (produccion elemento : vector_produccion) //ciclo para contar las unidades a producir
		total += elemento.cantidad;
	cout << setw(46) << setfill('-') << '\n' << setfill(' '); //linea de guiones
	cout << left << setw(25) << "Tipo" << right << setw(10) << "Cantidad" << right << setw(15) << "Porcentaje" << endl << endl;
	for (produccion elemento : vector_produccion) //ciclo que recorre el vector de produccion
	{
		float porcentaje = elemento.cantidad * 100 / total;
		string tipo = "Arduino " + elemento.arduino;
		cout << left << setw(25) << tipo << right << setw(10) << elemento.cantidad << right << setw(15) << porcentaje <<endl;
	}
	cout << setw(46) << setfill('-') << '\n' << setfill(' ');
	cout << left << setw(25) << "Total a producir" << right << setw(10) << total << right << setw(15) << 100 << endl << endl;
}
