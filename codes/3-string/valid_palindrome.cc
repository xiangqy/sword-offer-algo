//
// Created by xiang on 24-4-30.
//
/*
 * 给定一个字符串，判断如果最多从字符串中删除一个字符能不能
 * 得到一个回文字符串。如：输入字符串“abca”，由于删除字符
 * "b"或者“c”就能得到一个回文字符串，因此输出为true
 * */

#include "log/log_setting.h"

bool is_palindrome(const std::string &source, size_t start, size_t end) {
    while (start < end) {
        if (source.at(start) != source.at(end)) {
            break;
        }
        start++;
        end--;
    }
    return start >= end;
}

bool valid_palindrome(const std::string &source) {
    if (source.empty())
        return false;
    auto front_index = 0ull, rear_index = source.length() - 1;
    for (; front_index < source.length() / 2; ++front_index, --rear_index) {
        if (source.at(front_index) != source.at(rear_index)) {
            break;
        }
    }

    return front_index == source.length() / 2 || is_palindrome(source, front_index, rear_index - 1) || is_palindrome
            (source, front_index + 1, rear_index);
}

int main(int argc, char **argv) {
    auto source{"abca"};
    auto result = valid_palindrome(source);
    LogInfo("source data \"{}\", is palindrome {}", source, result);
    return 0;
}
