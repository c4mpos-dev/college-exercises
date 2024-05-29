#include <iostream>
#include <string>
using namespace std;

struct Cavaleiro {
    string nome;
    int base;
}cavaleiros[1000];

int main() {

    int N;
    cin >> N;
    cin.ignore(); // Limpar o buffer após ler o inteiro

    // Cadastro dos cavaleiros
    for (int i = 0; i < N; i++) {
        // Ler o nome usando getline() para permitir espaços em branco
        getline(cin, cavaleiros[i].nome);

        cin >> cavaleiros[i].base;
        cin.ignore(); // Limpar o buffer após ler o inteiro
    }

    // Busca pelo cavaleiro
    string busca;
    getline(cin, busca);
    
    bool encontrado = false;

    // Verifica se o cavaleiro está cadastrado e mostra a base
    for (int i = 0; i < N; i++) {
        if (cavaleiros[i].nome == busca) {
            cout << "Este cavaleiro esta na base "<< cavaleiros[i].base << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "Este cavaleiro nao esta cadastrado" << endl;
    }

    return 0;
}
