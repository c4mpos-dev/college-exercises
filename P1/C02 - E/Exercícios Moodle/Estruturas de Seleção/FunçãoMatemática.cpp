#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Função Matemática F(x,y)
	
    double x, y, fxy;

    cin >> x >> y;
    cout << fixed << setprecision(4);

    // Testa se o cálculo é possível
    if (x < 0 || y < 0){
        cout << "Erro; raiz numero negativo" << endl;
    }
    else if (pow(y,3) - sqrt(x) == 0){
        cout << "Erro; divisao por zero" << endl;
    }
    else {
        //Calcula e imprime F(x,y)
        fxy = (pow(x,3) - sqrt(y)) / (pow(y,3) - sqrt(x));
        cout << "f(x,y) = " << fxy << endl;
    }

    return 0;

}