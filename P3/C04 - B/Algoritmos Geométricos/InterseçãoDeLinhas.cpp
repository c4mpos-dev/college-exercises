#include <iostream>
using namespace std;

struct Ponto {
    int x, y;
};

// Retorna a orientação entre 3 pontos
int orientacao(Ponto a, Ponto b, Ponto c) {
    int val = (b.y - a.y)*(c.x - b.x) - (b.x - a.x)*(c.y - b.y);
    if (val == 0) return 0; // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

// Verifica se q está no segmento pr
bool noSegmento(Ponto p, Ponto q, Ponto r) {
    return q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
           q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y);
}

// Verifica se os segmentos AB e CD se cruzam
bool cruzam(Ponto a, Ponto b, Ponto c, Ponto d) {
    int o1 = orientacao(a, b, c);
    int o2 = orientacao(a, b, d);
    int o3 = orientacao(c, d, a);
    int o4 = orientacao(c, d, b);

    // Caso geral
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiais (colinearidade)
    if (o1 == 0 && noSegmento(a, c, b)) return true;
    if (o2 == 0 && noSegmento(a, d, b)) return true;
    if (o3 == 0 && noSegmento(c, a, d)) return true;
    if (o4 == 0 && noSegmento(c, b, d)) return true;

    return false;
}

int main() {
    Ponto a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    if (cruzam(a, b, c, d))
        cout << "SIM" << endl;
    else
        cout << "NAO" << endl;

    return 0;
}