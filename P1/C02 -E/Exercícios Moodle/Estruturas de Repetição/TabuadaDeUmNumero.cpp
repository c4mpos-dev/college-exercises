#include<iostream>

using namespace std;

int main() {

    double n;
        
    cin >> n;
    
    if (n < 1 || n > 10)
        cout << "Erro de entrada!" << endl;

    for (int i = 1; i <= 10; i++){
        
        cout << n * i << " ";

    }

    return 0;

}