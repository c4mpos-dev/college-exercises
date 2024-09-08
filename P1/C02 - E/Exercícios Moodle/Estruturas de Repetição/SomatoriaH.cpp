#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    int n;
    double h = 0;

    cin >> n;

    for (int i = 1; i <= n; i++){
        
        h += 1.0 / i;      
        
    }

    cout << fixed << setprecision(4) << h << endl;

    return 0;

}