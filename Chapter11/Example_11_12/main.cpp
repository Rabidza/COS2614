#include <QtWidgets>

QString name()
{
    return QString("Alan");
}

typedef QString (*funcPtr)();
Q_DECLARE_METATYPE(funcPtr)

int main(int, char*[])
{
    qRegisterMetaType<funcPtr>("funcPtr");
    funcPtr ptr = name;

    QString v = (*ptr)();
    qDebug() << v << endl;
    return 0;
}
