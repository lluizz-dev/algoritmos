#include <vector>
#include <iostream>
#include <set>
#include <map>

using namespace std;


// Retorna os dois números do vetor que somados = target
//   - retorna num vetor de 2 elementos, caso seja possível
//   - retorna vetor vazio, caso não seja

vector<int> two_sum_simple(const vector<int>& nums, int target) {
    // TODO
   
    return res;
}

void two_sum_test(const vector<int>& nums, int target) {
    auto res1 = two_sum_simple(nums, target);

    cout << "Testando " << target << "): ";
    if (res1.empty())
        cout << "impossivel" << endl;
    else {
        cout << res1[0] << " & " << res1[1] << endl;
    }
}

int main() {
//int two_sum() {
    cout << endl << "*** Problema TwoSum Simplificado *** " << endl;

    vector<int> nums = {2, 7, 11, 15, 12, 1, 35, 16, 23, 5};

    two_sum_test(nums, 12); // 7 & 5
    two_sum_test(nums, 23); // 7 & 16
    two_sum_test(nums, -1); // impossivel
    two_sum_test(nums, 17); // 2 & 15
    two_sum_test(nums, 34); // 11 & 23
    two_sum_test(nums, 16); // 11 & 5
    two_sum_test(nums, 41); // impossivel
    two_sum_test(nums, 10); // impossivel

    return 0;
}