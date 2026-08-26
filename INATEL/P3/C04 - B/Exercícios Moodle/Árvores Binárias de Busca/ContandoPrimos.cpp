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

// verifica se um número é primo
bool primo(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;
    return true;
}

// conta primos na árvore
int countPrimos(Node* root) {
    if (root == NULL)
        return 0;
    
    int count = 0;
    if (primo(root->info))
        count = 1;

    return count + countPrimos(root->left) + countPrimos(root->right);
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
    int n;

    while (cin >> n && n != -1) {
        insert(root, n);
    }

    int primos = countPrimos(root);
    cout << primos << " numeros primos" << endl;

    destruct(root);
    return 0;
}