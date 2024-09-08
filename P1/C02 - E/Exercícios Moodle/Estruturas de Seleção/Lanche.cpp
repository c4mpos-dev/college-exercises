#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle Lanche
	
    double total, cachorroQuente = 4, xSal = 4.5, xBac = 5, torrada = 2, refri = 1.5;
    int qtdItem, codigo;

    cin >> codigo >> qtdItem;

    switch (codigo) {
        case 1:
            total = qtdItem * cachorroQuente;
            break;
        case 2:
            total = qtdItem * xSal;
            break;
        case 3:
            total = qtdItem * xBac;
            break;
        case 4:
            total = qtdItem * torrada;
            break;
        case 5:
            total = qtdItem * refri;
    }

    cout << fixed << setprecision(2);
    cout << "Total: R$ " << total << endl;

    return 0;

}