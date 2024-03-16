#include "Bint.hpp"
using namespace std;

Bint::Bint():digits({0}) {}

Bint::Bint(vector<int> digits):digits(digits) {}

std::istream& operator>>(std::istream& is, Bint& bint) {
    std::string input;
    is >> input;
    bint.digits.clear();
    for (char c : input) {
        if (std::isdigit(c)) {
            bint.digits.push_back(c - '0');
        }
        else {
            bint=Bint();
            return is;
        }
    }
    return is;
}

ostream& operator<<(std::ostream& os, const Bint& bint) {
    for (int i = 0; i < bint.digits.size(); i++) {
        os << bint.digits[i];
    }
    return os;
}