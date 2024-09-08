#include <iostream>

using namespace std;

int main() {
    double times[999], time;
    int indices[999], i = 0;

    while (true) {
        cin >> time;

        if (time == -1)
            break;

        times[i] = time;
        indices[i] = i;  // Armazena o índice inicial
        i++;
    }

    cout << "Classificacao:" << endl;

    for (int f = 0; f < i; ++f) {
        for (int j = 0; j < i-f-1; ++j) {
            if (times[j] > times[j+1]) {
                // Troca de posição dos elementos no vetor times
                double tempTime = times[j];
                times[j] = times[j+1];
                times[j+1] = tempTime;

                // Troca de posição dos índices correspondentes
                int tempIndex = indices[j];
                indices[j] = indices[j+1];
                indices[j+1] = tempIndex;
            }
        }
    }
    
    for (int k = 0; k < i; k++) {
        cout << indices[k] << endl;  // Imprime os índices iniciais
    }

    return 0;

}
