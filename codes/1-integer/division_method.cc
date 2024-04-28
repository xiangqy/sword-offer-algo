/*
 *输入2个int型整数，它们进行除法计算并返回商，要求不得使用‘*’
 * 除号‘/’求余符号‘%’，当发生溢出时，返回最大的整数值。假设除数不为0
 * */

#include <iostream>
#include <climits>
#include "./log/log_setting.h"

int division_core(int dividend, int divisor) {
    int result = 0;
    auto sub_result = dividend - divisor;
    while (sub_result >= 0) {
        result++;
        sub_result -= divisor;
    }
    return result;
}

int division_core_optimize(int dividend, int divisor) {
    int result = 0;
    while (dividend >= divisor) {
        auto value = divisor;
        auto quotient = 1;
        while (value <= 0x7FFFFFFF && dividend >= value + value) {
            quotient += quotient;
            value += value;
        }

        result += quotient;
        dividend -= value;
    }
    return result;
}

int division(int dividend, int divisor) {
    if (dividend == 0x80000000 && divisor) {
        return INT_MAX;
    }

    auto positive = true;
    if (dividend < 0) {
        positive = !positive;
        dividend = -dividend;
    }

    if (divisor < 0) {
        positive = !positive;
        divisor = -divisor;
    }

    auto result = division_core(dividend, divisor);
    return positive ? result : -result;
}

int main(int argc, char **argv) {
    auto dividend = 98;
    auto divisor = 3;
    auto result = division(dividend, divisor);

    LogInfo("{} / {} = {}", dividend, divisor, result);
    result = division_core_optimize(dividend, divisor);
    LogInfo("{} / {} = {}", dividend, divisor, result);
    return 0;
}