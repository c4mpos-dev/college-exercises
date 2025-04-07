#include <iostream>
#include <list>

#define INF 9999
#define MAX_V 1000

using namespace std;

struct no {
    int v;
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
            int destino = it->v;
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
    int N, M;
    cin >> N >> M;

    list<no> adj[MAX_V];

    for (int i = 0; i < M; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        u--; // ajusta o indice para 0
        v--; // ajusta o indice para 0

        no a;
        a.v = v;
        a.peso = c;
        adj[u].push_back(a);

        no b;
        b.v = u;
        b.peso = c;
        adj[v].push_back(b); // nao orientado
    }

    int custo = prim(adj, N);
    cout << custo << endl;

    return 0;
}