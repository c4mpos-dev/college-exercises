#include <iostream>
#include <list>
#include <algorithm>
#include <cmath>

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
    if (totalCidades >= INF) {
        cout << "Erro: Limite maximo de cidades atingido!" << endl;
        return;
    }

    cout << "Nome da cidade: ";
    getline(cin >> ws, cidade[totalCidades].nome);

    cout << "Codigo da cidade: ";
    cin >> cidade[totalCidades].codigo;

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

void buscarCentroPokemonProximo(Cidade cidade[], int totalCidades) {
	if (totalCidades == 0) {
		cout << "Erro: Cadastre cidades antes!" << endl;
		return;
	}

	int codigoAtual;
	cout << "Digite o codigo da sua cidade atual: ";
	cin >> codigoAtual;

	// Verifica se o código da cidade atual existe e qual é
	int cidadeAtual = -1;
	for (int i = 0; i < totalCidades; i++) {
		if (cidade[i].codigo == codigoAtual) {
			cidadeAtual = i;
			break;
		}
	}

	// Se não existir, retorna erro e cancela a busca
	if (cidadeAtual == -1) {
		cout << endl << "Erro: Cidade nao encontrada!" << endl;
		return;
	}

	// Fila BFS iniciada e cidade inicial salva como visitada
	list<int> fila;
	bool visitada[INF] = {false};
	int pai[INF];
	for (int i = 0; i < INF; i++) pai[i] = -1;

	fila.push_back(cidadeAtual);
	visitada[cidadeAtual] = true;

	// Enquanto houver cidades na fila, faz a busca
	while (!fila.empty()) {
		// Cidade atual (frente da fila)
		int atual = fila.front();
		fila.pop_front();

		// Verifica se a cidade atual (da frente da fila tem centro pokemon), fica na parte de cima pois se a cidade que o user está tiver centro pokemon, nem precisa ser feita a busca
		if (cidade[atual].centroPokemon) {
			cout << endl << "Centro Pokemon mais proximo esta na cidade: " << cidade[atual].nome << "." << endl;

			// Reconstroi o caminho a partir do vetor de pais
			int caminho[INF];
			int tam = 0;
			int temp = atual;

			while (temp != -1) {
				caminho[tam++] = temp;
				temp = pai[temp];
			}

			cout << "Caminho percorrido: ";
			for (int i = tam - 1; i >= 0; i--) {
				cout << cidade[caminho[i]].nome;
				if (i != 0) cout << " -> ";
			}
			cout << endl;

			return;
		}

		// Percorrer as estradas dessa cidade
		// O auto detecta o tipo da variável automaticamente, sem precisar declarar o iterador (nao funciona no falcon)
		for (auto it = cidade[atual].vizinha.begin(); it != cidade[atual].vizinha.end(); ++it) {
			// Tenta encontrar o código da cidade destino, verificando se o codigo informado no cadastro das estradas existem
			int destino = -1;
			for (int i = 0; i < totalCidades; i++) {
				if (cidade[i].codigo == it->destino) {
					destino = i;
					break;
				}
			}

			// Se destino for válido e não tiver sido visitado, marca como visitado para evitar loops infinitos e mais processamentos
			if (destino != -1 && !visitada[destino]) {
				visitada[destino] = true;
				pai[destino] = atual;
				fila.push_back(destino);
			}
		}
	}

	cout << endl << "Nenhum Centro Pokemon acessivel a partir dessa cidade." << endl;
}


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

int contarProximos(Node* root, int px, int py) {
    if (!root) return 0;

    int count = 0;

    double dist = sqrt(pow(root->info.x - px, 2) + pow(root->info.y - py, 2));
    if (dist <= 100.0) {
        cout << "- " << root->info.nome << " (distancia: " << dist << ")\n";
        count++;
    }

    count += contarProximos(root->left, px, py);
    count += contarProximos(root->right, px, py);

    return count;
}

void encontrarPokemonsProximos() {
    int x, y;
    cout << "Digite sua localizacao atual (x y): ";
    cin >> x >> y;

    cout << "\nPokemons encontrados em um raio de 100 metros:\n";
    int total = contarProximos(rootNome, x, y);

    if (total == 0)
        cout << "Nenhum Pokemon encontrado no raio de 100 metros.\n";
    else
        cout << "\nTotal encontrados: " << total << "\n";
}

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