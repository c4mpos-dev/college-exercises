#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>

#define INF 9999 // Limite maximo de cidades, estradas e pokemons

using namespace std;

struct Estrada {
	int origem, destino, peso; // Peso/Tamanho ignorado por enquanto, todas terao o mesmo.
};

struct Cidade {
    int codigo;
    string nome;
    bool centroPokemon;
    list<Estrada> vizinha;
};

struct Pokemon {
    string nome, tipo;
    int numero;
    int x, y; // localizacao no mapa
};

struct Node {
    Pokemon info;
    Node *left, *right;
};

Node* rootNome = NULL;
Node* rootTipo = NULL;

void cadastrarCidades(Cidade cidade[], int &totalCidades) {
    if (totalCidades >= INT_MAX) {
        cout << "Erro: Limite maximo de cidades atingido!" << endl;
        return;
    }

    cout << "Nome da cidade: ";
    // Verifica se o nome ja foi cadastrado
    bool nomeExistente = false;
    string nome;
    getline(cin >> ws, nome);
    for (int i = 0; i < totalCidades; i++) {
        if (cidade[i].nome == nome) {
            nomeExistente = true;
            break;
        }
    }

    if (nomeExistente) {
        cout << "Erro: Cidade ja cadastrada! Tente novamente." << endl;
        return;
    }

    cidade[totalCidades].nome = nome;

    cout << "Codigo da cidade: ";
    // Verifica se o codigo ja foi cadastrado
    bool codigoExistente = false;
    int codigo;
    cin >> codigo;
    for (int i = 0; i < totalCidades; i++) {
        if (cidade[i].codigo == codigo) {
            codigoExistente = true;
            break;
        }
    }

    if (codigoExistente) {
        cout << "Erro: Codigo ja cadastrado! Tente novamente." << endl;
        return;
    }

    cidade[totalCidades].codigo = codigo;

    cout << "Tem centro Pokemon? [0]Nao [1]Sim: ";
    cin >> cidade[totalCidades].centroPokemon;

    cout << endl;

    totalCidades++;
    cout << "Cidade cadastrada!" << endl;
}

void cadastrarEstradas(Cidade cidade[], int totalCidades, int &totalEstradas) {
    if (totalCidades < 2) {
        cout << "Erro: Cadastre pelo menos duas cidades antes!" << endl;
        return;
    }

    if (totalEstradas >= INF) {
        cout << "Erro: Limite maximo de estradas atingido!" << endl;
        return;
    }

    int origem, destino, peso;

    // Criacao das estradas
    cout << "Agora insira a estrada entre as cidades." << endl;
    cout << "Ex: '2 3 5' Estrada da Cidade 2 (Codigo2) para Cidade 3 (Codigo3), com um tamanho de 5." << endl;
    cout << endl;

    cin >> origem >> destino >> peso;

    // Verifica se origem nao é igual destino
    if (origem == destino) {
        cout << "Erro: A origem nao pode ser igual ao destino!" << endl;
        return;
    }

    int idxOrigem = -1, idxDestino = -1;

    for (int i = 0; i < totalCidades; i++) {
        if (cidade[i].codigo == origem) idxOrigem = i;
        if (cidade[i].codigo == destino) idxDestino = i;
    }

    if (idxOrigem == -1 || idxDestino == -1) {
        cout << "Erro: Um ou ambos os codigos de cidade nao foram encontrados!" << endl;
        return;
    }

    cidade[idxOrigem].vizinha.push_back({origem, destino, peso});
    cidade[idxDestino].vizinha.push_back({destino, origem, peso}); // Tirar caso seja orientado

    totalEstradas++;
    cout << endl << "Estrada cadastrada!" << endl;
}


