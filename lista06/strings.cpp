#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar(const string &a, const string& b) {
    // TODO
    return false;    
}

vector<vector<string>> agrupar(vector<string> &strs) {
    vector<vector<string>> res;

    // TODO

    return res;
}

int main() {

    vector<string> strs = {"Redes", "IFPE", "Algoritmos", "Android",
                           "Complexidade", "IF", "PE", "Recife",
                           "TADS", "2025", "BubbleSort", "Git",
                           "GitHub", "Subversion", "Gradle", "Docker"};

    vector<vector<string>> groups = agrupar(strs);

    for (const auto &group : groups) {
        for (const auto &str : group) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}