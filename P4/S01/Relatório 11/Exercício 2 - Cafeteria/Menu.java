import java.util.ArrayList;

public class Menu {
    private ArrayList<Cafe> itens;

    public Menu() {
        this.itens = new ArrayList<>();
    }
    
    public Menu(ArrayList<Cafe> cafesIniciais) {
        this.itens = new ArrayList<>(cafesIniciais);
    }

    public void adicionarItem(Cafe cafe) {
        this.itens.add(cafe);
        System.out.println("Item adicionado ao Menu: " + cafe.getNome());
    }

    public void exibirMenu() {
        System.out.println("\n--- MENU DA CAFETERIA ---");
        for (int i = 0; i < itens.size(); i++) {
            Cafe item = itens.get(i);
            System.out.printf("%d. %s (Base: R$%.2f | Final: R$%.2f)\n", 
                (i + 1), item.getNome(), item.getPrecoBase(), item.calcularPrecoFinal());
        }
        System.out.println("-------------------------");
    }

    public ArrayList<Cafe> getItens() {
        return itens;
    }
}