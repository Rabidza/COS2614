#include <iostream>
#include "sstring.h"
using namespace std;

void passByValue(SString v)
{
    cout << v << v.refcount() << endl;
    v = "somethingelse";
    cout << v << v.refcount() << endl;
}

int main(int argc, char* argv[])
{
    SString s = "Hello";
    passByValue(s);
    cout << s << s.refcount() << endl;
}
