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
    int maior = *p;

    for (int i = 0; i < N; i++) {
        if (*p > maior) 
            maior = *p; 
        p++;
    }
    
    cout << maior << endl;

    delete[] v;

    return 0;
}