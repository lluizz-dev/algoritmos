#include <iostream>
#include <vector>

using namespace std;

void portland(const vector<vector<int>> &M) {
    // TODO
    int tamanho = M.size();

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1; j++) {
            int soma = M[i][j] + M[i + 1][j] + M[i][j + 1] + M[i + 1][j + 1];

            if (soma >= 2) {
                cout << "S";
            }
            else {
                cout << "U";
            }
        }
        cout << endl;
    }
}

int main() {
    // vector<vector<int>> M(n, vector<int>(n));
    const vector<vector<int>> M1 = {{1, 0},
                                    {0, 0}};
    const vector<vector<int>> M2 = {{1, 0, 0},
                                    {1, 1, 0},
                                    {0, 0, 1}};
    const vector<vector<int>> M3 = {{1, 1, 0, 1},
                                    {1, 0, 1, 0},
                                    {1, 0, 0, 1},
                                    {0, 1, 1, 0}};

    cout << "Caso 1:" << endl;
    portland(M1);
    cout << "Caso 2:" << endl;
    portland(M2);
    cout << "Caso 3:" << endl;
    portland(M3);
    return 0;
}