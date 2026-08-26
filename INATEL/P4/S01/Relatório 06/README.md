# ⚡ Paradigma Orientado a Objetos - C++

### 🔑 Características principais:
- Declaração de **classes** com `class NomeClasse`  
- **Encapsulamento**: atributos privados/protected + métodos públicos (`get`/`set`)  
- **Herança**: `class Filha : public Base`  
- **Polimorfismo**: métodos virtuais (`virtual`) e sobrescrita (`override`)  
- Criação de objetos com **construtores**  
- Manipulação de objetos via **ponteiros** e arrays  

## 📋 Exercícios

### 1️⃣ Exercício 1 – RPG Ataque entre Personagens
**Descrição:**  
- Cria a classe `Personagem` com atributos privados: `nome`, `nivel`, `dano` e `vida`.  
- Método `atacar(Personagem &alvo)` que causa dano ao outro personagem e exibe mensagem de ataque.  
- Método `mostrarInfo()` exibe os atributos do personagem.  
- No `main()`:  
  - Cria dois personagens.  
  - Cada um ataca o outro.  
  - Mostra o estado final após o combate.

---

### 2️⃣ Exercício 2 – Classes de Personagens com Herança
**Descrição:**  
- Classe base `Pessoa` com atributos privados `nome` e `idade`.  
- Classes derivadas:  
  - `Protagonista` com atributo `nivel`.  
  - `Personagem` com atributo `rank` (0 a 10).  
- Encapsulamento mantido com **getters** e **construtores** para inicialização.  
- Método `mostrarInfo()` exibe os valores.  
- No `main()`:  
  - Cria um objeto de cada classe usando construtor.  
  - Imprime os valores chamando métodos (não acessa atributos diretamente).

---

### 3️⃣ Exercício 3 – Professor e Aluno (Polimorfismo)
**Descrição:**  
- Classe base `Pessoa` com atributo `nome` e método virtual `apresentar()`.  
- Classes derivadas:  
  - `Professor` com atributo `disciplina`.  
  - `Aluno` com atributos `curso` e `matricula`.  
- Sobrescrevem o método `apresentar()` para exibir mensagens específicas.  
- No `main()`:  
  - Cria ponteiros da classe base apontando para objetos `Professor` e `Aluno`.  
  - Chama `apresentar()` via ponteiro, demonstrando **polimorfismo**.

---

### 4️⃣ Exercício 4 – Seres Vivos Fantasia (Polimorfismo com Array)
**Descrição:**  
- Classe base `SerVivo` com atributo protegido `nome` e método virtual `apresentar()`.  
- Classes derivadas: `Humano`, `Elfo`, `Fada`, cada uma sobrescrevendo `apresentar()`.  
- No `main()`:  
  - Cria um **array de ponteiros** `SerVivo*` para armazenar diferentes seres.  
  - Cria instâncias de cada raça dinamicamente (`new`) e adiciona ao array.  
  - Percorre o array e chama `apresentar()` de cada elemento (polimorfismo).  
  - Libera a memória ao final usando `delete`.

---
