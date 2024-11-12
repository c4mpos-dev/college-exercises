#include <iostream>
using namespace std;

struct dado {
    int k;        // chave
    int status;   // 0 = vazio, 1 = ocupado, 2 = removido
};

// Função hash1
int h1(int k, int m) {
    int ans = k % m;
    if (ans < 0) ans += m;
    return ans;
}

// Função hash2
int h2(int k, int m) {
    int ans = 1 + (k % (m - 1));  
    if (ans < 0) ans += m;
    return ans;
}

// Função double hash
int dhash(int k, int m, int i) {
    return (h1(k, m) + i * h2(k, m)) % m;
}

// Função para inserir uma chave na tabela hash
void hash_insert(dado t[], int m, int k) {
    int i = 0;
    while (i < m) {
        int j = dhash(k, m, i);
        if (t[j].status != 1) {  // Se a posição estiver vazia ou removida
            t[j].k = k;           // Insere a chave
            t[j].status = 1;       // Marca a posição como ocupada
            return;
        }
        i++;
    }
}

// Função para pesquisar uma chave na tabela hash
int hash_search(dado t[], int m, int k) {
    int i = 0;
    while (i < m) {
        int j = dhash(k, m, i);
        if (t[j].status == 0) {  // Se a posição estiver vazia, chave não encontrada
            break;
        }
        if (t[j].status == 1 && t[j].k == k) {
            return j;  // Se a chave foi encontrada
        }
        i++;
    }
    return -1;  // Chave não encontrada
}

// Função para remover uma chave da tabela hash
int hash_remove(dado t[], int m, int k){
    int j = hash_search(t,m,k);
    if(j != -1) {
       t[j].status = 2;
       t[j].k = -1;
       return 0; // consegui remover
    }
    else
       return -1; // k nao esta na tabela
}

int main() {
    int m, pos;
    cin >> m;  // Tamanho da tabela

    dado t[1000];  // Criação da tabela hash

    // Inicializa a tabela com status 0 (vazio)
    for (int i = 0; i < m; i++) {
        t[i].status = 0;  // 0 significa que está vazio
    }

    int option, k;

    while (true) {
        cin >> option;

        switch (option) {
            case 1:
                // Inserir chave
                cin >> k;
                hash_insert(t, m, k);
                break;

            case 2:
                // Pesquisar chave
                cin >> k;
                pos = hash_search(t, m, k);
                cout << pos << endl;  // Exibe a posição ou -1 se não encontrado
                break;

            case 3:
                // Remover chave
                cin >> k;
                hash_remove(t, m, k);
                break;

            case 4:
                // Listar a tabela
                for (int i = 0; i < m; i++) {
                    if (t[i].status == 1){   // Se a posição estiver ocupada
                        cout << t[i].k;
                        if (i < m - 1) { cout << " "; }
                    }
                    else{
                        cout << "-1" << " ";
                    }
                }
                cout << endl;
                break;

            case 5:
                // Sair
                return 0;

            default:
                cout << "Opção inválida!" << endl;
        }
    }

    return 0;
}