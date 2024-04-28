//
// Created by xiang on 24-4-20.
//
/*
 * 输入一个字符串数组words， 计算不包含相同字符的两个字符串
 * word[i]和word[j]的长度的乘积的最大值，如果所有字符串都
 * 包含至少一个相同的字符，返回0
 * */

#include "./log/log_setting.h"
#include <vector>
#include <string>

int word_max_accumulate(const std::vector<std::string> &word_array) {
    bool **flags = new bool *[word_array.size()];
    for (int i = 0; i < word_array.size(); ++i) {
        flags[i] = new bool[26];
        memset(flags[i], false, 26);
    }

    for (int i = 0; i < word_array.size(); ++i) {
        for (int j = 0; j < word_array[i].length(); ++j) {
            flags[i][word_array[i].at(j) - 'a'] = true;
        }
    }

    int result = 0;
    for (int i = 0; i < word_array.size(); ++i) {
        for (int j = i + 1; j < word_array.size(); ++j) {
            auto same = false;
            for (int k = 0; k < 26; ++k) {
                if (flags[i][k] && flags[j][k]) {
                    same = true;
                    break;
                }
            }
            if (!same) {
                auto product = word_array[i].length() * word_array[j].length();
                result = std::max(static_cast<int>(product), result);
            }
        }
    }

    for (int i = 0; i < word_array.size(); ++i) {
        delete[] flags[i];
    }
    delete[] flags;

    return result;
}

int word_max_accumulate_opt(const std::vector<std::string> &word_array) {
    int *flags = new int[word_array.size()];
    memset(flags, 0, word_array.size());

    for (int i = 0; i < word_array.size(); ++i) {
        for (int j = 0; j < word_array[i].length(); ++j) {
            flags[i] |= 1 << (word_array[i].at(j) - 'a');
        }
    }

    int result = 0;
    for (int i = 0; i < word_array.size(); ++i) {
        for (int j = i + 1; j < word_array.size(); ++j) {
            if ((flags[i] & flags[j]) == 0) {
                auto product = word_array[i].length() * word_array[j].length();
                result = std::max(static_cast<int>(product), result);
            }
        }
    }

    delete[]flags;
    return result;
}

int main(int argc, char **argv) {
    std::vector<std::string> word_array{"abc", "ac", "fgh", "nxlmop", "test"};
    auto result = word_max_accumulate(word_array);
    LogInfo("Base input data {}, max accumulate {}", word_array, result);

    result = word_max_accumulate_opt(word_array);
    LogInfo("Base input data {}, max accumulate {}", word_array, result);
    return 0;
}