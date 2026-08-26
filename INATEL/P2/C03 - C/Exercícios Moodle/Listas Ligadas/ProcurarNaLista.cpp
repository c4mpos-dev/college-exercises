#include <iostream>
#include <list>
using namespace std;

bool encontrar(list<int> lista, int x) {
    for (int num : lista) {  
        if (num == x) {
            return true;  
        }
    }
    return false;  
}

int main() {
    list<int> lista;  // Lista ligada para armazenar os números
    int valor;
    
    while (cin >> valor && valor != 0) {
        lista.push_back(valor);  
    }

    int numPesquisa;
    cin >> numPesquisa;  // Número a ser pesquisado na lista

    if (encontrar(lista, numPesquisa)) {
        cout << "Encontrado" << endl;
    } else {
        cout << "Nao encontrado" << endl;
    }

    return 0;
}