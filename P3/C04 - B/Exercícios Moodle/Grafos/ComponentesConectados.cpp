#include <iostream>
#include <list>

using namespace std;

void bfs(list<int> adj[], int nVertices, int s) {
    char state[nVertices];
    int pai[nVertices];
    list<int> Q;

    for (int u = 0; u < nVertices; u++) {
        if (u != s) {
            state[u] = 'u';
            pai[u] = -1;
        }
    }

    state[s] = 'd'; // discovered
    pai[s] = -1;
    Q.push_back(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();

        for (auto p = adj[u].begin(); p != adj[u].end(); p++) {
            int v = *p;

            if (state[v] == 'u') {
                state[v] = 'd';
                pai[v] = u;
                Q.push_back(v);
            }
        }

        state[u] = 'p'; // processed
    }

    bool conexo = true;
    for (int i = 0; i < nVertices; i++) {
        if (state[i] == 'u') {
            conexo = false;
            break;
        }
    }

    if (conexo)
        cout << "Conexo";
    else
        cout << "Nao conexo";
    }

int main() {
    int nVertices, start;
    cin >> nVertices >> start;
    
    list<int> adj[nVertices];
    
    while (true) {
        int u, v;
        cin >> u >> v;
        if (u == -1 && v == -1) break;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfs(adj, nVertices, start);
    
    return 0;
}