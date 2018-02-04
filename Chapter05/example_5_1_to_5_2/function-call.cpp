#include <iostream>
using namespace std;

class SignatureDemo
{
public:
    SignatureDemo(int val)
        : m_Val(val)
    {

    }

    void demo(int n)
    {
        cout << ++m_Val << "\tdemo(int)" << endl;
    }

    void demo(int n) const
    {
        cout << m_Val << "\tdemo(int) const" << endl;
    }

//    void demo(const int& n)
//    {
//        cout << ++m_Val << "\tdemo(int&)" << endl;
//    }

    void demo(short s)
    {
        cout << ++m_Val << "\tdemo(short)" << endl;
    }

    void demo(float f)
    {
        cout << ++m_Val << "\tdemo(float)" << endl;
    }

    void demo(float f) const
    {
        cout << m_Val << "\tdemo(float) const" << endl;
    }

    void demo(double d)
    {
        cout << ++m_Val << "\tdemo(double)" << endl;
    }
private:
    int m_Val;
};

int main()
{
    SignatureDemo sd(5);
    const SignatureDemo csd(17);
    sd.demo(2);
    csd.demo(2);
    int i = 3;
    sd.demo(i);
    short s = 5;
    sd.demo(s);
    csd.demo(s);
    sd.demo(2.3);
    float f(4.5);
    sd.demo(f);
    csd.demo(f);
    //csd.demo(4.5);

    return 0;
}
