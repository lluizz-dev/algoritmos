# Lista 06 — Algoritmos de Ordenação

Implementação e comparação dos principais algoritmos de ordenação, do O(N²) clássico ao O(N log N) eficiente, mais aplicações práticas usando ordenação.

---

## Parte 1 — Implementando Algoritmos de Ordenação

### ordenacao.h — Implementações

Todos os algoritmos recebem `vector<T> &array` por referência e ordenam in-place. O arquivo `ordenacao.cpp` testa e mede o tempo de cada um.

#### BubbleSort — O(N²)

Compara pares vizinhos repetidamente. A flag `swapped` interrompe cedo se o array já estiver ordenado.

| Caso | Complexidade |
|---|---|
| Pior (array invertido) | O(N²) |
| Melhor (já ordenado) | O(N) com flag |
| Espaço | O(1) |

#### SelectionSort — O(N²)

A cada passo encontra o menor elemento do trecho não ordenado e o coloca na posição correta.

| Caso | Complexidade |
|---|---|
| Pior e melhor | O(N²) — sempre percorre o trecho |
| Espaço | O(1) |

#### InsertionSort — O(N²)

Constrói o array ordenado elemento a elemento, "encaixando" cada novo valor na posição correta — como organizar cartas na mão.

| Caso | Complexidade |
|---|---|
| Pior (array invertido) | O(N²) |
| Melhor (quase ordenado) | O(N) |
| Espaço | O(1) |

#### MergeSort — O(N log N)

Divide o array ao meio recursivamente, ordena cada metade e mescla os resultados. Sempre O(N log N) independente da entrada.

| Caso | Complexidade |
|---|---|
| Todos os casos | O(N log N) |
| Espaço | O(N) — array auxiliar na mesclagem |

#### QuickSort — O(N log N) médio

Escolhe um pivô via `partition()`, reorganiza o array (menores à esquerda, maiores à direita) e recursiona nos dois lados. O pivô fica em sua posição final após o `partition` — não precisa ser tocado novamente.

| Caso | Complexidade |
|---|---|
| Médio | O(N log N) |
| Pior (pivô sempre mínimo/máximo) | O(N²) |
| Espaço | O(log N) — pilha de recursão |

**Como o `partition` funciona:**
```
Antes:  [7, 2, 9, 1, 5]  pivô = 5
Depois: [2, 1, 5, 7, 9]  retorna índice 2
         ↑↑  ↑  ↑↑
        ≤5  pivô  ≥5
```
O `int` retornado é o índice final do pivô — não uma cópia do array.

---

## Parte 2 — Usando Algoritmos de Ordenação

### colors.cpp — Ordenando cores

Dado um `vector` com valores `0`, `1`, `2` e `3` representando cores, retorna o array ordenado em O(N) sem usar `std::sort()`. A solução deve ser facilmente estendida para mais valores diferentes.

**Conceitos:** Counting Sort — conta ocorrências de cada valor e reconstrói o array.

> Desafio opcional: [LeetCode 75 — Sort Colors](https://leetcode.com/problems/sort-colors/)

---

### strings.cpp — Agrupamento por tamanho

A função `agrupar()` agrupa strings de mesmo comprimento usando `std::sort()` com o comparador customizado `comparar()` passado como parâmetro.

```
Entrada: "Redes", "IFPE", "Algoritmos", "Android", "IF", "PE" ...

Saída:
IF PE
Git
IFPE TADS 2025
Redes
Recife GitHub Gradle Docker
Android
BubbleSort
Algoritmos Subversion
Complexidade
```

**Conceitos:** `comparar()` retorna `a.length() < b.length()`, varredura linear após ordenação detecta mudança de grupo quando o tamanho muda, `vector<vector<string>>` como resultado.

---

## Comparativo de desempenho (N = 10000)

| Algoritmo | Complexidade | Tempo esperado |
|---|---|---|
| BubbleSort | O(N²) | lento — dezenas a centenas de ms |
| SelectionSort | O(N²) | lento |
| InsertionSort | O(N²) | lento (melhor que Bubble na prática) |
| MergeSort | O(N log N) | rápido — < 1 ms |
| QuickSort | O(N log N) | rápido — geralmente o mais rápido |
| std::sort | O(N log N) | referência — introsort híbrido |

---

## Como compilar

```bash
g++ -O2 ordenacao.cpp -o ordenacao && ./ordenacao
g++ colors.cpp        -o colors    && ./colors
g++ strings.cpp       -o strings   && ./strings
```