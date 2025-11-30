import java.util.LinkedHashSet;
import java.util.Set;

public class Boss {
    private String nome;
    private String idBoss;
    private String fracoContra;
    private Set<PadraoAtaque> moveset;

    public Boss(String nome, String idBoss, String fracoContra) {
        this.nome = nome;
        this.idBoss = idBoss;
        this.fracoContra = fracoContra;
        this.moveset = new LinkedHashSet<>();
    }

    public void adicionarAtaque(PadraoAtaque ataque) {
        this.moveset.add(ataque);
    }

    public void iniciarFase() {
        System.out.println("--- " + nome + " (ID: " + idBoss + ") entra na Arena! ---");
        System.out.println("Fraqueza: " + fracoContra);
        System.out.println("Movimentos: ");
        for (PadraoAtaque ataque : moveset) {
            System.out.println("- " + ataque.getNome() + " (Dano: " + ataque.getDano() + ")");
        }
    }

    public String getIdBoss() {
        return idBoss;
    }
    
    public String getNome() {
        return nome;
    }
}