using System;

namespace SociedadeDoAnel
{
    class MembroDaSociedade
    {
        private string nome;
        private string raca;
        private string funcao;

        public MembroDaSociedade(string nome, string raca, string funcao)
        {
            this.nome = nome;
            this.raca = raca;
            this.funcao = funcao;
        }

        public void Descrever()
        {
            Console.WriteLine($"Nome: {nome}");
            Console.WriteLine($"Raça: {raca}");
            Console.WriteLine($"Função: {funcao}");
            Console.WriteLine("-----------------------------");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MembroDaSociedade aragorn = new MembroDaSociedade("Aragorn", "Humano", "Guardiao");
            MembroDaSociedade legolas = new MembroDaSociedade("Legolas", "Elfo", "Arqueiro");

            aragorn.Descrever();
            legolas.Descrever();

            Console.ReadLine();
        }
    }
}
