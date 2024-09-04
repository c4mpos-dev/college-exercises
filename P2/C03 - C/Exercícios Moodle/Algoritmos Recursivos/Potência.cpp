#include<iostream>
using namespace std;

int pot(int a, int n) {
    if (n == 0)
        return 1;
    else   
        return (a * pot(a, n - 1));
}

int main() {
    int a, n, f;

    cin >> a >> n;

    f = pot(a, n);

    cout << f << endl;

    return 0;
}