#include "fraction.h"
#include "complex.h"
#include <iostream>

template <class T> T power(T a, int exp)
{
    T ans = a;
    while(--exp > 0)
    {
        ans *= a;
    }
    return ans;
}

int main()
{
    Complex z(3,4), z1;
    Fraction f(5,6), f1;
    int n(19);
    z1 = power(z, 3);
    f1 = power(f, 4);
    z1 = power<Complex>(n, 4);
    z1 = power(n,5);
}
