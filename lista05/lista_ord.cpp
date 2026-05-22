#include <iostream>

#include "lista_ord.h"

using namespace std;

struct tarefa {
    string nome;
    bool feita = false;

    bool operator < (const tarefa &t) const {
        return this->nome < t.nome;
    }

    bool operator > (const tarefa &t) const {
        return this->nome > t.nome;
    }

    bool operator ==(const tarefa &t) const {
        return this->nome == t.nome;
    }
};


int main() {
    cout << endl << " === Testando Lista Ordenada ==== " << endl;

    vector valores = {11, 4, 7, 9, 10};
    ListaOrdenada<int> listaOrd(10);
    for (auto &v : valores) {
        listaOrd.adicionar(v);
    }

    cout << endl << "Lista Ordenada: " << endl;
    for (int i = 1; i <= listaOrd.tamanho(); i++) {
        cout << i << ": " << listaOrd.pegar(i) << "; ";
    }
    cout << endl;

    vector buscas = {10, 22, 11, 5, 7};
    cout << "Buscas: " << endl;
    for (int v : buscas) {
        cout << "- Buscando " << v << ": " << listaOrd.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada de Tarefas: " << endl;

    // tarefa é o tipo do item; string é o tipo da chave usada para buscar o item
    ListaOrdenada<tarefa> todo(10);

    vector<tarefa> arr = { {"Feira", false},
                     {"Aluguel", false},
                     {"Lixo", false},
                     {"Estudar", false},
                     {"Cinema", false}};

    for (auto &v : arr) {
        todo.adicionar(v);
    }

    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome << " [" << (todo[i].feita?"feita":"nao feita") << "]" << endl;
    }

    vector<string> str = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    for (string &s : str) {
        // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        cout << "- Buscando " << s << ": " << todo.buscar({s, false }) << endl;
    }

    return 0;
}
