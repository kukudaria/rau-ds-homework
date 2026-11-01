#include "singly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <vector>
#include <iostream>

void eraseDuplicats(ListNode* head) {
    if (head==nullptr || head->next==nullptr) return;
    ListNode* curr = head;
    while(curr != nullptr && curr->next != nullptr) {
        if (curr->data == curr->next->data) erase_after(curr);
        else curr = curr->next;
    }
}

void test_eraseDuplicats() {
    {
    std::vector<int> vec = {1, 2};
    ListNode *head = turn_vector_to_sll(vec);
    std::vector<int> new_vec = {1, 2};
    ListNode *new_head = turn_vector_to_sll(new_vec);
    eraseDuplicats(head);
    assert(*head == new_head);
    delete_sll(head);
    delete_sll(new_head);
    }

    {
    std::vector<int> vec = {1, 1, 2};
    ListNode *head = turn_vector_to_sll(vec);
    std::vector<int> new_vec = {1, 2};
    ListNode *new_head = turn_vector_to_sll(new_vec);
    eraseDuplicats(head);
    assert(*head == new_head);
    delete_sll(head);
    delete_sll(new_head);
    }

    {
    std::vector<int> vec = {1, 1, 2, 3, 3};
    ListNode *head = turn_vector_to_sll(vec);
    std::vector<int> new_vec = {1, 2, 3};
    ListNode *new_head = turn_vector_to_sll(new_vec);
    eraseDuplicats(head);
    assert(*head == new_head);
    delete_sll(head);
    delete_sll(new_head);
    }
}

int main() {
    test_eraseDuplicats();
    std::cout << "All tests pass\n";
}