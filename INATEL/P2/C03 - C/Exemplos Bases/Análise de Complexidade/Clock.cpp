#include<iostream>
#include<ctime>

using namespace std;

int main() {
    
    long double i, n, soma1 = 0, soma2 = 0;

    clock_t inicio, fim;

    do {
        cin >> n;
    }while(n < 2);

    inicio = clock();
    for (i = 1; i <= n; i++){
        soma1 += i;
    }
    fim = clock();
    cout << "Tempo Soma1 = " << (double)(fim-inicio)/CLOCKS_PER_SEC << " s" << endl;
    cout << "Soma1: " << soma1 << endl << endl;

    inicio = clock();
    soma2 = n*(1+n)/2;
    fim = clock();
    cout << "Tempo Soma2 = " << (double)(fim-inicio)/CLOCKS_PER_SEC << " s" << endl;
    cout << "Soma2: " << soma2 << endl;
    
    return 0;
}