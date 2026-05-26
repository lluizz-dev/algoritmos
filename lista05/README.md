# Lista 05 — Busca Binária e Hashtable

Lista ordenada com busca binária, implementação de hashtable com tratamento de colisões, e uso do `std::unordered_map<>` para agrupamento de anagramas.

---

## Parte 1 — ListaOrdenada e Busca Binária

### lista_ord.h — `ListaOrdenada<T>`

Herda de `ListaArray` (Prática 04) e mantém os elementos sempre em ordem crescente.

- `inserir()` — lança exceção imediatamente, pois a posição é definida pela ordenação, não pelo usuário
- `adicionar()` — encontra a posição correta e insere, mantendo a ordem
- `buscar()` — busca binária iterativa ou recursiva: descarta metade dos candidatos a cada passo

**Complexidade da busca:** O(log n) — muito mais eficiente que busca linear O(n) para listas grandes.

**Como funciona a busca binária:**
```
Array ordenado: 1 3 5 7 9 11 13 15
Buscar 7:
  [1..15] → meio = 7  → encontrado no índice 3 ✅

Buscar 6:
  [1..15] → meio = 7  → 6 < 7, vai para esquerda
  [1..5]  → meio = 3  → 6 > 3, vai para direita
  [5..5]  → meio = 5  → 6 > 5, intervalo vazio → não encontrado
```

> Desafio opcional: mudar critério de ordenação da `struct tarefa` para priorizar não-feitas antes das feitas, com ordem alfabética dentro de cada grupo.

---

### kth_largest.cpp — K-ésimo maior (LeetCode 703)

A classe `KthLargest` mantém as pontuações de uma universidade fictícia e retorna o K-ésimo maior valor após cada inserção via `add()`.

**Estratégia:** usando a `ListaOrdenada` em ordem crescente, o K-ésimo maior é sempre o elemento na posição `tamanho - k + 1`.

> Desafio opcional: submeter no [LeetCode 703](https://leetcode.com/problems/kth-largest-element-in-a-stream/) incorporando toda a lógica na classe.

---

## Parte 2 — Hashtable e std::unordered_map<>

### hashtable.h — Hashtable com encadeamento

Implementação manual de uma tabela de espalhamento como `vector` de `std::list<pair<chave, valor>>`. Colisões tratadas por encadeamento (listas encadeadas por índice).

- `hash_function(CPF)` — recebe CPF como string, aproveita que os caracteres representam dígitos numéricos para calcular o hash
- `insert(key, value)` — calcula o índice via hash, remove entrada anterior com mesma chave se existir, insere o par
- `search(key)` — calcula o índice, percorre a lista do bucket procurando a chave
- `get_idx(key)` — função privada que calcula o hash e ajusta o índice ao tamanho da tabela

---

### anagramas.cpp — Agrupamento de anagramas

Usa `std::unordered_map<>` (hashtable padrão da STL) para agrupar palavras que são anagramas umas das outras.

```
Entrada: "casa", "roma", "cora", "gelo", "lego", "amor", "rota" ...

Grupos:
amor mora rota ator ramo roma
lego gelo
casa saca
```

**Estratégia:** para cada palavra, cria uma cópia ordenada como chave — anagramas geram a mesma chave. Acesso via `map[chave]` cria um `vector` vazio automaticamente se a chave não existir, então basta fazer `push_back` da palavra original.

```cpp
string aux = palavra;
sort(aux.begin(), aux.end());  // "roma" → "amor", "mora" → "amor"
map[aux].push_back(palavra);   // agrupa sob a mesma chave
```

---

## Como compilar

```bash
g++ lista_ord.cpp   -o lista_ord   && ./lista_ord
g++ kth_largest.cpp -o kth_largest && ./kth_largest
g++ hashtable.cpp   -o hashtable   && ./hashtable
g++ anagramas.cpp   -o anagramas   && ./anagramas
```