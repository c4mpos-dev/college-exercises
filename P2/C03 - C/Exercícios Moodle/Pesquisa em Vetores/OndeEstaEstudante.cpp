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
        return - 1;
}

int main() {
    int mat[10000], qtdAlunos, X;

    cin >> qtdAlunos;

    for (int i = 0; i < qtdAlunos; i++)
        cin >> mat[i];

    cin >> X;

    int search = binaria(mat, qtdAlunos, X);

    if (search == -1)
        cout << "Nao localizado" << endl;
    else
        cout << "Corredor " << search << endl;
}