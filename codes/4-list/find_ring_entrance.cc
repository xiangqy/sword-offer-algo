//
// Created by xiang on 24-5-4.
//
/*
 * 如果一个链表中包含环，那么应该如何找出环的入口节点？从链表
 * 的头节点顺着next指针方向进入环的第一个节点为环的入口节点
 *
 * 解法一：
 * 1. 找出环中的节点node
 * 2. 计算环的长度
 * 3. 快指针先偏移环长度指针
 * 4. 慢指针与快指针同时向后偏移直到遇到，遇到的节点就为环的入口点
 * */

#include "log/log_setting.h"
#include "node_common.h"

ListNode *get_node_in_loop(ListNode *head) {
    if (head == nullptr || head->next_node == nullptr)
        return nullptr;

    auto *slow = head->next_node;
    auto *fast = slow->next_node;

    while (slow && fast) {
        if (slow == fast) {
            return slow;
        }

        slow = slow->next_node;
        fast = fast->next_node;
        if (fast) {
            fast = fast->next_node;
        }
    }
    return nullptr;
}

ListNode *detect_cycle(ListNode *head) {
    auto in_loop = get_node_in_loop(head);
    if (!in_loop) {
        return nullptr;
    }

    int loop_count = 1;
    for (auto node = in_loop; node->next_node != in_loop; node = node->next_node) {
        loop_count++;
    }

    auto fast = head;
    for (int i = 0; i < loop_count; ++i) {
        fast = fast->next_node;
    }

    auto slow = head;
    while (fast != slow) {
        fast = fast->next_node;
        slow = slow->next_node;
    }
    return slow;
}

int main(int argc, char **argv) {
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    auto head = create_ring_list(values, 3);

    auto entrance_node = detect_cycle(head);
    LogInfo("The list ring entrance {}", entrance_node->value);
    return 0;
}