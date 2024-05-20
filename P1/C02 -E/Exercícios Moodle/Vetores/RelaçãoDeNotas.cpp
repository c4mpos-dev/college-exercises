#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    // Defino o vetor com 999 posições mesmo que grande parte fique vazia, pois a matéria é algoritmos 1 e não posso utilizar funções vector, por exemplo.
    int n, values[10], n_maior = 0, n_menor = 0;
    double media;

    do {
        cin >> n;
    }while(n < 0 || n > 1000);

    for (int i = 0; i < n; i++){
        cin >> values[i];
        media += values[i];
    }
    
    media = (media / n) / 1.0;

    n_menor = values[0];
    n_maior = values[0];

    for (int i = 0; i < n; i++){
        if (n_menor > values[i])
            n_menor = values[i];

    }
        
    for (int i = 0; i < n; i++){
        if (n_maior < values[i])
            n_maior = values[i];

    }

    cout << "Media dos elementos: " << media << endl;
    cout << "Maior elemento: " << n_maior << endl;
    cout << "Menor elemento: " << n_menor << endl;

    cout << "Elementos maiores que a media/posicao" << endl;
    for (int i = 0; i < n; i++){
        if (values[i] > media)
            cout << values[i] << " / " << i << endl;
    }

    cout << "Elementos menores que a media/posicao" << endl;
    for (int i = 0; i < n; i++){
        if (values[i] < media)
            cout << values[i] << " / " << i << endl;
    }

    return 0;

}