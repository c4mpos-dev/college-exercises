package org.example;

public class exercicio02 {
    public static void main(String[] args) {
        int quantidadeInteiros = 8;
        int valorInteiro = 30;
        int quantidadeMeiaEntrada = 5;
        int valorMeiaEntrada = 15;

        int totalInteiros = quantidadeInteiros * valorInteiro;
        int totalMeiaEntrada = quantidadeMeiaEntrada * valorMeiaEntrada;
        int totalArrecadado = totalInteiros + totalMeiaEntrada;
        int totalIngressos = quantidadeInteiros + quantidadeMeiaEntrada;
        double mediaPagoPorIngresso = (double) totalArrecadado / totalIngressos;

        System.out.println("Total arrecadado com ingressos inteiros: R$ " + totalInteiros);
        System.out.println("Total arrecadado com meia-entrada: R$ " + totalMeiaEntrada);
        System.out.println("Valor total arrecadado na sessão: R$ " + totalArrecadado);
        System.out.println("Valor médio pago por ingresso: R$ " + mediaPagoPorIngresso);
    }
}