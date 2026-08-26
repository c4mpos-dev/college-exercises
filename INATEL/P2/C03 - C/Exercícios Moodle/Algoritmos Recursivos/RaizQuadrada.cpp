#include<iostream>
#include<cmath>
using namespace std;

double raiz(double x, double x0, double e) {
    if (abs(pow(x0,2) - x) <= e) {
        return x0;
    } else {
        return raiz(x, (pow(x0,2) + x) / (2 * x0), e);
    }
}

int main() {
    double x, e, x0, f;

    cin >> x >> e >> x0;

    // Verificar se x e epsilon são positivos
    if (x <= 0) {
        cout << "O valor de x deve ser um número real positivo." << endl;
    } else if (e <= 0) {
        cout << "O valor de epsilon deve ser um número real positivo." << endl;
    } else if (x0 <= 0) {
        cout << "O valor de x0 deve ser um número real positivo." << endl;
    } else {
        f = raiz(x, x0, e);
        cout << f << endl;
    }

    return 0;
}