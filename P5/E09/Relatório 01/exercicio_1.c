#include <stdio.h>

int main() {
    int quantidade;
    float precoUnitario, precoTotal;

    scanf("%d", &quantidade);

    if (quantidade < 12) {
        precoUnitario = 0.80;
    } else {
        precoUnitario = 0.65;
    }

    precoTotal = quantidade * precoUnitario;

    printf("Preco da unidade: R$%.2f\n", precoUnitario);
    printf("Preco total: R$%.2f\n", precoTotal);

    return 0;
}