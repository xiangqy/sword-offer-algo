//
// Created by xiang on 24-4-27.
//
/*
 * 输入一个由正整数组成的数组和一个正整数k，
 * 请问数组中有多少个数子乘积小于k的连续数组
 * */
#include "./log/log_setting.h"
#include <map>

unsigned int multi_sub_array(const std::vector<unsigned int> &base_array, unsigned int k) {
    auto result = 0u;
    if (base_array.empty()) {
        return result;
    }
    auto front_index = 0u, multi_result = 1u;
    for (auto back_index = 0u; back_index < base_array.size(); ++back_index) {
        multi_result *= base_array[back_index];
        while (multi_result >= k && back_index >= front_index) {
            multi_result /= base_array[front_index++];
        }
        result += back_index >= front_index ? back_index - front_index + 1 : 0;
    }
    return result;
}

unsigned int sum_sub_array(const std::vector<unsigned  int>& base_array, unsigned int k){
    auto front_index = 0u, sum = 0u, result = 0u;
    for(auto back_index = 0u; back_index < base_array.size(); ++back_index){
        sum += base_array[back_index];
        while(sum >= k && back_index >= front_index){
            sum -= base_array[front_index++];
        }
        result += back_index >= front_index ? back_index - front_index + 1 : 0;
    }
    return result;
}

unsigned int sum_sub_array_hash(const std::vector<int>& base_array, int k){
    std::map<int, int> sum_count{{0, 1}};

    auto sum = 0, count = 0;
    for(auto number : base_array){
        sum += number;
        count += sum_count.find(sum - k) == sum_count.end() ? 0 : sum_count[sum - k];
        auto iter = sum_count.find(sum);
        if(iter == sum_count.end()){
            sum_count.insert(std::make_pair(sum, 1));
        }else{
            iter->second += 1;
        }
    }
    return count;
}


int main(int argc, char **argv) {
    std::vector<unsigned int> base_array{9, 8, 99, 2, 3, 5, 26};
    std::vector<int> base_array1{9, 8, 0, -17, 17, 17, -34};
    auto k = 88u;
    auto result = multi_sub_array(base_array, k);
    LogInfo("base array {}, multiplication less than {}, have {} sub array.", base_array, k, result);
    result = sum_sub_array(base_array, k);
    LogInfo("base array {}, add less than {}, have {} sub array.", base_array, k, result);
    result = sum_sub_array_hash(base_array1, static_cast<int>(k));
    LogInfo("base array {}, add less than {}, have {} sub array.",base_array1, k, result);
    return 0;
}