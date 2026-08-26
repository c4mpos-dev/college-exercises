public class TesteCasteloAnimado {
    public static void main(String[] args) {
        System.out.println("--- Criando Personagens e Castelo ---");
        
        Mago howl = new Mago("Howl", 27, "Transformação");
        System.out.println("Mago criado: " + howl.getNome() + ", Idade: " + howl.getIdade());
        
        System.out.println("Ação do Mago: " + howl.lancarFeitico());
        
        System.out.println("\n--- Criando Divisões ---");

        Divisao quarto = new Divisao("Quarto do Howl");
        Divisao cozinha = new Divisao("Cozinha");
        
        Castelo casteloAnimado = new Castelo("Castelo Mágico");
        
        casteloAnimado.adicionarDivisao(quarto);
        casteloAnimado.adicionarDivisao(cozinha);
        
        casteloAnimado.mostrarDivisoes();
    }
}