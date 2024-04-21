#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Análise de Circuitos
	
    double v, r1, r2, r3, Itotal, Requivalente;

    cin >> v >> r1 >> r2 >> r3;

    //Calcula a corrente total e resistência equivalente
    Itotal = v * ((1 / r1) + (1 / r2) + (1 / r3));
    Requivalente = 1 / ((1 / r1) + (1 / r2) + (1 / r3));

    //Imprime o valor de Itotal e Requivalente
    cout << Itotal << endl << Requivalente;

    return 0;

}