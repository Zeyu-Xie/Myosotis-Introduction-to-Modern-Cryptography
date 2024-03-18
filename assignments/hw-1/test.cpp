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
        Bint x, y;
        cin>>a>>b;
        Bint gcd = extendedEuclidean(a,b,x,y);
        cout<<a<<"*"<<x<<"+"<<b<<"*"<<y<<"="<<1<<"\n";
    }
    return 0;
}