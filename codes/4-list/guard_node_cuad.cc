//
// Created by naby on 24-5-3.
//
/*
 *通过哨兵节点可避免判断头结点是否为空的情形
 * */

#include "log/log_setting.h"
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

int main(int argc, char **argv) {
    std::vector<int> list_value{9, 8, 3, 7, -9, 34};
    auto head = create_list_node(list_value);
    print_node(head);
    head = delete_node(head, 7);
    print_node(head);
    head = append_node(head, 109);
    print_node(head);
    return 0;
}