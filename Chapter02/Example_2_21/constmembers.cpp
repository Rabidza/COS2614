#include <QTextStream>
#include <QString>

class Point
{
public:
    Point(int px, int py)
        : m_X(px), m_Y(py)
    {

    }

    void set(int nx, int ny)
    {
        m_X = nx;
        m_Y = ny;
    }

    QString toString() const
    {
        //m_X = 5;
        m_Count++;
        return QString("[%1,%2]").arg(m_X).arg(m_Y);
    }
private:
    int m_X, m_Y;
    mutable int m_Count;
};

int main()
{
    QTextStream cout(stdout);

    Point p(1, 1);
    const Point q(2, 2);
    p.set(4, 4);

    cout << p.toString() << endl;
    //q.set(4, 4);

    return 0;
}
