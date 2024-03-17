#include "Bint.hpp"

// Private

void Bint::_remove_front_zeros()
{
    while (this->digits.size() > 0 && this->digits[0] == 0)
        this->digits.erase(this->digits.begin());
}

std::vector<int> Bint::_get_digits() {
    return this->digits;
}

int Bint::_get_length() {
    return this->digits.size();
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

// Public

Bint::Bint() : digits(std::vector<int>({0})) {}

Bint::Bint(std::vector<int> digits) : digits(digits) {}

Bint::Bint(int num)
{
    std::string s = std::to_string(num);
    digits = {};
    for (int i = 0; i < s.length(); i++)
        digits.push_back(s[i] - '0');
}

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
    if (bint.digits.size() <= 0)
        bint.digits.push_back(0);
    return is;
}

std::ostream &operator<<(std::ostream &os, const Bint &bint)
{
    for (int i = 0; i < bint.digits.size(); i++)
        os << bint.digits[i];
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
        while (ans.size() > 0 && ans[0] == 0)
            ans.erase(ans.begin());
        return Bint(ans);
    }
}

// a*b，a 和 b 的大小不设限
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

// a/b，a 和 b 大小不设限
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
        current_dividend = current_dividend * Bint({1, 0}) + Bint(digits[i]);
        while (current_dividend >= other * (Bint(factor+1)))
            factor++;

        result[i] = factor;

        current_dividend = current_dividend - other * (Bint(factor));
       current_dividend._remove_front_zeros();
    }

    while (result.size() > 0 && result[0] == 0)
        result.erase(result.begin());

    return Bint(result);
}

// a%b，a 和 b 大小不设限
Bint Bint::operator%(const Bint &other) const
{
    return (*this) - other * ((*this) / other);
}