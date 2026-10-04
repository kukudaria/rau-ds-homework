#include <iostream>
#include <vector>
#include <cassert>

void manageCapacity(std::vector<int> &vec) {
    std::cout << "Capacity: " << vec.capacity() << "\n";
    std::cout << "Size: " << vec.size() << "\n";
    vec.reserve(500);
    for (int i = 1; i <= 500; i++) {
        vec.push_back(i);
    }
    std::cout << "Capacity: " << vec.capacity() << "\n";
    std::cout << "Size: " << vec.size() << "\n";
}

void test_manageCapacity() {
    std::vector<int> vec;
    manageCapacity(vec);
    assert(vec.capacity() == 500);
    assert(vec.size() == 500);
}

int main() {
    test_manageCapacity();
}
