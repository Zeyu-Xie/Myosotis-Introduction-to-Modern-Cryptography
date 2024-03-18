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
        a = Bint(randomNum(-4, 4));
        b = Bint(randomNum(-4, 4));
        cout<<a<<" "<<b<<"\n";
        if (a == b)
            cout << "==  ";
        if (a != b)
            cout << "!=  ";
        if (a < b)
            cout << "<  ";
        if (a > b)
            cout << ">  ";
        if (a <= b)
            cout << "<=  ";
        if (a >= b)
            cout << ">=  ";
        cout << "\n";
        getchar();
    }
}