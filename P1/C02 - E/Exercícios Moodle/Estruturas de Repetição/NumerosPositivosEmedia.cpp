#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    double valor, valorTotal = 0;
    int valoresPositivos = 0;

    for (int i = 0; i < 6; i++){
        cin >> valor;
        
        if (valor > 0){
            valoresPositivos += 1;
            valorTotal += valor;
        }
    }

    cout << valoresPositivos << " valores positivos" << endl;
    cout << fixed << setprecision(1);

    cout << valorTotal / valoresPositivos << endl;

    return 0;

}