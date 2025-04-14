#include <iostream>
#include <list>

#define INF 9999
#define MAX_V 1000

using namespace std;

struct no {
    int origem;
    int destino;
    int peso;
};

int prim(list<no> adj[], int nVertices) {
    bool intree[MAX_V];
    int distance[MAX_V];

    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;
        distance[i] = MAX_V;
    }

    distance[0] = 0; // começa no vértice 0
    int v = 0;
    int custoTotal = 0;

    while (true) {
        intree[v] = true;

        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            int destino = it->destino;
            int peso = it->peso;
            if (!intree[destino] && distance[destino] > peso) {
                distance[destino] = peso;
            }
        }

        int dist = INF;
        int proximo = -1;
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < dist) {
                dist = distance[u];
                proximo = u;
            }
        }

        if (proximo == -1) break;
        v = proximo;
    }

    for (int i = 0; i < nVertices; i++) {
        if (distance[i] != INF) {
            custoTotal += distance[i];
        }
    }

    return custoTotal;
}

int main() {
    int N, M, origem, destino, peso;
    cin >> N >> M;

    list<no> adj[MAX_V];

    for (int i = 0; i < M; i++) {
        cin >> origem >> destino >> peso;

        /*
            A entrada tem vértices numerados de 1 até N:

                1 2 5
                2 3 4

            Porém o código usa vetores com índices começando do 0, como adj[0], adj[1], ..., adj[N-1], então precisa ajustar os índices da entrada para caber no array.

            Ou seja:

                O vértice 1 da entrada vira o índice 0 no array adj[]
                O vértice 2 vira o índice 1
        */
        adj[origem - 1].push_back({origem - 1, destino - 1, peso}); 
        adj[destino - 1].push_back({destino - 1, origem - 1, peso});
    }

    int custo = prim(adj, N);
    cout << custo << endl;

    return 0;
}