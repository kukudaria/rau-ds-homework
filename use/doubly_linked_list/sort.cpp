#include "doubly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

void sort(ListNode* head) {
    ListNode* curr = head;
    ListNode* tail = nullptr;
    while (head != tail) {
        curr = head;
        while (curr->next != tail) {
            if (curr->data > curr->next->data) std::swap(curr->data, curr->next->data);
            curr = curr->next;
        }
        tail = curr;
    }
}

void test_sort() {
    std::vector<int> vec = {5, 3, 1, 2, 4};
    std::vector<int> sort_vec = {1, 2, 3, 4, 5};
    ListNode* head = turn_vector_to_dll(vec);
    ListNode* sort_head = turn_vector_to_dll(sort_vec);
    sort(head);
    assert(*head == sort_head);
}

int main() {
    test_sort();
    std::cout << "All tests pass\n";
}