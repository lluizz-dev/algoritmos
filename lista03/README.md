# Lista 03 — Pilhas e Filas

Implementação de estruturas clássicas com operações otimizadas, e aplicações práticas com pilha e fila da STL.

---

## Parte 1 — Implementando Pilhas e Filas

### pilha_min.cpp — MinStack (LeetCode 155)

Pilha especial que retorna o menor elemento presente em tempo constante O(1), sem percorrê-la.

```
push(5) → min: 5
push(3) → min: 3
push(7) → min: 3
pop()   → min: 3
pop()   → min: 5
```

**Conceitos:** `vector<>` com índice manual (sem `push_back`), vetor paralelo registrando o mínimo acumulado para cada posição da pilha — consulta em O(1).

> Desafio opcional: submeter no [LeetCode 155](https://leetcode.com/problems/min-stack/)

---

### fila_media.cpp — Fila com Média

Fila especial que retorna a média aritmética dos elementos presentes em O(1), sem recalcular a cada consulta.

```
enfileira(10) → média: 10.0
enfileira(2)  → média: 6.0
enfileira(3)  → média: 5.0
desenfileira() + enfileira(6) → média: 4.0
```

**Conceitos:** buffer circular com `vector<>` — inserção e remoção em O(1), variável `soma` atualizada incrementalmente, média como `soma / tamanho`, operador `%` para wrap-around do índice.

---

## Parte 2 — Usando Pilhas e Filas

### parentesis.cpp — Validação de Parênteses (LeetCode 20)

Dada uma string com `(`, `)`, `[`, `]`, `{`, `}`, verifica se é válida.

```
"[{()}]" → válida
"()[]{}" → válida
"{[(}])" → inválida
"(][){}" → inválida
```

**Conceitos:** ao encontrar caractere de abertura, empilha; ao encontrar fechamento, desempilha e verifica correspondência; string válida se a pilha estiver vazia ao final.

> Desafio opcional 1: submeter no [LeetCode 20](https://leetcode.com/problems/valid-parentheses/)  
> Desafio opcional 2: [LeetCode 150 — Notação Polonesa Reversa](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

---

### round_robin.cpp — Simulação Round Robin

Simula o algoritmo de escalonamento Round Robin. Processos com PID e demanda de ciclos são servidos em sequência; a cada rodada decrementa `max_ciclos`. Processos zerados saem da fila e são registrados na ordem de conclusão.

**Conceitos:** `queue<>` da STL, simulação de fila circular, controle de quantum de CPU.

---

## Como compilar

```bash
g++ pilha_min.cpp   -o pilha_min   && ./pilha_min
g++ fila_media.cpp  -o fila_media  && ./fila_media
g++ parentesis.cpp  -o parentesis  && ./parentesis
g++ round_robin.cpp -o round_robin && ./round_robin
```