# 📚 Estudos de Algoritmos — C++

Repositório com exercícios práticos de algoritmos e estruturas de dados desenvolvidos em C++ durante a disciplina de **Algoritmos e Estruturas de Dados** do curso de **Tecnologia em Análise e Desenvolvimento de Sistemas** no **IFPE** (Instituto Federal de Educação, Ciência e Tecnologia de Pernambuco).

---

## 📁 Estrutura do Projeto

```
.
├── rotate.cpp       # Rotação de array N posições
├── maior.cpp        # Maior elemento via recursão
├── strings.cpp      # Reordenação de string (Counting Sort)
├── reverse.cpp      # Inversão de string via recursão
├── portland.cpp     # Quarteirões seguros — BC2168
├── island.cpp       # Perímetro de ilha — LeetCode 463
├── chuva.cpp        # Propagação de chuva iterativa e recursiva — BC3052
├── contamina.cpp    # Contaminação em matriz — BC1583
├── pilha_min.cpp    # MinStack — menor elemento em O(1) — LC155
└── fila_media.cpp   # Fila com média atual em O(1) — buffer circular
```

---

## 🔄 rotate.cpp — Rotação de Array

Dado um array de inteiros e um valor `N`, a função `rotate()` desloca todos os elementos `N` posições à direita. Elementos que ultrapassam o fim do array voltam para o início.

**Exemplo:**
```
Entrada:  3 5 8 10 1 7 9 4  (N = 3)
Saída:    7 9 4 3 5 8 10 1
```

**Conceitos aplicados:**
- Operador módulo `%` para calcular novas posições
- Array auxiliar para evitar sobrescrita de elementos
- Suporte a valores negativos de `N`

---

## 🔢 maior.cpp — Maior Elemento Recursivo

A função recursiva `maior()` percorre um array e retorna o maior elemento, sem usar loops.

**Exemplo:**
```
Entrada:  10 1 5 3 12 7 4 6
Saída:    12
```

**Conceitos aplicados:**
- Recursão com caso base e caso recursivo
- Divisão e conquista: o maior de N elementos é o maior entre o último e o maior dos N-1 anteriores

---

## 🔤 strings.cpp — Reordenação de String

A função `reordenar()` recebe uma string com letras minúsculas e retorna uma nova string com as letras em ordem alfabética, preservando repetições.

**Exemplos:**
```
"casa"   → "aacs"
"escola" → "acelos"
"banana" → "aaabnn"
```

**Conceitos aplicados:**
- Counting Sort — algoritmo de ordenação linear O(n)
- Mapeamento de caracteres para índices via subtração ASCII (`'c' - 'a' = 2`)
- Sem uso de `std::sort()` ou algoritmos de ordenação tradicionais

---

## ↩️ reverse.cpp — Inversão de String Recursiva

A função recursiva `inverter()` recebe uma string e retorna ela com os caracteres na ordem inversa. Também inclui uma função para verificar se uma palavra é palíndromo.

**Exemplos:**
```
"recursao" → "oasrucer"
"banana"   → "ananab"
"ovo"      → é um palíndromo ✅
```

**Conceitos aplicados:**
- Recursão com `substr()` para reduzir o problema a cada chamada
- Caso base: string vazia
- Caso recursivo: última letra + inverter o restante

---

## 🏙️ portland.cpp — Quarteirões Seguros (BC2168)

Dado uma matriz de esquinas com câmeras (`1`) ou sem (`0`), determina se cada quarteirão é **seguro (S)** ou **inseguro (U)**. Um quarteirão é seguro se tiver pelo menos duas câmeras nas suas quatro esquinas.

**Exemplo:**
```
Entrada:        Saída:
1 1 0 1         SSS
1 0 1 0         SUS
1 0 0 1         SSS
0 1 1 0
```

**Conceitos aplicados:**
- Percurso de matrizes com duplo laço
- Soma das esquinas de cada quarteirão (i,j), (i,j+1), (i+1,j), (i+1,j+1)
- Classificação por limiar (>= 2 câmeras → seguro)

---

## 🏝️ island.cpp — Perímetro de Ilha (LeetCode 463)

Dada uma matriz representando um mapa, calcula o perímetro da ilha formada pelas células com valor `1`. A ilha é conexa, sem lagos internos.

**Exemplo:**
```
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0

Saída: 16
```

