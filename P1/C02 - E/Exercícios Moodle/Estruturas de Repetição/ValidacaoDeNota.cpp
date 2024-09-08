#include<iostream>
#include<iomanip>

using namespace std;

int main() {

    double np1 = -1, np2 = -1;

    while (np1 < 0 || np1 > 10){

        cin >> np1;

        if (np1 < 0 || np1 > 10)
            cout << "nota invalida" << endl;

    }

    while (np2 < 0 || np2 > 10){

        cin >> np2;

        if (np2 < 0 || np2 > 10)
            cout << "nota invalida" << endl;

    }

    cout << fixed << setprecision(2);
    cout << "media = " << (np1+np2)/2 << endl;

    return 0;

}