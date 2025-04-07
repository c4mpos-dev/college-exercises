#include <iostream>
#include <list>

#define INF 9999

using namespace std;

struct no {
    int v;
    int peso;
};

void prim(list<no> adj[], int nVertices, int start) {
    // considerar que o grafo terá no máximo 10 vértices (colocar 11 por segurança)
    bool intree[11];
    int distance[11];
    int parent[11];

    for (int u = 0; u < nVertices; u++) {
        intree[u] = false;
        distance[u] = INF;
        parent[u] = -1;
    }

    distance[start] = 0;
    int v = start;

    while (!intree[v]) {
        intree[v] = true;

        // auto reconhece o tipo da variavel it (iterador na lista de no)
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            int destino = it->v;
            int peso = it->peso;
            if (!intree[destino] && distance[destino] > peso) {
                distance[destino] = peso;
                parent[destino] = v;
            }
        }

        int dist = INF;
        v = -1;
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < dist) {
                dist = distance[u];
                v = u;
            }
        }

        if (v == -1)
            break;
    }

    int custoTotal = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < nVertices; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << endl;
            custoTotal += distance[i];
        }
    }
    cout << "Custo: " << custoTotal << endl;
}

int main() {
    int nVertices, orientado, start;
    cin >> nVertices >> orientado >> start;

    list<no> adj[11];

    while (true) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1)
            break;

        no aux;
        aux.v = destino;
        aux.peso = peso;
        adj[origem].push_back(aux);

        if (!orientado) {
            aux.v = origem;
            adj[destino].push_back(aux);
        }
    }

    prim(adj, nVertices, start);

    return 0;
}