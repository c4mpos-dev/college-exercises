#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    // Defino o vetor com 999 posições mesmo que grande parte fique vazia, pois a matéria é algoritmos 1 e não posso utilizar funções vector, por exemplo.
    int n_alunos, alunos_acima = 0, alunos_abaixo = 0;
    double media_turma, notas[999];

    do {
        cin >> n_alunos;
    }while(n_alunos < 0 || n_alunos > 1000);

    for (int i = 0; i < n_alunos; i++){
        cin >> notas[i];
        media_turma += notas[i];
    }

    media_turma = (media_turma / n_alunos) / 1.00;

    for (int i = 0; i < n_alunos; i++){
        if (notas[i] < media_turma)
            alunos_abaixo++;
        else 
            alunos_acima++;
    }

    cout << fixed << setprecision(2);
    cout << "Media da turma: " << media_turma << endl;
    cout << "Alunos com nota acima da media: " << alunos_acima << endl;
    cout << "Alunos com nota abaixo da media: " << alunos_abaixo << endl;

    return 0;

}