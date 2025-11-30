import java.util.HashMap;

public class Batalha {
    private String arena;
    private HashMap<String, Boss> bossesDisponiveis;

    public Batalha(String arena) {
        this.arena = arena;
        this.bossesDisponiveis = new HashMap<>();
    }

    public void adicionarBoss(Boss boss) {
        this.bossesDisponiveis.put(boss.getIdBoss(), boss);
        System.out.println("Boss " + boss.getNome() + " adicionado à Arena: " + arena);
    }

    public void iniciarBatalha(String idBoss) {
        Boss bossParaBatalha = this.bossesDisponiveis.get(idBoss);

        if (bossParaBatalha != null) {
            System.out.println("\n*** BATALHA INICIADA na Arena " + arena + "! ***");
            bossParaBatalha.iniciarFase();
            System.out.println("******************************************");
        } else {
            System.out.println("\nERRO: Boss com ID " + idBoss + " não encontrado nesta Arena.");
        }
    }
}