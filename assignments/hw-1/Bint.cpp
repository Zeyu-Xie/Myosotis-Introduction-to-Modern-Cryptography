#include "Bint.hpp"

// 重载输入输出流运算符
std::istream &operator>>(std::istream &is, Bint &bint)
{
    std::string input;
    is >> input;
    bint = Bint(input);
    return is;
}
std::ostream &operator<<(std::ostream &os, const Bint &bint)
{
    if (bint.positive == -1)
        os << "-";
    for (int i = 0; i < bint.digits.size(); i++)
        os << bint.digits[i];
    return os;
}

// 静态私密常量
const Bint Bint::_small_primes[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};

// Private

// 去除前面多余的 0
void Bint::_remove_front_zeros()
{
    while (digits[0] == 0 && digits.size() > 1)
        digits.erase(digits.begin());
}
// 与 int 类型 0~9 相乘
Bint Bint::_simpleTimes(int a)
{
    int length = digits.size();
    std::vector<int> ans(length);
    int tot = length - 1;
    int t = 0;
    while (tot >= 0)
    {
        int b = (tot >= 0) ? digits[tot] : 0;
        ans[tot] = b * a + t;
        if (ans[tot] >= 10)
        {
            t = ans[tot] / 10;
            ans[tot] %= 10;
        }
        else
            t = 0;
        tot--;
    }
    if (t > 0)
        ans.insert(ans.begin(), t);
    return Bint(ans);
}

// Public

// 默认构造为 0
Bint::Bint() : positive(0), digits(std::vector<int>({0})) {}
// 从 int 构造
Bint::Bint(int num)
{
    if (num == 0)
    {
        positive = 0;
        digits = std::vector<int>({0});
    }
    else if (num < 0)
    {
        positive = -1;
        num = -num;
        std::string s = std::to_string(num);
        digits = {};
        for (int i = 0; i < s.length(); ++i)
            digits.push_back(s[i] - '0');
    }
    else
    {
        positive = 1;
        std::string s = std::to_string(num);
        digits = {};
        for (int i = 0; i < s.length(); ++i)
            digits.push_back(s[i] - '0');
    }
}
// 从 std::string 构造
Bint::Bint(std::string s)
{
    std::string s1 = (s[0] == '-') ? s.substr(1) : s;

    digits = {};
    for (int i = 0; i < s1.length(); ++i)
        digits.push_back(s1[i] - '0');
    _remove_front_zeros();

    if (digits[0] == 0)
        positive = 0;
    else if (s[0] == '-')
        positive = -1;
    else
        positive = 1;
}
// 从 std::vector<int> 构造
Bint::Bint(std::vector<int> dig) : positive(1), digits(dig)
{
    _remove_front_zeros();
    if (digits[0] == 0)
        positive = 0;
}

// 复制构造
Bint::Bint(const Bint &other)
{
    positive = other.positive;
    digits = other.digits;
}

