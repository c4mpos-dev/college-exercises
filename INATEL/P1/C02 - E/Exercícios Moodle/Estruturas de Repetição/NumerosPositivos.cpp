#include<iostream>

using namespace std;

int main() {

    double valor;
    int valoresPositivos = 0;

    for (int i = 0; i < 6; i++){
        cin >> valor;
        if (valor > 0)
            valoresPositivos += 1;
    }

    cout << valoresPositivos << " valores positivos" << endl;

    return 0;

}