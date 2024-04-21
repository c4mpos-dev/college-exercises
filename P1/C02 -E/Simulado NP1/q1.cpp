#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main (){
    
    double x, y;
    
    cin >> x;
    
    cout << fixed << setprecision(5);
    
    if (x >= 0){
        y = sqrt(1/(1+x));
        cout << y << endl;
    }
    else{
        cout << "ERRO" << endl;
    }
    
    return 0;
    
}