#include <iostream>
#include <vector>
#include <cassert>


template <typename T>
void resizeVector(std::vector<T> &vec, int new_size, T param) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
    vec.resize(new_size, param);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

void test_resizeVector() {
    std::vector<int> v = {1, 2, 3};
    resizeVector(v, 5, 42);
    assert(v.size() == 5);
    assert(v[3] == 42);
    assert(v[4] == 42);
}

int main() {
    test_resizeVector();
}
