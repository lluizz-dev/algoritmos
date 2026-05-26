# Lista 02 — Matrizes com e sem Recursão

Percurso de matrizes, flood fill iterativo e recursivo, e problemas de juízes online (Beecrowd e LeetCode).

---

## Parte 1 — Matrizes sem Recursão

### portland.cpp — Crepúsculo em Portland (BC2168)

Dada uma matriz de esquinas com câmeras (`1`) ou sem (`0`), determina se cada quarteirão é seguro (`S`) ou inseguro (`U`). Um quarteirão é seguro se tiver pelo menos duas câmeras nas suas quatro esquinas.

```
Entrada:        Saída:
1 1 0 1         SSS
1 0 1 0         SUS
1 0 0 1         SSS
0 1 1 0
```

**Conceitos:** duplo laço percorrendo a matriz, soma das quatro esquinas `(i,j)`, `(i,j+1)`, `(i+1,j)`, `(i+1,j+1)`, classificação por limiar `>= 2`.

> Desafio opcional: submeter no [Beecrowd 2168](https://www.beecrowd.com.br/judge/pt/problems/view/2168)

---

### island.cpp — Island Perimeter (LeetCode 463)

Calcula o perímetro da ilha formada pelas células `1` em uma matriz. A ilha é conexa e sem lagos internos.

```
Matriz:         Saída: 16
0 1 0 0
1 1 1 0
0 1 0 0
1 1 0 0
```

**Conceitos:** para cada célula de terra, contribui com 4 lados menos os lados compartilhados com vizinhos também de terra.

> Desafio opcional: submeter no [LeetCode 463](https://leetcode.com/problems/island-perimeter/)

---

## Parte 2 — Matrizes com Recursão

### chuva.cpp — Propagação de Chuva (BC3052 / OBI 2019)

Simula o escoamento de chuva a partir de uma gota (`o`), com obstáculos (`#`). Duas abordagens com comportamentos distintos:

- **Iterativa:** escorre apenas para a **esquerda**
- **Recursiva:** escorre apenas para a **direita**

```
Original:   Iterativa:   Recursiva:
.o...       oo...        .oo..
.#...       o#...        .#o..
.....       o....        ..o..
```

**Conceitos:** simulação iterativa com flag de mudança (`do-while`), flood fill recursivo (DFS em matriz), propagação direcionada com restrição de movimento.

> Desafio opcional: adaptar e submeter no [Beecrowd 3052](https://www.beecrowd.com.br/judge/pt/problems/view/3052)

---

### contamina.cpp — Contaminação (BC1583)

Propaga contaminação de células `T` para todas as células livres `A` conectadas, com barreiras `X`. Adaptado diretamente da lógica do problema Chuva com mínimo de modificações.

```
Original:       Saída:
XXAAXXX         XXAAXXX
XAAAAAX         XTTTTTX
TAAXAAA         TTTXTTT
```

**Conceitos:** flood fill iterativo e recursivo nas 4 direções, reuso da estrutura do problema anterior, verificação de limites de matriz.

> Desafio opcional: submeter no [Beecrowd 1583](https://www.beecrowd.com.br/judge/pt/problems/view/1583)

---

## Como compilar

```bash
g++ portland.cpp  -o portland  && ./portland
g++ island.cpp    -o island    && ./island
g++ chuva.cpp     -o chuva     && ./chuva
g++ contamina.cpp -o contamina && ./contamina
```