#include <iostream>
#include <vector>

using namespace std;

int soma(const vector<int>& nums, int inicio = 0) {
    if (nums.empty()) {
        return 0;
    }
    vector<int> numeros = nums;
    numeros.erase(numeros.begin());
    int resultado = nums[inicio] + soma(numeros);
    return resultado;
}

int contador(const vector<int>& nums) {
    if (nums.empty()) {
       return 0;
    }

}

int main() {
    vector<int> numeros = {1, 2, 3, 4, 5};

    cout << soma(numeros);
}