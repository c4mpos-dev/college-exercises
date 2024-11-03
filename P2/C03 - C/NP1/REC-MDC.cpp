#include<iostream>
using namespace std;

// Nota: 10 / 10

int mdc(int x, int y){
    if (x == y)
        return x;
    else if (x < y)
        return mdc(y, x);
    else
        return mdc(x-y, y);
}

int main() {
    int x, y;
    
    cin >> x >> y;
    cout << mdc(x, y);
    
    return 0;
}