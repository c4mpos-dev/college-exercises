#include <iostream>
#include <list>
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

// Pré-ordem
void preOrder(Node* root, list<int>& l) {
    if (root != NULL) {
        l.push_back(root->info);
        preOrder(root->left, l);
        preOrder(root->right, l);
    }
}

// Em-ordem
void inOrder(Node* root, list<int>& l) {
    if (root != NULL) {
        inOrder(root->left, l);
        l.push_back(root->info);
        inOrder(root->right, l);
    }
}

// Pós-ordem
void postOrder(Node* root, list<int>& l) {
    if (root != NULL) {
        postOrder(root->left, l);
        postOrder(root->right, l);
        l.push_back(root->info);
    }
}

// posição de um valor em uma list<int>
int findPos(list<int>& l, int x) {
    int pos = 0;
    for (int val : l) {
        if (val == x)
            return pos;
        pos++;
    }
    return -1;
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

    int x; // cidade com chocolate
    cin >> x;

    // Percursos usando list
    list<int> pre, in, post;
    preOrder(root, pre);
    inOrder(root, in);
    postOrder(root, post);

    // Posições onde X aparece
    int pPre = findPos(pre, x);
    int pIn = findPos(in, x);
    int pPost = findPos(post, x);

    if (pPre < pIn && pPre < pPost)
        cout << "Pre" << endl;
    else if (pIn < pPre && pIn < pPost)
        cout << "Em" << endl;
    else
        cout << "Pos" << endl;

    destruct(root);
    return 0;
}