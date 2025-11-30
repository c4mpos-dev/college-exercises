import java.util.ArrayList;

public class Castelo {
    private String nome;
    private ArrayList<Divisao> divisoes; 

    public Castelo(String nome) {
        this.nome = nome;
        this.divisoes = new ArrayList<>(); 
    }

    public void adicionarDivisao(Divisao divisao) {
        this.divisoes.add(divisao);
        System.out.println("A divisão '" + divisao.getNome() + "' foi adicionada ao castelo " + this.nome + ".");
    }
    
    public String getNome() {
        return nome;
    }

    public ArrayList<Divisao> getDivisoes() {
        return divisoes;
    }
    
    public void mostrarDivisoes() {
        System.out.println("\nDivisões do Castelo " + this.nome + ":");
        if (this.divisoes.isEmpty()) {
            System.out.println("Nenhuma divisão cadastrada.");
        } else {
            for (Divisao d : this.divisoes) {
                System.out.println("- " + d.getNome());
            }
        }
    }
}