#ifndef PRATICA_06_LINKEDLIST_H
#define PRATICA_06_LINKEDLIST_H

#include <iostream>
#include <string>
#include "lista.h"

using namespace std;

/* Lista Encadeada*/

template<class T>
class ListaEncadeada : public Lista<T> {
    struct Nodo {
        T valor;
        Nodo * prox;
        Nodo(T valor, Nodo * prox) : valor(valor), prox(prox) { }
    };

    Nodo * ini = nullptr;
    Nodo * fim = nullptr;
    int num_itens = 0;

    T & pegar_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");
        Nodo *tmp = ini;
        for (int i = 1; i < idx && tmp != nullptr; i++) {
            tmp = tmp->prox;
        }
        return tmp->valor;
    }

public:
    explicit ListaEncadeada(int cap) : Lista<T>(cap) {  }

    ~ListaEncadeada() override {
        while (ini != nullptr) {
            Nodo * tmp = ini;
            ini = ini->prox;
            delete tmp;
        }
    }

    // Adiciona no final da lista
    void adicionar(T value) override {
        if (num_itens >= this->capacidade) throw runtime_error("Lista cheia.");

        Nodo *tmp = new Nodo(value, nullptr);

        if (ini == nullptr) ini = tmp; // 1o item?

	// ligando o final se nao for o unico
        if (fim != nullptr) fim->prox = tmp; 

        fim = tmp;

        num_itens++;
    }

    // Insere na posicao idx (comeca em 1)
    void inserir(int idx, T v) override {
        if (idx < 1 || idx > num_itens) throw runtime_error("Indice invalido.");
        if (num_itens >= this->capacidade) throw runtime_error("Lista cheia.");

        Nodo *tmp = new Nodo(v, nullptr);
        
	// TODO: 2 casos
	//   1 - 1o elemento?
	//   2 - Elemento no meio? [ver pegar]

        num_itens++;
    }

    // Remove um item dados o indice idx
    void remover(int idx) override {
        if (idx < 1 || idx > num_itens) throw runtime_error("Indice invalido.");

        Nodo *tmp = ini;

	// TODO: 4 casos
	//   1 - 1o elemento?
	//   2 - 1o e único elemento?
 	//   3 - Elemento do meio (não 1o)? [ver pegar]
        //   4 - Não 1o e último?

        delete tmp;

        num_itens--;
    }

    T pegar(int idx) const override {
        if (idx < 1 || idx > num_itens) throw runtime_error("Indice invalido.");
        Nodo *tmp = ini;
        for (int i = 1; i < idx && tmp != nullptr; i++) {
            tmp = tmp->prox;
        }
        return tmp->valor;
    }

    // Retorna o indice do valor (>= 1), se existir; -1 caso contrario
    int buscar(T valor) const override {
        Nodo *tmp = ini;
        // TODO [ver pegar]
        return -1;
    }

    int tamanho() const override {
        return num_itens;
    }

    T & operator [] (int idx) override {
        return pegar_ref(idx);
    }
};

#endif //PRATICA_06_LINKEDLIST_H
