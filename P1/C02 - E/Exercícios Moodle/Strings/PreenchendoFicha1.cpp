#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	
    string nome, cpf;
    int ano_nasc;

    cout << "Nome: ";
    getline(cin, nome);

    cout << "CPF: ";
    getline(cin, cpf);

    cout << "Nascimento: ";
    cin >> ano_nasc;
    
    cout << endl << "Nome: " << nome << endl;
    cout << "CPF: " << cpf << endl;
    cout << "Nascimento: " << ano_nasc << endl;

    return 0;

}