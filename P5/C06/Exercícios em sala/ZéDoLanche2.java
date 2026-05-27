package org.example;
import java.util.Scanner;

public class ZéDoLanche2 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o número de lanches consumidos: ");
        int numeroDeLanches = scanner.nextInt();

        int soma = 0;
        for (int i = 1; i <= numeroDeLanches; i++) {
            System.out.println("Digite o valor do lanche " + i + ": ");
            int valorLanche = scanner.nextInt();
            soma += valorLanche;
        }

        double media = (double) soma / numeroDeLanches;

        System.out.println("Total gasto: " + soma);
        System.out.println("Média por lanche: " + media);

        scanner.close();
    }
}