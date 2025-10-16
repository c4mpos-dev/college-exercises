using System;
using System.Collections.Generic;

namespace FrierenMaga
{
    class Feitico
    {
        public string Nome { get; set; }
        public string Efeito { get; set; }

        public Feitico(string nome, string efeito)
        {
            Nome = nome;
            Efeito = efeito;
        }
    }

    class Grimorio
    {
        private List<Feitico> feiticos = new List<Feitico>();

        public void AdicionarFeitico(Feitico f)
        {
            feiticos.Add(f);
        }

        public void MostrarFeiticos()
        {
            Console.WriteLine("📜 Feitiços no Grimório:");
            foreach (var f in feiticos)
            {
                Console.WriteLine($"- {f.Nome}: {f.Efeito}");
            }
        }
    }

    class Ferramenta
    {
        public string Nome { get; set; }

        public Ferramenta(string nome)
        {
            Nome = nome;
        }
    }

    class Maga
    {
        public string Nome { get; set; }
        public Grimorio Grimorio { get; private set; }
        public List<Ferramenta> Ferramentas { get; set; }

        public Maga(string nome, List<Ferramenta> ferramentas)
        {
            Nome = nome;
            Grimorio = new Grimorio();
            Ferramentas = ferramentas;
        }

        public void MostrarFerramentas()
        {
            Console.WriteLine("🧰 Ferramentas da Maga:");
            foreach (var f in Ferramentas)
            {
                Console.WriteLine($"- {f.Nome}");
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Ferramenta> ferramentas = new List<Ferramenta>()
            {
                new Ferramenta("Lanterna Mágica"),
                new Ferramenta("Capa de Viagem"),
                new Ferramenta("Poção de Cura")
            };

            Maga frieren = new Maga("Frieren", ferramentas);

            frieren.Grimorio.AdicionarFeitico(new Feitico("Raio de Gelo", "Congela o inimigo instantaneamente"));
            frieren.Grimorio.AdicionarFeitico(new Feitico("Escudo Arcano", "Cria uma barreira mágica protetora"));

            Console.WriteLine($"✨ Maga: {frieren.Nome}\n");
            frieren.Grimorio.MostrarFeiticos();
            Console.WriteLine();
            frieren.MostrarFerramentas();

            Console.ReadLine();
        }
    }
}
