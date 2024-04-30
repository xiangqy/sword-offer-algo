//
// Created by xiang on 24-4-30.
//
/*
 * 给定一个字符串，判断它是不是回文，
 * 假设只需要考虑字母和数字字符，并忽略大小写。
 * */
#include "log/log_setting.h"

bool judgement_palindrome(const std::string &source) {
    if (source.empty()) {
        return false;
    }
    auto front_index = 0ull, rear_index = source.length() - 1;
    while (front_index < rear_index) {
        auto front_char = source.at(front_index);
        auto rear_char = source.at(rear_index);
        if (!isalnum(front_char)) {
            front_index++;
        } else if (!isalnum(rear_char)) {
            rear_index--;
        } else {
            front_char = tolower(front_char);
            rear_char = tolower(rear_char);
            if (front_char != rear_char) {
                return false;
            }
            front_index++;
            rear_index--;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    auto source{"Was it a cat I saw?"};
    auto is_palindrome = judgement_palindrome(source);
    LogInfo("The string \"{}\" is palindrome {}", source, is_palindrome);
    return 0;
}