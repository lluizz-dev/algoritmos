#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>

using namespace std;

template <class T>
long hash_function(const T &v);

// Calcula o hash para chaves do tipo int
template <>
inline long hash_function<int>(const int &v) {
    return abs(v);
}

// Calcula o hash para chaves do tipo string
template <>
inline long hash_function<string>(const string &v) {
    long hash = -1;
    const char *str = v.c_str();
    while (*str) hash += *str++;
    return hash;
}

template<class T_key, class T_value>
class Hashtable {
    vector<list<pair<T_key, T_value>>> table;

    T_value not_found;

    int size = 0;

    // Pega a chave e retorna o indice
    // Chama hash_function() e ajusta para o tamanho da tabela
    int get_idx(T_key key) {
        long hash = hash_function(key);
        if (hash < 0) throw std::runtime_error("Erro no calculo do hash! [Negativo]");
        return hash % table.size();
    }

public:
    Hashtable(int cap, T_value not_found) : table(cap), not_found(not_found) { }

    ~Hashtable() = default;

    void insert(T_key key, T_value value) {
        // TODO
        int idx = get_idx(key);
        remove(key);
        table[idx].push_back(pair<T_key, T_value>(key, value));
    }

    void remove(T_key key) {
        // TODO
        int idx = get_idx(key);
        for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
            if (it->first == key) {
                table[idx].erase(it);
                break;
            }
        }
    }

    T_value search(T_key key) {
        int idx = get_idx(key);
        for (auto &par : table[idx]) {
            if (par.first == key) {
                return par.second;
            }
        }
        return not_found;
    }

    void show() {
        int i = 0;
        for (auto &list : table) {
            cout << i++ << ": ";
            for (auto &[key, value] : list)
                cout << "(" << key << ": " << value << ") ";
            cout << endl;
        }
    }

    T_value operator [] (const T_key &key) {
        return search(key);
    }
};

#endif //HASHTABLE_H
