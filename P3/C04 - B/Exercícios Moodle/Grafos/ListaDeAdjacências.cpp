#include <iostream>
#include <list>
using namespace std;

struct no {
    int v;    
    int peso; 
};

void cria_aresta(list<no> adj[], int u, int v, int p, int orientado) {
    adj[u].push_back({v, p});
    if (!orientado) {
        adj[v].push_back({u, p});
    }
}

int main() {
    int n, orientado;
    cin >> n >> orientado;

    list<no> adj[n];

    int u, v, p;
    while (cin >> u >> v >> p, u != -1 || v != -1 || p != -1) {
        cria_aresta(adj, u, v, p, orientado);
    }

    for (int i = 0; i < n; i++) {
        cout << i;
        for (const no& aresta : adj[i]) {
            cout << " " << aresta.v << " " << aresta.peso;
        }
        cout << endl;
    }

    return 0;
}
