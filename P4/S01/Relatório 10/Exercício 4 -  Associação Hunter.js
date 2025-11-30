// os emjojis podem quebrar em alguns terminais (aviso pro monitor)
// esse anime tem uns nomes exóticos pra personagens, mas é isso aí kkkkkkk

class Hunter {
    nome;
    idade;
    localizacao;

    constructor(nome, localizacao, idade) {
        this.nome = nome;
        this.localizacao = localizacao;
        this.idade = idade;
    }

    apresentar() {
        console.log(`Eu sou ${this.nome}, ${this.idade} anos. Estou em ${this.localizacao}.`);
    }
}

class Especialista extends Hunter {
    #habilidadeNen;

    constructor(nome, localizacao, idade, habilidade) {
        super(nome, localizacao, idade);
        this.#habilidadeNen = habilidade;
    }
}

class Manipulador extends Hunter {
    #alvoAtual;

    constructor(nome, localizacao, idade, alvo = null) {
        super(nome, localizacao, idade);
        this.#alvoAtual = alvo;
    }

    rastrearLocal(latitude, longitude) {
        this.localizacao = `${latitude}, ${longitude}`;
        let relatorio = `📡 ${this.nome} (Manipulador) rastreou o alvo. Nova localização: ${this.localizacao}.`;
        
        if (this.#alvoAtual) {
            relatorio += ` Foco: ${this.#alvoAtual.nome}`;
        }
        return relatorio;
    }
}

class Batalhao {
    #hunters;

    constructor() {
        this.#hunters = new Set();
    }

    adicionarHunter(hunter) {
        if (this.#hunters.has(hunter)) {
            console.log(`🚫 ${hunter.nome} já está no batalhão.`);
        } else {
            console.log(`✔️ ${hunter.nome} adicionado ao batalhão.`);
            this.#hunters.add(hunter);
        }
    }

    getNumHunters() {
        return this.#hunters.size;
    }

    iniciarRastreamento(latitude, longitude) {
        console.log(`\n--- 🗺️ Iniciando Rastreamento em [${latitude}, ${longitude}] ---`);
        const relatorios = [];

        for (const hunter of this.#hunters) {
            if (typeof hunter.rastrearLocal === 'function') {
                const relatorio = hunter.rastrearLocal(latitude, longitude);
                relatorios.push(relatorio);
            } else {
                console.log(`... ${hunter.nome} (Especialista) não pode rastrear.`);
            }
        }
        return relatorios;
    }
}

// simulacao

console.log("--- Recrutando Hunters ---");
const hisoka = new Manipulador("Hisoka", "Torre Celestial", 28);
const kurapika = new Especialista("Kurapika", "Yorknew", 17, "Emperor Time");
const illumi = new Manipulador("Illumi Zoldyck", "Montanha Kukuroo", 24, hisoka);

console.log("\n--- Montando Batalhão ---");
const batalhaoGenryodan = new Batalhao();
batalhaoGenryodan.adicionarHunter(hisoka);
batalhaoGenryodan.adicionarHunter(kurapika);
batalhaoGenryodan.adicionarHunter(illumi);
console.log(`Número de Hunters: ${batalhaoGenryodan.getNumHunters()}`);

console.log("\n--- Tentando adicionar duplicata ---");
batalhaoGenryodan.adicionarHunter(hisoka);
console.log(`Número de Hunters (após duplicata): ${batalhaoGenryodan.getNumHunters()}`);

const relatoriosFinais = batalhaoGenryodan.iniciarRastreamento("22.9068° S", "43.1729° W");

console.log("\n--- 📄 Relatórios de Rastreamento ---");
relatoriosFinais.forEach(r => console.log(r));

console.log("\n--- Posição final (prova da alteração) ---");
console.log(`Localização final de Hisoka: ${hisoka.localizacao}`);
console.log(`Localização final de Kurapika: ${kurapika.localizacao}`);