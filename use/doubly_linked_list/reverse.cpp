#include "doubly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

ListNode* reverse(ListNode* head) {
    ListNode* tmp = head;
    while (tmp->next != nullptr) {
        std::swap(tmp->next, tmp->prev);
        tmp = tmp->prev;
    }
    std::swap(tmp->next, tmp->prev);
    return tmp;
}

void test_reverse() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::vector<int> rev_vec = {5, 4, 3, 2, 1};
    ListNode* head = turn_vector_to_dll(vec);
    ListNode* rev_head = turn_vector_to_dll(rev_vec);
    assert(*reverse(head) == rev_head);
}

int main() {
    test_reverse();
    std::cout << "All tests pass\n";
}