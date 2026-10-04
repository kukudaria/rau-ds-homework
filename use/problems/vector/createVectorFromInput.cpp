#include <iostream>
#include <vector>
#include <cassert>

std::vector<int> createVectorFromInput() {
    std::vector<int> vec;
    int input;

    std::cin >> input; 

    while (input != 0) {
        vec.push_back(input);
        std::cin >> input;
    }

    return vec;
}

void test_createVectorFromInput() {
    std::vector<int> inputVec = createVectorFromInput();
    for (int i = 0; i < inputVec.size(); i++)
        assert(inputVec[i] != 0);
}
int main() {
    test_createVectorFromInput();
}
