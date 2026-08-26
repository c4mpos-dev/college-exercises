#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

void insert(Node*& root, int value) {
    if (root == NULL)
        root = new Node{value, NULL, NULL};
    else if (value < root->info)
        insert(root->left, value);
    else
        insert(root->right, value);
}

// conta folhas da árvore
int contaFolhas(Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return contaFolhas(root->left) + contaFolhas(root->right);
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

    cout << contaFolhas(root) << endl;

    destruct(root);
    return 0;
}