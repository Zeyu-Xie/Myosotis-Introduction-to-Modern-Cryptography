#pragma once

#include "Bint.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>

// 乘方
Bint pow(Bint a, Bint b);
// 乘方取余
Bint powMod(Bint a, Bint b, Bint c);

// 随机 int
int randomNum(int a, int b);
// 随机 Bint
Bint randomBigNum(int len);

// Miller-Rabin 素性验证
bool isBigPrime(Bint a, int accuracy);
bool isBigPrime(Bint a);

// 随机素数
Bint randomBigPrime(int len);