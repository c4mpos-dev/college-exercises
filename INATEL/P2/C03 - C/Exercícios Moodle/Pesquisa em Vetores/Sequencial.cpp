#include <iostream>
using namespace std;

int buscaSequencial(int vetor[], int tamanho, int x) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int vetor[100];
    int tamanho = 0;
    int valor;

    while (true) {
        cin >> valor;
        if (valor == -1) 
            break;
        vetor[tamanho++] = valor;
    }

    int x;
    cin >> x;

    int resultado = buscaSequencial(vetor, tamanho, x);

    if (resultado != -1) {
        cout << x << " encontrado na posicao " << resultado << endl;
    } else {
        cout << x << " nao encontrado" << endl;
    }

    return 0;
}