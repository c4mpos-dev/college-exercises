# 💎 Paradigma Orientado a Objetos - C#

### 🔑 Características principais:
- Declaração de **classes** com `class NomeDaClasse`  
- **Encapsulamento**: atributos privados + métodos públicos ou propriedades (`get` / `set`)  
- **Herança**: `class Filha : Base`  
- **Polimorfismo**: métodos `virtual`, `override` e classes `abstract`  
- **Composição** e **Agregação**: objetos dentro de outros objetos  
- Criação e inicialização via **construtores**  
- Manipulação de coleções com **List<T>** e **arrays**  

## 📋 Exercícios

### 1️⃣ Exercício 1 – A Sociedade do Anel
**Descrição:**  
- Classe `MembroDaSociedade` com atributos privados: `nome`, `raça`, `função`.  
- Construtor obriga a inicialização dos três atributos.  
- Método `Descrever()` exibe todas as informações do membro.  
- No `main`:  
  - Cria instâncias de `Aragorn` (Humano, Guardião) e `Legolas` (Elfo, Arqueiro).  
  - Chama `Descrever()` em ambos.  

🧝‍♂️ **Conceito aplicado:** Encapsulamento e construtores.

---

### 2️⃣ Exercício 2 – Evoluções e Tipos
**Descrição:**  
- Classe base `Pokemon` com atributo `Nome` e método virtual `Atacar()`.  
- Classes derivadas:  
  - `PokemonDeFogo`: sobrescreve `Atacar()` com ataque de fogo.  
  - `PokemonDeAgua`: sobrescreve `Atacar()` com ataque de água.  
- No `main`:  
  - Cria uma lista `List<Pokemon>` e adiciona `Charizard` e `Blastoise`.  
  - Percorre a lista e chama `Atacar()` em cada um.  

🔥💧 **Conceito aplicado:** Herança e Polimorfismo.

---

### 3️⃣ Exercício 3 – Armazenamento Mágico
**Descrição:**  
- Classe `Feitico` com propriedades `Nome` e `Efeito`.  
- Classe `Grimorio` contém uma `List<Feitico>` (Composição) e método `AdicionarFeitico()`.  
- Classe `Ferramenta` representa objetos como "Lanterna" e "Poção".  
- Classe `Maga` contém um `Grimorio` (Composição) e uma `List<Ferramenta>` (Agregação).  
- No `main`:  
  - Cria lista de ferramentas e instancia `Maga Frieren`.  
  - Adiciona feitiços ao grimório e imprime os nomes das ferramentas.  

🔮 **Conceito aplicado:** Composição e Agregação.

---

### 4️⃣ Exercício 4 – Horda Sombria
**Descrição:**  
- Classe abstrata `MonstroSombrio` com atributo `Nome` e método virtual `Mover()`.  
- Classes derivadas:  
  - `Zumbi`: sobrescreve `Mover()` com movimento lento.  
  - `Espectro`: sobrescreve `Mover()` com movimento rápido.  
- No `main`:  
  - Cria um array `MonstroSombrio[]` com instâncias de `Zumbi` e `Espectro`.  
  - Percorre o array chamando `Mover()` para cada monstro.  

👻 **Conceito aplicado:** Classe abstrata e Polimorfismo.
