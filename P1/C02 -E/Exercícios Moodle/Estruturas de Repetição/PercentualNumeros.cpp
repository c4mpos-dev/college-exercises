#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    double nNeg, nPos, num;
    int n;

    cin >> n; 

    for (int i = 0; i < n; i++){
        
        cin >> num;

        if (num < 0)
            nNeg++;
        else
            nPos++;               
        
    }

    nNeg = (nNeg / n) * 100;
    nPos = (nPos / n) * 100;

    cout << fixed << setprecision(1);
    cout << "Positivos: " << nPos << "%" << endl;
    cout << "Negativos: " << nNeg << "%" << endl;

    return 0;

}