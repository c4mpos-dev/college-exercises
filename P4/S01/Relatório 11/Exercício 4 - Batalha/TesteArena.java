public class TesteArena {
    public static void main(String[] args) {
        
        PadraoAtaque garra = new PadraoAtaque("Garra Destruidora", 50);
        PadraoAtaque onda = new PadraoAtaque("Onda de Choque", 35);
        PadraoAtaque fogo = new PadraoAtaque("Bola de Fogo", 75);
        PadraoAtaque cura = new PadraoAtaque("Regeneração Rápida", 0);

        Boss golem = new Boss("Golem de Rocha", "G-900", "Gelo");
        golem.adicionarAtaque(garra);
        golem.adicionarAtaque(onda);
        
        BossMagico dragao = new BossMagico("Dragão Arcano", "D-M15", "Venenoso");
        dragao.adicionarAtaque(fogo);
        dragao.adicionarAtaque(cura);
        
        Batalha arenaPrincipal = new Batalha("Pico da Ruína");
        
        arenaPrincipal.adicionarBoss(golem);
        arenaPrincipal.adicionarBoss(dragao);
        
        arenaPrincipal.iniciarBatalha("G-900"); 
        
        arenaPrincipal.iniciarBatalha("D-M15"); 
        
        arenaPrincipal.iniciarBatalha("X-999");
    }
}