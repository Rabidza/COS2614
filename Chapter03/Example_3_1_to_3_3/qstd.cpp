#include "qstd.h"

QTextStream qstd::cout(stdout, QIODevice::WriteOnly);
QTextStream qstd::cin(stdin, QIODevice::ReadOnly);
QTextStream qstd::cerr(stderr, QIODevice::WriteOnly);

/* Namespace members are like static class members */
bool qstd::yes(QString question)
{
    QString ans;
    cout << QString(" %1 [y/n]? ").arg(question);
    cout.flush();
    ans = cin.readLine();
    return (ans.startsWith("Y", Qt::CaseInsensitive));
}
