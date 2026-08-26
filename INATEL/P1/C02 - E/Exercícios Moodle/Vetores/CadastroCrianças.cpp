#include<iostream>
#include<iomanip>

using namespace std;

int main(){

    // Defino o vetor com 999 posições mesmo que grande parte fique vazia, pois a matéria é algoritmos 1 e não posso utilizar funções vector, por exemplo.
    int codigo_lista[999], idade_lista[999], codigo = 1, idade, contador = 0;
    double altura_lista[999], altura, conta1, conta2, qtdParametro1 = 0, qtdParametro2 = 0, qtdParametro3 = 0, qtdParametro4 = 0;


    // ----------Código-------------/

    while (codigo != 0){

        do {
            cin >> codigo;
        }while(codigo < 0);

        if (codigo == 0)
            break;

        codigo_lista[contador] = codigo;

        // ----------Altura-------------/

        do {
            cin >> altura;
        }while(altura < 1.0 || altura > 1.7);

        altura_lista[contador] = altura;

        // ----------Idade-------------/

        do {
            cin >> idade;
        }while(idade < 10 || idade > 14);

        idade_lista[contador] = idade;

        contador++;

    }

    altura = 0;
    idade = 0;

    for (int i = 0; i <= contador; i++){
        if (idade_lista[i] == 14 && altura_lista[i] > 1.5)
            qtdParametro1++;
        else if (idade_lista[i] == 10 && altura_lista[i] < 1.5)
            qtdParametro2++;

        
        altura += altura_lista[i];
        idade += idade_lista[i];
    }

    altura = altura / (contador);
    idade = idade / (contador);

    for (int i = 0; i <= contador; i++){
        if (altura_lista[i] >= altura)
            qtdParametro3++;
        if (idade_lista[i] < idade)
            qtdParametro4++;
    }

    conta1 = (qtdParametro3 / contador) * 100;
    conta2 = ((qtdParametro4-1) / contador) * 100;

    cout << "14 anos com mais de 1,5: " << qtdParametro1 << endl;
    cout << "10 anos com menos de 1,5: " << qtdParametro2 << endl;
    cout << "Altura acima da media: " << conta1 << "%" << endl;
    cout << "Idade abaixo da media: " << conta2 << "%" << endl;
    
    return 0;

}