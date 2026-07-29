//
// Created by IFPE on 05/08/2025.
//
#include <vector>
#include <iostream>

using namespace std;

// TODO: Fazer sem o Kadone
int max_profit(const vector<int> &costs, const vector<int> &sales) {
    int n = costs.size();
    int maior = 0;

    for (int start = 0; start < n; start++) {
        int soma = 0;
        for (int finish = start; finish < n; finish++) {
            soma += sales[finish] - costs[finish];
            if (soma > maior) {
                maior = soma;
            }
        }
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