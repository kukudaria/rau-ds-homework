#include <iostream>
#include <vector>
#include <cassert>

int removeElementsGreaterThan(std::vector<int> &vec, int val) {
    int removed = 0;
    while(vec.back()>val) {
        vec.pop_back();
        removed++;
    }
    return removed;
}

void test_removeElementsGreaterThan() {
    std::vector<int> v = {1, 3, 5, 7, 9};
    int removed = removeElementsGreaterThan(v, 5);
    assert(removed == 2);
    std::vector<int> expected = {1, 3, 5};
    assert(v == expected);
    std::cout << removed << "\n";
}

int main() {
    test_removeElementsGreaterThan();
}
