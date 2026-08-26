public class Alien extends Entidade implements IRastreavel {
    private String planetaOrigem;
    private String ovni;

    public Alien(String nome, String localizacao, Poder poder, String planetaOrigem, String Ovni) {
        super(nome, localizacao, poder);
        this.planetaOrigem = planetaOrigem;
        this.ovni = Ovni;
    }

    @Override
    public String obterCoordenadas() {
        return "Alien " + getNome() + " detectado em: " + getLocalizacao() + 
               " | Origem: " + planetaOrigem + 
               " | OVNI: " + ovni + 
               " | (Poder: " + getPoder().getNome() + ")";
    }
    public String getPlanetaOrigem() {
        return planetaOrigem;
    }

    public String getOvni() {
        return ovni;
    }
}
