#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

void agrupar(const vector<string> &palavras,
             unordered_map<string, vector<string>> &grupos) {

    for (const string &palavra : palavras) {
        string chave = palavra;

        sort(chave.begin(), chave.end());

        grupos[chave].push_back(palavra);
    }
}

int main() {
    unordered_map<string, vector<string>> grupos;
    vector<string> palavras = {
        "casa", "roma", "cora","gelo",
        "lego","ifpe", "arco","amor",
        "rota", "mora","caro", "saca",
        "ator", "fipe", "ramo", "pife"
    };

    agrupar(palavras, grupos);

    for (const auto &g : grupos) {
        for (const auto &s : g.second)
            cout << s << " ";
        cout << endl;
    }

    return 0;
}
