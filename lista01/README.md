# Lista 01 — Arrays, Strings e Recursão

Prática de revisão com foco em manipulação de arrays/strings e primeiros passos com recursão.

---

## Parte 1 — Arrays e Recursão

### rotate.cpp — Rotação de array

Dado um `vector` de inteiros e um valor `N`, a função `rotate()` desloca todos os elementos `N` posições à direita. Elementos que ultrapassam o fim voltam para o início.

```
Entrada:  3 5 8 10 1 7 9 4  (N = 3)
Saída:    7 9 4 3 5 8 10 1
```

**Conceitos:** operador `%` para calcular novas posições sem loop duplo, array auxiliar para evitar sobrescrita, suporte a valores negativos de `N`.

> Desafio opcional: [LeetCode 189](https://leetcode.com/problems/rotate-array/)

---

### maior.cpp — Maior elemento recursivo

A função recursiva `maior()` retorna o maior elemento de um array sem usar loops.

```
Entrada:  10 1 5 3 12 7 4 6
Saída:    12
```

**Conceitos:** caso base com array de um elemento, caso recursivo — o maior de N elementos é o maior entre o último e o maior dos N-1 anteriores.

---

## Parte 2 — Strings, Arrays e Recursão

### strings.cpp — Reordenação de string

A função `reordenar()` recebe uma string com letras minúsculas e retorna as letras em ordem alfabética, preservando repetições. Sem `std::sort()`.

```
"casa"   → "aacs"
"escola" → "acelos"
"banana" → "aaabnn"
```

**Conceitos:** vetor de contagem com 26 posições (uma por letra), mapeamento de caracteres para índices via subtração ASCII (`'c' - 'a' = 2`), reconstrução da string percorrendo o vetor de contagens.

> Desafio opcional: [Beecrowd 1276](https://www.beecrowd.com.br/judge/pt/problems/view/1276)

---

### reverse.cpp — Inversão recursiva de string

A função recursiva `inverter()` retorna uma string com os caracteres na ordem inversa. Inclui verificação de palíndromo como desafio opcional.

```
"recursao" → "oasrucer"
"banana"   → "ananab"
"ovo"      → é palíndromo ✅
```

**Conceitos:** caso base com string vazia, caso recursivo concatenando o último caractere com a inversão do restante via `substr()`.

---

## Como compilar

```bash
g++ rotate.cpp  -o rotate  && ./rotate
g++ maior.cpp   -o maior   && ./maior
g++ strings.cpp -o strings && ./strings
g++ reverse.cpp -o reverse && ./reverse
```