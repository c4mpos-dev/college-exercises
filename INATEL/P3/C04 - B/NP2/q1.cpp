#include <iostream>
using namespace std;

struct Peixe {
    int i;
    double V;
    double E;
    double O;
    int T;
    Peixe* left;
    Peixe* right;
};


void insert(Peixe*& curr, double V, double E, double O, int i) {
    if (curr == NULL) {
        curr = new Peixe;
        curr->V = V;
        curr->E = E;
        curr->O = O;
        curr->T = int(V * E * 7 * E * 7 * O);
        curr->i = i;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (V < curr->V)
            insert(curr->left, V, E, O, i);
        else
            insert(curr->right, V, E, O, i);
    }
}

void collect_between_T(Peixe* curr, Peixe* result[], int& count, int Tmin, int Tmax) {
    if (curr != NULL) {
        collect_between_T(curr->left, result, count, Tmin, Tmax);
        if (curr->T >= Tmin && curr->T <= Tmax) {
            result[count++] = curr;
        }
        collect_between_T(curr->right, result, count, Tmin, Tmax);
    }
}

void sort_desc(Peixe* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j]->T < arr[j + 1]->T) {
                Peixe* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void show_ordered_desc_of_T(Peixe* root, int Tmin, int Tmax) {
    Peixe* result[1000]; // o p nao passa de 1000 (foi colocado no enunciado do moodle)
    int count = 0;

    collect_between_T(root, result, count, Tmin, Tmax);
    sort_desc(result, count);

    for (int i = 0; i < count; i++) {
        cout << result[i]->i << ":" << result[i]->T << endl;
    }
}

void destruct(Peixe*& curr) {
    if (curr != NULL) {
        destruct(curr->left);
        destruct(curr->right);
        delete curr;
        curr = NULL;
    }
}

int main() {
    int P = -1, Tmin, Tmax;
    double V, E, O;
    Peixe* root = NULL;

    while (P <= 0 || P >= 1000) {
        cin >> P;
    }

    for (int i = 0; i < P; i++) {
        cin >> V >> E >> O;
        insert(root, V, E, O, i);
    }

    cin >> Tmin >> Tmax;
    show_ordered_desc_of_T(root, Tmin, Tmax);

    destruct(root);
    return 0;
}