#include<iostream> 
using namespace std;

int hash_aux(int k, int m){
    int result = k % m;

    if (result < 0)
        result += m;
    
    return result;
}

int hash1(int k, int i, int m) {
    return (hash_aux(k, m) + i) % m;
}

int main() {
    int k, m;

    cin >> k >> m;

    for (int i = 0; i < m; ++i) {
        int position = hash1(k, i, m);
        cout << position << " ";
    }

    return 0;
}