#include<iostream>
using namespace std;

int bubbleSort(int vetor[], int tamanho) {
    int i,j, contador = 0; // contadores
    int trab;
    bool troca;
    int limite;
    troca = true;
    limite = tamanho-1;
    while (troca) {
        troca = false;
        for (i=0;i<limite;i++)
            if (vetor[i] > vetor[i+1]) {
                trab = vetor[i];
                cout << "New trab:" << trab << endl;
                vetor[i] = vetor[i+1];
                vetor[i+1] = trab;
                j = i;
                troca = true;
                contador++;
            }
        limite = j;
    }

    cout << "Contador:" << contador << endl;

    return 0;
}

int main() {
    int vet[100], i, tam = 0;

    cin >> tam;

    for (i = 0; i < tam; i++)
        cin >> vet[i];

    bubbleSort(vet, tam);

    return 0;
}