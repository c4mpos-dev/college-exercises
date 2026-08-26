#include<iostream>
using namespace std;

// Nota: 8 / 10
// -0,5pts por não comentar o código
// -0,5pts por utilizar --> break;
// -1pt por utilizar cout dentro de uma função

void insercaoDireta(double vetor[], int tamanho){
    int i,j; // contadores
    double chave;
    for (j=1;j<tamanho;j++){
        chave = vetor[j];
        i = j-1;
        while ((i >= 0) && (vetor[i] > chave)){
            vetor[i+1] = vetor[i];
            i = i-1;
        }
        vetor[i+1] = chave;
    }
    
    for (int m = 0; m < tamanho; m++)
        cout << vetor[m] << " ";
} 

int main (){
    double vetor[20], x;
    int i = 0;
    
    while (true) {
        cin >> x;
        
        if (x == -1)
            break;
        else
            vetor[i] = x;
            
        i++;
    }
    
    insercaoDireta(vetor, i);
    
    return 0;
}