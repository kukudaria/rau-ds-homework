#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
std::vector<T> filterVector(std::vector<T> v, bool(*pred)(T)) {
    std::vector<T> new_v;
    for (int i = 0; i<v.size(); i++) {
        if (pred(v[i])) {
            new_v.push_back(v[i]);
        }
    }
    return new_v;
}

bool isEven(int x) {
        return x % 2 == 0;
    }

void test_filterVector() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> filtered = filterVector(vec, isEven);
    std::vector<int> expected = {2,4,6};
    assert(filtered == expected);
    for (int i = 0; i < filtered.size(); i++) {
        std::cout << filtered[i] << " ";
    }
}

int main() {
    test_filterVector();
}
