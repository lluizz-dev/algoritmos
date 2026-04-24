#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimetro = 0;

        int linhas = grid.size();
        int colunas = grid[0].size();

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {

                if (grid[i][j] == 1) {
                    // cima
                    if (i == 0 || grid[i - 1][j] == 0) perimetro++;

                    // baixo
                    if (i == linhas - 1 || grid[i + 1][j] == 0) perimetro++;

                    // esquerda
                    if (j == 0 || grid[i][j - 1] == 0) perimetro++;

                    // direita
                    if (j == colunas - 1 || grid[i][j + 1] == 0) perimetro++;
                }

            }
        }

        return perimetro;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    cout << Solution().islandPerimeter(grid) << endl; // res = 16

    return 0;
}
