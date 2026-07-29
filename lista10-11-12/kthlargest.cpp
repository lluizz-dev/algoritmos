#include <iostream>
#include <vector>

using namespace std;

// Partição estilo Lomuto: usa o último elemento como pivô.
// Ao final, tudo <= pivô fica antes dele, tudo > pivô fica depois.
// Retorna a posição final do pivô.
int partition(vector<int> &array, int start, int finish) {
    int pivot = array[finish];
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

// Busca recursiva pelo elemento que ficaria no índice targetIndex
// se o array estivesse totalmente ordenado (ascendente).
int quickselectRec(vector<int> &values, int start, int finish, int targetIndex) {
    if (start == finish) return values[start];

    int p = partition(values, start, finish);

    if (p == targetIndex) {
        return values[p];
    } else if (targetIndex < p) {
        return quickselectRec(values, start, p - 1, targetIndex);
    } else {
        return quickselectRec(values, p + 1, finish, targetIndex);
    }
}

// k-ésimo MAIOR elemento (k=1 é o maior, k=2 o segundo maior, etc.)
int quickselect(vector<int> &values, int k) {
    int n = values.size();
    if (k < 1 || k > n) return -1;

    int targetIndex = n - k; // k-ésimo maior == (n-k)-ésimo menor (0-indexado)
    return quickselectRec(values, 0, n - 1, targetIndex);
}

class KthLargest {
    int k;
    vector<int> scores;
public:
    KthLargest(int k, vector<int>& nums) : k(k), scores(nums) {
        // scores já inicia com os valores de nums
    }

    int add(int val) {
        scores.push_back(val);
        return quickselect(scores, k);
    }

    const vector<int> & values() {
        return scores;
    }
};

// int main() {
int kthlargest() {
    cout << endl << "******* KTHLARGEST *******" << endl << endl;

    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums);

    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v) << endl;
        for (int x : kthLargest.values()) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
