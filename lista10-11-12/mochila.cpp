#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

float solve(const vector<int> &price, const vector<int> &weight, int k) {
    int n = price.size();

    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;

    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return (float)price[a] / weight[a] > (float)price[b] / weight[b];
    });

    float totalValue = 0.0f;
    int restante = k;

    for (int i = 0; i < n && restante > 0; i++) {
        int pos = idx[i];

        if (weight[pos] <= restante) {
            // cabe inteiro
            totalValue += price[pos];
            restante -= weight[pos];
        } else {
            // não cabe inteiro
            float fraction = (float)restante / weight[pos];
            totalValue += price[pos] * fraction;
            restante = 0;
        }
    }

    return totalValue;
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


