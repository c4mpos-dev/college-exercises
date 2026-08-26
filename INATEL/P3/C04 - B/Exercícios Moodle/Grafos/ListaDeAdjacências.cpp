#include <iostream>
#include <list>
using namespace std;

struct no {
    int v; // vértice adjacente
    int peso; // peso da aresta
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    adj[u].push_back({v, p});
    if (!orientado) {
        adj[v].push_back({u, p});
    }
}

int main() {
    int N, orientado;
    cin >> N >> orientado;
    list<no> adj[N];
    
    while (true) {
        int u, v, p;
        cin >> u >> v >> p;
        if (u == -1 && v == -1 && p == -1) break;
        cria_aresta(adj, u, v, p, orientado);
    }
    
    int count = 0;
    list<no>::iterator it;
    for (int i = 0; i < N; i++) {
        for (it = adj[i].begin(); it != adj[i].end(); ++it) {
            if (count >= 1) cout << endl;
            cout << i << " " << it->v << " " << it->peso;
            count++;
        }
    }
    
    return 0;
}