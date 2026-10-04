#include <iostream>
#include <vector>
#include <cassert>

std::vector<std::vector<int>> groupAdjacent(std::vector<int> v) {
    std::vector<std::vector<int>> new_v;
    std::vector<int> vec;
    vec.push_back(v[0]);
    for (int i = 1; i<v.size(); i++) {
        if (v[i] == v[i-1]) {
            vec.push_back(v[i]);
        }
        else {
            new_v.push_back(vec);
            vec.clear();
            vec.push_back(v[i]);
        }
    }
    if (!vec.empty()) {
        new_v.push_back(vec);
    } 
    return new_v;
}

void test_groupAdjacent() {
    std::vector<int> vec = {1, 1, 2, 2, 2, 3, 1, 1};
    std::vector<std::vector<int>> groups = groupAdjacent(vec);
    assert(groups.size() == 4);
    for (int i = 0; i<groups.size(); i++) {
        std::cout << "{";
        for (int j = 0; j<groups[i].size(); j++) {
            std::cout << groups[i][j] << " ";
        }
        std::cout << "} ";
    }
    std::cout << "\n";
}

int main() {
    test_groupAdjacent();
}
