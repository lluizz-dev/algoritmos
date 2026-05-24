
#ifndef LISTA_ORD_H
#define LISTA_ORD_H

#include "lista_array.h"

using namespace std;


template <class T>
class ListaOrdenada : public ListaArray<T> {


public:
    explicit ListaOrdenada(int cap) : ListaArray<T>(cap) {  }

    void inserir(int idx, T v) override {
        // TODO
        throw runtime_error("Operação inválida em lista ordenada: use adicionar()");
    }

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");

        int pos = this->num_itens;
        while (pos > 0 && this->itens[pos - 1] > v) {
            this->itens[pos] = this->itens[pos - 1];
            pos--;
        }
        this->itens[pos] = v;
        this->num_itens++;
    }

    int buscar(T v) const override {
        // TODO: busca binária
        int esq = 0, dir = this->num_itens - 1;

        while (esq <= dir) {
            int meio = esq + (dir - esq) / 2;

            if (this->itens[meio] == v)
                return meio + 1;

            if (this->itens[meio] < v)
                esq = meio + 1;
            else
                dir = meio - 1;
        }
        return -1;
    }
};


#endif 
