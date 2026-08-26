#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Bhaskara
	
    double a, b, c, r1, r2;

    cin >> a >> b >> c;

    if (a == 0 || pow(b,2) - (4 * a * c) < 0) {
        cout << "Impossivel calcular" << endl;
    }
    else{
        r1 = (-b + sqrt(pow(b,2) - (4*a*c))) / (2 * a);
        r2 = (-b - sqrt(pow(b,2) - (4*a*c))) / (2 * a);
        cout << fixed << setprecision(5);
        cout << "R1 = " << r1 << endl << "R2 = " << r2 << endl;
    }

    return 0;

}