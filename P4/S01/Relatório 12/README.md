# λ Paradigma Funcional - Haskell

### 🚀 Características principais:
- Declaração de **Tipos de Dados Algébricos (ADTs)** com `data`.
- **Imutabilidade** (dados não são alterados após a criação).
- **Reconhecimento de Padrões (Pattern Matching)** para desestruturar dados (ex: `(x:xs)`, `[]`, `(Evento _ Cancelado)`).
- **Guards** (`|`) para lógicas condicionais múltiplas.
- **Funções de Ordem Superior** (como `map`, `sum`) e composição de funções.
- **Cláusulas `let...in`** para definir variáveis locais e cálculos intermediários.
- Derivação de **Typeclasses** (ex: `deriving (Show, Eq)`) para adicionar funcionalidades básicas.

## 📋 Exercícios

### 1️⃣ Exercício 1 – Café Leblanc
**Descrição:**
Modelar um sistema de pedidos para uma cafeteria. Cada `Pedido` contém uma lista de `Bebida` e um `Status`. O objetivo é calcular o valor total, aplicando uma taxa fixa (exceto se cancelado) e encontrar a primeira bebida do pedido.

#### 🧱 Estrutura:
- **`data Bebida`**
  - Campos: `nome`, `tipo`, `preco`.
- **`data StatusPedido`**
  - Construtores: `Aberto | Entregue | Cancelado`.
- **`data Pedido`**
  - Campos: `bebidas :: [Bebida]`, `status :: StatusPedido`.
- **`valorTotalPedido :: Pedido -> Double`**
- **`primeiraBebida :: Pedido -> String`**

☕ **Conceito aplicado:** `data` (ADTs), **Pattern Matching** (para `StatusPedido` e para listas `[]` vs `(b:_)`), `sum` e `map`.

---

### 2️⃣ Exercício 2 – Lojas de Hyrule
**Descrição:**
Implementar um carrinho de compras para uma loja em Hyrule. O sistema deve calcular o valor final de uma `CompraZelda`, aplicando um desconto de 10% para compras acima de 200 rúpias ou adicionando um frete fixo de 15 rúpias caso contrário.

#### 🧱 Estrutura:
- **`data Item`**
  - Campos: `nome`, `categoria`, `preco`.
- **`data CompraZelda`**
  - Campos: `itens :: [Item]`.
- **`valorFinal :: CompraZelda -> Double`**

🛡️ **Conceito aplicado:** `data`, **Guards** (para a lógica condicional de desconto/frete), Composição de funções (`sum (map...)`).

---

### 3️⃣ Exercício 3 – Casa de Shows
**Descrição:**
Gerenciar os custos de um evento musical. O `Evento` tem uma lista de `Bandas` e um `Status`. O custo total deve somar os cachês e adicionar 20% de taxa de produção (ou 0.0 se cancelado). Também deve identificar a banda de abertura e a de fechamento.

#### 🧱 Estrutura:
- **`data Banda`**
  - Campos: `nome`, `genero`, `cache`.
- **`data StatusEvento`**
  - Construtores: `Ativo | Encerrado | Cancelado`.
- **`data Evento`**
  - Campos: `bandas :: [Banda]`, `status :: StatusEvento`.
- **`custoTotalEvento :: Evento -> Double`**
- **`bandaAbertura :: Evento -> String`**
- **`bandaFechamento :: Evento -> String`**

🎤 **Conceito aplicado:** `data` (ADTs), **Pattern Matching** (em `StatusEvento` e listas), Funções de lista (`last`).

---

### 4️⃣ Exercício 4 – Casa de Banhos (Yubaba)
**Descrição:**
Calcular o valor de um `Atendimento` na casa de banhos. O cálculo é complexo: um bônus de 25% é aplicado se houver mais de 3 serviços, e um desconto de 10% é aplicado se o total (com bônus) ultrapassar 500.

#### 🧱 Estrutura:
- **`data Servico`**
  - Campos: `nome`, `tipo`, `precoBase`.
- **`data StatusAtendimento`**
  - Construtores: `EmAndamento | Finalizado | Cancelado`.
- **`data Atendimento`**
  - Campos: `servicos :: [Servico]`, `status :: StatusAtendimento`.
- **`bonusEspiritual :: [Servico] -> Double`**
- **`valorFinalAtendimento :: Atendimento -> Double`**
- **`descricaoPrimeiroServico :: Atendimento -> String`**

♨️ **Conceito aplicado:** `data`, **`let...in`** (para cálculos intermediários), **Guards** (para lógicas aninhadas de bônus/desconto), `length`.