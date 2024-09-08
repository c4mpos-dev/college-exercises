#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
	
    string nome;
    double salario;
    int matricula;

    cin >> matricula;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nome);

    cin >> salario;

    if (salario <= 3000){
        cout << "R$ " << salario * 1.1;
    }
    else if (salario <= 5000){
        cout << "R$ " << salario * 1.05;
    }
    else {
        cout << "R$ " << salario;
    }

    return 0;

}