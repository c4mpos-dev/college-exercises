#include <iostream>
using namespace std;

// Estrutura para representar cada entrada na tabela hash
struct dado {
    int k;       // chave
    int status;  // 0 = vazio, 1 = ocupado
};

// Função de inserção de chave usando sondagem linear
int hash_insert(dado t[], int m, int k) {
    int i = 0;
    while (i != m) {
        int j = (k + i) % m;  // Função de sondagem linear: (k + i) % m
        if (t[j].status != 1) {  // Se a posição estiver vazia
            t[j].k = k;           // Insere a chave
            t[j].status = 1;       // Marca a posição como ocupada
            return j;              // Retorna a posição onde a chave foi inserida
        }
        i++;  // Se a posição estiver ocupada, tenta a próxima
    }
    return -1;  // Se não conseguir inserir a chave (tabela cheia)
}

int main() {
    int m;
    cin >> m;  // tamanho da tabela

    // Criação da tabela hash com tamanho m
    dado t[1000];

    // Inicializa a tabela com status 0 (vazio)
    for (int i = 0; i < m; ++i) {
        t[i].status = 0;
    }

    int k;
    while (true) {
        cin >> k;  // Lê as chaves a serem inseridas
        if (k == 0) break;  // Se a chave for 0, interrompe a leitura
        hash_insert(t, m, k);  // Insere a chave na tabela
    }

    // Exibe o conteúdo final da tabela
    for (int i = 0; i < m; ++i) {
        if (t[i].status == 1) {
            cout << t[i].k << " ";  // Exibe a chave inserida
        } else {
            cout << "-1 ";  // Exibe -1 se a posição estiver vazia
        }
    }
    cout << endl;

    return 0;
}
