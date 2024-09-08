#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Salário
	
	int numeroFunc, qtdHoras;
    double valorHora, salario;
	
	cin >> numeroFunc >> qtdHoras >> valorHora;

	//Calcula o salário do funcionário
	salario = qtdHoras * valorHora;

    //Imprime o número do funcionário e seu salário(com uma precisão de 2 casas decimais)
	cout<< "NUMBER = " << numeroFunc << endl << "SALARY = U$ " << fixed << setprecision(2) << salario;
	
	return 0;
}