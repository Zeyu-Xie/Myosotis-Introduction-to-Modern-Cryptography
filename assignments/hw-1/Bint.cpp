#include "Bint.hpp"

Bint::Bint() : digits({0}) {}

Bint::Bint(std::vector<int> digits) : digits(digits) {}

Bint::Bint(const Bint &other)
{
    digits = other.digits;
}

std::istream &operator>>(std::istream &is, Bint &bint)
{
    std::string input;
    is >> input;
    bint.digits.clear();
    bool flag = false;
    for (char c : input)
    {
        if (std::isdigit(c))
        {
            if (flag)
            {
                bint.digits.push_back(c - '0');
            }
            else
            {
                if (c == '0')
                    continue;
                else
                {
                    bint.digits.push_back(c - '0');
                    flag = true;
                }
            }
        }
        else
        {
            bint = Bint();
            return is;
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Bint &bint)
{
    for (int i = 0; i < bint.digits.size(); i++)
    {
        os << bint.digits[i];
    }
    return os;
}

bool Bint::operator==(const Bint &other) const
{
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
    int length = digits.size();
    if (length != other.digits.size())
        return true;

    for (int i = 0; i < length; i++)
    {
        bool tmp = (digits[i] == other.digits[i]);
        if (tmp)
            continue;
        else
            return true;
    }

    return false;
}

bool Bint::operator<(const Bint &other) const
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

bool Bint::operator>(const Bint &other) const
{
    int length = digits.size();

    if (length > other.digits.size())
        return true;
    else if (length < other.digits.size())
        return false;
    else
    {
        for (int i = 0; i < length; i++)
        {
            if (digits[i] > other.digits[i])
                return true;
            else if (digits[i] < other.digits[i])
                return false;
        }
        return false;
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

// a+b，a 和 b 的大小不设限
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

// a-b，要求 a >= b，否则直接返回 0
Bint Bint::operator-(const Bint &other) const
{
    if (*this <= other)
        return Bint({0});
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
        if (ans[0] == 0)
            ans.erase(ans.begin());
        return Bint(ans);
    }
}

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

// a*b，a 和 b 的大小不设限
Bint Bint::operator*(const Bint &other) const
{
    if (*this == Bint({0}) || other == Bint({0}))
        return Bint({0});
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
    Bint ans({0});
    for (int j = 0; j < length2; j++)
        ans = ans + tmp[j];
    return ans;
}