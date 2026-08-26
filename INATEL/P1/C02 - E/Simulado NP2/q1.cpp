#include <iostream>
using namespace std;

int main ( )
{
	struct dados{
		char nm[80];
		int id;
		char op;
	}vet[200];

	int i;
	char flag;
	double cp=0, cm=0, ca=0;
	i=0;

	do{
		cout<<"Nome: ";
		cin.getline(vet[i].nm, 80);

		do{
			cout<<"Idade (10 a 100): ";
			cin>>vet[i].id;
		}while(vet[i].id<10 || vet[i].id>100);

		do{
			cout<<"Participacao (P , M ou A): ";
			cin>>vet[i].op;
		}while(vet[i].op!='P' && vet[i].op!='M' && vet[i].op!='A');

		if(vet[i].op=='P')
			cp++;
		else if(vet[i].op=='M')
				cm++;
		else ca++;

		i++;

		cout<<"Tecle 1 p/ novo cadastro ou diferente p/ terminar: ";
		cin>>flag;
		cin.ignore();

	}while(flag == '1' && i < 200);

	//calculos e saída
	cout<<"\nTotal de inscritos: "<< i<<endl;
	cout<<"Poesia: "<< cp/i*100 <<endl;
	cout<<"Musica: "<< cm/i*100 <<endl;
	cout<<"Artes: "<< ca/i*100 <<endl;
    
	return 0;	
}
