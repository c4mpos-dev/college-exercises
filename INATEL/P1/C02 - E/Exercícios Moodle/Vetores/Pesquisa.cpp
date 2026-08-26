#include<iostream>

using namespace std;

int main(){

    int numeros[100], numero, i = 0, n_pesquisado, posicao;
    bool isFind = false;
    
    while(true){
        cin >> numero;

        if (numero == 0)
            break;

        numeros[i] = numero;
        i++;
    }

    cin >> n_pesquisado;

    for (int a = 0; a < i; a++){
        if (numeros[a] == n_pesquisado){
            isFind = true;
            posicao = a;
        }
    }

    if (isFind == true)
        cout << "Elemento " << n_pesquisado << " encontrado na posicao " << posicao << endl;
    else
        cout << "Elemento " << n_pesquisado << " nao foi encontrado" << endl;
   
    return 0;

}