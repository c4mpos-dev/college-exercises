# 🐹 Paradigma Imperativo - Go

### 🔑 Características principais:
- Declaração de **funções** com `func`  
- Estruturas de controle: `if`, `else`, `switch`, `for`  
- Leitura de dados do usuário com `fmt.Scan`  

## 📋 Exercícios

### 1️⃣ Exercício 1 – Classificação de Número
**Descrição:**  
- Cria a função `func classificar_numero(num int) string`.  
- Usa `if/else` para verificar:  
  - `num > 0` → `"Positivo"`  
  - `num < 0` → `"Negativo"`  
  - `num == 0` → `"Zero"`  
- No `main`, solicita que o usuário digite um número.  
- Chama a função e imprime o resultado.

---

### 2️⃣ Exercício 2 – Par ou Ímpar com Switch
**Descrição:**  
- Pede ao usuário para digitar um número inteiro.  
- Usa `switch numero % 2` para verificar:  
  - `0` → `"O número é par"`  
  - `default` → `"O número é ímpar"`  
- Exibe a mensagem correspondente.

---

### 3️⃣ Exercício 3 – Sequência de Fibonacci
**Descrição:**  
- Cria a função `func fibonacci(n int) []int`.  
- Usa um `for` para gerar a sequência começando em `0` e `1`.  
- Soma os dois números anteriores para gerar o próximo.  
- No `main`:  
  - Solicita ao usuário quantos números deseja.  
  - Chama a função e imprime a sequência.  

---

### 4️⃣ Exercício 4 – Verificação de Login
**Descrição:**  
- Cria a função `func verificarLogin(usuario, senha string) bool`.  
- Verifica com `if/else`:  
  - Usuário = `"senha"` **E** senha = `"admin"` → retorna `true`  
  - Caso contrário → retorna `false`  
- No `main`:  
  - Usa um `for` infinito para pedir usuário e senha.  
  - Se o login for correto → imprime `"Login bem-sucedido!"` e sai do loop com `break`.  
  - Se incorreto → imprime `"Usuário ou senha incorretos. Tente novamente."` e continua o loop.

---