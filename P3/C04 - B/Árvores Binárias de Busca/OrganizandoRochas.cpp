#include <iostream>
using namespace std;

struct Rocha {
    string nome;
    string tipo;
    Rocha* left;
    Rocha* right;
};

void insert(Rocha*& curr, string nome, string tipo) {
    if (curr == NULL) {
        curr = new Rocha;
        curr->nome = nome;
        curr->tipo = tipo;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (nome < curr->nome)
            insert(curr->left, nome, tipo);
        else
            insert(curr->right, nome, tipo);
    }
}

Rocha* search(Rocha* curr, const string& nome) {
    if (curr == NULL) return NULL;
    if (nome == curr->nome) return curr;
    if (nome < curr->nome) return search(curr->left, nome);
    return search(curr->right, nome);
}


Rocha* repoint_smaller(Rocha*& curr){
	if(curr->left == NULL){
		Rocha * aux = curr;
		curr = curr->right;
		return aux;
	} else {
		return repoint_smaller(curr->left);
	}
}

Rocha* remove(Rocha* curr, const string& nome, const string& tipo, bool& success) {
    if (curr == NULL) {
        success = false;
        return NULL;
    }
    if (nome < curr->nome) {
        curr->left = remove(curr->left, nome, tipo, success);
    } else if (nome > curr->nome) {
        curr->right = remove(curr->right, nome, tipo, success);
    } else {
        if (curr->tipo != tipo) {
            success = false;
            return curr;
        }
        success = true;
        if (curr->left == NULL) {
            Rocha* temp = curr->right;
            delete curr;
            return temp;
        } else if (curr->right == NULL) {
            Rocha* temp = curr->left;
            delete curr;
            return temp;
        } else {
            Rocha* sucessor = curr->right;
            while (sucessor->left != NULL)
                sucessor = sucessor->left;
            curr->nome = sucessor->nome;
            curr->tipo = sucessor->tipo;
            curr->right = remove(curr->right, sucessor->nome, sucessor->tipo, success);
        }
    }
    return curr;
}

void destruct(Rocha*& curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    int comando;
    string nome, tipo;

    Rocha* root = NULL;

    while (true) {
        cin >> comando;
        if (comando == 0) break;
        
        if (comando == 1) {
            getline(cin >> ws, nome);
            getline(cin >> ws, tipo);
            insert(root, nome, tipo);
        } else if (comando == 2) {
            getline(cin >> ws, nome);

            Rocha* rocha = search(root, nome);
            if (rocha)
                cout << "Nome: " << rocha->nome << "\nTipo: " << rocha->tipo << endl;
            else
                cout << "Rocha nao encontrada" << endl;

        } else if (comando == 3) {
            getline(cin >> ws, nome);
            getline(cin >> ws, tipo);

            bool success = false;
            remove(root, nome, tipo, success);
            if (success)
                cout << "Rocha removida com sucesso" << endl;
            else
                cout << "Rocha nao encontrada para remocao" << endl;
        } else {
            cout << "Operacao invalida" << endl;
        }
    }

    destruct(root); // liberar memoria
    return 0;
}