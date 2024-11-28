#include <iostream>
#include <list>
using namespace std;

int soma(list<int> lista) {
    int total = 0;
    for (int num : lista) {  
        total += num;  
    }
    return total;
}

int main() {
    list<int> lista;  
    int valor;
    
    while (cin >> valor && valor != 0) {
        lista.push_back(valor);  
    }

    cout << soma(lista) << endl;

    return 0;
}