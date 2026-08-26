#include<iostream>
#include<string>

using namespace std;

int main() {

    string x[5], name;
    int t = 0, position;

    //Adiciona cada entrada nos índices da lista x
    for (int i = 0; i < 5; i++)
        getline(cin, x[i]);
    
    //Imprime cada valor no índice da lista x
    for (int i = 0; i < 5; i++)
        cout << x[i] << endl;

    cout << endl;

    getline(cin, name);

    //Verifica se o nome está na lista (nesse caso não há dois nomes iguais)
    for (int i = 0; i < 5; i++)
        if (x[i] == name){
            t = 1;
            position = i;
        }
    
    if (t == 0)
        cout << "Nome nao encontrado" << endl;
    else {
        cout << "Nome encontrado" << endl;
        cout << "Posicao do nome: " << position << endl;
    }

    return 0;

}