#include <iostream>
#include <iomanip>
using namespace std;

float ideal(float h, char sexo) {
    if (sexo == 'M' || sexo == 'm') {
        return 72.7 * h - 58;
    } else if (sexo == 'F' || sexo == 'f') {
        return 62.1 * h - 44.7;
    } else {
        cout << "Sexo inválido." << endl;
        return -1; // Retorno inválido para indicar erro
    }
}

int main() {
    float altura;
    char sexo;

    cin >> altura >> sexo;

    cout << fixed << setprecision(2);

    float peso_ideal = ideal(altura, sexo);
    if (peso_ideal != -1) {
        cout << "Peso ideal = " << peso_ideal << " kg" << endl;
    }

    return 0;
}
