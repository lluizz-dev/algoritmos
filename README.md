# 📚 Estudos de Algoritmos — C++

Repositório com exercícios práticos de algoritmos e estruturas de dados desenvolvidos em C++ durante os estudos da disciplina. Os problemas envolvem manipulação de arrays, recursão e strings.

---

## 📁 Estrutura do Projeto

```
.
├── rotate.cpp   # Rotação de array N posições
├── maior.cpp    # Maior elemento via recursão
├── strings.cpp  # Reordenação de string (Counting Sort)
└── reverse.cpp  # Inversão de string via recursão
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

## 🛠️ Como compilar

Cada arquivo é independente. Para compilar e rodar individualmente:

```bash
g++ rotate.cpp -o rotate && ./rotate
g++ maior.cpp -o maior && ./maior
g++ strings.cpp -o strings && ./strings
g++ reverse.cpp -o reverse && ./reverse
```

Ou configure o `CMakeLists.txt` com um `add_executable` para cada arquivo.

---

## 📖 Referências

- Livro: *Entendendo Algoritmos* — Aditya Bhargava
- Disciplina de Algoritmos e Estruturas de Dados