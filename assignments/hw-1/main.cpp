#include "Bint.hpp"
#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

Bint p, q;
Bint n;
Bint phi_n;
Bint e, d;

int main()
{
    // p = randomBigPrime(8);
    // q = randomBigPrime(8);

    // n = p * q;
    // phi_n = (p - Bint(1)) * (q - Bint(1));

    // cout<<"p: "<<p<<"\n";
    // cout<<"q: "<<q<<"\n";
    // cout<<"n: "<<n<<"\n";
    // cout<<"phi_n: "<<phi_n<<"\n";

    // e = Bint(65537);

    Bint a(35), b(47);

    Bint x, y;

    cout << extendedEuclidean(a, b, x, y) << "\n";

    cout << x << " " << y << "\n";

    return 0;
}