#pragma once
#include <vector>

struct ListNode {
    int data;
    ListNode* next;
    ListNode* prev;

    explicit ListNode(int val) : data(val), next(nullptr), prev(nullptr) {}

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

ListNode* turn_vector_to_dll(std::vector<int> vec) {
    if (vec.empty()) return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *node = head;
    for (int i = 1; i < vec.size(); i++) {
        ListNode *next = new ListNode(vec[i]);
        node->next = next;
        next->prev = node;
        node = next;
    }
    return head;
}

void delete_dll(ListNode* head) {
    if (head==nullptr) return;
    ListNode* curr = head;
    ListNode* next = head;
    while(next != nullptr) {
        curr = next;
        next = next->next;
        delete curr;
    }
}