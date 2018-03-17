#ifndef SHAPES_H
#define SHAPES_H

#include <QString>

class Shape
{
public:
    virtual double area() = 0;
    virtual QString getName() = 0;
    virtual QString getDimensions() = 0;
    virtual ~Shape(){}
};

class Rectangle: public Shape
{
public:
    Rectangle(double h, double w)
        : m_Height(h), m_Width(w) {}
    double area();
    QString getName();
    QString getDimensions();
protected:
    double m_Height;
    double m_Width;

};

class Square: public Rectangle
{
public:
    Square(double h)
        : Rectangle(h,h) {}
    double area();
    QString getName();
    QString getDimensions();
};

class Circle: public Shape
{
public:
    Circle(double r)
        : m_Radius(r) {}
    double area();
    QString getName();
    QString getDimensions();
private:
    double m_Radius;
};

#endif // SHAPES_H
