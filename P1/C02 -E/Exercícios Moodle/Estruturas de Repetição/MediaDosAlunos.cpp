#include<iostream>

using namespace std;

int main() {

    int qtdAlunos;
    double pv1, pv2, media;

    cout << "Quantos alunos? ";
    cin >> qtdAlunos;

    for (int i = 1; i <= qtdAlunos; i++){
        
        cout << "Digite as notas PV1 e PV2 do aluno " << i << " : ";
        cin >> pv1 >> pv2;

        media = (pv1 + pv2) / 2;

        if (media < 60)
            cout << "Media: " << media << " - REPROVADO" << endl;
        else
            cout << "Media: " << media << " - APROVADO" << endl; 

    }

    return 0;

}