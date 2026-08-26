#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); 

    string usuarios[N]; 
    bool seguidores[N][N] = {}; 

    for (int i = 0; i < N; i++) {
        getline(cin, usuarios[i]);
    }

    for (int i = 0; i < N; i++) {
        int seguidor;
        while (cin >> seguidor && seguidor != -1) {
            seguidores[seguidor][i] = true; 
        }
    }

    int consulta;
    cin >> consulta;

    for (int i = 0; i < N; i++) {
        if (seguidores[consulta][i]) {
            cout << usuarios[i] << endl;
        }
    }

    return 0;
}