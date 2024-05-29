#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    double A[100], B[100], R[100];
    int a_elem, b_elem, r_elem = 0;

    cin >> a_elem;

    for (int i = 0; i < a_elem; i++){
        cin >> A[i];
    }

    cin >> b_elem;

    for (int i = 0; i < b_elem; i++){
        cin >> B[i];
    }

    for (int i = 0; i < a_elem; i++){
        for (int j = 0; j < b_elem; j++){
            if (A[i] == B[j]){
                R[r_elem] = A[i];
                r_elem++;
                break;
            }
        }
    }

    if (r_elem > 0){
        cout << "Elementos repetidos:";
        for (int i = 0; i < r_elem; i++){
            cout << " " << R[i];
        }
    }
    else
        cout << "Elementos repetidos: nenhum";

    return 0;

}