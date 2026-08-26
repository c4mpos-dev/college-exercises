public class CafeGourmet extends Cafe {
    private double bonusAroma;

    public CafeGourmet(String nome, double precoBase, double bonusAroma) {
        super(nome, precoBase);
        this.bonusAroma = bonusAroma;
    }

    @Override
    public double calcularPrecoFinal() {
        return super.calcularPrecoFinal() + this.bonusAroma;
    }

    public double getBonusAroma() {
        return bonusAroma;
    }
}