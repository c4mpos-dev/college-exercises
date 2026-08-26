#include <iostream>
#include <list>
using namespace std;

int contar(list<int> lista) {
    int count = 0;
    for (int num : lista) {  
        count++;  
    }
    return count;
}

int main() {
    list<int> lista;  
    int valor;
    
    while (cin >> valor && valor != 0) {
        lista.push_back(valor);  
    }

    cout << contar(lista) << endl;

    return 0;
}