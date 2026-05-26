#include <algorithm>
#include <iostream>
#include <chrono>

#include "ordenacao.h"

// Valida um array (isto é, se está ordenado ou não)
template<class T>
int validate(vector<T> &array) {
    for (int i = 0; i < array.size() - 1; i++) {
        if (array[i] > array[i + 1]) return 0;
    }
    return 1;
}

// Exibe um array na tela
template<class T>
void print(vector<T> &array) {
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

// Testa um algoritmo passado como parâmetro.
template<class T>
void test(vector<T> &array, const char * name, void function(vector<T> &array), bool printFlag) {
    vector<T> copy = array;
    auto start = std::chrono::high_resolution_clock::now();

    function(copy);

    auto finish = std::chrono::high_resolution_clock::now();
    long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

    string status = "ok ";
    if (!validate(copy)) {
        status = "err";
    } else {
        auto copy2 = array;
        sort(copy2.begin(), copy2.end());
        for (int i = 0; i < array.size(); i++) {
            if (copy[i] != copy2[i]) {
                status = "corrupted";
                break;
            }
        }
    }

    cout << name << ": " << status << " (tempo[us] = " << elapsed << ") ";

    if (printFlag) print(copy); else cout << endl;
}

int main() {
    int size = 25;
    bool print = true;

    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * 2);
    }

    test(array, "BubbleSort   ", bubblesort, print);
    test(array, "SelectionSort", selectionsort, print);
    test(array, "InsertionSort", insertionsort, print);
    test(array, "MergeSort    ", mergesort, print);
    test(array, "QuickSort    ", quicksort, print);
    test(array, "std::sort    ", stdsort, print);
}