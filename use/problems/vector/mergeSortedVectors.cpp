#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> mergeSortedVectors(std::vector<int> v1, std::vector<int> v2) {
    std::vector<int> v(v1.size()+v2.size());
    int i = 0, j = 0, h = 0;
    for (; j<v1.size() && h<v2.size(); i++) {
        if(v1[j]<v2[h]) {
            v[i] = v1[j];
            j++;
        }
        else {
            v[i] = v2[h];
            h++;
        }
    }
    for (; j<v1.size(); i++) {
        v[i] = v1[j];
        j++;
    }
    for (; h<v2.size(); i++) {
        v[i] = v2[h];
        h++;
    }
    return v;
}

void test_mergeSortedVectors() {
    std::vector<int> vec1 = {1, 3, 5, 7};
    std::vector<int> vec2 = {2, 4, 6, 8, 9};
    std::vector<int> merged = mergeSortedVectors(vec1, vec2);
    std::vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(merged == expected);
    for (int i = 0; i < merged.size(); i++) {
        std::cout << merged[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    test_mergeSortedVectors();
}
