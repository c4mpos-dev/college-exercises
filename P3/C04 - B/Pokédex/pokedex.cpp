#include <iostream>
#include <list>

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

void cadastrarCidades(Cidade cidade[], int vertices, bool &cidadesCadastradas) {
    // Caso todas as cidades tenha sido cadastradas, retorna erro
    if (cidadesCadastradas) {
        cout << "Erro: Todas as cidades ja foram cadastradas!" << endl;
        return;
    }

    for (int i = 0; i < vertices; i++)
	{
		cout << "Nome da cidade: ";
		getline(cin >> ws, cidade[i].nome);
		cout << "Codigo da cidade: ";
		cin >> cidade[i].codigo;
		cout << "Tem centro Pokemon? [0]Nao [1]Sim: ";
		cin >> cidade[i].centroPokemon;
		cout << endl;
	}
    
    cout << "As cidades foram cadastradas!" << endl;
    cidadesCadastradas = true;
}

void cadastrarEstradas(Cidade cidade[], int arestas, bool &estradasCadastradas) {
    if (cidade[0].nome.empty() && cidade[1].nome.empty()) {
        cout << "Erro: Cadastre mais de uma cidade antes!" << endl;
        return;
    }
    if (estradasCadastradas) {
        cout << "Erro: Todas as estradas ja foram cadastradas!" << endl;
        return;
    }

    int origem, destino, peso;

    // Criacao das estradas
	cout << "Agora insira as estradas entre as cidades." << endl;
	cout << "Ex: '2 3 5' Estrada da Cidade 2 (Codigo2) para Cidade 3 (Codigo3), com um tamanho de 5." << endl;
	cout << endl;

	for (int i = 0; i < arestas; i++) {
		cin >> origem >> destino >> peso;

		cidade[origem].vizinha.push_back({origem, destino, peso});
        cidade[destino].vizinha.push_back({destino, origem, peso}); // Tirar caso seja orientado
	}

    cout << endl << "As estradas foram cadastradas!" << endl;
    estradasCadastradas = true;
}

void buscarCentroPokemonProximo(Cidade cidade[], int vertices) {
    if (cidade[0].nome.empty()) {
        cout << "Erro: Cadastre cidades antes!" << endl;
        return;
    }

    int codigoAtual;
    cout << "Digite o codigo da sua cidade atual: ";
    cin >> codigoAtual;

    // Verifica se o código da cidade atual existe e qual é
    int cidadeAtual = -1;
    for (int i = 0; i < vertices; i++) {
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
    bool visitada[vertices] = {false};

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
            return;
        }

        // Percorrer as estradas dessa cidade
        // O auto detecta o tipo da variável automaticamente, sem precisar declarar o iterador
        for (auto it = cidade[atual].vizinha.begin(); it != cidade[atual].vizinha.end(); ++it) {
            // Tenta encontrar o código da cidade destino, verificando se o codigo informado no cadastro das estradas existem
            int destino = -1;
            for (int i = 0; i < vertices; i++) {
                if (cidade[i].codigo == it->destino) {
                    destino = i;
                    break;
                }
            }

            // Se destino for válido e não tiver sido visitado, marca como visitado para evitar loops infinitos e mais processamentos
            if (destino != -1 && !visitada[destino]) {
                visitada[destino] = true;
                fila.push_back(destino);
            }
        }
    }

    cout << endl << "Nenhum Centro Pokemon acessivel a partir dessa cidade." << endl;
}

void cadastrarPokemon() {
    cout << "Pokemon cadastrado!" << endl;
}

void removerPokemon() {
    cout << "Pokemon removido!" << endl;
}

void listarPokemonsPorNome() {
    cout << "Pokemons listados por nome!" << endl;
}

void listarPokemonsPorTipo() {
    cout << "Pokemons listados por tipo!" << endl;
}

void contarPokemonsPorTipo() {
    cout << "Pokemons do tipo X contados!" << endl;
}

void encontrarPokemonsProximos() {
    cout << "Pokemons proximos encontrados!" << endl;
}

void intro(int &vertices, int &arestas) {
	cout << "Ola, bem-vindo a Pokedex!" << endl;
	cout << endl;

	// Informacoes necessarias para construcao do grafo
	cout << "Digite o numero de cidades e estradas a ser cadastrado, respectivamente:" << endl;
	cin >> vertices >> arestas;
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
    cout << "[8] Contar Pokemons de cada tipo" << endl;
    cout << "[9] Encontrar Pokemons proximos" << endl;
    cout << endl << "[0] Sair" << endl;
    cout << endl << "Escolha uma opcao: ";
}

int main() {
    bool cidadesCadastradas = false, estradasCadastradas = false;
    int vertices = 0, arestas = 0, opcao;

    // Só chama a intro uma vez, já que a quantidade de cidades e caminhos vai ser definida no início
    intro(vertices, arestas);
    // Array com tamanho baseado no que o user digitou
    Cidade cidade[vertices];

    do {
        exibirMenu();
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: cadastrarCidades(cidade, vertices, cidadesCadastradas); break;
            case 2: cadastrarEstradas(cidade, arestas, estradasCadastradas); break;
            case 3: buscarCentroPokemonProximo(cidade, vertices); break;
            case 4: cadastrarPokemon(); break;
            case 5: removerPokemon(); break;
            case 6: listarPokemonsPorNome(); break;   
            case 7: listarPokemonsPorTipo(); break;   
            case 8: contarPokemonsPorTipo(); break;    
            case 9: encontrarPokemonsProximos(); break;
                
            case 0: cout << "Saindo..." << endl; break;
                
            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}