#include "Bint.hpp"
#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

int main()
{
    Bint a, b;
    while (1)
    {
        a = Bint(randomNum(-100, 100));
        b = Bint(randomNum(0, 10));
        cout << a << " " << b << "\n";
        cout << a / b << " " << a % b << "\n\n";
        getchar();
    }
}