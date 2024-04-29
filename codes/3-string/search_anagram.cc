//
// Created by xiang on 24-4-29.
//
/*
 * 输入字符串s1和s2，如何判断字符串s2中是否包含字符串s1的某个变位词？如果字符串s2中包含
 * 字符串s1的某个变为成，则字符串s1至少有一个变位词是字符串s2的子字符串。假设两个字符串中
 * 只包含英文小写字符。例如，字符串s1为“ac”，字符串s2为“dgcaf”，由于字符串s2中包含字符
 * 串s1中的变位词“ca”，因此输出true，如果字符串s1为“ab”，字符串s2为“dgcaf”，则输出false
 * */
#include "log/log_setting.h"

bool search_anagram(const std::string &source, const std::string &dest) {
    if (source.length() > dest.length())
        return false;

    std::array<int, 26> counts{0};
    for (auto i = 0u; i < source.length(); ++i) {
        counts[source[i] - 'a']++;
        counts[dest[i] - 'a']--;
    }

    bool all_zero = std::all_of(counts.cbegin(), counts.cend(), [](const int num) { return num == 0; });
    if(all_zero){
        return true;
    }
    for(auto i = source.length(); i < dest.length(); ++i){
        counts[dest[i] - 'a']--;
        counts[dest[i - source.length()] - 'a']++;
        all_zero = std::all_of(counts.cbegin(), counts.cend(), [](const int num) { return num == 0; });
        if(all_zero){
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    std::string source{"ac"};
    std::string dest{"dgcaf"};
    bool has_anagram = search_anagram(source, dest);
    LogInfo("dest \"{}\" contain source \"{}\" anagram {}", dest, source, has_anagram);
    return 0;
}
