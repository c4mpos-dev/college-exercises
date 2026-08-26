# ⚡ Paradigma Imperativo - C++

### 🔑 Características principais:
- Declaração de **funções** com `tipo nome(parametros)`  
- Estruturas de controle: `if`, `else`, `switch`, `for`, `while`, `do-while`  
- Leitura de dados do usuário com `cin`  
- Impressão na tela com `cout`  

## 📋 Exercícios

### 1️⃣ Exercício 1 – Sequência de Fibonacci (recursivo)
**Descrição:**  
- Cria a função recursiva `int fibonacci(int n)`.  
- Regras da função:  
  - Se `n == 0` → retorna `0`  
  - Se `n == 1` → retorna `1`  
  - Caso contrário → retorna `fibonacci(n-1) + fibonacci(n-2)`  
- No `main`:  
  - Solicita ao usuário um número `n`.  
  - Chama a função e imprime o valor de `fibonacci(n)`.  

---

### 2️⃣ Exercício 2 – Somatório de Array
**Descrição:**  
- Cria a função `float somarArray(float arr[], int tamanho)`.  
- Percorre o array com um `for` somando todos os elementos.  
- Retorna o valor da soma.  
- No `main`:  
  - Solicita o tamanho do array ao usuário.  
  - Lê os valores do array com `cin`.  
  - Chama `somarArray` e imprime o resultado.  

---

### 3️⃣ Exercício 3 – Média de Notas com Validação
**Descrição:**  
- Pede ao usuário quantas notas deseja inserir.  
- Usa um `for` para repetir a leitura de notas.  
- Dentro do `for`, um `while` garante que a nota esteja no intervalo **0 a 10**.  
- Acumula as notas válidas em uma variável de soma.  
- Após o loop, calcula a **média** dividindo pela quantidade de notas.  
- Exibe a média final e usa `if/else` para verificar:  
  - Média `>= 7` → `"Aprovado"`  
  - Caso contrário → `"Reprovado"`  

---

### 4️⃣ Exercício 4 – Conversor de Unidades Interativo
**Descrição:**  
- Cria duas funções:  
  - `double celsiusParaFahrenheit(double celsius)` → converte para Fahrenheit.  
  - `double celsiusParaKelvin(double celsius)` → converte para Kelvin.  
- No `main`:  
  - Apresenta um menu em loop (`do-while`):  
    1. Converter Celsius para Fahrenheit  
    2. Converter Celsius para Kelvin  
    3. Sair  
  - Usa `switch` para tratar a opção:  
    - **Case 1:** lê o valor em Celsius, chama `celsiusParaFahrenheit` e imprime o resultado.  
    - **Case 2:** lê o valor em Celsius, chama `celsiusParaKelvin` e imprime o resultado.  
    - **Case 3:** encerra o programa.  
    - **Default:** mostra mensagem de opção inválida.  

---
