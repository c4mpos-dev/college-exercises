#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    struct{
        int matricula;
        double np1, np2;
    }aluno;

    cin >> aluno.matricula >> aluno.np1 >> aluno.np2;
    
    cout << fixed << setprecision(2);
    cout << "Matricula do aluno: " << aluno.matricula << endl;
    cout << "Nota da primeira prova: " << aluno.np1 << endl;
    cout << "Nota da segunda prova: " << aluno.np2 << endl;

    return 0;

}