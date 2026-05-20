#include <iostream>
#include <vector>

using namespace std;

string reordenar(const string &str) {
    // TODO
    vector<int> contagem(26, 0);

    for (int i = 0; i < str.length(); i++) {
        int indice = str[i] - 'a';
        contagem[indice]++;
    }

    string palavraOrdenada;
    for (int i = 0; i < contagem.size(); i++) {
        for (int j = 0; j < contagem[i]; j++) {
            palavraOrdenada = palavraOrdenada + (char)('a' + i);
        }
    }
    return palavraOrdenada;
}

int main() {
    cout << reordenar(string("casa")) << endl;
    cout << reordenar(string("escola")) << endl;
    cout << reordenar(string("banana")) << endl;
    cout << reordenar(string("luiz")) << endl;
}
