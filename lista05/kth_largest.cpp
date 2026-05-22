#include <iostream>
#include "lista_ord.h"

class KthLargest {
    ListaOrdenada<int> scores;
    int k;

public:
    KthLargest(int k, vector<int>& nums) : scores(10000), k(k) {
        for (int v : nums) scores.adicionar(v);
    }

    int add(int val) {
        // TODO
       
	return -1;
    }
};

int main() {
    vector nums = {4, 5, 8, 2};
    vector vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums);

    // Saída: 3o maior eh 4, 5, 5, 8, 8
    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
    }
}