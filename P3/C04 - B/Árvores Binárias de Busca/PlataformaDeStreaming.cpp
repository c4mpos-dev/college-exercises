#include <iostream>
using namespace std;

struct Filme {
    string nome;
    string genero;
    int duracao;
    int classificacao;
    int ano;
    Filme* left;
    Filme* right;
};

void insert(Filme*& root, string nome, string genero, int duracao, int classificacao, int ano) {
    if (root == NULL) {
        root = new Filme{nome, genero, duracao, classificacao, ano, NULL, NULL};
    } else if (nome < root->nome) {
        insert(root->left, nome, genero, duracao, classificacao, ano);
    } else if (nome > root->nome) {
        insert(root->right, nome, genero, duracao, classificacao, ano);
    }
}

Filme* search(Filme* root, string nome) {
    if (root == NULL) return NULL;
    if (nome == root->nome) return root;
    if (nome < root->nome) return search(root->left, nome);
    return search(root->right, nome);
}

void destruct(Filme*& root) {
    if (root != NULL) {
        destruct(root->left);
        destruct(root->right);
        delete root;
        root = NULL;
    }
}

int main() {
    Filme* root = NULL;
    int opcao;

    while (true) {
        cin >> opcao;

        if (opcao == 0) {
            break;
        } else if (opcao == 1) {
            string nome, genero;
            int duracao, classificacao, ano;

            getline(cin >> ws, nome);
            getline(cin >> ws, genero);
            cin >> duracao >> classificacao >> ano;

            insert(root, nome, genero, duracao, classificacao, ano);

        } else if (opcao == 2) {
            string nome;
            getline(cin >> ws, nome);

            Filme* resultado = search(root, nome);
            if (resultado == NULL) {
                cout << "Filme nao encontrado" << endl;
            } else {
                cout << "Nome: " << resultado->nome << endl;
                cout << "Genero: " << resultado->genero << endl;
                cout << "Duracao: " << resultado->duracao << " mins" << endl;
                cout << "Classificacao: " << resultado->classificacao << endl;
                cout << "Ano: " << resultado->ano << endl;
            }

        } else {
            cout << "Operacao invalida" << endl;
        }
    }

    destruct(root);
    return 0;
}