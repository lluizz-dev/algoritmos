//
// Created by IFPE on 05/08/2025.
//
#include <vector>
#include <iostream>
#include <ranges>

using namespace std;

int max_profit(const vector<int> &costs, const vector<int> &sales) {
    int n = costs.size();
    int maior = 0;
    int atual = 0;

    for (int i = 0; i < n; i++) {
        int lucroDia = sales[i] - costs[i];

        // Kadane: ou continua a sequência atual, ou recomeça a partir daqui
        atual = max(lucroDia, atual + lucroDia);
        maior = max(maior, atual);
    }

    return maior;
}

// int main() {
int sales_trip() {
    cout << endl << "******* SALES_TRIP *******" << endl << endl;

    vector<int> costs = {10, 22, 15, 20, 18, 16, 14, 12, 10};
    vector<int> sales = {17, 12, 21, 15, 25, 40, 34, 20, 5};

    cout << "Max profit = " << max_profit(costs, sales) << endl; // 60

    return 0;
}