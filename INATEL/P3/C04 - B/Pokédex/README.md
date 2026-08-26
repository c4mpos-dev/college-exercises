# 🧭 Pokémon Route Simulator

Este projeto simula um sistema de cidades interligadas por estradas e permite o gerenciamento de **Pokémons** e suas localizações. É possível cadastrar cidades com centros Pokémon, conectar cidades por estradas, registrar Pokémons em um mapa, buscar o centro Pokémon mais próximo usando o algoritmo de Dijkstra, listar Pokémons em ordem, contar por tipo e até procurar Pokémons próximos da sua localização.

---

## 📌 Funcionalidades

### 🏙️ Gerenciamento de Cidades
- **Cadastrar cidades** com código único, nome e indicação se possui um centro Pokémon.
- Armazenadas em um array de até `INF = 9999` cidades.
- Cada cidade pode se conectar a outras via estradas.

### 🛣️ Cadastro de Estradas
- Estradas são conexões bidirecionais entre duas cidades.
- Permite definir o peso/distância (utilizado na busca de caminhos).
- Não permite conexão de uma cidade com ela mesma.

### 🧭 Busca de Centro Pokémon mais Próximo
- Utiliza o **algoritmo de Dijkstra** para encontrar o menor caminho até o centro Pokémon mais próximo da cidade atual.
- Exibe o caminho percorrido e a distância total.

### 🔺 Cadastro e Gerenciamento de Pokémons
- Pokémons possuem: nome, tipo, número na Pokédex, e coordenadas no mapa (x, y).
- Armazenados em **duas Árvores Binárias de Busca (BST)**:
  - Uma ordenada por nome.
  - Outra ordenada por tipo.

### 📋 Listagem e Remoção de Pokémons
- **Listagem em ordem alfabética** por nome ou tipo.
- **Remoção** simultânea do Pokémon em ambas as árvores.

### 📊 Contagem de Pokémons por Tipo
- Permite buscar a quantidade de Pokémons cadastrados de um determinado tipo.

### 📍 Busca de Pokémons Próximos
- Dada uma localização `(x, y)`, lista todos os Pokémons a até 100 metros de distância.

## 🔧 Estrutura do Projeto

### Estruturas de Dados
- `Cidade`: representa uma cidade com código, nome, centro Pokémon e lista de estradas.
- `Estrada`: representa uma conexão entre duas cidades.
- `Pokemon`: representa um Pokémon com nome, tipo, número, e coordenadas.
- `Node`: nó das árvores binárias para armazenar os Pokémons.

### Algoritmos
- **Dijkstra**: para encontrar o centro Pokémon mais próximo.
- **Árvores Binárias de Busca (BSTs)**: para ordenar e pesquisar Pokémons por nome ou tipo.
- **Percurso em ordem (in-order traversal)**: para listar Pokémons ordenadamente.

## 🖥️ Menu de Navegação

```
[1] Cadastrar cidade
[2] Cadastrar estrada
[3] Buscar centro Pokemon mais proximo
[4] Cadastrar Pokemon
[5] Remover Pokemon
[6] Listar Pokemons (ordem alfabetica de nome)
[7] Listar Pokemons (ordem alfabetica de tipo)
[8] Contar Pokemons por tipo
[9] Encontrar Pokemons proximos
[0] Sair
```


## ✍️ Autores

```cpp
#define GROUP "10"
#define STUDENTS "Cauã Campos, David Morais, João Pedro Torrano"
#define TEACHER "Jonas Boas"
#define SEMESTER "2025/1"
```