#include <iostream>
#include <list>

#define MAX_V 100 // Definindo o número máximo de vértices
#define INF 999999 // Número grande para representar infinito

using namespace std;

struct Aresta {
    int origem;
    int destino;
    int tempo;
};

// Função Dijkstra
int dijkstra(list<Aresta> adj[], int nVertices, int start, int end) {
    bool intree[MAX_V]; // Verifica se o vértice já foi incluído na árvore
    int distance[MAX_V]; // Armazena a distância mínima de cada vértice
    // int parent[MAX_V]; // Armazena o vértice anterior no caminho mínimo (só se eu quiser mostrar o caminho)

    // Inicializa as variáveis
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;
        distance[i] = INF; // Inicializa todas as distâncias como "infinito"
        // parent[i] = -1; // Inicializa todos os pais como -1 (sem pai) (só se eu quiser mostrar o caminho)
    }

    distance[start] = 0; // A distância da cidade de origem para ela mesma é 0
    int v = start;

    // Enquanto houver vértices não processados
    while (!intree[v]) {
        intree[v] = true; // Marca o vértice como processado

        // Verifica os vizinhos de 'v'
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            int dest = it->destino;
            int tempo = it->tempo;

            // Relaxamento: verifica se há um caminho mais curto para 'dest'
            if (distance[dest] > distance[v] + tempo) {
                distance[dest] = distance[v] + tempo; // Atualiza a distância
                // parent[dest] = v; // Atualiza o pai
            }
        }

        // Escolhe o próximo vértice a ser processado (o de menor distância)
        int dist = INF;
        v = -1;
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < dist) {
                dist = distance[u];
                v = u;
            }
        }

        // Se não encontrar mais vértices não processados, termina
        if (v == -1)
            break;
    }

    // Recupera o caminho
    // SE EU QUISER MOSTRAR O CAMINHO:
    /*
        int caminho[MAX_V], tam = 0;
        int atual = end;
        while (atual != -1) {
            caminho[tam++] = atual;
            atual = parent[atual];
        }

        // Exibe o caminho
        cout << "Caminho: ";
        for (int i = tam - 1; i >= 0; i--) {
            cout << caminho[i];
            if (i > 0) cout << " -> ";
        }
        cout << endl;
    */

    // Retorna a distância mínima do vértice de origem para o de destino
    return distance[end];
}

int main() {
    int N, M, A, B;
    cin >> N >> M; // Lê o número de cidades (vértices) e estradas (arestas)

    list<Aresta> adj[MAX_V]; // Lista de adjacência para armazenar o grafo

    // Lê as estradas (arestas) entre as cidades
    for (int i = 0; i < M; i++) {
        int u, v, t;
        cin >> u >> v >> t;

        adj[u].push_back({u, v, t}); // Adiciona a estrada u -> v
        adj[v].push_back({v, u, t}); // Adiciona a estrada v -> u (grafo não orientado)
    }

    // Lê as cidades de origem e destino
    cin >> A >> B;

    // Chama a função dijkstra para calcular o tempo mínimo de A até B
    int tempo = dijkstra(adj, N, A, B);

    // Exibe o tempo mínimo de viagem
    cout << tempo << endl;

    return 0;
}