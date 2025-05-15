#include <iostream>
#include <list>

#define INF 9999 // Limite máximo de cidades

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
    string nome;
    string tipo;
    int numero;
    int x, y; // localizacao no mapa
};

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

void cadastrarPokemon(Pokemon pokemons[], int &totalPokemons) {
    if (totalPokemons >= INF) {
        cout << "Erro: Limite maximo de pokemons atingido!" << endl;
        return;
    }

    cout << "Nome do Pokemon: ";
    getline(cin >> ws, pokemons[totalPokemons].nome);

    cout << "Tipo do Pokemon: ";
    getline(cin >> ws, pokemons[totalPokemons].tipo);

    cout << "Numero na Pokedex: ";
    cin >> pokemons[totalPokemons].numero;

    cout << "Localizacao no mapa (x y): ";
    cin >> pokemons[totalPokemons].x >> pokemons[totalPokemons].y;

    totalPokemons++;
    cout << endl << "Pokemon cadastrado com sucesso!" << endl;
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
    Cidade cidade[INF];
    Pokemon pokemons[INF];

    int totalCidades = 0, totalEstradas = 0, totalPokemons = 0;;
    int opcao;

    do {
        exibirMenu();
        cin >> opcao;
        cout << endl;

        switch (opcao) {
            case 1: cadastrarCidades(cidade, totalCidades); break;
            case 2: cadastrarEstradas(cidade, totalCidades, totalEstradas); break;
            case 3: buscarCentroPokemonProximo(cidade, totalCidades); break;
            case 4: cadastrarPokemon(pokemons, totalPokemons); break;
            case 5: removerPokemon(); break;
            case 6: listarPokemonsPorNome(); break;   
            case 7: listarPokemonsPorTipo(); break;   
            case 8: contarPokemonsPorTipo(); break;    
            case 9: encontrarPokemonsProximos(); break;

            case 0: cout << "Saindo..." << endl; break;

            default: cout << "Opcao invalida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    // imprimir para mostrar na hora de avaliar
    cout << endl << "Pokemons cadastrados:" << endl;
    for (int i = 0; i < totalPokemons; i++) {
        cout << "Nome: " << pokemons[i].nome << endl;
        cout << "Tipo: " << pokemons[i].tipo << endl;
        cout << "Numero: " << pokemons[i].numero << endl;
        cout << "Localizacao: (" << pokemons[i].x << ", " << pokemons[i].y << ")" << endl;
        cout << "-----------------------------" << endl;
    }

    return 0;
}
