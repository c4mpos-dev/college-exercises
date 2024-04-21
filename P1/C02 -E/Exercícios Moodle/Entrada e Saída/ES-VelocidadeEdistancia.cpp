#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Velocidade e distância
	
    double v0, s0, a, t, v, s;

    cin >> v0 >> s0 >> a >> t;

    //Calcula a velocidade e distância

    v = v0 + a * t;
    s = s0 + v0*t + 0.5 * a * pow(t, 2);
	
    //Imprime os valores de v e s

    cout << fixed << setprecision(1);
    cout << "V = " << v << endl;
    cout << "S = " << s << endl;

    return 0;

}