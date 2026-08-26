#include <iostream>
using namespace std;

class SerVivo {
    protected:
        string nome;

    public:
        SerVivo(string n) : nome(n) {}

        virtual void apresentar() {
            cout << "Olá, eu sou um ser vivo genérico chamado " << nome << "." << endl;
        }

        virtual ~SerVivo() {}
};

class Humano : public SerVivo {
    public:
        Humano(string n) : SerVivo(n) {}

        void apresentar() override {
            cout << "Oi, eu sou um humano chamado " << nome << "." << endl;
        }
};

class Elfo : public SerVivo {
    public:
        Elfo(string n) : SerVivo(n) {}

        void apresentar() override {
            cout << "Saudacoes, sou um elfo chamado " << nome << "." << endl;
        }
};

class Fada : public SerVivo {
    public:
        Fada(string n) : SerVivo(n) {}

        void apresentar() override {
            cout << "Oi! Eu sou uma fada chamada " << nome << "." << endl;
        }
};

int main() {
    const int TOTAL_SERES = 3; // numero pra teste

    SerVivo* seres[TOTAL_SERES];

    seres[0] = new Humano("Caua");
    seres[1] = new Elfo("Tobias");
    seres[2] = new Fada("Ana");

    for (int i = 0; i < TOTAL_SERES; i++) {
        seres[i]->apresentar();
    }

    for (int i = 0; i < TOTAL_SERES; i++) {
        delete seres[i]; // libera a memoria
    }

    return 0;
}
