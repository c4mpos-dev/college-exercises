#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;  
    cin >> N;
    
    list<int> estoque;  
    list<int> venda;    
    
    for (int i = 0; i < N; ++i) {
        int operacao;
        cin >> operacao;  // Lê o tipo de operação
        
        if (operacao == 1) {
            int codigo;
            cin >> codigo;  // Lê o código do produto
            estoque.push_back(codigo);  // Adiciona no estoque
        } 
        else if (operacao == 2) {
            if (!estoque.empty()) {
                int codigo = estoque.front();  // Pega o produto do início do estoque
                estoque.pop_front();  // Remove do estoque
                venda.push_front(codigo);  // Adiciona à venda
            }
        }
    }

    cout << "Estoque: ";
    for (int codigo : estoque) {
        cout << codigo << " ";
    }
    cout << endl;

    cout << "Venda: ";
    for (int codigo : venda) {
        cout << codigo << " ";
    }
    cout << endl;

    return 0;
}