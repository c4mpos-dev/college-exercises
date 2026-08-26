public class BossMagico extends Boss {
    
    public BossMagico(String nome, String idBoss, String fracoContra) {
        super(nome, idBoss, fracoContra);
    }

    @Override
    public void iniciarFase() {
        super.iniciarFase();
        System.out.println("Alerta Mágico! Este Boss tem feitiços poderosos!");
    }
}