/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#ifndef ORDENACAO_H_AULA
#define ORDENACAO_H_AULA

#include <vector>

using namespace std;

//A STL oferece uma sunção swap() que troca elementos; ela pode ser usada abaixo

template<class T>
void bubblesort(vector<T> &array) {
	// TODO
	int n = array.size();
	bool transicao;

	for (int i = 0; i < n - 1; i++) {
		transicao = false;

		for (int j = 0; j < n - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				T temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				transicao = true;
			}
		}

		if (!transicao)
			break;
	}
}

template<class T>
void selectionsort(vector<T> &array) {
	// TODO
}

template<class T>
void insertionsort(vector<T> &array) {
	// TODO
}

// Faz o merge dos subarrays em aux para array, isto é, array[...] = aux[...]
template<class T>
void merge(vector<T> &array, vector<T> &aux, int start, int mid, int finish) {
	// TODO
}

// Array: array que vai conter o resultado ordenado
// Aux: array auxiliar usado para ordenar as duas metades, esquerda e direita
// Repare que na chamada recursiva de mergesorte, array e aux se alternam
// Isto é, uma hora um é o principal e o outro é o auxiliar, depois invertem
template<class T>
void mergesort(vector<T> &array, vector<T> &aux, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);

	merge(array, aux, start, mid + 1, finish);
}

// Função chamada inicialmente;
// Chama a função mergesorte() acima com os limites start e finish, e o clone do array (aux).
template<class T>
void mergesort(vector<T> &array) {
    vector<T> aux = array; // TODO errado!
	mergesort(array, aux, 0, array.size() - 1);
}

// Partição do QuickSort
template<class T>
int partition(vector<T> &array, int start, int finish) {
	T pivot = array[finish];
	int i = start - 1;

	for (int j = start; j < finish; j++) {
		if (array[j] <= pivot) {
			i++;
			swap(array[i], array[j]);
		}
	}
	swap(array[i + 1], array[finish]);
	return i + 1;
}

template<class T>
void quicksort(vector<T> &array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Semelhante ao que ocorre com o MergeSort.
template<class T>
void quicksort(vector<T> &array) {
	quicksort(array, 0, array.size() - 1);
}

template<class T>
void stdsort(vector<T> &array) {
	sort(array.begin(), array.end());
}

// Funções Utilitárias


#endif


