#include <iostream>
#include <iomanip> 

using namespace std;

int main() {

    int N, X[100], Y[100];
    char Op[100];
    double result;

    do{
        cin >> N;
    } while (N > 100 || N < 0);

    for (int i = 0; i < N; i++)
        cin >> X[i];
    
    for (int i = 0; i < N; i++)
        cin >> Y[i];
    
    for (int i = 0; i < N; i++)
        cin >> Op[i];


    for (int i = 0; i < N; i++){
        cout << fixed << setprecision(0);

        if (Op[i] == '*'){
            result = X[i] * Y[i];
            cout << X[i] << " * " << Y[i] << " = " << result << endl;;
        }
        else if (Op[i] == '-'){
            result = X[i] - Y[i];
            cout << X[i] << " - " << Y[i] << " = " << result << endl;;
        }
        else if (Op[i] == '/'){
            cout << fixed << setprecision(2);
            result = (X[i] * 1.00) / (Y[i] * 1.00);
            cout << X[i] << " / " << Y[i] << " = " << result << endl;
        }
        else if (Op[i] == '+'){
            result = X[i] + Y[i];
            cout << X[i] << " + " << Y[i] << " = " << result << endl;;
        }
    }
        
    return 0;

}