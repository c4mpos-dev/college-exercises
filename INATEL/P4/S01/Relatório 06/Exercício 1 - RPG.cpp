#include <iostream>
#include <string>
using namespace std;

class Personagem {
    private:
        string nome;
        int nivel;
        int dano;
        int vida;

    public:
        Personagem(string n, int lvl, int d, int v) {
            nome = n;
            nivel = lvl;
            dano = d;
            vida = v;
        }

        void atacar(Personagem &alvo) {
            cout << nome << " ataca " << alvo.nome << " causando " << dano << " de dano!" << endl;
            alvo.vida -= dano;
            if (alvo.vida < 0) alvo.vida = 0; // impede que a vida fique negativa
        }

        void mostrarInfo() {
            cout << "Nome: " << nome
                << ", Nivel: " << nivel
                << ", Dano: " << dano
                << ", Vida: " << vida << endl;
        }
};

int main() {
    Personagem heroi("Caua", 5, 15, 100);
    Personagem monstro("Campos", 3, 10, 60);

    cout << "Estado inicial:" << endl;
    heroi.mostrarInfo();
    monstro.mostrarInfo();
    cout << endl;

    heroi.atacar(monstro);

    monstro.atacar(heroi);

    cout << "\nEstado depois do combate:" << endl;
    heroi.mostrarInfo();
    monstro.mostrarInfo();

    return 0;
}