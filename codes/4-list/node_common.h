//
// Created by naby on 24-5-3.
//

#ifndef SWORD_OFFER_ALGO_NODE_COMMON_H
#define SWORD_OFFER_ALGO_NODE_COMMON_H

struct ListNode{
    int value;
    ListNode* next_node{nullptr};
    ListNode* pre_node{nullptr};

    ListNode() = default;
    ListNode(int value){
        this->value = value;
        next_node = nullptr;
        pre_node = nullptr;
    }
};
using ListNodePtr = ListNode*;

#endif //SWORD_OFFER_ALGO_NODE_COMMON_H
