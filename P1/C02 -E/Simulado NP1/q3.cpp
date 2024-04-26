#include<iostream>
#include<cmath>
#include<iomanip>
#include<string>
#include<limits>

using namespace std;

int main(){
    
    int nAtletas, idade, totalCats, contador = 0;
    string nome;
    double junior = 0, infantil = 0, juvenil = 0;
    
    cout << "Digite o numero de atletas: ";
    cin >> nAtletas;
    
    while (nAtletas <= 0){
        cout << "Numero invalido, digite novamente: ";
        cin >> nAtletas;
    }
    
    do {
        cout << "Digite o nome do atleta: ";
        cin.ignore();
        getline(cin,nome);
        
        cout << "Digite a idade do atleta: ";
        cin >> idade;

        while (idade < 7 || idade > 18){
            cout << "Numero invalido, digite novamente: ";
            cin >> idade;
        }

        if (idade <= 10){
            cout << endl << "Infantil" << endl << endl;
            infantil += 1;
        }
        else if (idade <= 14){
            cout << endl  << "Juvenil" << endl << endl;
            juvenil += 1;
        }
        else {
            cout << endl  << "Junior" << endl << endl;
            junior += 1;
        }

        contador += 1;

    } while (contador < nAtletas);
           
    cout << "Percentual de inscritos:" << endl;
    totalCats = junior + juvenil + infantil;
    
    infantil = (infantil / totalCats) * 100;
    juvenil = (juvenil / totalCats) * 100;
    junior = (junior / totalCats) * 100;
    
    cout << "Infantil: " << infantil << "%" << endl;
    cout << "Juvenil: " << juvenil << "%" << endl;
    cout << "Junior: " << junior << "%" << endl;
    
    return 0;
    
}