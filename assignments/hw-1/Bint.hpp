#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cmath>

class Bint
{
    // 重载输入输出流运算符
    friend std::istream &operator>>(std::istream &is, Bint &bint);
    friend std::ostream &operator<<(std::ostream &os, const Bint &bint);

private:
    // 去除前面多余的 0
    inline void _remove_front_zeros();
    // 与 int 类型 0~9 相乘
    inline Bint _simpleTimes(int a);

public:
    // 全部数位
    int positive;
    std::vector<int> digits;

    // 默认构造为 0
    Bint();
    // 从 int 构造
    Bint(int num);
    // 从 std::string 构造
    Bint(std::string s);
    // 从 std::vector<int> 构造
    Bint(std::vector<int> digits);

    // 复制构造
    Bint(const Bint &other);

    // 重载比较运算符
    bool operator==(const Bint &other) const;
    bool operator!=(const Bint &other) const;
    bool operator<(const Bint &other) const;
    bool operator>(const Bint &other) const;
    bool operator<=(const Bint &other) const;
    bool operator>=(const Bint &other) const;

    // 重载加、减、乘、整除、求余运算符
    Bint operator+(const Bint &other) const;
    Bint operator-(const Bint &other) const;
    Bint operator*(const Bint &other) const;
    Bint operator/(const Bint &other) const;
    Bint operator%(const Bint &other) const;

    // 数位之和
    int sum() const;

    // 绝对值
    inline Bint abs() const;
    // 相反数
    inline Bint opposite() const;

    // 获取末位
    inline int end() const;
    // 获取长度
    inline int length() const;

    // 是否是奇数
    bool isOdd() const;
    // 是否是偶数
    bool isEven() const;
    // 是否是 5 的倍数
    bool isMultipleOfFive() const;

    // 是否是 0
    inline bool isZero() const;
    // 是否是 1
    inline bool isOne() const;
};