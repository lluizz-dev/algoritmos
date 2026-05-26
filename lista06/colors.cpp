#include <vector>
#include <iostream>

using namespace std;

void ordenar_cores(vector<int>& nums) {
    if (nums.empty()) return;

    int max_val = nums[0];
    for (int num : nums) {
        if (num > max_val) max_val = num;
    }

    vector<int> contagem(max_val + 1, 0);

    for (int num : nums) {
        contagem[num]++;
    }

    int indice_original = 0;
    for (int cor = 0; cor <= max_val; ++cor) {
        while (contagem[cor] > 0) {
            nums[indice_original] = cor;
            indice_original++;
            contagem[cor]--;
        }
    }
}

int main() {
    vector test1 = {2, 0, 1, 3};
    vector test2 = {2, 3, 0, 2, 3, 1, 3, 1, 0};
    vector test3 = {1, 3, 0, 2, 0, 3, 1, 2, 0, 3, 1, 0, 2, 3, 2};

    ordenar_cores(test1); for (int v : test1) cout << v << " "; cout << endl;
    ordenar_cores(test2); for (int v : test2) cout << v << " "; cout << endl;
    ordenar_cores(test3); for (int v : test3) cout << v << " "; cout << endl;

    return 0;
}