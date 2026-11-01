#include "singly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <vector>
#include <iostream>

bool hasCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

void test_hasCycle() {
    std::vector<int> vec = {1, 2};
    ListNode *head = turn_vector_to_sll(vec);
    assert(hasCycle(head) == false);
    head->next->next = head;
    assert(hasCycle(head) == true);
    head->next->next = nullptr;
    delete_sll(head);
}

int main() {
    test_hasCycle();
    std::cout << "All tests pass\n";
}