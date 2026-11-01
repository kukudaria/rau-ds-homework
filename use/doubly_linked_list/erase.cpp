#include "doubly_linked_list.h"
#include <stdexcept>
#include <cassert>
#include <iostream>

void erase(ListNode* node) {
    if (node->prev != nullptr) node->prev->next = node->next;
    if (node->next != nullptr) node->next->prev = node->prev;
    delete node;
}

void test_erase() {
    {
    int val = 67;
    ListNode* node = new ListNode(val);
    int val2 = 68;
    ListNode* node2 = new ListNode(val2);
    int val3 = 69;
    ListNode* node3 = new ListNode(val3);
    node->next = node2;
    node2->prev = node;
    node2->next = node3;
    node3->prev = node2;
    erase(node2);
    assert(node->next == node3);
    assert(node3->prev == node);
    }

    {
    int val = 67;
    ListNode* node = new ListNode(val);
    int val2 = 68;
    ListNode* node2 = new ListNode(val2);
    int val3 = 69;
    ListNode* node3 = new ListNode(val3);
    node->next = node2;
    node2->prev = node;
    node2->next = node3;
    node3->prev = node2;
    erase(node);
    assert(node2->prev == nullptr);
    assert(node2->next == node3);
    assert(node3->prev == node2);
    }

    {
    int val = 67;
    ListNode* node = new ListNode(val);
    int val2 = 68;
    ListNode* node2 = new ListNode(val2);
    int val3 = 69;
    ListNode* node3 = new ListNode(val3);
    node->next = node2;
    node2->prev = node;
    node2->next = node3;
    node3->prev = node2;
    erase(node3);
    assert(node2->prev == node);
    assert(node2->next == nullptr);
    assert(node->next == node2);
    }
}

int main() {
    test_erase();
    std::cout << "All tests pass\n";
}