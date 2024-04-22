#include<iostream>

using namespace std;

int main() {

    double x[5];

    //Adiciona cada entrada nos índices da lista x
    for (int i = 0; i < 5; i++)
        cin >> x[i];
    
    //Imprime cada valor no índice da lista x
    for (int c = 0; c < 5; c++)
        cout << "Pos[" << c << "] = " << x[c] << endl;


    cout << endl << "Maiores que 3: ";

    //Imprime cada valor acima de 3 que esteja na lista x
    for(int n : x) {
        if (n > 3)
    	    cout<< n << " ";
    }

    return 0;

}