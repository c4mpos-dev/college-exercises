public class TesteCafeteria {
    public static void main(String[] args) {
        
        Cafe cafeSimples = new Cafe("Expresso", 4.00);
        CafeGourmet cafeDaCasa = new CafeGourmet("Latte Macchiato", 8.50, 1.50);
        Cafe cafePreto = new Cafe("Americano", 5.00);
        
        Menu menuDoDia = new Menu();
        menuDoDia.adicionarItem(cafeSimples);
        menuDoDia.adicionarItem(cafeDaCasa);
        menuDoDia.adicionarItem(cafePreto);
        
        menuDoDia.exibirMenu();
        
        CafeLeBlanc cafeteria = new CafeLeBlanc(menuDoDia);
        
        cafeteria.receberPedido(cafeSimples); 
        
        cafeteria.receberPedido(cafeDaCasa); 
    }
}