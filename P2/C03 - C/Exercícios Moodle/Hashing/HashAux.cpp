#include<iostream> 
using namespace std;

int hash_aux(int k, int m){
    int result = k % m;

    if (result < 0)
        result += m;
    
    return result;
}

int main() {
    int result, i = 0, k, m, vet[50];

    cin >> k >> m;

    while (k != 0 || m != 0){
        result = hash_aux(k, m);
        vet[i] = result;
        i++;
        cin >> k >> m;
    }
    
    for (int j = 0; j < i; j++)
        cout << vet[j] << endl;

    return 0;
}