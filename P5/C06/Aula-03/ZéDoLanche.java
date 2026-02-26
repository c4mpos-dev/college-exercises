package org.example;

public class Main {
    public static void main(String[] args) {
        int horas = 3;
        int primeiraHora = 10;
        int segundaHora = 4;
        int terceiraHora = 2;

        int soma = primeiraHora + segundaHora + terceiraHora;
        double  media = soma / horas;

        System.out.println("Total: ", + soma);
        System.out.println("Média: ", + media);
    }
}