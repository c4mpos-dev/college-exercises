import java.util.HashMap;

public class Registros {
    private String nomeEquipe;
    private HashMap<String, Entidade> avistamentos;

    public Registros(String nomeEquipe) {
        this.nomeEquipe = nomeEquipe;
        this.avistamentos = new HashMap<>();
    }

    public boolean registrarAvistamento(Entidade entidade) {
        if (this.avistamentos.containsKey(entidade.getNome())) {
            System.out.println("ERRO: Entidade " + entidade.getNome() + " já foi registrada.");
            return false;
        } else {
            this.avistamentos.put(entidade.getNome(), entidade);
            System.out.println("SUCESSO: Entidade " + entidade.getNome() + " registrada.");
            return true;
        }
    }
    
    public void listarAvistamentos() {
        System.out.println("\n--- Relatório da Equipe " + nomeEquipe + " ---");
        
        for (Entidade e : this.avistamentos.values()) {
            if (e instanceof IRastreavel) {
                System.out.println("-> " + ((IRastreavel) e).obterCoordenadas());
            } else {
                System.out.println("-> Entidade " + e.getNome() + " registrada, mas não rastreável.");
            }
        }
    }
}