#include <iostream>
using namespace std;

struct Ponto {
    int x, y;
};

bool pontoDentro(Ponto poligono[], int n, Ponto p) {
    int cont = 0;
    for (int i = 0; i < n; i++) {
        Ponto a = poligono[i];
        Ponto b = poligono[(i + 1) % n];

        // Verifica se a aresta cruza a linha horizontal a partir de p
        if ((a.y > p.y) != (b.y > p.y)) {
            float intersecX = (float)(b.x - a.x) * (p.y - a.y) / (b.y - a.y) + a.x;
            if (p.x < intersecX)
                cont++;
        }
    }
    return (cont % 2 == 1);
}

int main() {
    int n;
    cin >> n;
    Ponto poligono[110];
    for (int i = 0; i < n; i++) {
        cin >> poligono[i].x >> poligono[i].y;
    }

    Ponto p;
    cin >> p.x >> p.y;

    if (pontoDentro(poligono, n, p)) {
        cout << "DENTRO" << endl;
    } else {
        cout << "!(DENTRO)" << endl;
    }

    return 0;
}