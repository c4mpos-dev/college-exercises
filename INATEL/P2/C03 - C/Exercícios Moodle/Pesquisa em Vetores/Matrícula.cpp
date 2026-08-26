#include<iostream>
using namespace std;

int binaria(string vetor[],int tamanho, string x) {
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

struct Aluno {
    string nome;
    string curso;
    string matricula;
};

void insertionSort(string vet[], int tam) {
    for (int i = 1; i < tam; ++i) {
        string key = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }
}

int main() {
    Aluno alunos[10000];
    int qtdAlunos;
    string nome, alunosNomes[10000];

    cin >> qtdAlunos;
    cin.ignore();

    for (int i = 0; i < qtdAlunos; ++i) {
        getline(cin, alunos[i].nome);
        getline(cin, alunos[i].curso);
        getline(cin, alunos[i].matricula);
    }

    for (int l = 0; l < qtdAlunos; l++)
        alunosNomes[l] = alunos[l].nome;

    insertionSort(alunosNomes, qtdAlunos);

    getline(cin, nome);

    int search = binaria(alunosNomes, qtdAlunos, nome);

    if (search != -1) {
        for (int i = 0; i < qtdAlunos; i++) {
            if (alunos[i].nome == alunosNomes[search]) {
                cout << alunos[i].nome << endl;
                cout << alunos[i].curso << endl;
                cout << alunos[i].matricula << endl;
                break;
            }
        }
    } else {
        cout << "Aluno nao localizado" << endl;
    }

    return 0;
}