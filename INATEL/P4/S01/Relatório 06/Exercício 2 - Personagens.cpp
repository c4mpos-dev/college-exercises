#include <iostream>
#include <string>
using namespace std;

class Pessoa {
    private:
        string nome;
        int idade;

    public:
        Pessoa(string n, int i) {
            nome = n;
            idade = i;
        }

        string getNome() const { return nome; }
        int getIdade() const { return idade; }
};

class Protagonista : public Pessoa {
    private:
        int nivel;

    public:

        Protagonista(string n, int i, int lvl) : Pessoa(n, i) {
            nivel = lvl;
        }

        int getNivel() const { return nivel; }

        void mostrarInfo() const {
            cout << "Protagonista: " << getNome()
                << ", Idade: " << getIdade()
                << ", Nivel: " << nivel << endl;
        }
};

class Personagem : public Pessoa {
    private:
        int rank;

    public:
        Personagem(string n, int i, int r) : Pessoa(n, i) {
            if (r < 0) r = 0;
            if (r > 10) r = 10;
            rank = r;
        }

        int getRank() const { return rank; }

        void mostrarInfo() const {
            cout << "Personagem: " << getNome()
                << ", Idade: " << getIdade()
                << ", Rank: " << rank << endl;
        }
};

int main() {
    Protagonista heroi("Caua", 17, 5);
    Personagem aliado("Campos", 18, 8);

    heroi.mostrarInfo();
    aliado.mostrarInfo();

    return 0;
}