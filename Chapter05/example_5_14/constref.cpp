#include <QString>

class Person
{
public:
    void setNameV(QString newName)
    {
        newName += " Smith";
        m_Name = newName;
    }

    void setNameCR(const QString& newName)
    {
        //newName += " Python";
        m_Name = newName;
    }

    void setNameR(QString& newName)
    {
        newName += " Dobbs";
        m_Name = newName;
    }

private:
    QString m_Name;
};

#include <QDebug>

int main()
{
    Person p;
    QString name("Bob");
    p.setNameCR(name);
    //p.setNameR("Monty");
    p.setNameCR("Monty");
    p.setNameV("Connie");
    p.setNameR(name);
    qDebug() << name;

    return 0;
}
