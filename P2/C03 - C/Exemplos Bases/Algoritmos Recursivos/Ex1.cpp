#include<iostream>
using namespace std;

int fatorial(int n) {
    if (n== 0)
        return 1;
    else   
        return n * fatorial(n - 1);
}

int main() {
    int n = 3, f;

    f = fatorial(n);

    cout << f << endl;

    return 0;
}