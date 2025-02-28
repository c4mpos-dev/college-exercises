#include <iostream>
using namespace std;

void cadastrarCidade() {
    cout << endl << "Cidade cadastrada!" << endl;
}

void cadastrarEstrada() {
    cout << endl << "Estrada cadastrada!" << endl;
}

void buscarCentroPokemonProximo() {
    cout << endl << "Centro Pokemon mais proximo buscado!" << endl;
}

void cadastrarPokemon() {
    cout << endl << "Pokemon cadastrado!" << endl;
}

void removerPokemon() {
    cout << endl << "Pokemon removido!" << endl;
}

void listarPokemonsPorNome() {
    cout << endl << "Pokemons listados por nome!" << endl;
}

void listarPokemonsPorTipo() {
    cout << endl << "Pokemons listados por tipo!" << endl;
}

void contarPokemonsPorTipo() {
    cout << endl << "Pokemons do tipo X contados!" << endl;
}

void encontrarPokemonsProximos() {
    cout << endl << "Pokemons proximos encontrados!" << endl;
}

// Função para exibir menu (Main clean)
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
    int menu = 1;

    cout << "Oi, seja bem-vindo a Pokedex!" << endl;

    while (menu != 0) {
        exibirMenu();
        cin >> menu;
    
        switch (menu) {
            case 1: 
                cadastrarCidade(); 
                break;
            case 2: 
                cadastrarEstrada(); 
                break;
            case 3: 
                buscarCentroPokemonProximo(); 
                break;
            case 4: 
                cadastrarPokemon(); 
                break;
            case 5: 
                removerPokemon(); 
                break;
            case 6: 
                listarPokemonsPorNome(); 
                break;
            case 7: 
                listarPokemonsPorTipo(); 
                break;
            case 8: 
                contarPokemonsPorTipo();    
                break;
            case 9: 
                encontrarPokemonsProximos(); 
                break;
            case 0: 
                cout << "Saindo..." << endl; 
                break;
            default: 
                cout << endl << "Opcao invalida. Tente novamente." << endl;
        }
    }

    return 0;
}