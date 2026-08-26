#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N;

    cin >> N;

    int *v = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }

    double soma = 0.0;
    int *p = v; 

    for (int i = 0; i < N; i++) {
        soma += *p;
        p++;
    }

    double media = soma / N;

    cout << fixed << setprecision(2) << media << endl;

    delete[] v;

    return 0;
}