// 重载比较运算符
bool Bint::operator==(const Bint &other) const
{
    if (positive != other.positive)
        return false;

    int length = digits.size();
    if (length != other.digits.size())
        return false;

    for (int i = 0; i < length; ++i)
    {
        bool tmp = (digits[i] == other.digits[i]);
        if (tmp)
            continue;
        else
            return false;
    }

    return true;
}
bool Bint::operator!=(const Bint &other) const
{
    return !((*this) == other);
}
bool Bint::operator<(const Bint &other) const
{
    if (positive < other.positive)
        return true;
    if (positive > other.positive)
        return false;

    if (positive == 0)
        return false;
    if (positive == 1)
    {
        int length = digits.size();
        if (length > other.digits.size())
            return false;
        else if (length < other.digits.size())
            return true;
        else
        {
            for (int i = 0; i < length; ++i)
                if (digits[i] < other.digits[i])
                    return true;
                else if (digits[i] > other.digits[i])
                    return false;
            return false;
        }
    }
    else
    {
        int length = digits.size();
        if (length > other.digits.size())
            return true;
        else if (length < other.digits.size())
            return false;
        else
        {
            for (int i = 0; i < length; ++i)
                if (digits[i] < other.digits[i])
                    return false;
                else if (digits[i] > other.digits[i])
                    return true;
            return false;
        }
    }
}
bool Bint::operator>(const Bint &other) const
{
    if (positive < other.positive)
        return false;
    if (positive > other.positive)
        return true;

    if (positive == 0)
        return false;
    if (positive == 1)
    {
        int length = digits.size();
        if (length > other.digits.size())
            return true;
        else if (length < other.digits.size())
            return false;
        else
        {
            for (int i = 0; i < length; ++i)
                if (digits[i] < other.digits[i])
                    return false;
                else if (digits[i] > other.digits[i])
                    return true;
            return false;
        }
    }
    else
    {
        int length = digits.size();
        if (length > other.digits.size())
            return false;
        else if (length < other.digits.size())
            return true;
        else
        {
            for (int i = 0; i < length; ++i)
                if (digits[i] < other.digits[i])
                    return true;
                else if (digits[i] > other.digits[i])
                    return false;
            return false;
        }
    }
}
bool Bint::operator<=(const Bint &other) const
{
    if (*this > other)
        return false;
    return true;
}
bool Bint::operator>=(const Bint &other) const
{
    if (*this < other)
        return false;
    return true;
}

Bint _absAdd(Bint a, Bint b)
{
    int length = std::max(a.digits.size(), b.digits.size());
    std::vector<int> ans(length);
    int tot = length - 1;
    int tot1 = a.digits.size() - 1;
    int tot2 = b.digits.size() - 1;
    int t = 0;
    while (tot >= 0)
    {
        int x = (tot1 >= 0) ? a.digits[tot1] : 0;
        int y = (tot2 >= 0) ? b.digits[tot2] : 0;
        ans[tot] = x + y + t;
        if (ans[tot] >= 10)
        {
            ans[tot] -= 10;
            t = 1;
        }
        else
            t = 0;
        tot--;
        tot1--;
        tot2--;
    }
    if (t == 1)
        ans.insert(ans.begin(), 1);
    return Bint(ans);
}
Bint _absMinus(Bint c, Bint d)
{
    Bint a = c.abs();
    Bint b = d.abs();
    if (a == b)
        return Bint(0);
    if (a < b)
    {
        Bint t = a;
        a = b;
        b = t;
    }
    int length = a.digits.size();
    std::vector<int> ans(length);
    int tot = length - 1;
    int tot1 = a.digits.size() - 1;
    int tot2 = b.digits.size() - 1;
    int t = 0;
    while (tot >= 0)
    {
        int x = (tot1 >= 0) ? a.digits[tot1] : 0;
        int y = (tot2 >= 0) ? b.digits[tot2] : 0;
        ans[tot] = x - y - t;
        if (ans[tot] < 0)
        {
            ans[tot] += 10;
            t = 1;
        }
        else
            t = 0;
        tot--;
        tot1--;
        tot2--;
    }
    while (ans[0] == 0 && ans.size() > 1)
        ans.erase(ans.begin());
    return Bint(ans);
}

