#include "func.hpp"

const int primeEnd[] = {1, 3, 7, 9};
const Bint smallPrimeList[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};

// 随机 int
int randomNum(int a, int b)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(a, b - 1);
    return dis(gen);
}
// 随机 Bint（按位数生成）
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
        if (ans.isPrime())
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