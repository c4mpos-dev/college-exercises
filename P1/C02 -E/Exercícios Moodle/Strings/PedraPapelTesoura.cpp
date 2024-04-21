#include <iostream>
#include <string>

using namespace std;

int main() {

    int T;

    cin >> T; 

    for (int t = 0; t < T; ++t) {
        string jogadorA, jogadorB;
        cin >> jogadorA >> jogadorB;

        if (jogadorA == jogadorB) {
            cout << "Empate" << endl;
        } else if ((jogadorA == "pedra" && jogadorB == "tesoura") ||
                   (jogadorA == "tesoura" && jogadorB == "papel") ||
                   (jogadorA == "papel" && jogadorB == "pedra")) {
            cout << "Jogador A" << endl;
        } else {
            cout << "Jogador B" << endl;
        }
    }

    return 0;
}