// Funcao que faz a parte de buscar o centro Pokemon mais proximo (com Dijkstra)
void buscarCentroPokemonProximo(Cidade cidades[], int totalCidades) {
    if (totalCidades == 0) {
        cout << "Erro: Cadastre cidades antes!" << endl;
        return;
    }

    int codAtual;
    cout << "Digite o codigo da sua cidade atual: ";
    cin >> codAtual;

    int origem = -1;
    for (int i = 0; i < totalCidades; i++) {
        if (cidades[i].codigo == codAtual) {
            origem = i;
            break;
        }
    }

    if (origem == -1) {
        cout << "Erro: Cidade nao encontrada!" << endl;
        return;
    }

    bool intree[INF];
    int distance[INF], parent[INF];

    for (int i = 0; i < totalCidades; i++) {
        intree[i] = false;
        distance[i] = INT_MAX;
        parent[i] = -1;
    }

    distance[origem] = 0;
    int v = origem;

    while (!intree[v]) {
        intree[v] = true;

        for (auto it = cidades[v].vizinha.begin(); it != cidades[v].vizinha.end(); ++it) {
            int destino = -1;
            for (int j = 0; j < totalCidades; j++) {
                if (cidades[j].codigo == it->destino) {
                    destino = j;
                    break;
                }
            }

            if (destino != -1 && distance[destino] > distance[v] + it->peso) {
                distance[destino] = distance[v] + it->peso;
                parent[destino] = v;
            }
        }

        // Encontrar proximo vertice com menor distancia
        int menorDist = INT_MAX;
        v = -1;
        for (int i = 0; i < totalCidades; i++) {
            if (!intree[i] && distance[i] < menorDist) {
                menorDist = distance[i];
                v = i;
            }
        }

        if (v == -1) break; // Todos os caminhos acessiveis foram visitados
    }

    // Procurar o centro Pokemon mais próximo
    int cidadeCentro = -1;
    int menorDistCentro = INT_MAX;

    for (int i = 0; i < totalCidades; i++) {
        if (cidades[i].centroPokemon && distance[i] < menorDistCentro) {
            menorDistCentro = distance[i];
            cidadeCentro = i;
        }
    }

    if (cidadeCentro == -1) {
        cout << "Nenhum Centro Pokemon acessivel a partir dessa cidade." << endl;
        return;
    }

    // Reconstruir caminho com stack
    stack<int> caminho;
    int atual = cidadeCentro;
    while (atual != origem) {
        caminho.push(atual);
        atual = parent[atual];
    }

    cout << endl << "Centro Pokemon mais proximo esta na cidade: " << cidades[cidadeCentro].nome << endl;
    cout << "Distancia total: " << menorDistCentro << endl;
    cout << "Caminho percorrido: " << cidades[origem].nome;

    while (!caminho.empty()) {
        cout << " -> " << cidades[caminho.top()].nome;
        caminho.pop();
    }
    cout << endl;
}
// --------------------------------------------------------


// Funcoes que fazem a parte de cadastrar/inserir Pokemons nas duas árvores (por nome e por tipo)
string toLower(const string& s) {
    string res = s;
    transform(res.begin(), res.end(), res.begin(), ::tolower);
    return res;
}

void insertPokemon(Node*& root, Pokemon p, bool porNome) {
    if (root == NULL) {
        root = new Node{p, NULL, NULL};
    } else {
        string a = porNome ? toLower(p.nome) : toLower(p.tipo);
        string b = porNome ? toLower(root->info.nome) : toLower(root->info.tipo);
        if (a < b)
            insertPokemon(root->left, p, porNome);
        else
            insertPokemon(root->right, p, porNome);
    }
}

bool existeNome(Node* root, const string& nome) {
    while (root != NULL) {
        if (nome == root->info.nome) 
            return true;
        else if 
            (nome < root->info.nome) root = root->left;
        else 
            root = root->right;
    }

    return false;
}

bool existeNumero(Node* root, int numero) {
    if (!root) 
        return false;

    if (root->info.numero == numero) 
        return true;

    return existeNumero(root->left, numero) || existeNumero(root->right, numero);
}

void cadastrarPokemon() {
    Pokemon p;

    cout << "Nome do Pokemon: ";
    getline(cin >> ws, p.nome);

    if (existeNome(rootNome, p.nome)) {
        cout << endl << "Erro: Ja existe um Pokemon com esse nome!" << endl;
        return;
    }

    cout << "Tipo do Pokemon: ";
    getline(cin >> ws, p.tipo);

    cout << "Numero na Pokedex: ";
    cin >> p.numero;

    if (existeNumero(rootNome, p.numero)) {
        cout << endl << "Erro: Ja existe um Pokemon com esse numero na Pokedex!" << endl;
        return;
    }

    cout << "Localizacao no mapa (x y): ";
    cin >> p.x >> p.y;

    insertPokemon(rootNome, p, true);
    insertPokemon(rootTipo, p, false);

    cout << endl << "Pokemon cadastrado com sucesso!" << endl;
}
// --------------------------------------------------------


// Funcoes que fazem a parte de remover Pokemons das duas árvores (por nome)
Node* remove(Node* root, string valor, bool porNome, bool& removido) {
    if (!root) return NULL;

    if ((porNome && valor < root->info.nome) || (!porNome && valor < root->info.tipo)) {
        root->left = remove(root->left, valor, porNome, removido);
    } else if ((porNome && valor > root->info.nome) || (!porNome && valor > root->info.tipo)) {
        root->right = remove(root->right, valor, porNome, removido);
    } else {
        removido = true;
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* succ = root->right;
        while (succ->left) succ = succ->left;
        root->info = succ->info;
        root->right = remove(root->right, porNome ? succ->info.nome : succ->info.tipo, porNome, removido);
    }

    return root;
}

string buscarTipoPorNome(Node* root, const string& nome) {
    while (root != NULL) {
        if (nome == root->info.nome) {
            return root->info.tipo;
        } else if (nome < root->info.nome) {
            root = root->left;
        } else {
            root = root->right;
        }
    }

    return "";
}

