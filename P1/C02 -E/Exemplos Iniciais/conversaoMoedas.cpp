#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//Exemplos Iniciais com conversão de moedas

    double real, dolar, euro;

    cout << "Digite o valor em reais: " << endl;
    cin >> real;

    //Converte o valor para dólar e euro
    dolar = real / 4.95;
    euro = real / 5.4;

    //Imprime o valor em dólar e euro

    cout << "\nU$ " << dolar << endl;
    cout << "E " << fixed << setprecision(2) << euro;

	return 0;
}