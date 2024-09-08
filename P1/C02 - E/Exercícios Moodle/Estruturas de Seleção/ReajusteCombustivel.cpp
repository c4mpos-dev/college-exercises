#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Reajuste Combustível
	
    double Pgas, Peta, Vgas, Veta;

    cin >> Pgas >> Peta >> Vgas >> Veta;
    cout << fixed << setprecision(2);

    if (Vgas > 2*Veta){
        Pgas *= 1.2;
        Peta *= 0.9;
        cout << "R$ " << Pgas << "  R$ " << Peta << endl; 
    }
    else if ( Vgas == 2*Veta){
        Pgas *= 1.1;
        Peta *= 0.9;
        cout << "R$ " << Pgas << "  R$ " << Peta << endl; 
    }
    else{
        Pgas *= 0.9;
        Peta *= 1.2;
        cout << "R$ " << Pgas << "  R$ " << Peta << endl; 
    }
    
    return 0;

}