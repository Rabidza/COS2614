#include <iostream>
using namespace std;

int main()
{
    int* ip = 0;
    delete ip;

    if(ip)
        cout << "non-null" << endl;
    else
        cout << "null" << endl;

    ip = new int;
    int* jp = new int(13);
    //[...]

    delete ip;
    delete jp;

    return 0;
}
