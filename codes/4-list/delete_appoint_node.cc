//
// Created by xiang on 24-5-4.
//
/*
 * 给定一个链表，如何删除链表中的倒数第k个节点？假设链表中节点的
 * 总数为n，那么1<=k<=n。要求只能遍历一次链表。
 * */

#include "log/log_setting.h"
#include "node_common.h"

ListNode *delete_appoint_node(ListNode *head, unsigned k) {
    ListNode dummy(0);
    dummy.next_node = head;

    auto *front = head, *back = &dummy;
    for (int i = 0; i < k; ++i) {
        front = front->next_node;
    }

    while (front) {
        front = front->next_node;
        back = back->next_node;
    }
    auto delete_node = back->next_node;
    back->next_node = back->next_node->next_node;
    delete delete_node;
    return dummy.next_node;
}

int main(int argc, char **argv) {
    std::vector<int> values{0, 9, 89, 98, -7, -45};
    auto head = create_list_node(values);
    print_node(head);

    head = delete_appoint_node(head, 3);
    print_node(head);
    return 0;
}