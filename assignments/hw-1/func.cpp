#include "func.hpp"

const Bint smallPrimeList[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};

// 乘方
Bint pow(Bint a, Bint b)
{
    if (b == Bint(0))
        return Bint(1);
    if (b % Bint(2) == 0)
    {
        Bint tmp = pow(a, b / Bint(2));
        return tmp * tmp;
    }
    else
    {
        Bint tmp = pow(a, b / Bint(2));
        return tmp * tmp * a;
    }
}
// 乘方取余
Bint powMod(Bint a, Bint b, Bint c)
{
    if (b == Bint(0))
        return Bint(1);
    a = a % c;
    if (b % Bint(2) == 0)
    {
        Bint tmp = pow(a, b / Bint(2)) % c;
        return (tmp * tmp) % c;
    }
    else
    {
        Bint tmp = pow(a, b / Bint(2)) % c;
        return (((tmp * tmp) % c) * a) % c;
    }
}

// 随机 int
int randomNum(int a, int b)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}
// 随机 Bint
Bint randomBigNum(int len)
{
    std::vector<int> digits(len);
    for (int i = 0; i < len; i++)
        digits[i] = randomNum(0, 10);
    while (digits.size() > 1 && digits[0] == 0)
        digits.erase(digits.begin());
    return Bint(digits);
}

// Miller-Rabin 素性验证
bool isBigPrime(Bint a)
{

    if (a == Bint(0) || a == Bint(1))
        return false;
    if (a == Bint(2))
        return true;

    Bint a_1 = a - Bint(1);
    Bint _2_s = Bint(1);
    int s = 0;
    Bint d = a_1;

    while (d.isEven())
    {
        _2_s = _2_s + _2_s;
        s += 1;
        d = d / Bint(2);
    }

    for (int i = 0; i < 2; i++)
    {
        bool flag = true;
        if (powMod(smallPrimeList[i], d, a) == Bint(1))
            continue;
        for (int r = 0; r < s; r++)
        {
            if (powMod(smallPrimeList[i], d, a) == a_1)
            {
                flag = false;
                break;
            }
            d = d+ d;
        }
        if (flag == true)
            return false;
    }

    return true;
}

// 随机素数
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
