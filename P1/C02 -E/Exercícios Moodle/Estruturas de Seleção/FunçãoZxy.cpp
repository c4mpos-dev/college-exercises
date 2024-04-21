#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Função Z(x,y)
	
    double x, y, z;

    cin >> x >> y;

    //Verifica se x e y possuem condições de cálculo
    
    if (x - y >= 0 && x + y > 0){
        //Calcula o z
        z = sqrt(x - y) / sqrt(x + y);

        //Mostra o resultado
        cout << "Z = " << z << endl;
    }
    else {
        cout << "Calculo Impossivel." << endl;
    }

    return 0;

}