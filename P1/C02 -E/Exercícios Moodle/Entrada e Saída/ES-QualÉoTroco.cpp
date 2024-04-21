#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	//Exercícios Moodle - ES-Qual é o troco?

    float dinheiroZezinho, valorCompra, troco;

    cin >> dinheiroZezinho >> valorCompra;
 
    //Calcula o valor do troco do Zezinho
    troco = dinheiroZezinho - valorCompra;

    //Imprime o valor do troco de Zezinho
    cout << "TROCO = " << fixed << setprecision(2) << troco;

	return 0;
}