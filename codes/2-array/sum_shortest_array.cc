//
// Created by xiang on 24-4-27.
//
/*
 * 输入一个正整数组成的数组和一个正整数k，
 * 请问数组中和大于或等于k的连续子数组的
 * 最短长度是多少？如果不存在所有数字之和
 * 大于或等于k的子数组，则返回0
 * */

#include <vector>
#include "./log/log_setting.h"

unsigned search_shortest_array(const std::vector<unsigned int>& base_array, unsigned k){
    unsigned result = 0xFFFFFFFF, front_index = 0;
    unsigned sum = 0;
    for(unsigned back_index = 0; back_index < base_array.size(); ++back_index){
        sum += base_array[back_index];
        while(front_index <= back_index && sum >= k){
            result = std::min(result, back_index - front_index + 1);
            sum -= base_array[front_index++];
        }
    }

    return result == 0xFFFFFFFF ? 0 : result;
}


int main(int argc, char** argv){
    std::vector<unsigned int> base_array{10, 9, 7, 29, 48, 8, 14, 36};
    auto k = 100u;
    auto result = search_shortest_array(base_array, k);
    LogInfo("Base array {}, limit value {}, shortest data {}", base_array, k, result);
    return 0;
}