#include <iostream>
#include <list>

#define INF 9999

using namespace std;

// Agora o struct contém tanto a origem quanto o destino
struct no {
    int origem;
    int v;
    int peso;
};

void prim(list<no> adj[], int nVertices, int start) {
    // Arrays auxiliares para controlar o estado dos vértices
    bool intree[11];      // indica se o vértice já foi incluído na MST
    int distance[11];     // armazena o menor peso para conectar cada vértice à árvore
    int parent[11];       // armazena o pai de cada vértice na MST

    // Inicialização dos vetores
    for (int u = 0; u < nVertices; u++) {
        intree[u] = false;        // Nenhum vértice foi visitado ainda
        distance[u] = INF;        // Distância infinita inicialmente
        parent[u] = -1;           // Sem pai (ainda não está conectado)
    }

    distance[start] = 0;   // Começa do vértice inicial
    int v = start;

    // Enquanto ainda houver vértices fora da árvore
    while (!intree[v]) {
        intree[v] = true;  // Inclui o vértice atual na árvore

        // Percorre todos os vizinhos de 'v'
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            int destino = it->v;
            int peso = it->peso;

            // Se o vizinho ainda não está na árvore E o peso da aresta for menor que o atual
            if (!intree[destino] && distance[destino] > peso) {
                distance[destino] = peso;   // Atualiza a menor distância para esse vizinho
                parent[destino] = v;        // Define 'v' como o pai desse vizinho
            }
        }

        // Escolhe o próximo vértice: o que tem a menor distância e ainda não está na árvore
        int dist = INF;
        v = -1;
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < dist) {
                dist = distance[u];
                v = u;
            }
        }

        // Se não achou nenhum vértice, termina o loop
        if (v == -1)
            break;
    }

    // Imprime os resultados: arestas da MST e o custo total
    int custoTotal = 0;
    cout << "Arvore Geradora Minima:" << endl;
    for (int i = 0; i < nVertices; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " " << i << endl;   // aresta: pai -> filho
            custoTotal += distance[i];               // soma os pesos das arestas usadas
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

        adj[origem].push_back({origem, destino, peso});

        if (!orientado) {
            adj[destino].push_back({destino, origem, peso});
        }
    }

    prim(adj, nVertices, start);

    return 0;
}