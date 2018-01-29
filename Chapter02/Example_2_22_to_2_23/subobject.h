#ifndef SUBOBJECT_H
#define SUBOBJECT_H

class Point
{
public:
    Point(int xx, int yy)
        : m_x(xx), m_y(yy)
    {

    }

    ~Point()
    {
        cout << "point destroyed: ("
             << m_x << "," << m_y << ")" << endl;
    }
private:
    int m_x, m_y;
};

class Square
{
public:
    Square(int ulx, int uly, int lrx, int lry)
        : m_UpperLeft(ulx, uly), m_LowerRight(lrx, lry)
    {

    }

    Square
};

#endif // SUBOBJECT_H
