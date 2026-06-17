# 🌳 Prática 07 — Árvore de Busca Binária (BST) e AVL

Disciplina: Algoritmos e Estruturas de Dados — IFPE  
Implementações em C++ de BST e AVL, com aplicações práticas de ordenação e busca eficiente.

---

## 📁 Arquivos

| Arquivo | Descrição |
|---|---|
| `bst.h` / `bst.cpp` | Implementação da Árvore de Busca Binária |
| `avl.h` / `avl.cpp` | Implementação da AVL (BST autobalanceada) |
| `bst_avl.cpp` | Testes de inserção, busca, remoção e validação |
| `tree_sort.cpp` | Ordenação de vetor usando a árvore |
| `two_sum.cpp` | Problema Two Sum com complexidade O(N log N) |

---

## 🔧 Parte 1 — Implementando BST e AVL

### `_insert()` e `_search()` — bst.cpp

Inserção recursiva na BST: valores menores vão para a esquerda, maiores para a direita. Duplicatas são ignoradas. A altura do nó é atualizada via `updateH()` ao final de cada inserção, o que é necessário para o funcionamento correto da AVL.

A busca segue a mesma lógica: desce à esquerda se a chave for menor que o nó atual, à direita se for maior, retornando `nullptr` se não encontrar.

### `rotateRight()` — avl.cpp

Implementada simetricamente ao `rotateLeft()` já fornecido. Ao final da rotação, as alturas dos nós envolvidos são atualizadas na ordem correta (filho antes do pai).

---

## 📊 Parte 2 — Aplicações

### Problema 1 — Tree Sort (`tree_sort.cpp`)

Usa a BST/AVL para ordenar um vetor. O percurso **em-ordem** (esquerda → raiz → direita) visita os elementos em ordem crescente, pois a BST garante que tudo à esquerda de um nó é menor e tudo à direita é maior.

```cpp
void BinaryTree::_sort(Node * _root, vector<int> &res) {
    if (_root == nullptr) return;
    _sort(_root->left, res);
    res.push_back(_root->key);
    _sort(_root->right, res);
}
```

**Exemplo:**
```
Antes:  2 7 11 15 12 1 35 16 23 5
Depois: 1 2 5 7 11 12 15 16 23 35
```

> ⚠️ O uso de `push_back()` é ineficiente pois pode forçar realocações internas do vetor a cada inserção.

---

### Problema 2 — Two Sum (`two_sum.cpp`)

Dado um vetor e um valor `target`, encontra dois elementos distintos que somam o alvo.

**Estratégia O(N log N):**

1. Insere todos os elementos num `std::set<>` — O(N log N)
2. Para cada elemento X, verifica se o complemento `target - X` existe no set — O(log N) por busca
3. Garante que X ≠ complemento (sem somar o mesmo elemento duas vezes)

```
Testando 12): 7 & 5
Testando 23): 7 & 16
Testando 17): 2 & 15
Testando 34): 11 & 23
Testando -1): impossivel
```

A solução ingênua (força bruta) testa todos os pares possíveis e tem complexidade O(N²). A abordagem com `std::set<>` reduz para **O(N log N)**, a mesma diferença de desempenho entre Bubble Sort e Quick Sort.

---

## 🛠️ Como compilar

```bash
# Tree Sort
g++ tree_sort.cpp bst.cpp avl.cpp -o tree_sort && ./tree_sort

# Two Sum
g++ two_sum.cpp -o two_sum && ./two_sum

# Testes BST/AVL
g++ bst_avl.cpp bst.cpp avl.cpp -o bst_avl && ./bst_avl
```