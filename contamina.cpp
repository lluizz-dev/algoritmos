#include <iostream>
#include <vector>

using namespace std;

void solucao_iterativa(vector<string> &mat) {
    bool changed;
    const int M = static_cast<int>(mat.size());
    const int N = static_cast<int>(mat[0].size());
    do {
        changed = false;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (mat[i][j] != 'A') continue;

                if ((i > 0     && mat[i - 1][j] == 'T') ||
                    (i < M - 1 && mat[i + 1][j] == 'T') ||
                    (j > 0     && mat[i][j - 1] == 'T') ||
                    (j < N - 1 && mat[i][j + 1] == 'T')) {
                    mat[i][j] = 'T';
                    changed = true;
                }
            }
        }
    }
    while (changed);
}

void recursao(vector<string> &mat, int i, int j) {
    int M = mat.size();
    int N = mat[0].size();

    if (i < 0 || i >= M || j < 0 || j >= N) return;
    if (mat[i][j] != 'A') return;

    mat[i][j] = 'T';

    recursao(mat, i - 1, j);
    recursao(mat, i + 1, j);
    recursao(mat, i, j - 1);
    recursao(mat, i, j + 1);
}

void solucao_recursiva(vector<string> &C) {
    int M = C.size();
    int N = C[0].size();

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] == 'T') {
                recursao(C, i - 1, j);
                recursao(C, i + 1, j);
                recursao(C, i, j - 1);
                recursao(C, i, j + 1);
            }
        }
    }
}

void print(vector<string> &C) {
    for (int i = 0; i < (int)C.size(); i++) {
        for (int j = 0; j < (int)C[i].size(); j++) {
            cout << C[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<string> matriz = {
        "XXAAXXX",
        "XXAAXAX",
        "XXXXAXX",
        "XAAAAAX",
        "TAAXAAA",
        "XXXXXXX"
    };

    auto m_iterativa = matriz;
    auto m_recursiva = matriz;

    solucao_iterativa(m_iterativa);
    solucao_recursiva(m_recursiva);

    cout << "Original: " << endl;
    print(matriz);
    cout << "Iterativa: " << endl;
    print(m_iterativa);
    cout << "Recursiva: " << endl;
    print(m_recursiva);

    return 0;
}