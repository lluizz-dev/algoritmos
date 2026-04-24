#include <iostream>

using namespace std;

string inverter(const string &s) {
    // TODO
    string invertida;
    string semUltimaLetra = s.substr(0, s.length() - 1);
    // Caso base
    if (s.empty()) {
        return s;
    }
    // Caso reursivo
    invertida = s[s.length() - 1] + inverter(semUltimaLetra);

    return invertida;
}

void palindromo(const string &s) {
    string invertida = inverter(s);
    if (invertida == s) {
        cout << "A palavra " << invertida << " é um palíndromo" << endl;
    }
}

int main() {
    system("chcp 65001");
    cout << inverter("recursao") << endl;  // oasrucer
    cout << inverter("banana") << endl;    // ananab
    cout << inverter("ifpe") << endl;      // epfi
    cout << inverter("luiz") << endl;      // ziul

    palindromo("ovo");

    return 0;
}
