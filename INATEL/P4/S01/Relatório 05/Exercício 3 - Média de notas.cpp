#include <iostream>
using namespace std;

int main() {
    int qtdNotas;
    float nota, soma = 0;

    cout << "Digite a quantidade de notas: ";
    cin >> qtdNotas;

    for (int i = 0; i < qtdNotas; i++) {
        cout << "Digite a nota " << (i + 1) << ": ";
        cin >> nota;

        while (nota < 0 || nota > 10) {
            cout << "Nota invalida! Digite novamente (0 a 10): ";
            cin >> nota;
        }

        soma += nota;
    }

    float media = soma / qtdNotas;

    cout << "Media final = " << media << endl;

    if (media >= 7) {
        cout << "Aprovado!" << endl;
    } else {
        cout << "Reprovado!" << endl;
    }

    return 0;
}