#include <iostream>
using namespace std;

int main()
{
	//Aula02 - C02
	
	float L, C, A;
	
	cout<<"Digite a largura da sala (metros)" <<endl;	
	cin>>L;
	cout<<"Digite o comprimento da sala (metros)" <<endl;
	cin>>C;
	
	//Calcula a área da sala 
	A = L* C;
	
	cout<< "Area = " << A << " metros." << endl;
	
	return 0;
}