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

    friend std::istream &operator>>(std::istream &is, Bint &bint);
    friend std::ostream &operator<<(std::ostream &os, const Bint &bint);

private:
    std::vector<int> digits;

    void _remove_front_zeros();
    std::vector<int> _get_digits();
    int _get_length();
    Bint _simpleTimes(int a);

public:
    Bint();
    Bint(int num);
    Bint(std::vector<int> digits);
    Bint(const Bint &other);

    bool operator==(const Bint &other) const;
    bool operator!=(const Bint &other) const;
    bool operator<(const Bint &other) const;
    bool operator>(const Bint &other) const;
    bool operator<=(const Bint &other) const;
    bool operator>=(const Bint &other) const;

    Bint operator+(const Bint &other) const;
    Bint operator-(const Bint &other) const;
    Bint operator*(const Bint &other) const;
    Bint operator/(const Bint &other) const;
    Bint operator%(const Bint &other) const;
};