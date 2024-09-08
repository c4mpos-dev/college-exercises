#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    // Defino o vetor com 999 posições mesmo que grande parte fique vazia, pois a matéria é algoritmos 1 e não posso utilizar funções vector, por exemplo.
    int n_votos, like = 0, dislike = 0, avaliacoes[999];

    do {
        cin >> n_votos;
    }while(n_votos < 0 || n_votos > 1000);

    for (int i = 0; i < n_votos; i++)
        cin >> avaliacoes[i];

    for (int i = 0; i < n_votos; i++){
        if (avaliacoes[i] < 0)
            dislike++;
        else 
            like++;
    }

    if (like > dislike)
        cout << "A maioria gostou" << endl;
    else if (dislike > like)
        cout << "A maioria nao gostou" << endl;
    else 
        cout << "Deu empate" << endl;

    return 0;

}