#include "Bint.hpp"
#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

Bint p, q;

int main()
{
    int cnt = 25;

    for (int i = 100; i <= 1000; i++)
    {
        if (isBigPrime(i))
        {
            cout << i << "\n";
            cnt ++;
        }
    }
    cout<<"\n"<<cnt;
    return 0;
}