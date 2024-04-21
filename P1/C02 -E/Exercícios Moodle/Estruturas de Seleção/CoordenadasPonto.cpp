#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Coordenada de um ponto
	
    double x, y;

    cin >> x >> y;

    if (x == 0 && y == 0) {
        cout << "Origem" << endl;
    }
    else if (x == 0 || y == 0) {
        if (x == 0)
            cout << "Eixo Y" << endl;
        else 
            cout << "Eixo X" << endl;
    }
    // X positivo
    else if (x > 0) {
        if (y > 0)
            //Q1
            cout << "Q1" << endl;
        else 
            //Q4
            cout << "Q4" << endl;
    }
    // X negativo
    else if (x < 0){
        if (y > 0)
            //Q2
            cout << "Q2" << endl;
        else 
            //Q3
            cout << "Q3" << endl;  
    }
    
    return 0;

}