using System;

namespace MasmorraDeTerror
{
    abstract class MonstroSombrio
    {
        public string Nome { get; set; }

        public MonstroSombrio(string nome)
        {
            Nome = nome;
        }

        public virtual void Mover()
        {
            Console.WriteLine($"{Nome} se move de forma sombria...");
        }
    }

    class Zumbi : MonstroSombrio
    {
        public Zumbi(string nome) : base(nome) { }

        public override void Mover()
        {
            Console.WriteLine($"{Nome} se arrasta lentamente, fazendo barulhos assustadores...");
        }
    }

    class Espectro : MonstroSombrio
    {
        public Espectro(string nome) : base(nome) { }

        public override void Mover()
        {
            Console.WriteLine($"{Nome} flutua rapidamente pelo ar, quase invisível!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MonstroSombrio[] monstros = new MonstroSombrio[]
            {
                new Zumbi("Zumbi Lerdo"),
                new Espectro("Espectro Rápido")
            };

            Console.WriteLine("🏰 Início da Masmorra do Terror 🕯️\n");

            foreach (var monstro in monstros)
            {
                monstro.Mover();
            }

            Console.ReadLine();
        }
    }
}