void removerPokemon() {
    if (rootNome == NULL) {
        cout << "Nenhum Pokemon cadastrado!" << endl;
        return;
    }

    string nome;
    cout << "Qual pokemon voce deseja remover? ";
    getline(cin >> ws, nome);

    // Busca o tipo do Pokémon pelo nome
    string tipo = buscarTipoPorNome(rootNome, nome);

    if (tipo == "") {
        cout << "Pokemon nao encontrado!" << endl;
        return;
    }

    // Remove nas duas árvores
    bool removidoNome = false, removidoTipo = false;
    rootNome = remove(rootNome, nome, true, removidoNome);
    rootTipo = remove(rootTipo, tipo, false, removidoTipo);

    if (removidoNome && removidoTipo)
        cout << "Pokemon removido com sucesso!" << endl;
    else
        cout << "Erro ao remover Pokemon!" << endl;
}
// --------------------------------------------------------


// Funcao que faz a parte de listar Pokemons em ordem alfabetica (por tipo ou nome)
void listarPokemon(Node* root, bool porNome) { 
    if (rootNome == NULL) {
        cout << "Nenhum Pokemon cadastrado!" << endl;
        return;
    }

    if (root != NULL) {
        listarPokemon(root->left, porNome);

        cout << "Nome: " << root->info.nome << endl;
        cout << "Tipo: " << root->info.tipo << endl;
        cout << "Numero: " << root->info.numero << endl;
        cout << "Localizacao: (" << root->info.x << ", " << root->info.y << ")" << endl;
        cout << "-------------------------" << endl;

        listarPokemon(root->right, porNome);
    }
}
// --------------------------------------------------------


// Funcoes que fazem a parte de contar Pokemons por tipo
int contarPorTipo(Node* root, const string& tipo) {
    if (!root) return 0;

    int count = 0;
    if (root->info.tipo == tipo) 
        count++;

    return count + contarPorTipo(root->left, tipo) + contarPorTipo(root->right, tipo);
}

void contarPokemonsPorTipo() {
    if (rootTipo == NULL) {
        cout << "Nenhum Pokemon cadastrado!" << endl;
        return;
    }

    string tipo;

    cout << "Insira o tipo de pokemon desejado: ";
    getline(cin >> ws, tipo);
    
    int qtd = contarPorTipo(rootTipo, tipo);

    cout << endl;

    if (qtd == 1)
        cout << "Existe " << qtd << " Pokemon do tipo " << tipo << "!" << endl;
    else
        cout << "Existem " << qtd << " Pokemons do tipo " << tipo << "!" << endl;
}
// --------------------------------------------------------

// Funcao que faz a parte de encontrar Pokemons proximos (dentro de um raio de 100 metros)
int pokemonsProximos(Node* root, int px, int py) {
    if (!root) return 0;

    int count = 0;

    double dist = sqrt(pow(root->info.x - px, 2) + pow(root->info.y - py, 2));
    if (dist <= 100.0) {
        cout << "- " << root->info.nome << " (distancia: " << dist << "m)" << endl;
        count++;
    }

    count += pokemonsProximos(root->left, px, py);
    count += pokemonsProximos(root->right, px, py);

    return count;
}

void encontrarPokemonsProximos() {
    if (rootNome == NULL) {
        cout << "Nenhum Pokemon cadastrado!" << endl;
        return;
    }

    int x, y;
    cout << "Digite sua localizacao atual (x y): ";
    cin >> x >> y;

    cout << "\nPokemons encontrados em um raio de 100 metros:\n";
    int total = pokemonsProximos(rootNome, x, y);

    if (total == 0)
        cout << "Nenhum Pokemon encontrado no raio de 100 metros.\n";
    else
        cout << "\nTotal encontrados: " << total << "\n";
}
// --------------------------------------------------------

// Funcao para exibir menu (Main clean)
void exibirMenu() {
    cout << endl << "=====================================================================" << endl;
    cout << endl << "Menu Inicial:" << endl;
    cout << "[1] Cadastrar cidade" << endl;
    cout << "[2] Cadastrar estrada" << endl;
    cout << "[3] Buscar centro Pokemon mais proximo" << endl;
    cout << "[4] Cadastrar Pokemon" << endl;
    cout << "[5] Remover Pokemon" << endl;
    cout << "[6] Listar Pokemons (ordem alfabetica de nome)" << endl;
    cout << "[7] Listar Pokemons (ordem alfabetica de tipo)" << endl;
    cout << "[8] Contar Pokemons por tipo" << endl;
    cout << "[9] Encontrar Pokemons proximos" << endl;
    cout << endl << "[0] Sair" << endl;
    cout << endl << "Escolha uma opcao: ";
}

int main() {
    Cidade cidade[INF];
    Pokemon pokemons[INF];

    int totalCidades = 0, totalEstradas = 0;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: cadastrarCidades(cidade, totalCidades); break;
            case 2: cadastrarEstradas(cidade, totalCidades, totalEstradas); break;
            case 3: buscarCentroPokemonProximo(cidade, totalCidades); break;
            case 4: cadastrarPokemon(); break;
            case 5: removerPokemon(); break;
            case 6: listarPokemon(rootNome, true); break;
            case 7: listarPokemon(rootTipo, false); break;
            case 8: contarPokemonsPorTipo(); break;  
            case 9: encontrarPokemonsProximos(); break;

            case 0: cout << "Saindo..." << endl; break;

            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}