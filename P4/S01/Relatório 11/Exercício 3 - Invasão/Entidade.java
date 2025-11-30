public class Entidade {
    private String nome;
    private String localizacao;
    private Poder poder;

    public Entidade(String nome, String localizacao, Poder poder) {
        this.nome = nome;
        this.localizacao = localizacao;
        this.poder = poder;
    }

    public String getNome() {
        return nome;
    }

    public String getLocalizacao() {
        return localizacao;
    }

    public Poder getPoder() {
        return poder;
    }
}