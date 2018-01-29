#include <QTextStream>
#include "fraction.h"

int main()
{
    QTextStream cout(stdout);

    Fraction twothirds(2,3);
    Fraction threequarters(3,4);
    Fraction acopy(twothirds);
    Fraction f4 = threequarters;

    cout << "after declarations - " << Fraction::report();
    f4 = twothirds;
    cout << "\nbefore multiply - " << Fraction::report();
    f4 = twothirds.multiply(threequarters);
    cout << "\nafter multiply - " << Fraction::report() << endl;

    return 0;
}
