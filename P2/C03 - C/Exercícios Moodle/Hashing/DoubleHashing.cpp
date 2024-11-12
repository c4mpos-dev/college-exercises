#include <iostream>
using namespace std;

int h1(int k, int m) {
    int ans = k % m;
    if (ans < 0) ans += m;
    return ans;
}

int h2(int k, int m) {
    int ans = 1 + (k % (m - 1));  
    if (ans < 0) ans += m;
    return ans;
}

int dhash(int k, int m, int i) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

int main() {
    int k, m;
    cin >> k >> m;

    for (int i = 0; i < m; i++) {
        int pos = dhash(k, m, i);
        cout << pos << " ";
    }

    return 0;
}