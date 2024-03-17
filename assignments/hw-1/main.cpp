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

    int cnt = 0;
    for(int i=100;i<=120;i++) {
        Bint t(i);
        cout<<t.isOdd()<<t.isEven()<<t.isMultipleOfFive()<<"\n";
    }
    cout << cnt;

    return 0;
}