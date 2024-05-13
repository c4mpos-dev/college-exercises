#include<iostream>
#include<vector>

using namespace std;

int main(){

    // Defino o vetor com 999 posições mesmo que grande parte fique vazia, pois a matéria é algoritmos 1 e não posso utilizar funções vector, por exemplo.
    int nUser = 0, nContatos[999], nMaior, nMenor;

    do {
        cin >> nUser;
    }while(nUser < 0 || nUser > 1000);

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