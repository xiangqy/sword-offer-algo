//
// Created by xiang on 24-4-30.
//
/*
 * 给定一个字符串，请问该字符串中有多少个回文连续字符串？
 * 例如：字符串“abc”有3个回文字符串，分别为“a”、“b”、“c”
 * 而字符串“aaa”有6个回文字符串，分别为“a” “a” “a” “aa”
 * “aa” “aaa”
 * */

#include "log/log_setting.h"

int count_palindrome(const std::string &source, int start, int end) {
    auto count = 0;
    while (start >= 0 && end < source.length() && source.at(start) == source.at(end)) {
        count++;
        start--;
        end++;
    }
    return count;
}

int count_palindrome(const std::string &source) {
    if (source.empty())
        return 0;

    auto count = 0;
    for (auto i = 0; i < source.length(); ++i) {
        count += count_palindrome(source, i, i);
        count += count_palindrome(source, i, i + 1);
    }
    return count;
}

int main(int argc, char **argv) {
    auto source{"aaa"};
    auto result = count_palindrome(source);
    LogInfo("source string \"{}\", result {}", source, result);
    return 0;
}