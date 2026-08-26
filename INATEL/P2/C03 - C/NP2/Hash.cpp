#include<iostream>
using namespace std;

struct dado {
    int k; // chave
    int status; // 0=vazio 1=ocupado
};

int hash_aux(int k, int m) {
    int ans = k % m;
    if (ans < 0) ans += m; // se for < 0 soma m
    return ans;
}

int hash1(int k, int i, int m, int c1, int c2) {
    int ans = (hash_aux(k, m) + c1 * i + c2 * i * i) % m;
    if (ans < 0) ans += m; // se for < 0 soma m
    return ans;
}

int hash_insert(dado t[], int m, int k, int c1, int c2) {
    int i = 0;
    while (i != m) {
        int j = hash1(k, i, m, c1, c2); // sondagem quadrática
        if (t[j].status != 1) { // Se a posição estiver vazia
            t[j].k = k; // Insere a chave
            t[j].status = 1; // Marca a posição como ocupada
            return j; // Retorna a posição onde a chave foi inserida
        }
        i++; // Se a posição estiver ocupada, tenta a próxima
    }
    return -1; // tabela cheia
}

int hash_search(dado t[], int m, int k, int c1, int c2) {
    int j, i = 0;
    do {
        j = hash1(k, i, m, c1, c2);
        if (t[j].k == k)
            return j;
        i++;
    } while (t[j].status != 0 and i < m);

    return -1;
}

int main() {
    int m, c1, c2;
    cin >> m >> c1 >> c2;

    dado t[1000];

    // Inicializa a tabela com status 0 (vazio)
    for (int i = 0; i < m; ++i)
        t[i].status = 0;

    int k = 1;
    while (k != 0) { // para quando for 0
        cin >> k;
        if (k != 0) hash_insert(t, m, k, c1, c2); // Insere a chave na tabela
    }

    int searchKey;
    cin >> searchKey; // Digita a chave que deseja buscar

    int pos = hash_search(t, m, searchKey, c1, c2); // Busca a chave

    if (pos != -1)
        cout << "Chave " << searchKey << " encontrada na posicao " << pos;
    else
        cout << "Chave " << searchKey << " nao encontrada";

    return 0;
}