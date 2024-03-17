#include "Bint.hpp"
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <random>
using namespace std;

int randomNum(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(a, b);
    return dis(gen);
}

Bint p, q;

int main()
{
    while (1)
    {
        int a = randomNum(1, 100005);
        int b = randomNum(1, 10005);
        Bint ba(a);
        Bint bb(b);

        cout << a + b << " " << ba + bb << " ";
        cout << (Bint(a + b) == ba + bb) << "\n";

        cout << a - b << " " << ba - bb << " ";
        cout << (Bint(a - b) == ba - bb) << "\n";

        cout << a * b << " " << ba * bb << " ";
        cout << (Bint(a * b) == ba * bb) << "\n";

        cout << a / b << " " << ba / bb << " ";
        cout << (Bint(a / b) == ba / bb) << "\n";

        cout << a % b << " " << ba % bb << " ";
        cout << (Bint(a % b) == ba % bb) << "\n";

        if (Bint(a + b) != (ba + bb) || Bint(a * b) != (ba * bb) || Bint(a / b) != (ba / bb) || Bint(a % b) != (ba % bb))
        {
            return 0;
        }

    }

    return 0;
}