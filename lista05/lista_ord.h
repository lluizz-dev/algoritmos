
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

    }

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");
        // TODO
    }

    int buscar(T v) const override {
        // TODO: busca binária

        return -1;
    }
};


#endif 
