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

public:
    Bint();
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

// private:
    std::vector<int> digits;

    Bint _simpleTimes(int a);
};