**Conceitos aplicados:**
- Percurso de matriz com verificação de vizinhos
- Para cada célula de terra, contribui com 4 lados menos os lados compartilhados com vizinhos também de terra

---

## 🌧️ chuva.cpp — Propagação de Chuva (BC3052 / OBI 2019)

Simula o escoamento da chuva em uma matriz a partir de uma gota (`o`), com obstáculos (`#`). Implementa duas abordagens com comportamentos distintos:

- **Iterativa:** a chuva escorre apenas para a **esquerda**
- **Recursiva:** a chuva escorre apenas para a **direita**

**Exemplo:**
```
Original:       Iterativa:      Recursiva:
.o...           oo...           .oo..
.#...           o#...           .#o..
.....           o....           ..o..
.....           o....           ..o..
.....           o....           ..oo.
..#..           o.#..           ..#o.
.....           o....           ...o.
```

**Conceitos aplicados:**
- Simulação iterativa com flag de mudança (`do-while`)
- Flood fill recursivo (DFS em matriz)
- Propagação direcionada com restrição de movimento

---

## ☣️ contamina.cpp — Contaminação (BC1583)

Dado um mapa com células livres (`A`), bloqueadas (`X`) e contaminadas (`T`), propaga a contaminação para todas as células `A` conectadas às células `T`. Adaptado diretamente da lógica do problema Chuva.

- **Iterativa:** propaga nas 4 direções via `do-while`
- **Recursiva:** flood fill a partir de cada célula `T`

**Exemplo:**
```
Original:       Iterativa e Recursiva:
XXAAXXX         XXAAXXX
XXAAXAX         XXAAXAX
XXXXAXX         XXXXTXX
XAAAAAX         XTTTTTX
TAAXAAA         TTTXTTT
XXXXXXX         XXXXXXX
```

**Conceitos aplicados:**
- Flood fill iterativo e recursivo
- Reuso e adaptação mínima de código existente
- Verificação de limites de matriz

---

## 🥇 pilha_min.cpp — MinStack (LeetCode 155)

Implementação de uma pilha especial que retorna o **menor elemento presente na pilha** em tempo constante, sem precisar percorrê-la.

**Exemplo:**
```
push(5) → min: 5
push(3) → min: 3
push(7) → min: 3
pop()   → min: 3
pop()   → min: 5
```

**Conceitos aplicados:**
- Pilha implementada com `vector<>` e lógica de índice manual (sem `push_back`)
- Registro paralelo do mínimo acumulado para cada posição da pilha
- Consulta do mínimo em O(1) — sem percorrer nenhum elemento
- Desafio opcional: solução submetida e aceita no LeetCode 155

---

## 📊 fila_media.cpp — Fila com Média

Implementação de uma fila especial que retorna a **média aritmética atual dos elementos** presentes nela em tempo constante, sem recalcular a cada consulta.

**Exemplo:**
```
enfileira(10) → média: 10.0
enfileira(2)  → média: 6.0
enfileira(3)  → média: 5.0
enfileira(5)  → média: 5.0   (fila cheia, capacidade 4)
desenfileira() + enfileira(6) → média: 4.0
```

**Conceitos aplicados:**
- Buffer circular com `vector<>` — inserção e remoção em O(1)
- Variável `soma` atualizada incrementalmente a cada `enfileira` e `desenfileira`
- Cálculo da média em O(1): `soma / tamanho` — sem percorrer a fila
- Operador módulo `%` para wrap-around do índice no array circular

---

## 🛠️ Como compilar

Cada arquivo é independente. Para compilar e rodar individualmente:

```bash
g++ rotate.cpp -o rotate && ./rotate
g++ maior.cpp -o maior && ./maior
g++ strings.cpp -o strings && ./strings
g++ reverse.cpp -o reverse && ./reverse
g++ portland.cpp -o portland && ./portland
g++ island.cpp -o island && ./island
g++ chuva.cpp -o chuva && ./chuva
g++ contamina.cpp -o contamina && ./contamina
g++ pilha_min.cpp -o pilha_min && ./pilha_min
g++ fila_media.cpp -o fila_media && ./fila_media
```

---

## 📖 Referências

- Livro: *Entendendo Algoritmos* — Aditya Bhargava
- Disciplina de Algoritmos e Estruturas de Dados — IFPE
- [Beecrowd](https://www.beecrowd.com.br) — plataforma de juízes online
- [LeetCode](https://leetcode.com) — plataforma de desafios de programação