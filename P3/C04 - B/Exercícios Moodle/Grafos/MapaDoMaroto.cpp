#include <iostream>
#include <list>

using namespace std;

struct caminho {
    int sala;
    int distancia;
};

void cria_aresta(list<caminho> adj[], int u, int v, int p, int orientado) {
    adj[u].push_back({v, p});
    if (!orientado) {
        adj[v].push_back({u, p});
    }
}

int main() {
    int salas, orientado, u, v, p;
    cin >> salas >> orientado;

    list<caminho> adj[salas];

    while (cin >> u >> v >> p) {
        if (u == -1 && v == -1 && p == -1) {
            break;
        }
        cria_aresta(adj, u, v, p, orientado);
    }

    for (int i = 0; i < salas; i++) {
        for (auto it = adj[i].begin(); it != adj[i].end(); it++) {
            cout << i << ' ' <<  it->sala << ' ' << it->distancia;
            cout << endl;
        }
    }

    return 0;
}