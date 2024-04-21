#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	
    string subfilo, classe, mammalia;

    getline(cin, subfilo);
    getline(cin, classe);
    getline(cin, mammalia);

    if (subfilo == "vertebrado"){
        if (classe == "ave"){
            if (mammalia == "carnivoro")
                cout << "aguia" << endl;
            else
                cout << "pomba" << endl;               
        }
        else{
            if (mammalia == "onivoro")
                cout << "homem" << endl;
            else
                cout << "vaca" << endl; 
        }
    }
    else {
        if (classe == "inseto"){
            if (mammalia == "hematofago")
                cout << "pulga" << endl;
            else
                cout << "lagarta" << endl;               
        }
        else{
            if (mammalia == "hematofago")
                cout << "sanguessuga" << endl;
            else
                cout << "minhoca" << endl; 
        }
    }
}