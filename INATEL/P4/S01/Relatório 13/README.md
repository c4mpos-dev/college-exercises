# Paradigma Funcional - Common Lisp

### 🚀 Características principais:
- Definição de **Estruturas** com `defstruct` para criar tipos de dados compostos.
- **Notação Polonesa (Prefixada)** para operações matemáticas e chamadas de função (ex: `(+ 1 2)`).
- **Funções Puras** declaradas com `defun`.
- **Condicionais** robustos com `cond` (para múltiplos casos) e `if`.
- **Funções de Ordem Superior** (Higher-Order Functions) como `mapcar` (map) e `remove-if-not` (filter).
- Uso extensivo de **Listas Encadeadas** (`list`, `car`, `cdr`) e **Recursão**.
- **Expressões Lambda** para funções anônimas passadas como argumento.
- Escopo local com **`let`** para variáveis temporárias.

## 📋 Exercícios

### 1️⃣ Exercício 1 – Farmácia da Maomao
**Descrição:**
Criar um sistema simples de cálculo de dosagem e precificação para uma boticária. A dosagem depende de regras condicionais baseadas em idade e peso. O preço sofre ajustes multiplicativos dependendo do nome da erva (ex: "Ginseng" ou "Lótus").

#### 🧱 Estrutura:
- **Funções Puras (sem struct):**
  - **`calcula-dosagem`**: Recebe peso e idade. Retorna `10`, `25` ou `50`.
  - **`ajusta-preco`**: Recebe preço base e nome. Retorna o novo valor.

🧪 **Conceito aplicado:** `defun`, `cond` (para múltiplas guardas), Operadores Lógicos (`and`, `or`), Comparação de strings (`string-equal`).

---

### 2️⃣ Exercício 2 – Catálogo de Fauna (Planet 4546B)
**Descrição:**
Gerenciar um catálogo de criaturas marinhas. O sistema deve filtrar criaturas perigosas (removendo as de periculosidade "Baixa") e gerar um relatório formatado apenas para criaturas que vivem no ambiente "Deep".

#### 🧱 Estrutura:
- **`defstruct criatura`**
  - Campos: `nome`, `ambiente`, `periculosidade`, `vida-media`.
- **`filtra-por-perigo :: catalogo -> lista`**
- **`relatorio-profundidade :: catalogo -> lista de strings`**

🐟 **Conceito aplicado:** `defstruct`, **Filtragem** (`remove-if-not`), **Mapeamento** (`mapcar`), **Lambda** anônimo, Formatação de Strings (`format`).

---

### 3️⃣ Exercício 3 – A Loja de Iwai
**Descrição:**
Gerenciar vendas de itens amaldiçoados. O fluxo envolve três etapas: filtrar apenas itens do tipo "Arma", aplicar um imposto de 15% no preço, e aplicar um bônus de maldição na força mágica (caso seja superior a 80).

#### 🧱 Estrutura:
- **`defstruct item`**
  - Campos: `nome`, `tipo`, `preco`, `forca-magica`.
- **`adiciona-imposto :: numero -> numero`**
- **`bonus-maldicao :: numero -> numero`**
- **`processa-venda :: catalogo -> lista`**

⚔️ **Conceito aplicado:** `defstruct`, **Escopo Local** (`let`), Composição de funções em etapas (filter depois map), Transformação de dados.

---

### 4️⃣ Exercício 4 – Gerenciamento de Ocorrências
**Descrição:**
Analisar missões paranormais. O sistema deve calcular a soma total do "medo" usando **recursão**. Em seguida, uma função de alto nível calcula a média e filtra as ocorrências críticas (medo acima da média E mais de 3 agentes), retornando apenas os nomes.

#### 🧱 Estrutura:
- **`defstruct ocorrencia`**
  - Campos: `nome`, `ritual`, `nivel-medo`, `agentes-enviados`.
- **`soma-medo-recursiva :: lista -> numero`**
  - Percorre a lista somando `nivel-medo`.
- **`analise-final :: lista -> lista de nomes`**

👻 **Conceito aplicado:** `defstruct`, **Recursão em Listas** (uso de `car` head e `cdr` tail), `let` (para calcular a média uma única vez), `length`, Lógica complexa com `and`.