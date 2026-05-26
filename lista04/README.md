# Lista 04 — Listas com Array e Encadeada

Implementação de uma lista genérica com template e duas estratégias internas, mais aplicações práticas com `std::list<>`.

> **Atenção:** todas as listas são indexadas em 1, não em 0.

---

## Parte 1 — Implementando Listas

### lista.h — Interface genérica `Lista<T>`

Classe base abstrata com as operações fundamentais:

| Método | Descrição |
|---|---|
| `adicionar(v)` | Insere no fim |
| `inserir(idx, v)` | Insere em posição específica (1..tamanho) |
| `remover(idx)` | Remove por índice |
| `pegar(idx)` | Retorna elemento por valor |
| `buscar(valor)` | Retorna índice do elemento ou -1 |
| `tamanho()` | Número de elementos atual |

---

### lista_array.h — `ListaArray<T>`

Armazena elementos em `vector<T>` de capacidade fixa. Sem usar `vector<>.insert()` ou `vector<>.erase()` — o deslocamento é feito manualmente para não forçar realocação.

- `inserir`: desloca elementos à direita a partir do índice, então coloca o novo valor
- `remover`: desloca elementos à esquerda a partir do índice removido, decrementa `num_itens`

**Complexidade:** inserção e remoção no meio são O(n) pelo deslocamento.

---

### lista_encadeada.h — `ListaEncadeada<T>`

Armazena elementos em nós ligados por ponteiros. Cuidado especial com manipulação de ponteiros para evitar acessos inválidos à memória.

- Inserção e remoção no início: O(1)
- Acesso por índice: O(n) — percorre a cadeia até a posição

> Desafio opcional: [Beecrowd 1740](https://www.beecrowd.com.br/judge/pt/problems/view/1740)

---

## Parte 2 — Usando Listas

### alunos.cpp — Filtro por nota

A função `filtrar()` separa alunos em aprovados e reprovados com base em uma nota de corte. Funciona tanto com `ListaArray` quanto com `ListaEncadeada`.

```
filtrar(alunos, reprovados, 7.0)

Aprovados:   Esmeralda 7.5, Vicente 8.6, Vitruvio 9.6, Tereza 8.2
Reprovados:  Gilmar 5.4, Matilda 4.6, Roberval 6.8, Juliete 5.5
```

**Por que remover de trás para frente?** Ao remover o elemento na posição `i`, todos os elementos seguintes deslocam uma posição. Se percorremos da frente para trás, o índice do próximo elemento a verificar muda — pulamos elementos sem querer. Percorrendo de trás para frente, remoções não afetam os índices das posições ainda não visitadas.

> Desafio opcional: refazer com `std::list<>` e `splice()`

---

### todo.cpp — Lista de Tarefas (TO-DO)

Gerenciador de tarefas via linha de comando usando `std::list<>` e iteradores. Permite: listar, adicionar ao final, inserir na posição atual, navegar (próxima/anterior), exibir e apagar a tarefa atual.

**Conceitos:** `std::list<>` duplamente encadeada da STL, iteradores como "ponteiros" para elementos (`++`, `--`, `*`), `list.insert()` retorna iterador para o novo item, `list.erase()` retorna o próximo elemento.

---

## Como compilar

```bash
g++ listas.cpp  -o listas  && ./listas
g++ alunos.cpp  -o alunos  && ./alunos
g++ todo.cpp    -o todo    && ./todo
```