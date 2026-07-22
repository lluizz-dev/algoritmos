//
// Created by IFPE on 05/08/2025.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


bool solveRec(vector<string> &M, int lin, int col) {
    int nLin = M.size();
    int nCol = M[0].size();

    if (lin < 0 || lin >= nLin || col < 0 || col >= nCol) return false;

    char c = M[lin][col];

    if (c == '#' || c == 'x') return false;

    if (c == 'd') return true;

    bool eraOrigem = (c == 'o');
    if (!eraOrigem) M[lin][col] = 'x';

    if (solveRec(M, lin - 1, col)) return true; // cima
    if (solveRec(M, lin + 1, col)) return true; // baixo
    if (solveRec(M, lin, col - 1)) return true; // esquerda
    if (solveRec(M, lin, col + 1)) return true; // direita

    if (!eraOrigem) M[lin][col] = '.';

    return false;
}

void solve(vector<string> &M) {
    int nLin = M.size();
    int nCol = M[0].size();

    // encontra a posição de origem 'o'
    for (int i = 0; i < nLin; i++) {
        for (int j = 0; j < nCol; j++) {
            if (M[i][j] == 'o') {
                solveRec(M, i, j);
                return;
            }
        }
    }
}

void print(const vector<string> &M) {
    for (auto &s : M) {
        cout << s << endl;
    }
    cout << endl;
}

int labirinto() {
    cout << endl << "******* LABIRINTO *******" << endl << endl;

    vector<string> M1 = {
            ".#...",
            "...##",
            ".#..#",
            "o##.d",
            "#####"
    };

    vector<string> M2 = {
            "#...o",
            "..###",
            ".#...",
            "...#.",
            "###d."
    };

    solve(M1);
    print(M1);

    /* sa�da valida
    .#...
    xxx##
    x#xx#
    o##xd
    #####
    */

    solve(M2);
    print(M2);

    /*
    #xxxo
    xx###
    x#xxx
    xxx#x
    ###dx
     */


    return 0;
}

/*
  https://judge.beecrowd.com/pt/problems/view/1621

5 5
.#...
...##
.#..#
.##..
#####
5 5
.....
####.
.....
.####
.....
0 0
 */
