#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Função F(x,y)
	
    double x, y, f;

    cin >> x >> y;

    //Verifica as condições para o cálculo correto
    
    if (x > y){
        //Calcula a opção1
        f = pow(x,2) - pow(y,2) + (2 * x * y);

        //Mostra o resultado da opção1
        cout << "f(x,y) = " << f;
    }
    else if (x == y){
        //Calcula a opção2
        f = (2 * x * y) + x + y;

        //Mostra o resultado da opção2
        cout << "f(x,y) = " << f;
    }
    else {
        //Calcula a opção3
        f = pow(y,2) + pow(x,2) + (2 * x * y);

        //Mostra o resultado da opção3
        cout << "f(x,y) = " << f;
    }

    return 0;

}