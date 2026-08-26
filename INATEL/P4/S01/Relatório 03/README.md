# 🦀 Paradigma Imperativo - Rust

### 🔑 Características principais:
- Uso de **variáveis imutáveis e mutáveis**  
- Estruturas de controle: `if`, `else`, `for`, `loop`  
- Funções para **modularização e reutilização de lógica**  
- Leitura de dados com `stdin` e escrita com `stdout`  

## 📋 Exercícios

### 1️⃣ Exercício 1 – Verificação de Senha
**Descrição:**  
- Cria a função `fn verificar_senha(senha: &str) -> bool`.  
- Regras para senha válida:  
  - Ter **pelo menos 8 caracteres**.  
  - Conter **pelo menos um número**.  
  - Conter **pelo menos uma letra maiúscula**.  
- No `main`, solicita que o usuário digite senhas até ser válida.  
- Exibe: `"Senha válida! Acesso concedido."` quando aceita.  

---

### 2️⃣ Exercício 2 – Jogo do Par ou Ímpar
**Descrição:**  
- Cria a função `fn eh_par(numero: i32) -> bool`.  
- Jogador 1 escolhe **par ou ímpar** e digita um número.  
- Jogador 2 digita um número.  
- Soma dos números é calculada.  
- Usa a função `eh_par` para determinar se o resultado é **par ou ímpar**.  
- Se a soma corresponder à escolha do Jogador 1 → ele vence.  
- Caso contrário → Jogador 2 vence.  

---

### 3️⃣ Exercício 3 – Impressão de Tabuada
**Descrição:**  
- Cria a função `fn imprimir_tabuada(numero: i32, limite_inferior: i32, limite_superior: i32)`.  
- Utiliza um `for` para iterar do limite inferior ao limite superior.  
- Imprime a tabuada do número nesse intervalo.  
- No `main`, o usuário informa:  
  - O número da tabuada.  
  - O limite inferior.  
  - O limite superior.  

---

### 4️⃣ Exercício 4 – Média Ponderada
**Descrição:**  
- Cria a função `fn calcular_media(nota1: f64, nota2: f64, nota3: f64) -> f64`.  
- Usa os pesos:  
  - Nota 1 → peso **2**  
  - Nota 2 → peso **3**  
  - Nota 3 → peso **5**  
- No `main`:  
  - Define três notas (`7.5`, `8.0`, `9.2`).  
  - Chama a função e calcula a média ponderada.  
  - Exibe o resultado.  
  - Verifica com `if/else`:  
    - Se média ≥ 7 → `"Aluno Aprovado!"`.  
    - Caso contrário → `"Aluno Reprovado!"`.  

---
