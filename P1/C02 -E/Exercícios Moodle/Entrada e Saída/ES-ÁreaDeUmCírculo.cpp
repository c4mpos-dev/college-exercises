#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	//Exercício Moodle ES-Área de um círculo
	
	float raio, area, pi = 3.14159;
	
	cin>>raio;
	
	//Calcula á area do círculo
	area = pi * pow(raio, 2);
	
    //Imprime o valor da área com uma precisão de 3 casas decimais
	cout<< "AREA = " << fixed << setprecision(3) << area;
	
	return 0;
}