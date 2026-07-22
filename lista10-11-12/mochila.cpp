#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float solve(const vector<int> &price, const vector<int> &weight, int k) {
    // TODO
   
    return -1.0;
}

// int main() {
int mochila() {
    cout << endl << "******* MOCHILA *******" << endl << endl;

    vector<int> precos = {100, 10 , 10, 100, 50};
    vector<int> pesos  = {50, 50, 100, 20, 10};
    int K = 100;

    float res = solve(precos, pesos, K);

    cout << res << endl; // 254

    return 0;
}


