#include<iostream>

using namespace std;

int main() {

    int valor, valoresPares = 0;

    for (int i = 0; i < 5; i++){

        cin >> valor;

        if (valor % 2 ==  0)
            valoresPares += 1;

    }

    cout << valoresPares << " valores pares" << endl;

    return 0;

}