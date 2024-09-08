#include <iostream>
#include <string>

using namespace std;

int main() {
    string palavra1, palavra2, palavra3;

    cin >> palavra1 >> palavra2 >> palavra3;

    // Compara as palavras em ordem lexicográfica, ou seja, em ordem alfabética
    if (palavra1 > palavra2) {
        swap(palavra1, palavra2);
    }
    if (palavra1 > palavra3) {
        swap(palavra1, palavra3);
    }
    if (palavra2 > palavra3) {
        swap(palavra2, palavra3);
    }

    // Saída das palavras em ordem alfabética
    cout << palavra1 << " " << palavra2 << " " << palavra3 << endl;

    return 0;
}
