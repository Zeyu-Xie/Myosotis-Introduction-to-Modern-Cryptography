#include "Bint.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

Bint p, q;

int main()
{
    while (1)
    {
        cin >> p >> q;

        if (p == q)
            cout << p << "==" << q << "\n";
        if (p != q)
            cout << p << "!=" << q << "\n";
        if (p < q)
            cout << p << "<" << q << "\n";
        if (p > q)
            cout << p << ">" << q << "\n";
        if (p <= q)
            cout << p << "<=" << q << "\n";
        if (p >= q)
            cout << p << ">=" << q << "\n";
        cout << p << "+" << q << "=" << p + q << "\n";
        cout << p << "-" << q << "=" << p - q << "\n";
    }

    return 0;
}