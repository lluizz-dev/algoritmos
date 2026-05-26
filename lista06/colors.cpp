#include <vector>
#include <iostream>

using namespace std;

void ordenar_cores(vector<int>& nums) {
    // TODO
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