#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(const string &s) {
        // TODO
        return false;
    }
};

int main() {
    string testes[] = {
        "(", // I
        ")", // I
        "()", // V
        "[{()}]", // V
        "()[]{}", // V
        "{[(}])", // I
        "(][){}", // I
        "}{)(][" // I
    };

    for (auto &s : testes) {
        cout << s << ": ";
        cout << (Solution().isValid(s)?"Valida":"Invalida") << endl;
    }
}
