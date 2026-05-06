#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
private:
    stack<int> stack;
public:
    bool isValid(const string &s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            }
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (stack.empty()) return false;

                if (s[i] == ')' && stack.top() == '(') {
                    stack.pop();
                }
                else if (s[i] == '}' && stack.top() == '{') {
                    stack.pop();
                }
                else if (s[i] == ']' && stack.top() == '[') {
                    stack.pop();
                }
                else return false;
            }
        }
        return stack.empty();
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
