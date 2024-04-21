#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Sinal elétrico
	
    double t, xt;
    cin >> t;

    if (t < -1 || t > 1){
        cout << "x(t) = 0" << endl;
    }
    else{
        //Calcula e imprime x(t)
        xt = 1 - abs(t);
        cout << "x(t) = " << xt << endl;
    }
    
    return 0;

}