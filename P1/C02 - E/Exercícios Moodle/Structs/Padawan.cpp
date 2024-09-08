#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Padawan {
    string nome;
    int pontos;
};

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Limpar o buffer após ler o inteiro

    Padawan padawans[1000];
    int soma_pontos = 0;
    string melhor_padawan_nome;
    int melhor_padawan_pontos = 0;

    for (int i = 0; i < N; i++) {
        // Ler o nome usando getline() para permitir espaços em branco
        getline(cin, padawans[i].nome);

        cin >> padawans[i].pontos;
        cin.ignore(); // Limpar o buffer após ler o inteiro

        soma_pontos += padawans[i].pontos;

        if (padawans[i].pontos > melhor_padawan_pontos) {
            melhor_padawan_nome = padawans[i].nome;
            melhor_padawan_pontos = padawans[i].pontos;
        }
    }

    double media = (soma_pontos * 1.00) / (N * 1.00);

    cout << "Padawan com mais pontos: " << melhor_padawan_nome << endl;
    cout << "Pontos: " << melhor_padawan_pontos << endl;
    cout << fixed << setprecision(2) << "Media da turma: " << media << " pontos" << endl;

    return 0;
}
