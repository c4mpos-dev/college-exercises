#include <iostream>
#include <iomanip>
#include<string>

using namespace std;

int main()
{
	
    string nome, listaNomes;
    int idade, nJog, mais18 = 0;

    cin >> nJog;
    
    while (nJog <= 0){
        cin >> nJog;
    }

    for (int i = 0; i < nJog; i++){

        cin.ignore();
        getline(cin,nome);
        
        cin >> idade;

        if (idade >= 18){
            listaNomes += nome + " " + to_string(idade) + "\n";
            mais18 += 1;
        }
    }

    if (mais18 == 0)
        cout << endl  << "Nenhum jogador com 18 anos ou mais" << endl << endl;
    else
        cout << endl  << listaNomes << endl << endl;

    return 0;

    /*

    cout << "Digite o numero de jogadores: ";
    cin >> nJog;
    
    while (nJog <= 0){
        cout << "Numero invalido, digite novamente: ";
        cin >> nJog;
    }

    for (int i = 0; i < nJog; i++){

        cout << "Digite o nome do jogador: ";
        cin.ignore();
        getline(cin,nome);
        
        cout << "Digite a idade do jogador: ";
        cin >> idade;

        if (idade >= 18){
            listaNomes += nome + " " + to_string(idade) + "\n";
            mais18 += 1;
        }
    }

    if (mais18 == 0)
        cout << endl  << "Nenhum jogador com 18 anos ou mais" << endl << endl;
    else
        cout << endl  << listaNomes << endl << endl;

    return 0;

    */

}