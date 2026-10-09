#include <iostream>
#include <string>

template <typename T>
bool isEqual(T val1, T val2) {
    return val1 == val2;
}

template <>
bool isEqual(const char* str1, const char* str2) {
    if (strcmp(str1, str2) == 0) return true;
    return false;
}

int main() {
}
