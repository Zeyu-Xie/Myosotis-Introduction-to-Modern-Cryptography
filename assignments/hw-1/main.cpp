#pragma GCC optimize(2)
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")

#include "Bint.hpp"
#include "func.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
#include <chrono>
using namespace std;

Bint p, q;
Bint n;
Bint phi_n;
Bint e(65537), d;
Bint tmp, _gcd;
Bint plaintext, encryptedText, decryptedText;

int main()
{
    cout << "----------\n";

    auto start = std::chrono::steady_clock::now();

    while (1)
    {
        cout << "Process: ";

        while (1)
        {
            p = randomBigPrime(24);
            q = randomBigPrime(24);
            plaintext = randomBigNum(23);
            n = p * q;
            phi_n = (p - Bint(1)) * (q - Bint(1));
            if (phi_n % e <= Bint(0))
                continue;
            else
            {
                _gcd = extendedEuclidean(e, phi_n, d, tmp);
                if (d < Bint(0))
                    d = d % phi_n;
                break;
            }
        }

        cout << "\n";

        encryptedText = plaintext.powMod(e, n);
        decryptedText = encryptedText.powMod(d, n);

        cout << "p: " << p << "\n";
        cout << "q: " << q << "\n";
        cout << "n: " << n << "\n";
        cout << "phi_n: " << phi_n << "\n";
        cout << "e: " << e << "\n";
        cout << "d: " << d << "\n";
        cout << "Public Key: (" << n << ", " << e << ")\n";
        cout << "Private Key: (" << n << ", " << d << ")\n";
        cout << "Plain Text: " << plaintext << "\n";
        cout << "Encrypted Text: " << encryptedText << "\n";
        cout << "Decrypted Text: " << decryptedText << "\n";

        auto end = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        start = end;
        cout << "Time: " << duration.count() << " ms\n";
        cout << "----------\n";

        if (plaintext != decryptedText)
        {
            cout << "ERROR";
            break;
        }
    }
    return 0;
}