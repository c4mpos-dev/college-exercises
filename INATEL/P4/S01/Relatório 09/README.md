# 🏮 Paradigma Orientado a Objetos - Ruby

### 🔑 Características principais:
- Declaração de **classes** com `class NomeDaClasse` e **módulos** com `module NomeDoModulo`.  
- **Encapsulamento** com `attr_reader`, `attr_writer` e `attr_accessor`.  
- **Herança** usando `< NomeDaClasseBase`.  
- **Polimorfismo** com sobrescrita de métodos e `respond_to?`.  
- **Composição** e **Agregação** com objetos internos e externos.  
- **Mixins** com `include` para adicionar comportamentos de módulos.  
- **Interação com o usuário** via `gets.chomp`.  

## 📋 Exercícios

### 1️⃣ Exercício 1 – Bar AfterLife  
**Descrição:**  
O *Bar AfterLife* serve **drinks lendários** e **drinks comuns**, sendo que o preço dos lendários aumenta conforme seus anos de existência.  

#### 🧱 Estrutura:
- **Classe base `Drink`**  
  - Atributos encapsulados `@_nome` e `@_preco_base`.  
  - Getter explícito `def preco_base` e setter `def preco_base=` com validação de valor positivo.  
  - Método `to_s` para exibir nome e preço.  

- **Classe `DrinkLenda` (herda `Drink`)**  
  - Atributo adicional `@anos_desde_criacao`.  
  - Método `preco_final` que soma `$5` por ano de existência ao preço base.  
  - Sobrescreve `to_s` para mostrar o preço final.  

No `main`:  
- Recebe nome, preço e anos via `gets.chomp`.  
- Cria um objeto `DrinkLenda` e exibe o resultado formatado.  

🍸 **Conceito aplicado:** Encapsulamento, herança, validação de atributos e sobrescrita de método (`to_s`).

---

### 2️⃣ Exercício 2 – O Maestro e seu Conjunto  
**Descrição:**  
O *Maestro* coordena um conjunto de músicos, cada um com sua própria forma de tocar uma peça.  

#### 🧱 Estrutura:
- **Classe base `Musico`**  
  - Atributos `@nome` e `@instrumento`.  
  - Método abstrato `tocar_partitura(peca)` que lança `NotImplementedError`.  

- **Classes `Pianista` e `Violinista` (herdam `Musico`)**  
  - Sobrescrevem `tocar_partitura(peca)` com mensagens específicas.  

- **Classe `Maestro`**  
  - Recebe uma lista de músicos.  
  - Método `iniciar_ensaio(peca)` usa `each` para chamar o método polimórfico.  
  - Método `mudar_foco(estado)` usa `map` para gerar mensagens de foco para cada músico.  

No `main`:  
- O usuário define o nome da peça via `gets.chomp`.  
- O maestro inicia o ensaio e muda o foco dos músicos.  

🎼 **Conceito aplicado:** Abstração por contrato, herança, polimorfismo e uso de `each` e `map`.

---

### 3️⃣ Exercício 3 – Telefone de Micro-ondas (D-Mail)  
**Descrição:**  
O *TelefoneDeMicroondas* é um sistema que envia mensagens (D-Mails) após um aquecimento controlado.  

#### 🧱 Estrutura:
- **Classe `MicroondasUnidade` (Composição)**  
  - Método `aquecer_por(segundos)` simula o aquecimento da unidade.  

- **Classe `DMail` (Agregação)**  
  - Atributos `conteudo` e `hora_envio`.  
  - Método `to_s` exibe o conteúdo e horário.  

- **Classe `TelefoneDeMicroondas`**  
  - Possui internamente um `MicroondasUnidade` (composição).  
  - Mantém uma lista de `DMail` (agregação).  
  - Método `enviar_dmail` coleta dados do usuário e adiciona o D-Mail.  
  - Método `listar_dmails(horario_corte)` usa `select` para filtrar mensagens enviadas após o horário.  

No `main`:  
- O menu permite enviar D-Mails ou listá-los após um horário informado.  

☢️ **Conceito aplicado:** Composição, agregação, uso de `select` e interação com o usuário.

---

### 4️⃣ Exercício 4 – O Jogo das Sombras  
**Descrição:**  
No *Jogo das Sombras*, participantes possuem módulos que definem suas capacidades rastreáveis e perigosas.  

#### 🧱 Estrutura:
- **Módulo `Rastreavel`**  
  - Método `obter_localizacao(hora)` retorna localização formatada.  

- **Módulo `Perigoso`**  
  - Método `calcular_risco` (abstrato) deve ser implementado nas classes que o incluem.  

- **Classe base `Participante`**  
  - Atributos `@nome` e `@localizacao`.  
  - Método `to_s` mostra status atual.  

- **Classe `Detetive` (inclui `Rastreavel`)**  
  - Método `investigar` descreve a ação do detetive.  

- **Classe `MestreDoCrime` (inclui `Rastreavel` e `Perigoso`)**  
  - Implementa `calcular_risco` com cálculo dinâmico baseado em periculosidade.  

- **Classe `Cenario`**  
  - Recebe uma lista de participantes.  
  - Método `listar_rastreaveis` retorna objetos que incluem `Rastreavel`.  
  - Método `identificar_ameacas` usa `respond_to?(:calcular_risco)` para filtrar criminosos.  

No `main`:  
- O usuário informa as localizações de *Sherlock Holmes* e *Moriarty*.  
- O cenário lista os rastreáveis e identifica ameaças com base nos módulos.  

🕵️‍♂️ **Conceito aplicado:** Mixins, herança, polimorfismo, reflexão com `respond_to?` e encapsulamento.

---