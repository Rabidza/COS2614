#include "complex.h"

Complex& Complex::operator+=(const Complex& c)
{
    m_Re += c.m_Re;
    m_Im += c.m_Im;
    return *this;
}

Complex Complex::operator +(const Complex& c2)
{
    return Complex(m_Re + c2.m_Re, m_Im + c2.m_Im);
}

Complex& Complex::operator -=(const Complex& c)
{
    m_Re -= c.m_Re;
    m_Im -= c.m_Im;
    return *this;
}