// 重载加、减、乘、整除、求余运算符
Bint Bint::operator+(const Bint &other) const
{
    if (positive == other.positive)
    {
        Bint ans = _absAdd(*this, other);
        ans.positive = positive;
        return ans;
    }
    else if (positive == 0)
        return other;
    else if (other.positive == 0)
        return *this;
    else
    {
        Bint a = abs();
        Bint b = other.abs();
        Bint ans = _absMinus(a, b);
        if (ans == Bint(0))
            ans.positive = 0;
        else
        {
            if (a < b)
                ans.positive = other.positive;
            else
                ans.positive = positive;
        }
        return ans;
    }
}
Bint Bint::operator-(const Bint &other) const
{
    return (*this) + (other.opposite());
}
Bint Bint::operator*(const Bint &other) const
{
    if (*this == Bint() || other == Bint())
        return Bint();
    int length = std::max(digits.size(), other.digits.size());
    int length1 = digits.size();
    int length2 = other.digits.size();
    std::vector<Bint> tmp(length2);
    for (int j = 0; j < length2; ++j)
    {
        Bint x = (*this);
        tmp[j] = x._simpleTimes(other.digits[j]);
        for (int k = 1; k <= length2 - j - 1; ++k)
            tmp[j].digits.push_back(0);
    }
    Bint ans;
    for (int j = 0; j < length2; ++j)
        ans = ans + tmp[j];
    ans.positive = positive * other.positive;
    return ans;
}
Bint Bint::operator/(const Bint &other) const
{
    if (other.positive <= 0)
        return Bint();

    if (positive >= 0)
    {
        if (*this < other)
            return Bint();

        if (*this == other)
            return Bint(1);

        std::vector<int> result = digits;

        for (int i = 0; i < result.size(); ++i)
            result[i] = 0;

        Bint current_dividend;

        for (int i = 0; i < digits.size(); ++i)
        {
            int factor = 0;
            current_dividend = current_dividend * Bint("10") + Bint(digits[i]);
            while (current_dividend >= other * (Bint(factor + 1)))
                factor++;

            result[i] = factor;

            current_dividend = current_dividend - other * (Bint(factor));
            current_dividend._remove_front_zeros();
        }

        while (result.size() > 1 && result[0] == 0)
            result.erase(result.begin());

        return Bint(result);
    }
    else
    {
        return ((opposite() - Bint(1)) / other + Bint(1)).opposite();
    }
}
Bint Bint::operator%(const Bint &other) const
{
    return (*this) - other * ((*this) / other);
}

// 乘方
Bint Bint::pow(Bint c) const
{
    if (c.isZero())
        return Bint_one;
    if (c % Bint_two == 0)
    {
        Bint tmp = pow(c / Bint_two);
        return tmp * tmp;
    }
    else
    {
        Bint tmp = pow(c / Bint_two);
        return tmp * tmp * (*this);
    }
}
Bint Bint::powMod(Bint b, Bint c) const
{
    if (b.isZero())
        return Bint_one;
    if (*this > c)
        return ((*this) / c).powMod(b, c);
    if (b % Bint_two == 0)
    {
        Bint tmp = powMod(b / Bint_two, c);
        return (tmp * tmp) % c;
    }
    else
    {
        Bint tmp = powMod(b / Bint_two, c);
        return (tmp * tmp * (*this)) % c;
    }
}

// 绝对值
Bint Bint::abs() const
{
    return Bint(digits);
}
// 相反数
Bint Bint::opposite() const
{
    Bint ans = *this;
    ans.positive *= (-1);
    return ans;
}

// 转为 int
int Bint::toInt() const
{
    if (length() > 10)
        return -1;
    int ans = 0, d = 1;
    for (int i = length() - 1; i >= 0; --i)
    {
        ans += digits[i] * d;
        d = (d << 3) + (d << 1);
    }
    if (positive < 0)
        ans *= (-1);
    return ans;
}
// 转为 string
std::string Bint::toString() const
{
    std::string ans = positive >= 0 ? "" : "-";
    std::string tmp;

    std::ostringstream oss;
    int l = length();
    for (int i = 0; i < l; ++i)
        oss << digits[i];
    return ans + oss.str();
}

// 获取首位
int Bint::begin() const
{
    return *(digits.begin());
}
// 获取末位
int Bint::end() const
{
    return *(digits.end() - 1);
}
// 获取长度
int Bint::length() const
{
    return digits.size();
}
// 数位之和
int Bint::sum() const
{
    int ans = 0;
    for (int i = 0; i < digits.size(); ++i)
    {
        ans += digits[i];
    }
    return ans;
}

// 是否是奇数
bool Bint::isOdd() const
{
    if (end() % 2 == 0)
        return false;
    return true;
}
// 是否是偶数
bool Bint::isEven() const
{
    if (end() % 2 == 0)
        return true;
    return false;
}
// 是否是 3 的倍数
bool Bint::isMultipleOfThree() const
{
    if (sum() % 3 == 0)
        return true;
    return false;
}
// 是否是 5 的倍数
bool Bint::isMultipleOfFive() const
{
    if (end() % 5 == 0)
        return true;
    return false;
}

