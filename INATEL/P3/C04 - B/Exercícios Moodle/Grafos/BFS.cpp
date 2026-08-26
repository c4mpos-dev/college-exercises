#include <iostream>
#include <list>

using namespace std;

struct no {
    int v, w;
};

void bfs(list<no> adj[], int nVertices, int s) {
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
        cout << u << endl;

        for (auto p = adj[u].begin(); p != adj[u].end(); p++) {
            int v = p->v;
            cout << u << " " << v << endl;

            if (state[v] == 'u') {
                state[v] = 'd';
                pai[v] = u;
                Q.push_back(v);
            }
        }

        state[u] = 'p'; // processed
    }
}

int main() {
    int nVertices, start;
    cin >> nVertices >> start;
    
    list<no> adj[nVertices];
    
    while (true) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == -1 && v == -1 && w == -1) break;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    bfs(adj, nVertices, start);
    
    return 0;
}