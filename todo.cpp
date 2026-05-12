//
// Created by IFPE on 05/05/2026.
//

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

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
    vector tarefas = {
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
        switch (comandos[cmd]) {
            case ADD:
                cout << "Nova tarefa a adicionar:";
                cin.ignore();
                getline(cin, tarefa);
                todo.push_back(tarefa);
                break;
            case INS:
                // TODO ler do teclado e inserior na posicao atual da lista
                break;
            case DELETE:
                // TODO apagar tarefa atual
                break;
            case NEXT:
                // TODO ir para proxima tarefa (e exibir); erro se no final
                break;
            case PREV:
                // TODO voltar a tarefa anterior (e exibir); erro se na 1a
                break;
            case SHOW:
                // TODO exibir tarefa atual
                break;
            case LIST:
                cout << "Tarefas: " << endl;
                for (auto &t : todo)
                    cout << " - " << t << endl;
                break;
            case UNKNOWN:
            default:
                cout << "Commando desconhecido! (q para sair)" << endl;
        }
    }
}