#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> fila;
    int valor;

    for (int i = 0; i < 4; i++) {
        cin >> valor;
        fila.push_back(valor); // Adiciona ao final da fila
    }

    for (auto it = fila.begin(); it != fila.end(); ++it) {
        cout << *it <<  " "; // Mostra o valor atual
    }
    cout << endl;

    return 0;
}