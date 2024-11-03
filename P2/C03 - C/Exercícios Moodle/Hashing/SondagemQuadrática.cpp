#include<iostream> 
using namespace std;

int hash_aux(int k, int m){
    int result = k % m;

    if (result < 0)
        result += m;
    
    return result;
}

int hash2(int k, int i, int m, int c1, int c2) {
    return (hash_aux(k, m) + (c1*i) + (c2*i*i)) % m;
}

int main() {
    int k, m, c1, c2;
    cin >> k >> m >> c1 >> c2;

    for (int i = 0; i < m; ++i) {
        int pos = hash2(k, i, m, c1, c2);
        cout << pos;
        if (i < m - 1) { cout << " "; }
    }

    return 0;
}