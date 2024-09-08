#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Média do aluno
	
	double ep, mf;
    int pv1, pv2;

    cin >> pv1 >> pv2 >> ep;

    // Calcula a média final
    mf = (pv1+pv2) / 2 * 0.9 + ep * 0.1;

    // Mostra o valor da média final
    cout << fixed << setprecision(1) << mf;

    return 0;

}