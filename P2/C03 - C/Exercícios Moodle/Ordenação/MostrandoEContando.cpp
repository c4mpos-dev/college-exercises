#include<iostream>
using namespace std;

void bubbleSort(int vetor[], int tamanho)
 {
    int i,j,k=0; // contadores
    int trab,vetTrab[100];
    bool troca;
    int limite;

    troca = true;
    limite = tamanho-1;
    while (troca) {
        troca = false;
        for (i=0;i<limite;i++)
            if (vetor[i] > vetor[i+1]) {
                trab = vetor[i];
                vetTrab[i] = trab;
                vetor[i] = vetor[i+1];
                vetor[i+1] = trab;
                j = i;
                troca = true;
                k++;
            }
        limite = j;
    }

    // return vetTrab[], k;
 }

int main() {
    int vet[100], i, X, tam = 0;

    cin >> tam;

    for (i = 0; i < tam; i++)
        cin >> vet[i];

    // int search = binaria(vet, tam, X);

    // if (search == -1)
    //     cout << "Nao possui acesso" << endl;
    // else
    //     cout << "Possui acesso" << endl;
}