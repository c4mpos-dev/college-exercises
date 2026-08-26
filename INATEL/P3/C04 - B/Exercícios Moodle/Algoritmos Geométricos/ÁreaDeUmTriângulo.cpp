#include <iostream>
#include <cmath>
using namespace std;

struct Ponto {
    int x, y;
};

float area_triangulo(Ponto a, Ponto b, Ponto c) {
    return abs(
        a.x * (b.y - c.y) +
        b.x * (c.y - a.y) +
        c.x * (a.y - b.y)
    ) / 2.0;
}

int main() {
    Ponto a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    float area = area_triangulo(a, b, c);
    cout << area/1.0 << endl;

    return 0;
}