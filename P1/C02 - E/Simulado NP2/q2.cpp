#include <iostream>
#include<cmath>
using namespace std;

double Vfinal(double vo, double a, double t)
{
	return vo + a*t;
}
double Sfinal(double so, double vo, double a, double t)
{
	return so+vo*t+0.5*a*t*t;
}

int main ()
{
	double v0, s0, a, t, vf, sf;
	//entrada de dados
	do{
		cout<<"Vo (>=0): ";
		cin>>v0;
	}while(v0<0);
	do{
		cout<<"So (>=0): ";
		cin>>s0;
	}while(s0<0);
	do{
		cout<<"T (>=0): ";		
		cin>>t;
	}while(t<0);

	cout<<"A: ";	
	cin>>a;

	//chamada da funçao Vfinal
	vf = Vfinal(v0, a, t);
	sf = Sfinal(s0,v0,a,t);

	cout<<"V = "<<vf<<endl;
	cout<<"S = "<<sf<<endl;

	return 0;	
}

