#include<iostream>
using namespace std;

int main() {
    int v[10], N, i, X, pos = -1;

    cin >> N;

    for (i = 0; i < N; i++){
        cin >> v[i];
    }
 
    cin >> X;

    for (i = 0; i < N; i++)  
        if (X == v[i])
            pos = i;

    if (pos == -1)
        cout << "X nao existe em v." << endl;
    else 
        cout << "X esta na posicao: " << pos << endl;


    return 0;
}
