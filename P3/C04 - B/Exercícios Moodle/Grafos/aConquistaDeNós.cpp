#include <iostream>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int matriz[100][100] = {0};

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        matriz[A - 1][B - 1] = 1;
        matriz[B - 1][A - 1] = 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}