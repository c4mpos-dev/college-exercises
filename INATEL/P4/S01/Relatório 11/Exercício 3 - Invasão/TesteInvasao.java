public class TesteInvasao {
    public static void main(String[] args) {
        
        Poder telepatia = new Poder("Telepatia");
        Poder ilusionismo = new Poder("Ilusionismo");
        Poder controleFogo = new Poder("Controle de Fogo");

        Alien zargon = new Alien("Zargon", "Área 51", telepatia, "Xylar-4", "O-31");
        Youkai kitsune = new Youkai("Kitsune", "Floresta de Aokigahara", ilusionismo);
        Alien zargon2 = new Alien("Zargon", "Deserto do Atacama", telepatia, "Xylar-4", "O-31");
        Youkai karasu = new Youkai("Karasu-Tengu", "Monte Kurama", controleFogo);

        Registros equipeDelta = new Registros("Delta Oculta");

        equipeDelta.registrarAvistamento(zargon);
        equipeDelta.registrarAvistamento(kitsune);
        equipeDelta.registrarAvistamento(karasu);
        
        equipeDelta.registrarAvistamento(zargon2);

        equipeDelta.listarAvistamentos();
    }
}