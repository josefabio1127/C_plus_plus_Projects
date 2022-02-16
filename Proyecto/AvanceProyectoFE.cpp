//Directivas para el compilador
//funciona
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


int existen(vector<int>listaRandom, vector<int>listaResp){
    int existe=0;
    for(auto x:listaResp)
	{
        for(auto y: listaRandom)
		{
			if (x == y)
			{
				existe++;
				break;
			}
				
        }
    }
    return existe;
}

int analizar(vector<int>num_random, vector<int>numeros )
{
	int total = 0;
	int x = 0;
	while (x < 4)
	{
		if (numeros[x] == num_random[x])
			total++;
		x++;
	}
	return total;
}


int main()
{
	vector<int>num_random;
	int x = 0;
	srand(time(NULL));
	while (x < 4)
	{
		int num = 1 + rand() % (5 - 1);
		cout << num <<" ";
		num_random.push_back(num);
		x++;
	}
	bool y = false;
	while (y == false)
	{
		vector<int>numeros{};
		int i = 0;
		while (i < 4) {
			int num;
			cout << "Digite el numero: "; cin >> num;
			numeros.push_back(num);
			i++;
		}
		int existe = existen(num_random, numeros);
		cout << "Existen: " << existe << endl;
		int iguales = analizar(num_random, numeros);
		cout << "Correctos: " << iguales << endl;
		if (iguales == 4)
			y = true;
	}
}

