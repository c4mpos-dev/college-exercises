#include <iostream>
#include <cmath>

using namespace std;

struct Peixe {
    int i;
    double C;
    Peixe* left;
    Peixe* right;
};

void insert(Peixe*& curr, double C, int i) {
    if (curr == NULL) {
        curr = new Peixe;
        curr->C = C;
        curr->i = i;
        curr->left = NULL;
        curr->right = NULL;
    } else {
        if (C < curr->C)
            insert(curr->left, C, i);
        else
            insert(curr->right, C, i);
    }
}

void collect_in_order(Peixe* curr, Peixe* result[], int& count) {
    if (curr != NULL) {
        collect_in_order(curr->left, result, count);
        result[count++] = curr;
        collect_in_order(curr->right, result, count);
    }
}

void sort_desc(Peixe* arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j]->C > arr[j + 1]->C) {
                Peixe* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void show_ordered(Peixe* root) {
    Peixe* result[1000]; // o p nao passa de 1000 (foi colocado no enunciado do moodle)
    int count = 0;

    collect_in_order(root, result, count);
    sort_desc(result, count);

    for (int i = 0; i < count; i++) {
        cout << result[i]->i << ":" << result[i]->C << endl;
    }
}

int main() {
    int P;
    cin >> P;

    Peixe* root = NULL;

    for (int i = 0; i < P; i++) {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        double d1 = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        double d2 = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));

        double C = max(d1, d2);

        insert(root, C, i);
    }

    show_ordered(root);

    return 0;
}