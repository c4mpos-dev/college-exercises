#include <iostream>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

int main()
{
	
    string nome, tipo;
    double media; 
    int matricula, np1, np2;

    cout << "Matricula: ";
    cin >> matricula;

    cout << "Nome: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nome);

    cout << "Tipo ('A' ou 'B'): ";
    getline(cin, tipo);

    cout << "Notas: ";
    cin >> np1 >> np2;

    media = (np1 + np2) / 2.0;

    cout << "Matricula: " << matricula << endl;
    cout << "Media: " << media << endl;

    return 0;

}