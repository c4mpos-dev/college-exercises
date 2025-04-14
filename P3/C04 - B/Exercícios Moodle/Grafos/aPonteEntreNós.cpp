#include <iostream>
#include <list>
using namespace std;

void bfs(list<int> adj[], int nVertices, int s, bool visitado[], int x, int y) {
    char state[nVertices];
    list<int> Q;

    for (int u = 0; u < nVertices; u++) {
        state[u] = 'u';
    }

    state[s] = 'd';
    Q.push_back(s);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop_front();

        for (auto p = adj[u].begin(); p != adj[u].end(); ++p) {
            int v = *p;

            // Ignora a aresta destruída (x, y)
            if ((u == x && v == y) || (u == y && v == x)) continue;

            if (state[v] == 'u') {
                state[v] = 'd';
                Q.push_back(v);
            }
        }

        state[u] = 'p';
    }

    for (int i = 0; i < nVertices; i++) {
        visitado[i] = (state[i] != 'u');
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    list<int> adj[N];

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // convertendo para 0-based
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int x, y;
    cin >> x >> y;
    x--; y--; // convertendo para 0-based

    bool visitado[N];
    bfs(adj, N, x, visitado, x, y);

    for (int i = 0; i < N; i++) {
        if (!visitado[i]) {
            cout << i + 1 << " "; // convertendo de volta para 1-based
        }
    }

    return 0;
}
