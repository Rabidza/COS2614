#include "fraction.h"

int Fraction::s_assigns = 0;
int Fraction::s_copies = 0;
int Fraction::s_ctors = 0;

Fraction::Fraction(const Fraction &other)
    : m_Numer(other.m_Numer), m_Denom(other.m_Denom)
{
    ++s_copies;
}

Fraction& Fraction::operator =(const Fraction& other)
{
    if (this != &other)
    {
        m_Numer = other.m_Numer;
        m_Denom = other.m_Denom;
        ++s_assigns;
    }

    return *this;
}
