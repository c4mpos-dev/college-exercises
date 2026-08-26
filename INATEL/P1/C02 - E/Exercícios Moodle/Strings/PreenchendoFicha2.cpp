#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	
    string nome;
    char estado[3];
    int idade;

    cout << "Nome: ";
    getline(cin, nome);

    cout << "Estado: ";
    cin.getline(estado, 3);
    
    cout << "Idade: ";
    cin >> idade;
    
    cout << endl << "Nome: " << nome << endl;
    cout << "Estado: " << estado << endl;
    cout << "Idade: " << idade << endl;

    return 0;

}