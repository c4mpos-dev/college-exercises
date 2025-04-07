#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> pilha;
    int valor;

    for (int i = 0; i < 4; i++) {
        cin >> valor;
        pilha.push_back(valor); // Adiciona ao final da lista
    }

    while (!pilha.empty()) {
        cout << pilha.back() << " "; // Mostra o elemento do topo
        pilha.pop_back();     // Remove o elemento do topo
    }
    cout << endl;

    return 0;
}