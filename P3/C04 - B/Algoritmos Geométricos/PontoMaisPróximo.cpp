#include <iostream>
using namespace std;

struct Ponto {
    int x, y;
};

int distancia_quadrada(Ponto a, Ponto b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int main() {
    int N;
    cin >> N;

    Ponto pontos[100];
    for (int i = 0; i < N; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    Ponto usuario;
    cin >> usuario.x >> usuario.y;

    Ponto maisProximo = pontos[0];
    int menorDist = distancia_quadrada(usuario, pontos[0]);

    for (int i = 1; i < N; i++) {
        int dist = distancia_quadrada(usuario, pontos[i]);
        if (dist < menorDist) {
            menorDist = dist;
            maisProximo = pontos[i];
        } else if (dist == menorDist) {
            if (pontos[i].x < maisProximo.x || 
               (pontos[i].x == maisProximo.x && pontos[i].y < maisProximo.y)) {
                maisProximo = pontos[i];
            }
        }
    }

    cout << maisProximo.x << " " << maisProximo.y << endl;

    return 0;
}