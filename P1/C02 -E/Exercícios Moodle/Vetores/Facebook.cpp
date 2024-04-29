#include<iostream>

using namespace std;

int main(){

    int nUser = 0, nMaior, nMenor;
    
    cin >> nUser;

    double nContatos[nUser];


    for (int i = 0; i < nUser; i++)
        cin >> nContatos[i];

    nMenor = nContatos[0];
    nMaior = nContatos[0];

    for (int i = 0; i < nUser; i++){
        if (nMenor > nContatos[i])
            nMenor = nContatos[i];
    }
        
    for (int i = 0; i < nUser; i++){
        if (nMaior < nContatos[i])
            nMaior = nContatos[i];
    }

    cout << "Menor numero de contatos: " << nMenor << endl;
    cout << "Maior numero de contatos: " << nMaior << endl;

}