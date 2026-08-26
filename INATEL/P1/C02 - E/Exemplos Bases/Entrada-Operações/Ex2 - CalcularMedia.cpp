#include <iostream>
using namespace std;

int main()
{
	//Aula02 - C02
	
	float NP1, NP2, NPL, MF;
	
	cout << "Digite as duas notas teóricas: " << endl;	
	cin >> NP1 >> NP2;
	cout << "Digite a nota prática: " << endl;
	cin >> NPL;
	
	//Calcula a média final
	MF = ((NP1 + NP2)/2) * 0.7 + NPL * 0.3;
	
	cout << "Media final: " << MF << endl; 
	
	return 0;
}