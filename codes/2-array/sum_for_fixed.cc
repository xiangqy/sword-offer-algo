//
// Created by xiang on 24-4-21.
//
/*
 * 输入一个数组，找出数组中所有和为0的3个数字组成的3元组，
 * 需要注意的是：返回值中不得包含重复的三元组
 * */

#include "./log/log_setting.h"
#include <vector>

void two_sum(const std::vector<int> &base_array, int i, std::vector<std::vector<int>> *result) {
    auto j = i + 1;
    auto k = static_cast<int>(base_array.size() - 1);

    while (j < k) {
        if (base_array[i] + base_array[j] + base_array[k] == 0) {
            result->push_back({base_array[i], base_array[j], base_array[k]});
            int temp = base_array[j];
            while (base_array[j] == temp && j < k) {
                ++j;
            }
        } else if (base_array[i] + base_array[j] + base_array[k] < 0) {
            ++j;
        } else {
            --k;
        }
    }
}

std::vector<std::vector<int>> three_sum(std::vector<int> base_array) {
    std::vector<std::vector<int>> result;
    if (base_array.size() >= 3) {
        std::sort(base_array.begin(), base_array.end());

        int i = 0;
        while (i < base_array.size() - 2) {
            two_sum(base_array, i, &result);

            int temp = base_array[i];
            while (i < base_array.size() && base_array[i] == temp) {
                ++i;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    std::vector<int> base_array{9, -9, 0, -14, 5, 10, -1};
    auto result = three_sum(base_array);
    LogInfo("Base array {}, result {}", base_array, result);
    return 0;
}
