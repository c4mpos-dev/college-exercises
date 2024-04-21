#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {

    int n;
    double result;

    cin >> n;

    for (int i = 1; i <= n; i++){
        
        if (i % 2 == 0){
            result = pow(i,2);
            cout << fixed << setprecision(0);
            cout << i << "^2" << " = " << result << endl;
        }

    }

    return 0;

}