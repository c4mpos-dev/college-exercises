#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {

    int N, N1, N2, N3, N4;
    string nome;

    cin >> N; 

    for (int i = 0; i < N; ++i) {
        
        cin.ignore(); 
        getline(cin, nome); 

        cin >> N1 >> N2 >> N3 >> N4; 

        double media = (N1 + 2 * N2 + 3 * N3 + 4 * N4) / 10.0; 

        cout << fixed << setprecision(2) << nome << ": " << media << endl;
    }

    return 0;
}
