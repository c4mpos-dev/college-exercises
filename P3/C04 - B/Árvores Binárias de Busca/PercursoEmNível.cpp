#include <iostream>
#include <list>
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

// nível usando list como fila
void percursoEmNivel(Node* root) {
    if (root == NULL) return;

    list<Node*> fila;
    fila.push_back(root);

    while (!fila.empty()) {
        Node* atual = fila.front();
        fila.pop_front();

        cout << atual->info << " ";

        if (atual->left != NULL)
            fila.push_back(atual->left);
        if (atual->right != NULL)
            fila.push_back(atual->right);
    }

    cout << endl;
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
    int valor;

    while (cin >> valor && valor != -1) {
        insert(root, valor);
    }

    percursoEmNivel(root);

    destruct(root);
    return 0;
}
