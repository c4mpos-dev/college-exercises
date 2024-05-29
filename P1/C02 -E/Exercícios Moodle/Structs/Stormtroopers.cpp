#include <iostream>
#include <iomanip>
using namespace std;

struct Stormtrooper {
    int id;
    double im, fa;
}trooper;

int main() {
    Stormtrooper melhor_trooper = {0, 0.0, 0.0};
    double melhor_ga = 0;

    while (true) {
        cin >> trooper.id;
        if (trooper.id == 0) {
            break;
        }
        cin >> trooper.im >> trooper.fa;
        
        double ga = (trooper.im + trooper.fa) / 2;
        
        if (ga > melhor_ga) {
            melhor_ga = ga;
            melhor_trooper = trooper;
        }
    }

    if (melhor_trooper.id != 0) {
        cout << "Stormtrooper escolhido: " << melhor_trooper.id << fixed << setprecision(2) << endl << "GA = " << melhor_ga << endl;
    }

    return 0;
}
