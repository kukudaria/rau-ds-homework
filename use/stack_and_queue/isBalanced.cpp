#include <iostream>
#include <stack>
#include <cassert>

bool isBalanced(const std::string &str) {
    std::stack<char> parens;
    for (int i = 0; i<str.size(); i++) {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            parens.push(str[i]);
        }
        else {
            if (str[i] == ')' && parens.top() == '(') {
                parens.pop();
            }
            else if (str[i] == ']' && parens.top() == '[') {
                parens.pop();
            }
            else if (str[i] == '}' && parens.top() == '{') {
                parens.pop();
            }
            else return false;
        }
    }
    return parens.empty();
}

void test_isBalanced() {
    assert(isBalanced("{[()]}") == true);
    assert(isBalanced("{}[]()") == true);
    assert(isBalanced("") == true);
    assert(isBalanced("{()}[]") == true);

    assert(isBalanced("()){}") == false);
    assert(isBalanced("(){}}") == false);
    assert(isBalanced("(){[}") == false);
    assert(isBalanced("([]{}") == false);
}

int main() {
    test_isBalanced();
    std::cout << "All tests pass\n";
}