public class Youkai extends Entidade implements IRastreavel {
    
    public Youkai(String nome, String localizacao, Poder poder) {
        super(nome, localizacao, poder);
    }

    @Override
    public String obterCoordenadas() {
        return "Youkai " + getNome() + " detectado em: " + getLocalizacao() + 
               " (Poder: " + getPoder().getNome() + ")";
    }
}