//
// Created by xiang on 24-5-9.
//
/*
 * 给定两个表示非负整数的单向链表，如何实现这两个整数的相加并且把它们的和
 * 仍然使用单向链表表示？链表中的每个节点表示十进制的一位，并且头节点对应
 * 整数的最高位数而尾节点对应整数的个位数
 * */

#include "node_common.h"

ListNode *list_add(ListNode *head1, ListNode *head2) {
    head1 = reverse_list(head1);
    head2 = reverse_list(head2);

    ListNode dummy(0);
    auto added_node = &dummy;
    auto carry = 0;
    while (head1 || head2) {
        auto sum = (head1 ? head1->value : 0) + (head2 ? head2->value : 0) + carry;
        carry = sum / 10;
        sum %= 10;

        auto node = new ListNode(sum);
        added_node->next_node = node;
        added_node = added_node->next_node;

        head1 = head1 == nullptr ? nullptr : head1->next_node;
        head2 = head2 == nullptr ? nullptr : head2->next_node;
    }

    if (carry > 0) {
        added_node->next_node = new ListNode(carry);
    }

    return reverse_list(dummy.next_node);
}

int main(int argc, char **argv) {
    std::vector<int> values1{1, 2, 3, 9, 8};
    std::vector<int> values2{3, 4, 6, 7, 9, 2, 9};
    auto head1 = create_list_node(values1);
    auto head2 = create_list_node(values2);

    auto added_head = list_add(head1, head2);
    print_node(added_head);
    return 0;
}