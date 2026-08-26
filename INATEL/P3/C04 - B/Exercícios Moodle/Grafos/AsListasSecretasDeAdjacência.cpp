#include <iostream>
#include <list>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    list<int> adj[N+1];

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        adj[A].push_back(B);
        adj[B].push_back(A); // grafo não direcionado
    }

    for (int i = 1; i <= N; i++) {
        adj[i].sort();
    }

    for (int i = 1; i <= N; i++) {
        cout << adj[i].size(); // número de vizinhos

        for (auto it = adj[i].begin(); it != adj[i].end(); ++it) {
            cout << " " << *it;
        }

        if(i != N)
            cout << endl << endl;
    }

    return 0;
}
