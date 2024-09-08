#include <iostream>
using namespace std;

int main()
{
	//Exercício Moodle Variação do preço
	
    double preco, qtdVenda;

    cin >> qtdVenda >> preco;
    
    //Verifica em qual caso o produto se enquadra e faz os cálculos de reajuste

    if (preco < 0 || qtdVenda < 0){
        cout << "Erro de entrada" << endl;
    }
    else if (qtdVenda == 0){
        preco *= 0.90;
        cout << "R$ " << preco << " - diminui preco" << endl;
    }
    else if (qtdVenda < 500)
    {
        cout << "R$ " << preco << " - sem reajuste" << endl;
    }
    else if (qtdVenda < 1000){
        preco *= 1.10;
        cout << "R$ " << preco << " - aumentou preco" << endl;
    }
    else{
        preco *= 1.15;
        cout << "R$ " << preco << " - aumentou preco" << endl;
    }
    
    return 0;
}