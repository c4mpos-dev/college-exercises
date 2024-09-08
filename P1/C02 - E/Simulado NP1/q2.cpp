#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main() {
    
    int nFunc, nFaltas, nMoveisVend, contador = 0;
    double salario, bonus;
    
    cout << "Digite o numero de funcionarios: ";
    cin >> nFunc;
    
    while (nFunc <= 0){
        cout << "Numero invalido, digite novamente: ";
        cin >> nFunc;
    }
    
    while (contador < nFunc){
    
        cout << "Digite o salario do funcionario: ";
        cin >> salario;
        
        while (salario < 0){
            cout << "Numero invalido, digite novamente: ";
            cin >> salario;
        }
        
        cout << "Digite o numero de imoveis vendidos no mes: ";
        cin >> nMoveisVend;
        
        while (nMoveisVend < 0){
            cout << "Numero invalido, digite novamente: ";
            cin >> nMoveisVend;
        }
        
        cout << "Digite o numero de faltas no mes (0 a 25): ";
        cin >> nFaltas;
        
        while (nFaltas < 0 && nFaltas > 25){
            cout << "Numero invalido, digite novamente: ";
            cin >> nFaltas;
        }
        
        if (nMoveisVend <= 10){
            if (nFaltas <= 5){
                bonus = salario * 0.15;
            }
            else if (nFaltas <= 10){
                bonus = salario * 0.05;
            }
            else{
                bonus = 0;
            }
        }
            
        else{
            if (nFaltas <= 5){
                bonus = salario * 0.2;
            }
            else if (nFaltas <= 10){
                bonus = salario * 0.1;
            }
            else{
                bonus = 0;
            }
        }
        
        cout << fixed << setprecision(2);
        
        if (bonus == 0){
            cout << endl << "Sem bonus" << endl << endl;
        }
        else {
            cout << endl << "R$" << bonus << endl << endl;
        }
        
        contador += 1;
    }
    
    return 0;
    
}