//
// Created by IFPE on 05/05/2026.
//

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

enum Comando {
    UNKNOWN,
    ADD,
    INS,
    DELETE,
    NEXT,
    PREV,
    SHOW,
    LIST,
    QUIT
};
// Explicado no futuro
std::map<string, Comando> comandos = {
    {"add", ADD},
    {"ins", INS},
    {"del", DELETE},
    {"next", NEXT},
    {"prev", PREV},
    {"show", SHOW},
    {"list", LIST},
    {"quit", QUIT}
};

int main() {
    vector<string> tarefas = {
        "Pratica de Redes",
        "Questionario de AED",
        "Estudar Listas",
        "Pesquisar sobre a STL",
        "Instalar IDE"
    };

    list<string> todo;
    for (auto &s : tarefas) todo.push_back(s);

    string cmd, tarefa;

    // iterador que aponta para tarefa atual (1a)
    auto atual = todo.begin();

    while (cout << endl << "Comando: " && cin >> cmd && cmd != "quit") {
        try {
            switch (comandos[cmd]) {
                case ADD:
                    cout << "Nova tarefa a adicionar: ";
                    cin.ignore();
                    getline(cin, tarefa);
                    todo.push_back(tarefa);
                    break;

                case INS:
                    // TODO ler do teclado e inserir na posicao atual da lista
                    if (todo.empty())
                        throw runtime_error("Lista vazia, nao ha posicao atual para inserir.");
                    cout << "Tarefa a inserir na posicao atual: ";
                    cin.ignore();
                    getline(cin, tarefa);
                    todo.insert(atual, tarefa); // insere ANTES de atual
                    break;

                case DELETE:
                    // TODO apagar tarefa atual
                    if (todo.empty())
                        throw runtime_error("Lista vazia, nada a apagar.");
                    cout << "Tarefa \"" << *atual << "\" removida." << endl;
                    atual = todo.erase(atual);
                    // se apagou o ultimo, recua para o novo ultimo
                    if (atual == todo.end() && !todo.empty())
                        atual = prev(todo.end());
                    break;

                case NEXT:
                    // TODO ir para proxima tarefa (e exibir); erro se no final
                    if (todo.empty())
                        throw runtime_error("Lista vazia.");
                    if (next(atual) == todo.end())
                        throw runtime_error("Ja esta na ultima tarefa.");
                    ++atual;
                    cout << "Atual: " << *atual << endl;
                    break;

                case PREV:
                    // TODO voltar a tarefa anterior (e exibir); erro se na 1a
                    if (todo.empty())
                        throw runtime_error("Lista vazia.");
                    if (atual == todo.begin())
                        throw runtime_error("Ja esta na primeira tarefa.");
                    --atual;
                    cout << "Atual: " << *atual << endl;
                    break;

                case SHOW:
                    // TODO exibir tarefa atual
                    if (todo.empty())
                        throw runtime_error("Lista vazia.");
                    cout << "Atual: " << *atual << endl;
                    break;

                case LIST:
                    if (todo.empty())
                        throw runtime_error("Lista vazia.");
                    cout << "Tarefas: " << endl;
                    for (auto it = todo.begin(); it != todo.end(); ++it) {
                        cout << (it == atual ? " -> " : "    ");
                        cout << *it << endl;
                    }
                    break;

                case UNKNOWN:
                default:
                    throw invalid_argument("Comando desconhecido! (quit para sair)");
            }
        } catch (const exception &e) {
            cout << "Erro: " << e.what() << endl;
        }
    }
}