// Cauã Campos de Souza e Silva - 651 - GES

#include <stdio.h>

void analisarNumeros(int a, int b, int c, int d, int e) {
    int pares = 0, impares = 0, positivos = 0, negativos = 0;
    int v[5] = {a, b, c, d, e};

    for (int i = 0; i < 5; i++) {
        if (v[i] % 2 == 0)
            pares++;
        else
            impares++;

        if (v[i] >= 0)
            positivos++;
        else if (v[i] < 0)
            negativos++;
    }

    printf("Quantidade de numeros pares: %d\n", pares);
    printf("Quantidade de numeros impares: %d\n", impares);
    printf("Quantidade de numeros positivos: %d\n", positivos);
    printf("Quantidade de numeros negativos: %d\n", negativos);
}

int main() {
    int n;
    int a, b, c, d, e;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
        analisarNumeros(a, b, c, d, e);
    }

    return 0;
}