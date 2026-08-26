#include <iostream>
using namespace std;

struct Node{
	int info;
	Node * left;
	Node * right;	
};

void insert(Node * &curr, int info){
	if(curr == NULL){
		curr = new Node;
		curr->info = info;
		curr->right = NULL;
		curr->left = NULL;
	} else {
		if(info < curr->info){
			insert(curr->left,info);
		} else {
			insert(curr->right,info);
		}
	}
}

void show_ordered(Node* curr){
	if(curr != NULL) {
		show_ordered(curr->left);
	    cout << curr->info << " ";
		show_ordered(curr->right);
    }
}

Node* repoint_smaller(Node * & curr){
	if(curr->left == NULL){
		Node * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return repoint_smaller(curr->left);
	}
}

// Remove todos os nós com valor info
bool remove(Node*& curr, int info) {
    if (curr == NULL) return false;

    if (info < curr->info) {
        return remove(curr->left, info);
    } else if (info > curr->info) {
        return remove(curr->right, info);
    } else {
        // Encontrado
        Node* aux = curr;
        if (curr->left == NULL) {
            curr = curr->right;
        } else if (curr->right == NULL) {
            curr = curr->left;
        } else {
            aux = repoint_smaller(curr->right);
            curr->info = aux->info;
        }
        delete aux;
        // Tentar remover novamente se houver outro igual
        remove(curr, info);
        return true;
    }
}

void destruct(Node *& curr){
	if(curr != NULL){
		destruct(curr->left);
		destruct(curr->right);
		delete curr;
		curr = NULL;
	}
}

int main(){
	int N = 1;
    Node* root = NULL;

    while (N != 0) {
        cin >> N;
        if (N <= 0) break;

        insert(root, N);
    }

    int X;
    cin >> X;

    remove(root, X);
    
    show_ordered(root);

    destruct(root);
    return 0;
}