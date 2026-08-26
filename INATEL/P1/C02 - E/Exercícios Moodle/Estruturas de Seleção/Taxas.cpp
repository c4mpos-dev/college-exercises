#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Taxas
	
    double salario, valorContado, imposto;

    cin >> salario;

    valorContado = salario - 2000;

    if (salario <= 2000){
        cout << "Isento" << endl;
    }
    else {
        if (valorContado <= 1000)
            imposto = valorContado * 0.08;
        
        else if (valorContado <= 2500)
            imposto = 80 + ((valorContado - 1000) * 0.18);
        
        else 
            imposto = 80 + 270 + ((valorContado - 2500) * 0.28);

        cout << fixed << setprecision(2);
        cout << "R$ " << imposto << endl;
    }

    return 0;

}