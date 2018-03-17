#include "shapes.h"
#include <QString>
#include <QDebug>

void showNameAndArea(Shape* pshp)
{
    qDebug() << pshp->getName()
             << " " << pshp->getDimensions()
             << " area= " << pshp->area();
}

int main()
{
    // Shape shp; NH: This will result in an error because instantiation is not allowed on abstract classes

    Rectangle rectangle(4.1, 5.2);
    Square square(5.1);
    Circle circle(6.1);

    qDebug() << "This program uses hierarchies for Shapes";
    showNameAndArea(&rectangle);
    showNameAndArea(&circle);
    showNameAndArea(&square);

    return 0;
}
