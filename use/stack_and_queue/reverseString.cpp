#include <iostream>
#include <stack>
#include <cassert>
#include <string>

void reverseString(std::string &str) {
    std::stack<char> chars;
    for (int i = 0; i < str.size(); i++) {
        chars.push(str[i]);
    }
    for (int i = 0; i < str.size(); i++) {
        str[i] = chars.top();
        chars.pop();
    }
}

void test_reverseString() {
    std::string str = "blah";
    reverseString(str);
    assert(str == "halb");

    std::string str2 = "";
    reverseString(str2);
    assert(str2 == "");
}

int main() {
    test_reverseString();
    std::cout << "All tests pass\n";
}