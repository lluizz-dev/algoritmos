#include <iostream>
#include <string>
#include <vector>

#include "hashtable.h"

using namespace std;

struct CPF {
    string valor;

    CPF(const char * s) : valor(s) {
        if (valor.empty()) throw runtime_error("CPF vazio!");
    }
    bool operator== (const CPF& cpf) const {
        return valor == cpf.valor;
    }
};

inline ostream &operator<< (ostream &out, const CPF& cpf) {
    return out << cpf.valor;
}

template <>
inline long hash_function<CPF>(const CPF &cpf) {
    // TODO
    return -1;
}

template <class T_chave, class T_valor>
bool testar_hashtable (const vector<pair<T_chave, T_valor>> &dados_criacao,
                       const vector<pair<T_chave, T_valor>> &dados_teste,
                       const T_valor not_found) {

    Hashtable<T_chave, T_valor> tabela(10, not_found);

    try {
        for (auto &[k, v] : dados_criacao) {
            tabela.insert(k, v);
        }
    } catch (std::runtime_error &e) {
        cout << "Erro na insercao: " << e.what() << endl;
        return false;
    }

    cout << "TABELA CRIADA: " << endl;
    tabela.show();

    cout << endl << "TESTANDO BUSCA E REMOCAO: "  << endl;

    for (auto &a: dados_teste) {
        cout << "Buscando " << a.first << " ... ";

        T_valor valor = tabela.search(a.first);

        if (valor != a.second) { // encontrado valor errado!
            cout << "ERRO ";
            cout << " esperado = " << a.second;
            cout << " encontrado = " << valor;
            return false;
        }

        if (a.second == not_found) {
            cout << "Nao encontrado [OK]" << endl;
            continue;
        }

        cout << "encontrado = " << a.second <<  " ... removendo...";
        tabela.remove(a.first);
        bool removido = tabela.search(a.first) == not_found;
        cout << (removido ? "OK!" : "ERRO!") << endl;

        if (!removido) return false;
    }

    cout << endl << "TABELA FINAL: " << endl;
    tabela.show();

    return true;
}

int hashfunc() {
    // int main() {
    cout << endl << "*** Testando Funcoes de Espalhamento *** " << endl;

    cout << "Hash de " << 100 << " = " << hash_function(100) << endl;
    cout << "Hash de " << 11241 << " = " << hash_function(11241) << endl;
    cout << "Hash de " << -123 << " = " << hash_function(-123) << endl;

    cout << "Hash de " << "Maria" << " = " << hash_function(string("Maria")) << endl;
    cout << "Hash de " << "Joao" << " = " << hash_function(string("Joao")) << endl;
    cout << "Hash de " << "StringGrandeDeTeste" << " = " << hash_function(string("StringGrandeDeTeste")) << endl;

    cout << "Hash do CPF " << "123.456.789-00" << " = " << hash_function(CPF("123.456.789-00")) << endl;
    cout << "Hash do CPF " << "111.222.333-44" << " = " << hash_function(CPF("111.222.333-44")) << endl;
    cout << "Hash do CPF " << "987.654.321-00" << " = " << hash_function(CPF("987.654.321-00")) << endl;

    return 0;
}

int hashtable() {
// int main() {

    cout << endl << "****** Testando Hashtable ****** " << endl << endl;

    cout << endl << "*** Tabela de Alunos *** " << endl;

    vector<pair<string, float>> dados_notas =  {{"Joao", 5},
                                                {"Pedro", 7},
                                                {"Larissa", 10},
                                                {"Tereza", 7.5},
                                                {"Victor", 6},
                                                {"Mario", 4}};

    vector<pair<string, float>> teste_notas = {{"Joao", 5},
                                               {"Carlos", -1},
                                               {"Pedro", 7},
                                               {"Maria", -1},
                                               {"Mario", 4}};

    if (!testar_hashtable<string, float>(dados_notas, teste_notas, -1.0f))
        return -1;

    // ----------------------
    /* Tabela de clientes: CPF -> Nome */
    cout << endl << "*** Tabela de Clientes *** " << endl;

    vector<pair<CPF, string>> dados_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"987.654.231-00", "Maria"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"555.666.777-88", "Pedro"},
                                                  {"123.321.123-32", "Everaldo"}};

    vector<pair<CPF, string>> teste_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"999.999.999-99", "NOT_FOUND"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"111.111.111-11", "NOT_FOUND"},
                                                  {"123.321.123-32", "Everaldo"}};

    if (!testar_hashtable<CPF, string>(dados_clientes, teste_clientes, "NOT_FOUND"))
        return -1;

    cout << endl << "****** HASHTABLE COMPLETA OK! *******" << endl;

    return 0;
}

int main() {

    hashfunc();
    hashtable();

    return 0;
}

