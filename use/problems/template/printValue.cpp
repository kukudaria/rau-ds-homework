#include <iostream>
#include <string>

template <typename T>
void printValue(T val) {
    std::cout << val;
}

template <>
void printValue(bool val) {
    if (val) std::cout << "true";
    else std::cout << "false";
}

template <>
void printValue(char* str) {
    std::cout << "\"" << str << "\"";
}

int main() {
}
