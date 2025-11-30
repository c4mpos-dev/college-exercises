public class CafeLeBlanc {
    private Menu menu;

    public CafeLeBlanc(Menu menu) {
        this.menu = menu;
        System.out.println("Cafeteria LeBlanc aberta com um novo menu.");
    }

    public void receberPedido(Cafe cafe) {
        double preco = cafe.calcularPrecoFinal();
        
        System.out.printf("\nPedido recebido: %s. Preço a pagar: R$%.2f\n", 
                          cafe.getNome(), preco);
        
        if (cafe instanceof CafeGourmet) {
             System.out.println("Ah, um café Gourmet! Bônus de Aroma aplicado.");
        }
    }

    public Menu getMenu() {
        return menu;
    }
}