# 💎 Paradigma Orientado a Objetos - Python

### 🔑 Características principais:
- Declaração de **classes** com `class NomeDaClasse:`  
- **Encapsulamento**: atributos privados e métodos públicos  
- **Herança** e **Polimorfismo** com métodos sobrescritos  
- **Composição**: objetos criados e gerenciados dentro de outros objetos  
- **Agregação**: objetos recebidos de fora e utilizados por outra classe  
- **Construtores** com `__init__()`  
- Uso de **listas** (`list`) para armazenar coleções de objetos  

## 📋 Exercícios

### 1️⃣ Exercício 1 – Dark Souls  
**Descrição:**  
No universo *Dark Souls*, todos são personagens, mas um **Cavaleiro** possui atributos especiais (como **armadura pesada**).  

#### 🧱 Estrutura:
- **Classe base `Personagem`**:  
  - Atributos privados `_vida` e `_resistencia`.  
  - Construtor `__init__()` inicializa esses atributos.  
  - Propriedades para getter e setter de `_vida`.  
  - Método `__str__()` retorna descrição formatada.

- **Classe `Cavaleiro` (herda `Personagem`)**:  
  - Atributo exclusivo `armadura_pesada` (booleano).  
  - Sobrescreve `__str__()` para incluir a informação de armadura.

No `main`:  
- Cria instâncias de `Cavaleiro` com vida, resistência e armadura.  
- Exibe informações usando `print()`.

🛡️ **Conceito aplicado:** Encapsulamento, herança, composição de atributos exclusivos e método `__str__()`.

---

### 2️⃣ Exercício 2 – Overwatch  
**Descrição:**  
No universo *Overwatch*, todos os heróis possuem uma habilidade definitiva (**Ultimate**), mas cada classe tem uma ação única.  

#### 🧱 Estrutura:
- **Classe base `Heroi`** (abstrata):  
  - Atributos `nome` e `funcao` (ex: Tanque, Dano, Suporte).  
  - Método abstrato `usar_ultimate()`.

- **Classes filhas `Tanque` e `Dano`**:  
  - Herda `Heroi` e implementa `usar_ultimate()` com ação específica.

No `main`:  
- Cria uma lista com instâncias de `Tanque` e `Dano`.  
- Percorre a lista e chama `usar_ultimate()` de cada herói.

💥 **Conceito aplicado:** Herança, polimorfismo e métodos abstratos.

---

### 3️⃣ Exercício 3 – Persona 5  
**Descrição:**  
O protagonista *Joker* possui sua arma de combate e agrega membros ao seu time (*Phantom Thieves*).  

#### 🧱 Estrutura:
- **Classe `ArmaCorpoACorpo` (composição)**:  
  - Define nome e dano da arma.

- **Classe `PhantomThieves` (agregação)**:  
  - Representa membros da equipe, cada um com arma própria.

- **Classe `Joker`**:  
  - Composição: cria internamente sua própria arma.  
  - Agregação: recebe lista de `PhantomThieves`.  
  - Método `mostrar_equipe()` que exibe todos os membros.

No `main`:  
- Cria Joker e membros da equipe com suas armas.  
- Chama `mostrar_equipe()` para exibir informações.

🃏 **Conceito aplicado:** Composição e agregação.

---

### 4️⃣ Exercício 4 – Night City  
**Descrição:**  
Em *Night City*, personagens, veículos e robôs são **hackeáveis** e **customizáveis**.  

#### 🧱 Estrutura:
- **Classe abstrata `Cibernetico`**:  
  - Método abstrato `realizar_hack()`.

- **Classe `Implante` (composição)**:  
  - Atributos `custo` e `funcao`.

- **Classe `NetRunner`**:  
  - Herda `Cibernetico` e compõe um `Implante`.  
  - Implementa `realizar_hack()`.

- **Classe `Faccao` (agregação)**:  
  - Recebe lista de `Cibernetico` e manda todos executar `realizar_hack()`.

No `main`:  
- Cria instâncias de `NetRunner` com diferentes implantes.  
- Cria uma `Faccao` e adiciona os NetRunners.  
- Executa `realizar_hack()` em todos os membros.

🕶️ **Conceito aplicado:** Composição, agregação, herança e polimorfismo.

---
