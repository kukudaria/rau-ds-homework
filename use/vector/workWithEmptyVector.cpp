#include <iostream>
#include <vector>
#include <cassert>

void workWithEmptyVector() {
    std::vector<int> vec;

    for (int i = 1; i < 11; i++) {
        vec.push_back(i);
        std::cout << "Capacity: " << vec.capacity() << "\n";
        std::cout << "Size: " << vec.size() << "\n";
    }

    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }

    std::cout << "\n";
}

int main() {
    workWithEmptyVector();
}
