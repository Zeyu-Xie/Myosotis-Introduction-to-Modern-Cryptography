#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

class Bint {

    friend std::istream& operator>>(std::istream& is, Bint& bint);
    friend std::ostream& operator<<(std::ostream& os, const Bint& bint);

public:
    Bint();
    Bint(std::vector<int> digits);

    bool operator==(const Bint& other) const;
    bool operator!=(const Bint& other) const;

private:
    std::vector<int> digits;
};