#include <iostream>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

struct Ponto {
    int x, y;
};

Ponto p0;

void swap(Ponto &a, Ponto &b) {
    Ponto temp = a;
    a = b;
    b = temp;
}

float area(Ponto a, Ponto b, Ponto c) {
    return (
        a.x * b.y - a.y * b.x + 
        a.y * c.x - a.x * c.y + 
        b.x * c.y - b.y * c.x
    ) / 2.0;
}

int orientacao(Ponto p1, Ponto p2, Ponto p3) {
    float a = area(p1, p2, p3);
    if (a == 0) return 0;
    return (a < 0) ? 1 : 2;
}

float dist(Ponto p1, Ponto p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + 
                (p1.y - p2.y)*(p1.y - p2.y));
}

float dist_quadrada(Ponto p1, Ponto p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + 
           (p1.y - p2.y)*(p1.y - p2.y);
}

int compare(const void *a, const void *b) {
    Ponto *p1 = (Ponto *)a;
    Ponto *p2 = (Ponto *)b;
    int o = orientacao(p0, *p1, *p2);
    if (o == 0) {
        return (dist_quadrada(p0, *p1) < dist_quadrada(p0, *p2)) ? -1 : 1;
    }
    return (o == 2) ? -1 : 1;
}

Ponto anterior(stack<Ponto> &s) {
    Ponto topo = s.top(); s.pop();
    Ponto anterior = s.top(); s.push(topo);
    return anterior;
}

float fecho_convexo(Ponto pontos[], int n) {
    int ymin = pontos[0].y, imin = 0;
    for (int i = 1; i < n; i++) {
        if ((pontos[i].y < ymin) || (pontos[i].y == ymin && pontos[i].x < pontos[imin].x)) {
            ymin = pontos[i].y;
            imin = i;
        }
    }

    swap(pontos[0], pontos[imin]);
    p0 = pontos[0];
    qsort(&pontos[1], n - 1, sizeof(Ponto), compare);

    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && orientacao(p0, pontos[i], pontos[i+1]) == 0)
            i++;
        pontos[m++] = pontos[i];
    }

    if (m < 3) return 0;

    stack<Ponto> fecho;
    fecho.push(p0);
    fecho.push(pontos[1]);
    fecho.push(pontos[2]);

    for (int i = 3; i < m; i++) {
        while (fecho.size() > 1 && orientacao(anterior(fecho), fecho.top(), pontos[i]) != 2) {
            fecho.pop();
        }
        fecho.push(pontos[i]);
    }

    // Calcular o perímetro
    float perimetro = 0;
    Ponto primeiro = fecho.top();
    Ponto anterior = fecho.top(); fecho.pop();

    while (!fecho.empty()) {
        Ponto atual = fecho.top(); fecho.pop();
        perimetro += dist(anterior, atual);
        anterior = atual;
    }
    perimetro += dist(anterior, primeiro);

    return perimetro;
}

int main() {
    int n;
    cin >> n;
    Ponto pontos[105];

    for (int i = 0; i < n; i++) {
        cin >> pontos[i].x >> pontos[i].y;
    }

    float resultado = fecho_convexo(pontos, n);
    cout << resultado << endl;

    return 0;
}