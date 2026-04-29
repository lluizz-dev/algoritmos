#include <iostream>
#include <vector>

using namespace std;

class fila_media {
private:
    vector<int> itens;
    // sugestao de atributos; pode/deve haver outros
    int ini = 0,   // posicao do 1o elemento
        tam = 0,   // tamanho (numero atual de elementos)
        cap = 0,   // capacidade (numero max. de elementos)
        soma = 0;

public:
    // construtor receba capacidade; inicializa cap e o vector itens.
    explicit fila_media(int cap) : itens(cap), cap(cap) {  }

    // fila esta cheia?
    bool cheia() const {
        // TODO
        if (this->tam == this->cap) return true;
        return false;
    }

    // fila esta vazia?
    bool vazia() const {
        // TODO
        if (this->tam == 0) return true;
        return false;
    }

    // remove elemento na frente da fila
    void desenfileira() {
        // TODO
        if (!vazia()) {
            this->soma -= this->itens[this->ini];
            this->ini = (this->ini + 1) % this->cap;
            this->tam--;
        }
        else cout << "Underflow" << endl;
    }

    // adiciona i ao final da fila
    void enfileira(int i) {
        // TODO
        if (!cheia()) {
            this->itens[(this->ini + this->tam) % this->cap] = i;
            this->tam++;
            this->soma += i;
        }
        else {
            cout << "Overflow" << endl;
        }
    }

    // retorna elemento na frente da fila
    int proximo() {
        // TODO
        if (!vazia()) return this->itens[this->ini];
        cout << "Underflow" << endl;
        return -1;
    }

    // retorna atual media dos elementos
    double media() const {
        // TODO
        if (!vazia()) return (double)this->soma / this->tam;
        return 0.0;
    }

    // retorna o numero de elementos na fila
    int tamanho() {
        // TODO
        return this->tam;
    }
};

int main() {
    vector arr = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6};

    fila_media fila(4);

    for (int i : arr) {
        if (fila.cheia()) fila.desenfileira();

        fila.enfileira(i);

        cout << fila.media() << endl;
    }

    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7

    return 0;
}
