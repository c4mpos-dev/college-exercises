// Cauã Campos de Souza e Silva - 651 - GES

#include <stdio.h>

int main() {
    int n, i;

    scanf("%d", &n);

    if (n < 0 || n > 50) {
        printf("Valor invalido\n");
        return 0;
    }

    for (i = n - 1; i >= 1; i--) {
        printf("Resto da divisao de %d por %d: %d\n", n, i, n % i);
    }

    return 0;
}