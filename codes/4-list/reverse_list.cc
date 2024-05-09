//
// Created by xiang on 24-5-7.
//

#include "log/log_setting.h"
#include "node_common.h"

int main(int argc, char **argv) {
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7};
    auto head = create_list_node(values);
    print_node(head);
    head = reverse_list(head);
    print_node(head);
    return 0;
}