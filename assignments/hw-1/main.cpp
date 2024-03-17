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
    p = randomBigPrime(2);
    q = randomBigPrime(2);

    n = p * q;
    phi_n = (p - Bint(1)) * (q - Bint(1));

    e = Bint(65537);

    Bint tmp;
    Bint gcd = extendedEuclidean(e, phi_n, d, tmp);

    cout << "p: " << p << "\n";
    cout << "q: " << q << "\n";
    cout << "n: " << n << "\n";
    cout << "phi_n: " << phi_n << "\n";
    cout << "e: " << e << "\n";
    cout << "d: " << d << "\n";

    return 0;
}