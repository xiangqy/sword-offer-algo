/*
 * 输入2个表示二进制的字符串，请计算它们的和，
 * 并以二进制字符串的形式输出
 * */

#include <string>
#include <algorithm>
#include "./log/log_setting.h"

std::string binary_addition(const std::string &addend_front, const std::string &addend_rear) {
    auto i = static_cast<int>(addend_front.length() - 1);
    auto j = static_cast<int>(addend_rear.length() - 1);

    std::string result;
    auto carry = 0;
    while (i >= 0 || j >= 0) {
        int digit_front = i >= 0 ? addend_front.at(i--) - '0' : 0;
        int digit_rear = j >= 0 ? addend_rear.at(j--) - '0' : 0;
        auto sum = digit_front + digit_rear + carry;
        carry = sum >= 2 ? 1 : 0;
        sum = sum >= 2 ? sum - 2 : sum;
        result.append(std::to_string(sum));
    }
    if (carry == 1) {
        result.append("1");
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main(int argc, char **argv) {
    std::string addend_front{"100001110011"};
    std::string addend_rear{"111100011100001010101"};
    auto result = binary_addition(addend_front, addend_rear);
    LogInfo("addend_front + addend_rear = {}", result);
    return 0;
}
