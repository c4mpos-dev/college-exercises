# ☕ Paradigma Orientado a Objetos - JAVA

### 🔑 Características principais:
- Declaração de **Classes** e **Objetos**.
- **Encapsulamento** com `private` e métodos `getters`/`setters`.
- **Herança** usando `extends NomeDaClasseBase` e `super()`.
- **Polimorfismo** com sobrescrita de métodos (`@Override`).
- **Interfaces** (`interface IRastreavel`).
- **Composição** (objeto *cria* sua dependência) e **Agregação** (objeto *recebe* sua dependência).
- **Coleções** específicas como `ArrayList`, `HashMap` e `LinkedHashSet`.

## 📋 Exercícios

### 1️⃣ Exercício 1 – Castelo Animado
**Descrição:**
Modelar a estrutura de um castelo. A classe `Mago` herda de `Personagem`. O `Castelo` deve gerenciar suas `Divisoes` usando **Agregação** com `ArrayList`, demonstrando a relação 'tem um'.

#### 🧱 Estrutura:
- **Classe base `Personagem`**
  - Atributos privados, `getters`/`setters`.
- **Classe `Mago` (herda `Personagem`)**
  - Sobrescreve métodos (se aplicável) e adiciona funcionalidade única (`lancarFeitico`).
- **Classe `Divisao`**
  - Componente agregado.
- **Classe `Castelo` (Agregação)**
  - Atributo `divisoes` do tipo `ArrayList<Divisao>`.
  - Método `adicionarDivisao(Divisao)`.

👾 **Conceito aplicado:** Encapsulamento, Herança (`extends`), Agregação (`ArrayList`).

---

### 2️⃣ Exercício 2 – Cafeteria LeBlanc
**Descrição:**
Criar um sistema de menu para uma cafeteria. A classe `CafeGourmet` herda de `Cafe`. O preço deve ser calculado usando **Polimorfismo** para incluir um bônus. A `CafeLeBlanc` *possui* o `Menu` (Composição).

#### 🧱 Estrutura:
- **Classe base `Cafe`**
  - Método `calcularPrecoFinal()` simples.
- **Classe `CafeGourmet` (herda `Cafe`)**
  - Sobrescreve (`@Override`) `calcularPrecoFinal()` para adicionar `bonusAroma`.
- **Classe `Menu` (Composição)**
  - Atributo `itens` do tipo `ArrayList<Cafe>`.
- **Classe `CafeLeBlanc` (Composição)**
  - Recebe uma instância de `Menu` em seu construtor.

🎖️ **Conceito aplicado:** Herança, Polimorfismo (`@Override`), Composição, `ArrayList`.

---

### 3️⃣ Exercício 3 – Invasão Alienígena
**Descrição:**
Sistema de rastreamento de entidades. `Alien` e `Youkai` devem estender `Entidade` e implementar a **Interface** `IRastreavel`. O registro deve usar **HashMap** para garantir a unicidade pelo nome.

#### 🧱 Estrutura:
- **Interface `IRastreavel`**
  - Contrato com o método `obterCoordenadas()`.
- **Classe `Poder`**
  - Componente usado por **Composição** nas entidades.
- **Classe `Entidade` (Base)**
- **Classes `Alien` e `Youkai`**
  - Herdam `Entidade` e `implements IRastreavel`.
- **Classe `Registros`**
  - Atributo `avistamentos` do tipo `HashMap<String, Entidade>` (chave = nome).
  - Método `registrarAvistamento()` que verifica a unicidade via `containsKey()`.

🌲 **Conceito aplicado:** Interfaces (`implements`), Herança, Composição, Polimorfismo (via Interface), Coleção (`HashMap`).

---

### 4️⃣ Exercício 4 – Encontro na Arena
**Descrição:**
Organizar chefes (`Bosses`) para uma batalha. O `Boss` usa um `LinkedHashSet` para seu `moveset` (**Composição**). A `Batalha` deve gerenciar os `Bosses` disponíveis usando **HashMap** para localização rápida pelo ID.

#### 🧱 Estrutura:
- **Classe `PadraoAtaque`**
  - Usado por Composição.
- **Classe base `Boss`**
  - Atributo `moveset` do tipo `LinkedHashSet<PadraoAtaque>`.
- **Classe `BossMagico` (herda `Boss`)**
  - Sobrescreve `iniciarFase()`.
- **Classe `Batalha` (Agregação)**
  - Atributo `bossesDisponiveis` do tipo `HashMap<String, Boss>`.
  - Método `iniciarBatalha(idBoss)` que usa o `HashMap` para buscar o objeto.

🃏 **Conceito aplicado:** Herança, Polimorfismo, Composição (`LinkedHashSet`), Agregação (`HashMap`).