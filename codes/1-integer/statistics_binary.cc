//
// Created by xiang on 2024/4/17.
//

/*
 * 输入一个非负数n，计算0到n之间每个数字的二进制形式中1的个数，
 * 并输出提个数组。例如n为4，输出[0,1,1,2,1]
 * */
#include <memory>
#include <vector>
#include "./log/log_setting.h"

using array_number = std::vector<unsigned int>;
using array_number_ptr = std::shared_ptr<array_number>;

array_number_ptr statistic_binary(unsigned int max_number) {
    array_number_ptr result = std::make_shared<array_number>(max_number, 0);
    for (unsigned i = 1; i < max_number; ++i) {
        unsigned value = i;
        while (value != 0) {
            result->at(i)++;
            value = value & (value - 1);
        }
    }
    return result;
}

array_number_ptr statistic_binary_opt(unsigned int max_number) {
    array_number_ptr result = std::make_shared<array_number>(max_number, 0);
    for (unsigned int i = 1; i < max_number; ++i) {
        result->at(i) = result->at(i & (i - 1)) + 1;
    }
    return result;
}

array_number_ptr statistic_binary_opt_other(unsigned int max_number) {
    array_number_ptr result = std::make_shared<array_number>(max_number, 0);
    for (unsigned int i = 1; i < max_number; ++i) {
        result->at(i) = result->at(i >> 1) + (i & 1);
    }
    return result;
}


int main(int argc, char **argv) {
    auto max_number = 10;
    auto result1 = statistic_binary(max_number);
    LogInfo("{}", *result1);

    auto result2 = statistic_binary_opt(max_number);
    LogInfo("{}", *result2);

    auto result3 = statistic_binary_opt_other(max_number);
    LogInfo("{}", *result3);
    return 0;
}
