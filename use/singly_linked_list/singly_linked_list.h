#pragma once
#include <vector>

struct ListNode {
    int data;
    ListNode* next;

    explicit ListNode(int val) : data(val), next(nullptr) {}

    bool operator==(const ListNode* rhead) {
        ListNode* lhead = this;
        while (rhead != nullptr && lhead != nullptr) {
            if (rhead->data != lhead->data) return false;
            rhead = rhead->next;
            lhead = lhead->next;
        }
        return rhead==lhead;
    }
};

void erase_after(ListNode* node) {
    if (node==nullptr || node->next==nullptr) throw std::invalid_argument("invalid node");
    ListNode* tmp = node->next->next;
    delete node->next;
    node->next = tmp;
}

ListNode* turn_vector_to_sll(std::vector<int> vec) {
    if (vec.empty()) return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *node = head;
    for (int i = 1; i < vec.size(); i++) {
        ListNode *next = new ListNode(vec[i]);
        node->next = next;
        node = next;
    }
    return head;
}

void delete_sll(ListNode* head) {
    if (head==nullptr) return;
    ListNode* curr = head;
    ListNode* next = head;
    while(next != nullptr) {
        curr = next;
        next = next->next;
        delete curr;
    }
}