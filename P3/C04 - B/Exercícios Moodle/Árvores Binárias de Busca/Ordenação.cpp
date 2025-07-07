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
		show_ordered(curr->right);
	    cout << curr->info << " ";
		show_ordered(curr->left);
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

    while (cin >> N && N != -1) 
        insert(root, N);
    
    show_ordered(root);

    destruct(root);
    return 0;
}