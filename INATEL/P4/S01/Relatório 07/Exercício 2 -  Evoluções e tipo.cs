using System;
using System.Collections.Generic;

namespace PokemonBattle
{
    class Pokemon
    {
        public string Nome { get; set; }

        public Pokemon(string nome)
        {
            Nome = nome;
        }

        public virtual void Atacar()
        {
            Console.WriteLine($"{Nome} realiza um ataque genérico!");
        }
    }

    class PokemonDeFogo : Pokemon
    {
        public PokemonDeFogo(string nome) : base(nome) { }

        public override void Atacar()
        {
            Console.WriteLine($"{Nome} lança uma poderosa labareda de fogo!");
        }
    }

    class PokemonDeAgua : Pokemon
    {
        public PokemonDeAgua(string nome) : base(nome) { }

        public override void Atacar()
        {
            Console.WriteLine($"{Nome} lança um jato de água!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            List<Pokemon> pokemons = new List<Pokemon>();

            pokemons.Add(new PokemonDeFogo("Charizard"));
            pokemons.Add(new PokemonDeAgua("Blastoise"));

            foreach (var p in pokemons)
            {
                p.Atacar();
            }

            Console.ReadLine();
        }
    }
}
