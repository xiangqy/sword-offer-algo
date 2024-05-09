//
// Created by naby on 24-5-3.
//

#ifndef SWORD_OFFER_ALGO_NODE_COMMON_H
#define SWORD_OFFER_ALGO_NODE_COMMON_H

#include <vector>

struct ListNode {
    int value;
    ListNode *next_node{nullptr};
    ListNode *pre_node{nullptr};

    ListNode() = default;

    ListNode(int value) {
        this->value = value;
        next_node = nullptr;
        pre_node = nullptr;
    }
};

using ListNodePtr = ListNode *;

ListNode *create_list_node(const std::vector<int> &values);

ListNode *append_node(ListNode *head, int value);

ListNode *delete_node(ListNode *head, int value);

ListNode *create_ring_list(const std::vector<int> &values, int ring_index);

ListNode *reverse_list(ListNode *head);

void print_node(ListNode *head);

#endif //SWORD_OFFER_ALGO_NODE_COMMON_H
