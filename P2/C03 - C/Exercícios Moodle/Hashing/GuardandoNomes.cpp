#include <iostream>
#include <cstring>
using namespace std;

struct dado {
    char info[50];  // informação (string)
    int k;          // chave calculada a partir da soma dos valores ASCII
    int status;     // 0: vazio, 1: ocupado, 2: removido
};

// Função h1 (primeira função hash)
int h1(int k, int m) {
    return k % m;
}

// Função h2 (segunda função hash)
int h2(int k, int m) {
    return 1 + (k % (m - 1));
}

// Função de double hashing (função de sondagem)
int dhash(int k, int m, int i) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

// Função para calcular a chave k de uma string
int calc_chave(const char* str) {
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        k += str[i];  // Soma dos valores ASCII dos caracteres
    }
    return k;
}

// Função para inserir uma informação na tabela hash
void hash_insert(dado t[], int m, const char* info) {
    int k = calc_chave(info);  // Calcula a chave a partir da string
    int i = 0;
    while (i < m) {
        int j = dhash(k, m, i);
        if (t[j].status != 1) {  // Se a posição estiver vazia ou removida
            strcpy(t[j].info, info);  // Insere a string
            t[j].k = k;               // Atribui a chave
            t[j].status = 1;           // Marca como ocupado
            return;
        }
        i++;
    }
}

// Função para pesquisar uma chave na tabela hash
int hash_search(dado t[], int m, const char* info) {
    int k = calc_chave(info);  // Calcula a chave da string
    int i = 0;
    while (i < m) {
        int j = dhash(k, m, i);
        if (t[j].status == 0) {  // Se a posição estiver vazia
            break;
        }
        if (t[j].status == 1 && strcmp(t[j].info, info) == 0) {
            return j;  // Se a chave foi encontrada
        }
        i++;
    }
    return -1;  // Chave não encontrada
}

// Função para remover uma chave da tabela hash
void hash_remove(dado t[], int m, const char* info) {
    int k = calc_chave(info);  // Calcula a chave da string
    int i = 0;
    while (i < m) {
        int j = dhash(k, m, i);
        if (t[j].status == 0) {  // Se a posição estiver vazia
            break;
        }
        if (t[j].status == 1 && strcmp(t[j].info, info) == 0) {
            t[j].status = 2;  // Marca como removido
        }
        i++;
    }
}

// Função para listar todos os elementos da tabela
void hash_list(dado t[], int m) {
    bool first = true;  // Para controlar se é o primeiro elemento
    for (int i = 0; i < m; i++) {
        if (t[i].status == 1) {  // Se a posição estiver ocupada
            if (!first) {
                cout << endl;  // Imprime o espaço antes do próximo elemento
            }
            cout << t[i].info;
            first = false;  // Marca que o primeiro elemento foi impresso
        } else {
            if (!first) {
                cout << endl;  // Imprime o espaço antes de "vazio"
            }
            cout << "vazio";
            first = false;
        }
    }
}

int main() {
    int m;
    cin >> m;  // Tamanho da tabela

    dado t[m];  // Criação da tabela hash

    // Inicializa a tabela com status 0 (vazio)
    for (int i = 0; i < m; i++) {
        t[i].status = 0;  // 0 significa que está vazio
    }

    int opcao;
    cin >> opcao;  // Lê a opção do menu

    while (opcao != 5) {
        if (opcao == 1) {  // Inserir
            char info[50];
            cin.ignore();  // Para limpar o buffer
            cin.getline(info, 50);  // Lê a string
            hash_insert(t, m, info);  // Insere a chave na tabela
        } else if (opcao == 2) {  // Pesquisar
            char info[50];
            cin.ignore();
            cin.getline(info, 50);
            int pos = hash_search(t, m, info);
            if (pos != -1) {
                cout << info << " encontrado na posicao " << pos << endl;
            } else {
                cout << info << " nao encontrado" << endl;
            }
        } else if (opcao == 3) {  // Remover
            char info[50];
            cin.ignore();
            cin.getline(info, 50);
            hash_remove(t, m, info);  // Remove a chave da tabela
        } else if (opcao == 4) {  // Listar
            hash_list(t, m);  // Exibe os elementos na tabela
        }

        cin >> opcao;  // Lê a próxima opção
    }

    return 0;
}
