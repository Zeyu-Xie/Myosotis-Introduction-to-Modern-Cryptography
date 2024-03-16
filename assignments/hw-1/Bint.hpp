#pragma once

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Bint {

public:
    Bint();
    Bint(vector<int> digits);
private:
    friend std::istream& operator>>(std::istream& is, Bint& bint);
    friend std::ostream& operator<<(std::ostream& os, const Bint& bint);

    vector<int> digits;
};