#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Locadora D´vagar
	
    int TypeAuto, Ndays;
    double total;

    cin >> TypeAuto >> Ndays;

    switch (TypeAuto){
        case 1: 
            TypeAuto = 50;
            break;
        case 2:
            TypeAuto = 100;
            break;
        case 3: 
            TypeAuto = 150;
    }

    if (Ndays < 7){
        total = TypeAuto * Ndays;
    }
    else if (Ndays < 15){
        total = (TypeAuto * Ndays) * 0.95;
    }
    else{
        total = (TypeAuto * Ndays) * 0.9;
    }

    cout << fixed << setprecision(2);
    cout << total << endl;

    return 0;

}