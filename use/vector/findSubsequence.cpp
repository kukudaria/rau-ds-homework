#include <iostream>
#include <vector>
#include <cassert>

int findSubsequence(std::vector<int> v, std::vector<int> subseq) {
    for (int i = 0; i<v.size()-subseq.size(); i++) {
        int flag = 1;
        for (int j = 0; j<subseq.size(); j++) {
            if (v[i+j] != subseq[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            return i;
        }
    }
    return -1;
}

void test_findSubsequence() {
    std::vector<int> main_vec = {1, 2, 3, 4, 5, 6};
    std::vector<int> sub_vec = {3, 4, 5};
    assert(findSubsequence(main_vec, sub_vec) == 2);
    std::cout << findSubsequence(main_vec, sub_vec) << "\n";
}

int main() {
    test_findSubsequence();
}
