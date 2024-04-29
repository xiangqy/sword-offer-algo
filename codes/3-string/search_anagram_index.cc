//
// Created by xiang on 24-4-29.
//
/*
 * 输入字符串s1和s2，如何找出字符串s1的所有变位词在字符串s2中的起始下标？
 * 假设两个字符串中只包含英文小写字母。如s1为“abc”，s2为“cbadabacg”，字
 * 符串s1的两个变位词“cba”和“bac”是字符串s1中的字符串，输出它们在字符串s2
 * 中的起始下标0和5
 * */
#include "log/log_setting.h"

std::vector<size_t> search_anagram_index(const std::string &source, const std::string &dest) {
    std::vector<size_t> result;
    if (source.length() > dest.length()) {
        return result;
    }
    std::array<int, 26> counts{0};
    for (auto i = 0u; i < source.length(); ++i) {
        counts[source[i] - 'a']++;
        counts[dest[i] - 'a']--;
    }
    auto count_zero = std::all_of(counts.cbegin(), counts.cend(), [](const int num) { return num == 0; });
    if (count_zero) {
        result.push_back(0);
    }

    for (auto i = source.length(); i < dest.length(); ++i) {
        counts[dest[i] - 'a']--;
        counts[dest[i - source.length()] - 'a']++;

        count_zero = std::all_of(counts.cbegin(), counts.cend(), [](const int num) { return num == 0; });
        if (count_zero) {
            result.push_back(i - source.length() + 1);
        }
    }
    return result;
}

int main(int argc, char **argv) {
    auto source{"abc"};
    auto dest{"cbadabacg"};
    auto result = search_anagram_index(source, dest);
    LogInfo("dest \"{}\" contain source \"{}\" anagram index {}", dest, source, result);
    return 0;
}

