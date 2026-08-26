#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    int *v = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    int *p = v;
    int contagem = 0;

    for (int i = 0; i < N; i++) {
        if (*p > 0 && *p % 2 == 0) 
            contagem++;
        p++;
    }

    cout << contagem << endl;

    delete[] v;

    return 0;
}