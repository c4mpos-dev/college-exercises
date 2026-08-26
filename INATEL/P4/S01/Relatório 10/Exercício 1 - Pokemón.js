// os emjojis podem quebrar em alguns terminais (aviso pro monitor)

class Pokemon {
    #vida;
    nome;
    tipo;

    constructor(nome, tipo, vidaInicial) {
        this.nome = nome;
        this.tipo = tipo;
        this.#vida = vidaInicial;
    }

    getVida() {
        return this.#vida;
    }

    receberDano(dano) {
        this.#vida -= dano;
        if (this.#vida < 0) {
            this.#vida = 0;
        }
        console.log(`💥 ${this.nome} recebeu ${dano} de dano e agora tem ${this.#vida} de vida.`);
    }

    receberCura(cura) {
        this.#vida += cura;
        console.log(`✨ ${this.nome} se curou em ${cura} HP! Vida atual: ${this.#vida}`);
    }

    atacar(alvo) {
        console.log(`❓ ${this.nome} usa um ataque genérico...`);
        const danoBase = 5;
        alvo.receberDano(danoBase);
    }
}

class PokemonFogo extends Pokemon {
    bonusAtaque;

    constructor(nome, vidaInicial, bonus) {
        super(nome, 'Fogo', vidaInicial);
        this.bonusAtaque = bonus;
    }

    atacar(alvo) {
        console.log(`🔥 ${this.nome} usa Lança-Chamas!`);
        const danoTotal = 15 + this.bonusAtaque;
        alvo.receberDano(danoTotal);
    }
}

class PokemonAgua extends Pokemon {
    curaBase;

    constructor(nome, vidaInicial, curaBase) {
        super(nome, 'Água', vidaInicial);
        this.curaBase = curaBase;
    }

    atacar(alvo) {
        console.log(`💧 ${this.nome} usa Jato d'Água!`);
        
        const danoAtaque = 12;
        alvo.receberDano(danoAtaque);

        this.receberCura(this.curaBase);
    }
}

// batalha simulada

console.log("--- Criando os Pokémon ---");
const charizard = new PokemonFogo('Charizard', 100, 10);
const blastoise = new PokemonAgua('Blastoise', 120, 5);

console.log(`${charizard.nome} (Vida: ${charizard.getVida()})`);
console.log(`${blastoise.nome} (Vida: ${blastoise.getVida()})`);
console.log("\n--- A BATALHA COMEÇA ---");

console.log("\n--- Turno 1: Charizard ataca ---");
charizard.atacar(blastoise);

console.log("\n--- Turno 2: Blastoise ataca ---");
blastoise.atacar(charizard);

console.log("\n--- Status Final ---");
console.log(`Vida final do ${charizard.nome}: ${charizard.getVida()}`);
console.log(`Vida final do ${blastoise.nome}: ${blastoise.getVida()}`);


console.log("\n--- Tentativa de Alteração Externa (Falha) ---");
console.log(`Vida do Charizard antes: ${charizard.getVida()}`);

charizard.vida = 999; 

console.log(`Vida do Charizard (via getVida()): ${charizard.getVida()}`);
console.log("A vida real (#vida) permaneceu protegida!");