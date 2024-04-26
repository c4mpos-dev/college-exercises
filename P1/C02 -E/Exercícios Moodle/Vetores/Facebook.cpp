#include<iostream>

using namespace std;

int main(){

    int nUser, nMaior = 0, nMenor = 0;
    
    cin >> nUser;

    double nContatos[nUser];

    for (int i = 0; i < nUser; i++){
        cin >> nContatos[i];
        
        if (nContatos[i] > nContatos[i-1] && nContatos[i] > nMaior)
            nMaior = nContatos[i];


        if (nContatos[i] < nContatos[i-1] && nContatos[i] < nMenor)
            nMenor = nContatos[i];
    }

    cout << "Menor numero de contatos" << nMenor << endl;
    cout << "Maior numero de contatos" << nMaior << endl;

}