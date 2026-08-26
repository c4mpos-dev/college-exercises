class Criatura {
    nome;
    perigosa;

    constructor(nome, perigosa) {
        this.nome = nome;
        this.perigosa = perigosa;
    }
}

class Diario {
    #autorSecreto;
    enigmas;
    criaturasAvistadas;

    constructor(autor) {
        this.#autorSecreto = autor;
        this.enigmas = new Map();
        this.criaturasAvistadas = [];
    }

    getAutor() {
        return this.#autorSecreto;
    }

    adicionarEnigma(num, enigma) {
        this.enigmas.set(num, enigma);
        console.log(`...enigma ${num} catalogado.`);
    }

    adicionarCriatura(criatura) {
        this.criaturasAvistadas.push(criatura);
    }

    decodificar(chave, num) {
        if (chave !== this.#autorSecreto) {
            return "Acesso negado. Chave incorreta.";
        }

        const enigma = this.enigmas.get(num);
        return enigma ? `Segredo #${num}: ${enigma}` : "Enigma não encontrado.";
    }
}

class Personagem {
    nome;
    idade;

    constructor(nome, idade) {
        this.nome = nome;
        this.idade = idade;
    }
}

class Protagonista extends Personagem {
    #diario;

    constructor(nome, idade, autorDiario) {
        super(nome, idade);
        this.#diario = new Diario(autorDiario);
    }

    getDiario() {
        return this.#diario;
    }
}

class CabanaMisterio {
    visitantes;
    #funcionarios;

    constructor(diario) {
        this.visitantes = [];
        this.#funcionarios = []; 
    }

    adicionarFuncionario(personagem) {
        this.#funcionarios.push(personagem);
        console.log(`${personagem.nome} agora trabalha na Cabana do Mistério.`);
    }

    listarFuncionarios() {
        return this.#funcionarios;
    }
}


// simulacao

console.log("--- Criando Personagens ---");
const dipper = new Protagonista("Dipper", 12, "Ford Pines");
const mabel = new Personagem("Mabel", 12);
const soos = new Personagem("Soos", 30);
const wendy = new Personagem("Marcelo", 15);

console.log("\n--- Inicializando a Cabana ---");
const diarioDoDipper = dipper.getDiario();
const cabanaDoMisterio = new CabanaMisterio(diarioDoDipper);

cabanaDoMisterio.adicionarFuncionario(soos);
cabanaDoMisterio.adicionarFuncionario(wendy);
cabanaDoMisterio.visitantes.push("Turista Aleatório");

console.log("\n--- Item 1: Testando o Diário ---");
diarioDoDipper.adicionarEnigma(21, "O Gnomo não é o que parece.");
diarioDoDipper.adicionarEnigma(10, "Bill Cipher está observando.");

console.log("Tentativa 1 (Chave errada):");
console.log(diarioDoDipper.decodificar("Dipper", 21));

console.log("Tentativa 2 (Chave correta):");
console.log(diarioDoDipper.decodificar("Ford Pines", 10));

console.log("\n--- Itens 2 e 3: Listando Funcionários ---");
const equipe = cabanaDoMisterio.listarFuncionarios();
console.log("A equipe da Cabana é:");
equipe.forEach(p => {
    console.log(`- ${p.nome} (Idade: ${p.idade})`);
});