//
// Created by naby on 24-5-3.
//
/*
 * 通过哨兵节点可避免判断头结点是否为空的情形
 * 使用哨兵节点可以简化创建或者删除链表头节点
 * 操作的代码
 * */

#include "node_common.h"
#include <iostream>

ListNode *append_node(ListNode *head, int value) {
    ListNode dummy(0);
    dummy.next_node = head;

    auto *append_node = new ListNode(value);
    auto node = &dummy;
    while (node->next_node) {
        node = node->next_node;
    }
    node->next_node = append_node;
    return dummy.next_node;
}

ListNode *delete_node(ListNode *head, int value) {
    ListNode dummy(0);
    dummy.next_node = head;

    auto node = &dummy;
    while (node->next_node) {
        if (node->next_node->value == value) {
            auto delete_node = node->next_node;
            node->next_node = node->next_node->next_node;
            delete delete_node;
            break;
        }
        node = node->next_node;
    }
    return dummy.next_node;
}

ListNode *create_list_node(const std::vector<int> &values) {
    ListNode dummy(0);
    auto node = &dummy;
    for (auto value: values) {
        auto new_node = new ListNode(value);
        node->next_node = new_node;
        node = new_node;
    }
    return dummy.next_node;
}

void print_node(ListNode *head) {
    std::cout << "{";
    while (head) {
        std::cout << head->value;
        if (head->next_node) {
            std::cout << ",";
        }
        head = head->next_node;
    }
    std::cout << "}" << std::endl;
}

ListNode *create_ring_list(const std::vector<int> &values, int ring_index) {
    ListNode dummy(0);
    auto *node = &dummy;
    ListNode *entrance_node{nullptr};
    for (auto i = 0; i < values.size(); ++i) {
        auto new_node = new ListNode(values[i]);
        node->next_node = new_node;
        node = new_node;

        if (i == ring_index) {
            entrance_node = new_node;
        } else if (i == values.size() - 1) {
            node->next_node = entrance_node;
        }
    }
    return dummy.next_node;
}

ListNode *reverse_list(ListNode *head) {
    ListNode *prev = nullptr;
    auto current = head;
    while (current) {
        auto next = current->next_node;
        current->next_node = prev;
        prev = current;
        current = next;
    }
    return prev;
}
