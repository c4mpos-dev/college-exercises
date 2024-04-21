#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Função Y(x)
	
    double x, y;

    cin >> x;

    //Calcula a função Y
    y = sqrt(1 / (1 + pow(x,2)));

    //Imprime o valor de Y
    cout << fixed << setprecision(4) << "y = " << y;

    return 0;
}