#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString
{
public:
    MyString(const MyString& str);
    MyString& operator=(const MyString& a);
    MyString();
    MyString(const char* chptr);
    explicit MyString(int size);
    virtual ~MyString();
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
    int length() const;
    MyString& operator+=(const MyString& other);
    friend MyString operator+(const MyString&, const MyString&);
protected:
    int m_Len;
    char* m_Buffer;
    void copy(const char* chptr);
};

#endif // MYSTRING_H
