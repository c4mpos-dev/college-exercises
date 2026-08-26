#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Info {
    char nome[100];
    int idade;
    float peso;
    float altura;
};

struct Dado {
    Info atleta; // Dados do atleta
    int k;       // Chave (calculada a partir do nome)
    int status;  // 0: vazio, 1: ocupado, 2: removido
};

// Função para calcular a chave usando os valores ASCII do nome
int calculaChave(const string &nome) {
    int chave = 0;
    for (char c : nome) {
        chave += c;
    }
    return chave;
}

// Função hash principal
int hash1(int chave, int m) {
    return chave % m;
}

// Função hash secundária (para double hashing)
int hash2(int chave, int m) {
    return 1 + (chave % (m - 1));
}

// Função de inserção com double hashing
void inserir(Dado tabela[], int m, Info atleta) {
    int chave = calculaChave(atleta.nome);
    int h1 = hash1(chave, m);
    int h2 = hash2(chave, m);

    for (int i = 0; i < m; i++) {
        int pos = (h1 + i * h2) % m;
        if (tabela[pos].status == 0 || tabela[pos].status == 2) { // Vazio ou removido
            tabela[pos].atleta = atleta;
            tabela[pos].k = chave;
            tabela[pos].status = 1; // Ocupado
            return;
        }
    }
}

// Função para pesquisar um atleta na tabela hash
int pesquisar(Dado tabela[], int m, const string &nome) {
    int chave = calculaChave(nome);
    int h1 = hash1(chave, m);
    int h2 = hash2(chave, m);

    for (int i = 0; i < m; i++) {
        int pos = (h1 + i * h2) % m;
        if (tabela[pos].status == 0) {
            return -1; // Não encontrado
        }
        if (tabela[pos].status == 1 && tabela[pos].k == chave && nome == tabela[pos].atleta.nome) {
            return pos;
        }
    }
    return -1; // Não encontrado
}

// Função para remover um atleta da tabela hash
void remover(Dado tabela[], int m, const string &nome) {
    int pos = pesquisar(tabela, m, nome);
    if (pos != -1) {
        tabela[pos].status = 2; // Marcado como removido
    }
}

void listar(Dado tabela[], int m) {
    for (int i = 0; i < m; i++) {
        if (tabela[i].status == 1) { // Apenas posições ocupadas
            
            cout << "Nome: " << tabela[i].atleta.nome << endl;
            cout << "Idade: " << tabela[i].atleta.idade << endl;
            cout << "Peso: " << fixed << setprecision(1) << tabela[i].atleta.peso << endl;
            cout << "Altura: " << fixed << setprecision(2) << tabela[i].atleta.altura << endl;
            if (i < 5) cout << endl;
        }
    }
}

int main() {
    int m;
    cin >> m;

    Dado tabela[m];
    for (int i = 0; i < m; i++) {
        tabela[i].status = 0; // Inicializa todas as posições como vazias
    }

    int opcao;
    while (cin >> opcao) {
        if (opcao == 1) { // Inserir
            Info atleta;
            cin.ignore(); // Ignora o caractere de nova linha
            cin.getline(atleta.nome, 100);
            cin >> atleta.idade >> atleta.peso >> atleta.altura;
            inserir(tabela, m, atleta);
        } else if (opcao == 2) { // Pesquisar
            string nome;
            cin.ignore();
            getline(cin, nome);
            int pos = pesquisar(tabela, m, nome);
            if (pos != -1) {
                cout << "Nome: " << tabela[pos].atleta.nome << endl;
                cout << "Idade: " << tabela[pos].atleta.idade << endl;
                cout << "Peso: " << fixed << setprecision(1) << tabela[pos].atleta.peso << endl;
                cout << "Altura: " << fixed << setprecision(2) << tabela[pos].atleta.altura << endl;
            } else {
                cout << endl << nome << " nao encontrado" << endl << endl;
            }
        } else if (opcao == 3) { // Remover
            string nome;
            cin.ignore();
            getline(cin, nome);
            remover(tabela, m, nome);
        } else if (opcao == 4) { // Listar
            listar(tabela, m);
        } else if (opcao == 5) { // Sair
            break;
        }
    }

    return 0;
}
