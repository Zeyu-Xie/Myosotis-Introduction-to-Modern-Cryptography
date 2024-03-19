#pragma once

#include "Bint.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>

// 随机 int
int randomNum(int a, int b);
// 随机 Bint（按位数生成）
Bint randomBigNum(int len);
// 随机素数
Bint randomBigPrime(int len);
// 扩展 Euclidean
Bint extendedEuclidean(Bint a, Bint b, Bint &x, Bint &y);