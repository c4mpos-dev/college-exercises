#include<iostream>
#include<ctime>
using namespace std;

int main() {
    int i, j, k;
    int N = 16;

    // for (i = 0; i < N; i++){
    //     cout << "pipoca" << endl;
    // }
    
    // i = 1;

    // while (i < N){
    //     cout << "computador" << endl;
    //     i = i*2;
    // }

    int cont = 0;

    // for (i = 0; i < N; i++){
    //     for(j = 0; j < N; j++){s
    //         cont++;
    //     }
    // }

    // for (i = 0; i < N; i++){
    //     j = 1;
    //     while (j < N){
    //         j = j*2;
    //         cont++;
    //     }
    // }

    for (i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            for(k = 0; k < N; k++){      
                cont++;
            }
        }
    }

    cout << cont;

    return 0;
}