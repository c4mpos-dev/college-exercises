#include<iostream>
using namespace std;

int insertionSort(int vet[], int tam) {
    for (int i = 1; i < tam; ++i) {
        int key = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] < key) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = key;
    }

    for (int k = 0; k < tam; k++)
        cout << vet[k] << " ";

    return 0;
}

int main () {
    int vet[100], i = 0, x;

    while (true){
        cin >> x;

        if (x == 0)
            break;
        else
            vet[i] = x;

        i++;
    }

    insertionSort(vet, i);
    
    return 0;
}