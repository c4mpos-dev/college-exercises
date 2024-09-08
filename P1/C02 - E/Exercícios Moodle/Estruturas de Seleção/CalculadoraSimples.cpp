#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Calculadora Simples
	
    double n1, n2;
    int op;

    cin >> n1 >> n2 >> op;
    
    //Verifica qual operação foi escolhida
    
    switch (op){
        case 1:
            cout << n1 + n2;
            break;
        case 2:
            cout << n1 - n2;
            break;
        case 3:
            cout << n1 * n2;
            break;
        case 4:
            //Verifica se a divisão é por 0
            if (n2 == 0){
                cout << "Erro" << endl;
                return 0;
            }
            else {
                cout << n1 / n2;
                break;
            }    
        default:
            cout << "Erro";
            break;
    }

    return 0;

}