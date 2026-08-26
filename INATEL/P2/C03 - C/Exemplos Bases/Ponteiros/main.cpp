#include<iostream>
using namespace std;

int main () {
    int *vetor = NULL;
    int N;
    int i;

    cin >> N;

    vetor = new int[N];

    vetor[0] = 2;
    vetor[1] = 3;
    vetor[2] = 7;
    vetor[3] = 5;

    for (i = 0; i < N; i++)
        cout << vetor[i] << endl;

    delete [] vetor;

    return 0;
}