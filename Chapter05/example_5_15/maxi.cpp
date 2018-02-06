#include <iostream>
using namespace std;
int& maxi(int& x, int& y)
{
    return (x > y) ? x : y;
}

int main()
{
    int a = 10, b = 20;
    maxi(a, b) = 5;
    maxi(a, b) += 6;
    ++maxi(a, b);
    cout << a << '\t' << b << endl;

    return 0;
}
