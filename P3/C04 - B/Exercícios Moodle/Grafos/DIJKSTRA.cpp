#include <iostream>
#include <list>

#define MAX_V 10 // Número máximo de vértices
#define INF 999999

using namespace std;

// Estrutura para representar uma aresta
struct Aresta {
    int origem;
    int destino;
    int peso;
};

// Função que implementa o algoritmo de Dijkstra
int dijkstra(list<Aresta> adj[], int nVertices, int start, int end) {
    bool intree[MAX_V];       // Indica se o vértice já foi incluído no caminho mais curto
    int distance[MAX_V];      // Armazena a menor distância conhecida até cada vértice
    int parent[MAX_V];        // Armazena o pai de cada vértice no caminho

    // Inicialização dos vetores
    for (int i = 0; i < nVertices; i++) {
        intree[i] = false;
        distance[i] = INF; // Distância infinita no começo
        parent[i] = -1;        // Nenhum pai definido ainda
    }

    distance[start] = 0; // Começamos pelo vértice inicial
    int v = start;       // v é o vértice atual

    // Enquanto houver vértices fora da árvore de caminhos mínimos
    while (!intree[v]) {
        intree[v] = true; // Marca o vértice atual como já visitado

        // Verifica todos os vizinhos do vértice atual
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            int dest = it->destino;
            int peso = it->peso;

            // Relaxamento: se achamos um caminho melhor até 'dest', atualizamos
            if (distance[dest] > distance[v] + peso) {
                distance[dest] = distance[v] + peso;
                parent[dest] = v;
            }
        }

        // Escolhe o próximo vértice com menor distância ainda não incluído
        int dist = INF;
        v = -1;
        for (int u = 0; u < nVertices; u++) {
            if (!intree[u] && distance[u] < dist) {
                dist = distance[u];
                v = u;
            }
        }

        if (v == -1) // Se não achou próximo vértice, encerra
            break;
    }

    // Impressão do caminho de menor custo de start até end
    cout << "Menor caminho: ";
    int atual = end;
    int caminho[MAX_V], tam = 0;

    // Reconstrução do caminho a partir do vetor de pais
    while (atual != -1) {
        caminho[tam++] = atual;
        atual = parent[atual];
    }

    // Imprime o caminho de trás pra frente (do start até o end)
    for (int i = tam - 1; i >= 0; i--) {
        cout << caminho[i]; 
        if (i > 0) cout << ' ';
    }

    // Retorna o custo total do caminho
    return distance[end];
}

int main() {
    int nVertices, orientado, start, end;
    cin >> nVertices >> orientado >> start >> end;

    list<Aresta> adj[MAX_V]; // Lista de adjacência

    // Leitura das arestas
    while (true) {
        int origem, destino, peso;
        cin >> origem >> destino >> peso;
        if (origem == -1 && destino == -1 && peso == -1)
            break;

        // Inserção da aresta no grafo
        adj[origem].push_back({origem, destino, peso});
        if (!orientado)
            adj[destino].push_back({destino, origem, peso}); // Aresta de volta se não for orientado
    }

    // Chama Dijkstra e imprime o custo
    int custo = dijkstra(adj, nVertices, start, end);
    cout << endl;
    cout << "Custo: " << custo << endl;

    return 0;
}
