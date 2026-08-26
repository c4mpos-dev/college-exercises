#include <iostream>

using namespace std;

float sinal(int n) {
    if (n < 0) {
        return -1;
    } else if (n > 0) {
        return 1;
    } else {
        return 0; 
    }
}

int main() {
    int n;

    cin >> n;

    if (sinal(n) == 1) 
        cout << "Positivo" << endl;
    else if (sinal(n) == -1) 
        cout << "Negativo" << endl;
    else
        cout << "Zero" << endl;

    return 0;
}
