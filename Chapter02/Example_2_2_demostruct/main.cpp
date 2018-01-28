#include <iostream>
using namespace std;

struct Fraction
{
    int numer, denom;
    string description;
};

void printFraction(Fraction f)
{
    cout << f.numer << "/" << f.denom << endl;
    cout << " =? " << f.description << endl;
}

int main()
{
    Fraction f1;
    f1.numer = 4;
    f1.denom = 5;
    f1.description = "four fiths";

    Fraction f2 = {2, 3, "two thirds"};

    f1.numer = f1.numer + 2;

    printFraction(f1);
    printFraction(f2);

    return 0;
}
