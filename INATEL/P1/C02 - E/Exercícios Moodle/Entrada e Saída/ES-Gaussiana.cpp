#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Gaussiana
	
	double x, m, s, fx, pi = 3.14159;

    cin >> x >> m >> s;

    // Calcula f(x)
    fx = (1 / sqrt(2*pi*pow(s,2))) * exp(- pow((x - m), 2) / (2 * pow(s, 2)));

    // Mostra o valor de f(x)
    cout << fixed << setprecision(4) << fx;

    return 0;

}