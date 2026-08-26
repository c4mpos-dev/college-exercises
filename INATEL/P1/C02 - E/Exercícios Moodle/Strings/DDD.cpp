#include <iostream>
#include <cstring>
#include <string>
#include<limits>

using namespace std;

int main()
{
	
    string city;

    getline(cin, city);

    if (city == "Brasilia")
        cout << 61;
    else if (city == "Salvador")
        cout << 71;
    else if (city == "Sao Paulo")
        cout << 11;
    else if (city == "Rio de Janeiro")
        cout << 21;
    else if (city == "Juiz de Fora")
        cout << 32;
    else if (city == "Campinas")
        cout << 19;
    else if (city == "Vitoria")
        cout << 27;
    else if (city == "Belo horizonte")
        cout << 31;
    else if (city == "Santa Rita do Sapucai")
        cout << 35;
    else
        cout << "DDD nao cadastrado";
    

    return 0;

}