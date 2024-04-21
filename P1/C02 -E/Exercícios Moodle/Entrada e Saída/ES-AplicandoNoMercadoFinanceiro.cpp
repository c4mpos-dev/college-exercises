#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Aplicando no mercado financeiro
	
	double capitalInicial, taxaJuros, montante, lucro;
    int tempoAplicacao;

    cin >> capitalInicial >> taxaJuros >> tempoAplicacao;

    // Calcula o montante e lucro

    montante = capitalInicial * pow((1 + (taxaJuros / 100)), tempoAplicacao);
    lucro = montante - capitalInicial;

    // Imprime o lucro
    cout << "LUCRO = " << fixed << setprecision(2) << lucro;
	
	return 0;
}