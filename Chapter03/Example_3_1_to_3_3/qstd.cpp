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

int qstd::promptInt(int base /* =10 */)
{ /* Usage: int n = promptInt(); */
    QString numstr;
    int result;
    bool ok;
    cout << ": " << flush;
    while (1)
    {
        numstr = cin.readLine();
        result = numstr.toInt(&ok, base);
        if (!ok)
        {
            cout << "Invalid number. Try again: ";
            cout.flush();
        }
        else
            return result;
    }
}
