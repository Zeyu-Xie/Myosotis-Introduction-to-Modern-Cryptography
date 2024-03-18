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

// Private

// 去除前面多余的 0
void Bint::_remove_front_zeros()
{
    while (this->digits.size() > 1 && this->digits[0] == 0)
        this->digits.erase(this->digits.begin());
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
        for (int i = 0; i < s.length(); i++)
            digits.push_back(s[i] - '0');
    }
    else
    {
        positive = 1;
        std::string s = std::to_string(num);
        digits = {};
        for (int i = 0; i < s.length(); i++)
            digits.push_back(s[i] - '0');
    }
}
// 从 std::string 构造
Bint::Bint(std::string s)
{
    std::string s1 = (s[0] == '-') ? s.substr(1) : s;

    digits = {};
    for (int i = 0; i < s1.length(); i++)
        digits.push_back(s1[i] - '0');
    this->_remove_front_zeros();

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
    this->_remove_front_zeros();
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

    for (int i = 0; i < length; i++)
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
            for (int i = 0; i < length; i++)
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
            for (int i = 0; i < length; i++)
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
            for (int i = 0; i < length; i++)
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
            for (int i = 0; i < length; i++)
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

// 重载加、减、乘、整除、求余运算符
Bint Bint::operator+(const Bint &other) const
{
    int length = std::max(digits.size(), other.digits.size());
    std::vector<int> ans(length);
    int tot = length - 1;
    int tot1 = digits.size() - 1;
    int tot2 = other.digits.size() - 1;
    int t = 0;
    while (tot >= 0)
    {
        int a = (tot1 >= 0) ? digits[tot1] : 0;
        int b = (tot2 >= 0) ? other.digits[tot2] : 0;
        ans[tot] = a + b + t;
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
Bint Bint::operator-(const Bint &other) const
{
    if (*this <= other)
        return Bint();
    else
    {
        int length = digits.size();
        std::vector<int> ans(length);
        int tot = length - 1;
        int tot1 = digits.size() - 1;
        int tot2 = other.digits.size() - 1;
        int t = 0;
        while (tot >= 0)
        {
            int a = (tot1 >= 0) ? digits[tot1] : 0;
            int b = (tot2 >= 0) ? other.digits[tot2] : 0;
            ans[tot] = a - b - t;
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
        while (ans.size() > 1 && ans[0] == 0)
            ans.erase(ans.begin());
        return Bint(ans);
    }
}
Bint Bint::operator*(const Bint &other) const
{
    if (*this == Bint() || other == Bint())
        return Bint();
    int length = std::max(digits.size(), other.digits.size());
    int length1 = digits.size();
    int length2 = other.digits.size();
    std::vector<Bint> tmp(length2);
    for (int j = 0; j < length2; j++)
    {
        Bint x = (*this);
        tmp[j] = x._simpleTimes(other.digits[j]);
        for (int k = 1; k <= length2 - j - 1; k++)
            tmp[j].digits.push_back(0);
    }
    Bint ans;
    for (int j = 0; j < length2; j++)
        ans = ans + tmp[j];
    return ans;
}
Bint Bint::operator/(const Bint &other) const
{
    if (*this < other)
        return Bint();

    if (*this == other)
        return Bint(1);

    std::vector<int> result = digits;

    for (int i = 0; i < result.size(); i++)
        result[i] = 0;

    Bint current_dividend;

    for (int i = 0; i < digits.size(); i++)
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
Bint Bint::operator%(const Bint &other) const
{
    return (*this) - other * ((*this) / other);
}

// 绝对值
Bint Bint::abs()
{
    return Bint(this->digits);
}
// 相反数
Bint Bint::opposite()
{
    Bint ans = *this;
    ans.positive *= (-1);
    return ans;
}

// 获取末位
int Bint::end()
{
    return *(digits.end() - 1);
}
// 获取长度
int Bint::length()
{
    return digits.size();
}

// 是否是奇数
bool Bint::isOdd()
{
    if (this->end() % 2 == 0)
        return false;
    return true;
}
// 是否是偶数
bool Bint::isEven()
{
    if (this->end() % 2 == 0)
        return true;
    return false;
}
// 是否是 5 的倍数
bool Bint::isMultipleOfFive()
{
    if (this->end() % 5 == 0)
        return true;
    return false;
}
