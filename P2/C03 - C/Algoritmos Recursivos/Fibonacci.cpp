#include<iostream>
using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)    
        return 1;
    else   
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n = 8, f;

    f = fib(n);

    cout << f << endl;

    return 0;
}