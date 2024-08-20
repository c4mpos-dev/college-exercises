#include<iostream>
using namespace std;

int binaria(int vetor[],int tamanho, int x) {
    bool achou; // var aux p/ busca
    int baixo, meio, alto; // var aux

    baixo = 0;
    alto = tamanho-1;
    achou = false;

    while ((baixo <= alto) && (achou == false)) {
        meio = (baixo + alto) / 2;

        if (x < vetor[meio])
            alto = meio- 1;
        else
            if (x > vetor[meio])
                baixo = meio + 1;
            else
                achou = true;
    }

    if (achou)
        return meio;
    else
        return-1;
}

int main() {
    int vet[100], i, X, tam = 0;

    while (true){
        cin >> i;

        if (i == -1){
            break;
        }
        else{
            vet[i];
            tam++;
        }
    }

    cin >> X;

    int search = binaria(vet, tam, X);

    if (search == -1)
        cout << X << "nao encontrado" << endl;
    else
        cout << X << " encontrado na posicao " << search << endl;
}


