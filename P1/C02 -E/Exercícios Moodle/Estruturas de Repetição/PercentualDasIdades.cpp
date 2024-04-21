#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    double maisou21, menos21;
    int n, idade;

    cin >> n; 

    for (int i = 0; i < n; i++){
        
        cin >> idade;

        if (idade < 21)
            menos21++;
        else
            maisou21++;              
        
    }

    menos21 = (menos21 / n) * 100;
    maisou21 = (maisou21 / n) * 100;

    cout << fixed << setprecision(2);
    cout << "Maiores: " << maisou21 << "%" << endl;
    cout << "Menores: " << menos21 << "%" << endl;

    return 0;

}