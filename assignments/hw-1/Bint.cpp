#include "Bint.hpp"

Bint::Bint():digits({0}) {}

Bint::Bint(std::vector<int> digits):digits(digits) {}

std::istream& operator>>(std::istream& is, Bint& bint) {
    std::string input;
    is >> input;
    bint.digits.clear();
    bool flag = false;
    for (char c : input) {
        if (std::isdigit(c)) {
            if(flag) {
                bint.digits.push_back(c - '0');
            }
            else {
                if(c=='0') continue;
                else {
                    bint.digits.push_back(c-'0');
                    flag = true;
                }
            }
        }
        else {
            bint=Bint();
            return is;
        }
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Bint& bint) {
    for (int i = 0; i < bint.digits.size(); i++) {
        os << bint.digits[i];
    }
    return os;
}

bool Bint::operator==(const Bint& other) const {
    int length = digits.size();
    if(length != other.digits.size()) return false;

    for(int i=0;i<length;i++) {
        bool tmp = (digits[i]==other.digits[i]);
        if(tmp) continue;
        else return false;
    }

    return true;
}

bool Bint::operator!=(const Bint& other) const {
    int length = digits.size();
    if(length != other.digits.size()) return true;

    for(int i=0;i<length;i++) {
        bool tmp = (digits[i]==other.digits[i]);
        if(tmp) continue;
        else return true;
    }

    return false;
}