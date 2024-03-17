#include "Bint.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

Bint bigPow(Bint a, Bint b)
{
    if (b == Bint(0))
        return Bint(1);
    if (b % Bint(2) == 0)
    {
        Bint tmp = bigPow(a, b / Bint(2));
        return tmp * tmp;
    }
    else
    {
        Bint tmp = bigPow(a, b / Bint(2));
        return tmp * tmp * a;
    }
}

Bint bigPowMod(Bint a, Bint b, Bint c)
{
    if (b == Bint(0))
        return Bint(1);
    a = a % c;
    if (b % Bint(2) == 0)
    {
        Bint tmp = bigPow(a, b / Bint(2)) % c;
        return (tmp * tmp) % c;
    }
    else
    {
        Bint tmp = bigPow(a, b / Bint(2)) % c;
        return (((tmp * tmp) % c) * a) % c;
    }
}

int randomNum(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}

Bint randomBigNum(int len)
{
    vector<int> digits(len);
    for (int i = 0; i < len; i++)
        digits[i] = randomNum(0, 10);
    while (digits.size() > 1 && digits[0] == 0)
        digits.erase(digits.begin());
    return Bint(digits);
}

Bint smallPrimeList[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};

bool isBigPrime(Bint a, int accuracy = 20)
{

    if (a == Bint(0) || a == Bint(1))
        return false;
    if (a == Bint(2))
        return true;
    for (int i = 0; i < 25; i++)
    {
        if (a % smallPrimeList[i] == Bint(0))
            return false;
    }

    return true;
}

Bint randomBigPrime(int len)
{

    Bint ans(0);

    while (true)
    {
        ans = randomBigNum(len);
        if (isBigPrime(ans))
            return ans;
    }
}

Bint p, q;

int main()
{

    int cnt = 0;
    for (int i = 1001; i <= 100000; i++)
    {
        if (isBigPrime(Bint(i)))
        {
            cnt++;
            // cout << i << " ";
        }
    }
    cout << "\n\n\n"
         << cnt;

    return 0;
}