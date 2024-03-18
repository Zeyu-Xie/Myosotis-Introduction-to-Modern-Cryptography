#include "func.hpp"

const int primeEnd[] = {1, 3, 7, 9};
const Bint smallPrimeList[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};

// 乘方
inline Bint pow(Bint a, Bint b)
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
    if (a > c)
        a = a % c;
    if (b % Bint(2) == 0)
    {
        Bint tmp = powMod(a, b / Bint(2), c);
        return (tmp * tmp) % c;
    }
    else
    {
        Bint tmp = powMod(a, b / Bint(2), c);
        return (tmp * tmp * a) % c;
    }
}

// 随机 int
inline int randomNum(int a, int b)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b - 1);
    return dis(gen);
}
// 随机 Bint
Bint randomBigNum(int len)
{
    std::vector<int> digits(len);
    digits[0] = randomNum(1, 10);
    for (int i = 1; i < len; ++i)
        digits[i] = randomNum(0, 10);
    while (digits.size() > 1 && digits[0] == 0)
        digits.erase(digits.begin());
    return Bint(digits);
}

// Miller-Rabin 素性验证
inline bool isBigPrime(Bint a)
{
    std::cout<<a<<"\n";

    if (a <= Bint(1))
        return false;
    if (a.isEven())
        return false;
    if (a.isMultipleOfFive())
        return false;
    if (a.sum() % 3 == 0)
        return false;

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

    Bint d0 = d;

    for (int i = 0; i < 13; ++i)
    {

        if (smallPrimeList[i] >= a)
            return true;

        d = d0;
        bool flag = true;
        Bint pm = powMod(smallPrimeList[i], d, a);
        if (pm == Bint(1))
            continue;
        for (int r = 0; r < s; ++r)
        {
            if (pm == a_1)
            {
                flag = false;
                break;
            }
            d = d + d;
            pm = pm * pm % a;
        }
        if (flag == true)
            return false;
    }

    return true;
}

// 随机素数
Bint randomBigPrime(int len)
{

    Bint ans;

    while (true)
    {
        ans = randomBigNum(len - 1);
        ans.digits.push_back(primeEnd[randomNum(0, 4)]);
        while (ans.digits[0] == 0)
            ans.digits.erase(ans.digits.begin());
        if (isBigPrime(ans))
            return ans;
    }
}

// 扩展 Euclidean
Bint extendedEuclidean(Bint a, Bint b, Bint &x, Bint &y)
{

    if (b == Bint(0))
    {
        x = Bint(1);
        y = Bint(0);
        return a;
    }

    Bint x1, y1;
    Bint gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}