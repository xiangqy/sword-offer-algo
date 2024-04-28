//
// Created by xiang on 24-4-20.
//
/*
 * 输入一个整形数据，数组中只有一个数字出现了一次，
 * 而其它数字都出现了3次，找出只出现一次的数字。
 * */
#include "./log/log_setting.h"
#include <vector>

int search_appear_once(const std::vector<int> &array_number) {
    std::vector<int> bits_sum(32, 0);
    for (auto number: array_number) {
        for (int i = 0; i < bits_sum.size(); ++i) {
            bits_sum[i] += (number >> i) & 0x1;
        }
    }

    int result = 0;
    for (int i = 0; i < bits_sum.size(); ++i) {
        result |= (bits_sum[i] % 3) << i;
    }
    return result;
}

int main(int argc, char **argv) {
    std::vector<int> base_number{100, 211, 421, 211, 315, 211, 421, 421, 315, 315};
    auto result = search_appear_once(base_number);
    LogInfo("Base numbers {}, search appear once number {}", base_number, result);
    return 0;
}