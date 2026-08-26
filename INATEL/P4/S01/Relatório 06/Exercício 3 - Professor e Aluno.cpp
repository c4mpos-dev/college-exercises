#include <iostream>
#include <string>
using namespace std;

class Pessoa {
    protected:
        string nome;

    public:
        Pessoa(string n) : nome(n) {}

        virtual void apresentar() {
            cout << "Oi, meu nome é " << nome << " e eu sou uma pessoa." << endl;
        }

        virtual ~Pessoa() {}
};

class Professor : public Pessoa {
    private:
        string disciplina;

    public:
        Professor(string n, string d) : Pessoa(n), disciplina(d) {}

        void apresentar() override {
            cout << "Oi, meu nome e " << nome << " e eu sou um professor de " << disciplina << "." << endl;
        }
};

class Aluno : public Pessoa {
    private:
        string curso;
        int matricula;

    public:
        Aluno(string n, string c, int m) : Pessoa(n), curso(c), matricula(m) {}

        void apresentar() override {
            cout << "Oi, meu nome e " << nome << " e eu sou um aluno de " << curso << "." << endl;
        }
};

int main() {
    Professor prof("Dr. Estevan", "Calculo II");
    Aluno aluno("Caua", "Engenharia", 12345);

    Pessoa* p1 = &prof;
    Pessoa* p2 = &aluno;

    p1->apresentar();
    p2->apresentar();

    return 0;
}