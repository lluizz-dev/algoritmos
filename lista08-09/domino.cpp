#include "graph.h"


Graph montar_grafo(const vector<pair<int, int>> &pecas, int max) {
    Graph grafo(max + 1);

    // pecas sao bidirecionais
    for (const auto& par : pecas) {
        grafo.edge(par.first, par.second, 1);
        grafo.edge(par.second, par.first, 1);
    }


    return grafo;
}

bool is_euler(const Graph &graph) {
    // conexo
    if (!graph.isConnected()) return false;

    // dois vertices com grau impar
    int oddCount = 0;
    for (int i = 0; i < graph.size(); i++) {
        if (graph.degree(i) % 2 != 0) {
            oddCount++;
        }
    }

    return oddCount <= 2;
}

// int main() {
void domino() {
    cout << endl << "*** Testando Domino ***" << endl << endl;

    vector<pair<int, int>> pecas1 = {{0, 1}, {1, 2}, {1, 0}, {3, 2}, {2, 1}};
    vector<pair<int, int>> pecas2 = {{0, 1}, {1, 2}, {1, 0}, {3, 2}, {2, 3}, {0, 4}};

    Graph grafo1 = montar_grafo(pecas1, 3);
    Graph grafo2 = montar_grafo(pecas2, 4);

    cout << "Pecas 1: " << (is_euler(grafo1)?"Sim":"Nao") << endl; // Sim
    cout << "Pecas 2: " << (is_euler(grafo2)?"Sim":"Nao") << endl; // Nao
}