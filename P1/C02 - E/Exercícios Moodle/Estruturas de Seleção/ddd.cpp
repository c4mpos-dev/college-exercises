#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle DDD
	
    int ddd;
    string city;

    cin >> ddd;

    switch (ddd) {
        case 61:
            city = "Brasilia";
            break;
        case 71:
            city = "Salvador";
            break;
        case 11:
            city = "Sao Paulo";
            break;
        case 21:
            city = "Rio de Janeiro";
            break;
        case 32:
            city = "Juiz de Fora";
            break;
        case 19:
            city = "Campinas";
            break;
        case 27:
            city = "Vitoria";
            break;
        case 31:
            city = "Belo Horizonte";
            break;
        default:
            city = "DDD nao cadastrado";
    }

    cout << city << endl;

    return 0;

}