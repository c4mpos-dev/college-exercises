# Paradigma Lógico - Prolog

### 🚀 Características principais:
- Definição de **Fatos** (`progenitor/2`, `dominio/2`) para estabelecer o conhecimento inicial.
- Construção de **Regras** com a notação `Cabeca :- Corpo` (Implicação Lógica).
- Uso de conectivos lógicos: **Conjunção** (`,` = E Lógico) e **Disjunção** (`;` = OU Lógico).
- **Unificação** e **Backtracking** como mecanismos centrais de busca de soluções.
- **Recursão** para definir relações transitivas e cadeias de parentesco.
- Uso de **Predicados de Agregação** (`findall/3`) e **Aritmética** para contagem e comparação.
- **Distinção** e negação de variáveis (`\=`).

## 📋 Exercícios

### 1️⃣ Exercício 1 – Divindade Olímpica
**Descrição:**
Criar uma regra que identifique os deuses definidos como "olímpicos" por serem **filhos de Cronos** E terem domínio sobre um dos elementos primários: **Céu OU Mar OU Submundo**.

#### 🧱 Regra:
- **`divindade_olimpica(Deus)`**

🔥 **Conceito aplicado:** Criação de Regras de **Seleção**, **Conjunção** (`,` para "E"), **Disjunção** (`;` para "OU").

---

### 2️⃣ Exercício 2 – Deus Maior
**Descrição:**
Identificar o "Deus Maior" que **habita o Olimpo** E tem **pelo menos dois domínios** associados no banco de dados, indicando um escopo de poder mais amplo.

#### 🧱 Regra:
- **`deus_maior(Deus)`**

🔱 **Conceito aplicado:** Uso do predicado de **Agregação** (`findall/3`) para coletar dados, **Contagem de Listas** (`length/2`) e **Aritmética** (`>= 2`).

---

### 3️⃣ Exercício 3 – Irmãos de Sangue
**Descrição:**
Definir a relação estrita de **Irmãos Germanos** (irmãos de sangue), exigindo que dois indivíduos tenham **exatamente o mesmo pai E a mesma mãe**, e que não sejam a mesma pessoa.

#### 🧱 Regra:
- **`irmaos_germanos(A, B)`**

🤝 **Conceito aplicado:** Múltiplas **Conjunções** (`,`) usando **Variáveis Compartilhadas** (para o Pai e a Mãe) e **Distinção** (`\=`).

---

### 4️⃣ Exercício 4 – Ancestralidade
**Descrição:**
Criar a regra `ancestral(A, D)` que define a **cadeia de descendência** (relação transitiva) 

[Image of Family Tree Diagram with recursive relationships]
 para permitir consultas a avós, bisavós e outros.

#### 🧱 Regra:
- **`ancestral(A, D)`** (Implementada com **Caso Base** e **Passo Recursivo**).

📜 **Conceito aplicado:** **Recursão** como a principal ferramenta para percorrer cadeias de dados, definindo um **Caso Base** (`progenitor(A, D)`) e um **Passo Recursivo** (`progenitor(A, Z), ancestral(Z, D)`).