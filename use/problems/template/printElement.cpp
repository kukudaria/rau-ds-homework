#include <iostream>
#include <string>

template <typename T>
void printElement(const T &element) {
    std::cout << element << "\n";
}

void test_printElement() {
    printElement(5);
    printElement(5.5);
    printElement("пять");
}

int main() {
    test_printElement();
}
