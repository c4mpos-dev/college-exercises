#include <iostream>
using namespace std;

int main()
{
	//Exercício Moodle Aposentadoria?
	
    double idade, tempoContribuicao;

    cin >> idade >> tempoContribuicao;

    //Vê em qual caso a pessoa se enquadra e mostra na tela
    
    if (idade >=  60 && tempoContribuicao >= 30){
        cout << "Qualificado" << endl;
    }
    else if (idade >= 65 || tempoContribuicao >= 35){
        cout << "Qualificado" << endl;
    }
    else {
        cout << "Nao qualificado" << endl;
    }

    return 0;
}