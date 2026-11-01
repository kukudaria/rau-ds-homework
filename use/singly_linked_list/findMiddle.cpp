#include "singly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <vector>
#include <iostream>

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void test_findMiddle() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *head = turn_vector_to_sll(vec);
    assert(findMiddle(head)->data == 3);
    delete_sll(head);

    std::vector<int> vec2 = {1, 2, 3, 4, 5, 6};
    ListNode *head2 = turn_vector_to_sll(vec2);
    assert(findMiddle(head2)->data == 4);
    delete_sll(head2);

    std::vector<int> vec3;
    ListNode *head3 = turn_vector_to_sll(vec3);
    assert(findMiddle(head3) == nullptr);
    delete_sll(head3);

    std::vector<int> vec4 = {1};
    ListNode *head4 = turn_vector_to_sll(vec4);
    assert(findMiddle(head4)->data == 1);
    delete_sll(head4);
}

int main() {
    test_findMiddle();
    std::cout << "All tests pass\n";
}