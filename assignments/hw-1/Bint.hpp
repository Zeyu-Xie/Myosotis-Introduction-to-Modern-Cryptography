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
    int length;
    vector<int> digits;
};