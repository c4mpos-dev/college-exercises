#include<iostream>

using namespace std;

int main() {

    int inter = 0, gremio = 0, escolha, golG, golI, qtdGrenais = 0, empates = 0;

    while (escolha != 2){

        cin >> golI >> golG;

        if (golI > golG)
            inter++;
        else if (golG > golI)
            gremio++;
        else
            empates++;

        qtdGrenais++;

        cout << "Novo grenal (1-sim 2-nao)" << endl;
        cin >> escolha;

    }

    cout << qtdGrenais << " grenais" << endl;
    cout << "Inter:" << inter << endl;
    cout << "Gremio:" << gremio << endl;
    cout << "Empates:" << empates << endl;

    if (inter > gremio)
        cout << "Inter venceu mais" << endl;
    else if (gremio > inter)
        cout << "Gremio venceu mais" << endl;
    else 
        cout << "Nao houve vencedor" << endl;

    return 0;

}