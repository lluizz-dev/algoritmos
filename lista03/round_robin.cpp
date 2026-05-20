
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct processo {
    int pid;
    int ciclos;
};

vector<int> round_robin(vector<processo> processos, int max_ciclos) {
    queue<processo> fila;
    vector<int> concluidos;

    for (auto &p : processos)
        fila.push(p);

    while (!fila.empty()) {
        processo atual = fila.front();
        fila.pop();

        atual.ciclos -= max_ciclos;

        if (atual.ciclos <= 0) {
            concluidos.push_back(atual.pid);
        } else {
            fila.push(atual);
        }
    }

    return concluidos;
}

int main() {
    int max_ciclos = 500;

    std::vector<processo> processos = {
        {1, 1000},
        {2, 1500},
        {3, 2200},
        {4, 500},
        {5, 750},
        {6, 1250},
        {7, 120},
        {8, 5000}
    };

    auto concluidos = round_robin(processos, max_ciclos);

    cout << "Ordem de processos concluidos: " << endl;
    for (auto pid : concluidos) {
        cout << pid << " ";
    }
    cout << endl;

    return 0;
}