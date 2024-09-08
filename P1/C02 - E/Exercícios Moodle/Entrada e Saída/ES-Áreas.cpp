#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	//Exercícios Moodle - ES-Áreas

    double A, B, C;
    float triangulo, circulo, trapezio, quadrado, retangulo, pi = 3.14159;

    /*
    a) a área do triângulo retângulo que tem A por base e C por altura. 
    b) a área do círculo de raio C. (pi = 3.14159) 
    c) a área do trapézio que tem A e B por bases e C por altura. 
    d) a área do quadrado que tem lado B. 
    e) a área do retângulo que tem lados A e B. 
    */

    cin >> A >> B >> C;

    //Calcula as áres das formas geométricas
    triangulo = (A * C) / 2;
    circulo = pi * pow(C,2);
    trapezio = ((A + B) * C) / 2;
    quadrado = pow(B,2);
    retangulo = A * B;

    //Imprime a área das figuras
    cout << fixed << setprecision(3);
    cout << "TRIANGULO: " << triangulo << endl;
    cout << "CIRCULO: " << circulo << endl;
    cout << "TRAPEZIO: " << trapezio << endl;
    cout << "QUADRADO: " << quadrado << endl;
    cout << "RETANGULO: " << retangulo;

	return 0;
}