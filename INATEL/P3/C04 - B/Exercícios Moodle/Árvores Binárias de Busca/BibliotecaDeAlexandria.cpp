#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* left;
    Node* right;
};

void insert(Node*& curr, int info) {
    if (curr == NULL) {
        curr = new Node;
        curr->info = info;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (info < curr->info)
            insert(curr->left, info);
        else
            insert(curr->right, info);
    }
}

bool search(Node* curr, int info) {
    if (curr == NULL) {
        return false;
    } else if (info == curr->info) {
        return true;
    } else if (info < curr->info) {
        return search(curr->left, info);
    } else {
        return search(curr->right, info);
    }
}

void destruct(Node*& curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    char type;
    int N, X;
    cin >> N;

    Node* root = NULL;

    for (int i = 0; i < N; ++i) {
        cin >> type;
        cin >> X;

        if (type == 'i') {
            insert(root, X);
        } else if (type == 'b') {
            if (search(root, X)) {
                cout << "Sim" << endl;
            } else {
                cout << "Não" << endl;
            }
        }
    }

    destruct(root); // liberar memória
    return 0;
}