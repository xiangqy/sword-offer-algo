//
// Created by xiang on 24-4-21.
//
/*
 * 输入一个递增排序的数组和一个值k，如何在数组中找出2个和为k
 * 的数字，并返回它们的下标？假设数组中有且仅有一对符合条件的
 * 数字，同时一个数字不能出现2次。
 * */

#include "./log/log_setting.h"
#include <vector>
#include <tuple>

using array_number = std::vector<int>;

std::tuple<int, int> search_sum_index(const array_number &base_array, int sum) {
    int begin_index = 0, end_index = static_cast<int>(base_array.size() - 1);
    while (begin_index < end_index){
        if(sum >  base_array[begin_index] + base_array[end_index]){
            ++begin_index;
        }else if(sum < base_array[begin_index] + base_array[end_index]){
            --end_index;
        }else{
            break;
        }
    }
    auto result = std::make_tuple(begin_index, end_index);
    return result;
}

int main(int argc, char **argv) {
    array_number base_array{0, 3, 6, 7, 10, 19, 99};
    auto k = 25;
    auto result = search_sum_index(base_array, k);
    LogInfo("Base array is {}, target sum {}, result index is {}", base_array, k, result);
    return 0;
}