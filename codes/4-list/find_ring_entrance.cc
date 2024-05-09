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
 *
 * 解法二：
 * 如果链表中有环，快慢两个指针一定会在环中的某个节点相遇。慢指针每次
 * 走一步，假设在相遇时慢指针一共走了k步。由于快指针一次走两步，因此在
 * 相遇时快指针一共走2k步。因此，到相遇时快的指针比慢指针多走了k步。另
 * 外，两个相遇时遇到快的指针比慢的指针在环中多转了若干圈。也就是说，两
 * 个指针相遇时快指针多走的步数k一定是环中节点的数目的整数倍，此时慢的指
 * 针走过的步数k也是环中节点数的整数倍。
 *
 * 此时可以让一个指针指向相遇的节点，该指针的位置是之前慢的指针走了k步到
 * 达的位置。接着让另一个指针指向链表的头结点，然后两个指针以相同的速度一
 * 起朝者指向下一个节点指针移动，当后面的指针到达环入口节点时，前面的指针
 * 比它多走了k步。而k是环中节点的数目的整数倍，相当于前面的指针在环中转了
 * k圈后也达到环的入口点，两个指针正好相遇。也就是说，两个指针相遇的节点正
 * 好是环的入口节点
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

ListNode *detect_cycle_opt(ListNode *head) {
    auto in_loop = get_node_in_loop(head);
    if (in_loop == nullptr)
        return nullptr;

    auto node = head;
    while (node != in_loop) {
        node = node->next_node;
        in_loop = in_loop->next_node;
    }
    return node;
}

int main(int argc, char **argv) {
    std::vector<int> values{1, 2, 3, 4, 5, 6};
    auto head = create_ring_list(values, 3);

    auto entrance_node = detect_cycle(head);
    LogInfo("The list ring entrance {}", entrance_node->value);

    entrance_node = detect_cycle_opt(head);
    LogInfo("The list ring entrance {}", entrance_node->value);
    return 0;
}