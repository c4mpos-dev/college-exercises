#include <iostream>
#include <iomanip> // para std::setprecision
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

void insert(Node*& root, int value) {
    if (root == NULL) {
        root = new Node{value, NULL, NULL};
    } else if (value < root->info) {
        insert(root->left, value);
    } else {
        insert(root->right, value);
    }
}

// auxiliar para somar e contar os nós
void sume(Node* root, int& soma, int& cont) {
    if (root != NULL) {
        soma += root->info;
        cont++;
        sume(root->left, soma, cont);
        sume(root->right, soma, cont);
    }
}

// calcular a média
float media(Node* root) {
    int soma = 0;
    int cont = 0;
    sume(root, soma, cont);
    if (cont == 0) return 0.0;
    return (float)soma / cont;
}

void destruct(Node*& root) {
    if (root != NULL) {
        destruct(root->left);
        destruct(root->right);
        delete root;
        root = NULL;
    }
}

int main() {
    Node* root = NULL;
    int N;

    while (cin >> N && N != -1) {
        insert(root, N);
    }

    cout << "Media: ";
    float result = media(root);
    cout << fixed << setprecision(2) << result << endl;

    destruct(root);
    return 0;
}