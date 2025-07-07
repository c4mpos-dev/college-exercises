#include <iostream>
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

// encontrar o menor valor (extrema esquerda)
int menor(Node* root) {
    if (root == NULL) return -1; // Árvore vazia
    while (root->left != NULL) {
        root = root->left;
    }
    return root->info;
}

// encontrar o maior valor (extrema direita)
int maior(Node* root) {
    if (root == NULL) return -1; // Árvore vazia
    while (root->right != NULL) {
        root = root->right;
    }
    return root->info;
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
    int value;

    while (cin >> value && value != -1) {
        insert(root, value);
    }

    cout << menor(root) << " e " << maior(root) << endl;

    destruct(root);
    return 0;
}