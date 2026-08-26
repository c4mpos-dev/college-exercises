// os emjojis podem quebrar em alguns terminais (aviso pro monitor)

class ODM_Gear {
    #gasRestante;
    modelo;

    constructor(modelo, gasInicial) {
        this.modelo = modelo;
        this.#gasRestante = gasInicial;
    }

    getGas() {
        return this.#gasRestante;
    }

    usarGas(quantidade) {
        if (this.#gasRestante >= quantidade) {
            this.#gasRestante -= quantidade;
            console.log(`💨... ${this.modelo} usou ${quantidade} de gás. Restam: ${this.#gasRestante}`);
            return true;
        } else {
            console.log(`🚫... ${this.modelo} sem gás suficiente!`);
            return false;
        }
    }
}

class Soldado {
    #gear;
    nome;

    constructor(nome, modeloGear) {
        this.nome = nome;
        this.#gear = new ODM_Gear(modeloGear, 100);
    }

    explorarTerritorio() {
        console.log(`🏃‍♂️ ${this.nome} está explorando...`);
        const gasUsado = 15;
        const sucesso = this.#gear.usarGas(gasUsado);

        if (sucesso) {
            return `${this.nome} explorou os telhados e retornou.`;
        } else {
            return `${this.nome} não pôde explorar (sem gás!).`;
        }
    }

    verificarEquipamento() {
        const gas = this.#gear.getGas();
        return `${this.nome} (${this.#gear.modelo}): ${gas} de gás restante.`;
    }
}

class Esquadrao {
    lider;
    membros;

    constructor(lider, membrosIniciais = []) {
        this.lider = lider;
        this.membros = [lider, ...membrosIniciais];
    }

    adicionarMembro(soldado) {
        this.membros.push(soldado);
        console.log(`📋 ${soldado.nome} foi adicionado ao esquadrão.`);
    }

    relatarStatus() {
        console.log(`\n--- 🎖️ Relatório do Esquadrão (Líder: ${this.lider.nome}) ---`);
        const statusList = this.membros.map(soldado => {
            return soldado.verificarEquipamento();
        });
        return statusList;
    }

    explorarTerritorio() {
        console.log(`\n--- 🗺️ Esquadrão (Líder: ${this.lider.nome}) iniciando exploração! ---`);
        const relatorios = this.membros.map(soldado => {
            return soldado.explorarTerritorio();
        });
        console.log("--- 🗺️ Exploração do Esquadrão concluída. ---");
        return relatorios;
    }
}


// missão simulada

console.log("--- Recrutando Soldados ---");
const levi = new Soldado("Capitão Levi", "Modelo Avançado");
const mikasa = new Soldado("Mikasa Ackerman", "Modelo Padrão");
const eren = new Soldado("Eren Yeager", "Modelo Padrão");

console.log("\n--- Formando Esquadrão ---");
const esquadraoLevi = new Esquadrao(levi, [mikasa]);
esquadraoLevi.adicionarMembro(eren);

let statusInicial = esquadraoLevi.relatarStatus();
statusInicial.forEach(status => console.log(status));

const relatorioExploracao = esquadraoLevi.explorarTerritorio();
relatorioExploracao.forEach(relatorio => console.log(relatorio));

let statusFinal = esquadraoLevi.relatarStatus();
statusFinal.forEach(status => console.log(status));