// 是否是 0
bool Bint::isZero() const
{
    if (positive == 0)
        return true;
    return false;
}
// 是否是 1
bool Bint::isOne() const
{
    if (digits.size() > 1)
        return false;
    if (digits[0] != 1)
        return false;
    if (positive <= 0)
        return false;
    return true;
}
// 是否是 2
bool Bint::isTwo() const
{
    if (digits.size() > 1)
        return false;
    if (digits[0] != 2)
        return false;
    if (positive <= 0)
        return false;
    return true;
}
// 是否是 3
bool Bint::isThree() const
{
    if (digits.size() > 1)
        return false;
    if (digits[0] != 3)
        return false;
    if (positive <= 0)
        return false;
    return true;
}
// 是否是 4
bool Bint::isFour() const
{
    if (digits.size() > 1)
        return false;
    if (digits[0] != 4)
        return false;
    if (positive <= 0)
        return false;
    return true;
}
// 是否是 5
bool Bint::isFive() const
{
    if (digits.size() > 1)
        return false;
    if (digits[0] != 5)
        return false;
    if (positive <= 0)
        return false;
    return true;
}

// 是否是素数
const Bint y7gksjr8ejgosofj[] = {Bint(2), Bint(3), Bint(5), Bint(7), Bint(11), Bint(13), Bint(17), Bint(19), Bint(23), Bint(29), Bint(31), Bint(37), Bint(41), Bint(43), Bint(47), Bint(53), Bint(59), Bint(61), Bint(67), Bint(71), Bint(73), Bint(79), Bint(83), Bint(89), Bint(97)};                                                                                                                                                                                                                                                                                                                                                                                                                                       // <=100 的素数
const bool d541f7e06fd1dd1e[] = {false, true, true, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, true, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, true, false, false, false, false, false, true, false, false, false, true, false, false, false, false, false, true, false, false, false, false, false, false, false, true, false, false}; // 1~9 的素性
const Bint a3d794cb09d7dd2f[] = {Bint("341550071728321"), Bint("1646697619851137101"), Bint("1167748053436849501"), Bint("1144336081150073701"), Bint("1134931906634489281"), Bint("84983557412237221"), Bint("230245660726188031"), Bint("3825123056546413051")};                                                                                                                                                                                                                                                                                                                                                                                                                                                            // 8 pseudoprimes
bool Bint::isPrime() const
{
    // <100 的数

    // 非正数
    if (positive <= 0)
        return false;
    // 一位数
    if (length() == 1)
        return d541f7e06fd1dd1e[digits[0] - 1];
    // 两位数
    if (length() == 2)
        return d541f7e06fd1dd1e[digits[0] * 10 + digits[1] - 1];

    // >=100 的数

    // 排除 2、3、5 的倍数
    if (isEven())
        return false;
    if (isMultipleOfThree())
        return false;
    if (isMultipleOfFive())
        return false;
    // 排除 8 个 pseudoprimes
    for (int i = 0; i < 8; ++i)
    {
        if ((*this) == a3d794cb09d7dd2f[i])
            return false;
    }

    // Miller-Rabin Main Part
    Bint a_1 = (*this) - Bint_one;
    Bint _2_s = Bint_one;
    int s = 0;
    Bint d = a_1;

    while (d.isEven())
    {
        _2_s = _2_s + _2_s;
        s += 1;
        d = d / Bint_two;
    }

    Bint d0 = d;

    for (int i = 0; i < 8; ++i)
    {
        d = d0;
        bool flag = true;
        Bint pm = y7gksjr8ejgosofj[i].powMod(d, (*this));
        if (pm.isOne())
            continue;
        for (int r = 0; r < s; ++r)
        {
            if (pm == a_1)
            {
                flag = false;
                break;
            }
            d = d + d;
            pm = pm * pm % (*this);
        }
        if (flag == true)
            return false;
    }

    return true;
}

// 静态公开常量
const Bint Bint::Bint_zero = Bint();
const Bint Bint::Bint_one = Bint(1);
const Bint Bint::Bint_two = Bint(2);
const Bint Bint::Bint_three = Bint(3);
