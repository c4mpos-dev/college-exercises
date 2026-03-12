package Codes;

import java.util.Scanner;

public class Cinema_Q10 {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        //  variáveis explícitas
        int qtdInteira;
        int qtdMeia;
        String valorInteiraStr;
        String valorMeiaStr;
        double valorInteira;
        double valorMeia;
        double totalInteira;
        double totalMeia;
        double totalArrecadado;
        double valorMedio;
        int totalIngressos;

        // entrada com o scanner
        System.out.print("Quantidade de ingressos inteiros: ");
        qtdInteira = scanner.nextInt();

        // faz sentido só ser metade do preço da inteira, mas foi colocado scanner por ser exercício acadêmico
        System.out.print("Quantidade de ingressos meia-entrada: ");
        qtdMeia = scanner.nextInt();

        scanner.nextLine(); // limpa o buffer

        System.out.print("Valor do ingresso inteiro: ");
        valorInteiraStr = scanner.nextLine();

        // transforma , em .
        valorInteiraStr = valorInteiraStr.replace(",", ".");
        valorInteira = Double.parseDouble(valorInteiraStr);

        System.out.print("Valor do ingresso meia-entrada: ");
        valorMeiaStr = scanner.nextLine();

        // transforma , em .
        valorMeiaStr = valorMeiaStr.replace(",", ".");
        valorMeia = Double.parseDouble(valorMeiaStr);

        totalInteira = qtdInteira * valorInteira;
        totalMeia = qtdMeia * valorMeia;
        totalArrecadado = totalInteira + totalMeia;

        totalIngressos = qtdInteira + qtdMeia;
        valorMedio = totalArrecadado / totalIngressos;

        System.out.println("\n--- Resultados ---");
        System.out.println("Total arrecadado com ingressos inteiros: R$ " + totalInteira);
        System.out.println("Total arrecadado com meia-entrada: R$ " + totalMeia);
        System.out.println("Total arrecadado na sessão: R$ " + totalArrecadado);
        System.out.println("Valor médio pago por ingresso: R$ " + valorMedio);

        scanner.close();
    }
}