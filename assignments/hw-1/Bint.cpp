#include "Bint.hpp"
using namespace std;

Bint::Bint():length(0),digits({0}) {}

Bint::Bint(vector<int> digits):length(digits.size()),digits(digits) {}